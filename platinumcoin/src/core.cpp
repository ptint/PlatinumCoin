// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Platinumcoin developers
// Copyright (c) 2014 The Mini-Blockchain Project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "core.h"
#include "util.h"
#include "hashblock.h"
#include "script.h"
#include "base58.h"

CTxIn::CTxIn(CScript scriptSigIn, unsigned int nSequenceIn)
{
    scriptSig = scriptSigIn;
}

CTxIn::CTxIn(uint160 pubKeyIn, uint64_t nValueIn){
	pubKey = pubKeyIn; nValue = nValueIn;
}


std::string CTxIn::ToString() const
{
    //TODO: incomplete
    std::string str;
    str += "CTxIn(";
    if (IsNull())
        str += strprintf("nValue %d.%08d, coinbase %s",  nValue / COIN, nValue % COIN, HexStr(scriptSig));
    else
        str += strprintf("nValue %d.%08d, addr %s, pubKey %s, scriptSig=%s",  nValue / COIN, nValue % COIN, 
		CPlatinumcoinAddress(CKeyID(pubKey)).ToString(), pubKey.ToString(), HexStr(scriptSig));
    str += ")";
    return str;
}

void CTxIn::print() const
{
    LogPrintf("%s\n", ToString());
}

CTxOut::CTxOut(int64_t nValueIn, uint160 pubKeyIn)
{
    nValue = nValueIn;
    pubKey = pubKeyIn;
}

uint256 CTxOut::GetHash() const
{
    return SerializeHash(*this);
}

std::string CTxOut::ToString() const
{
    return strprintf("CTxOut(nValue=%d.%08d, addr=%s, pubKey=%s)", nValue / COIN, nValue % COIN, CPlatinumcoinAddress(CKeyID(pubKey)).ToString(), pubKey.GetHex());
}

void CTxOut::print() const
{
    LogPrintf("%s\n", ToString());
}

uint256 CTransaction::GetHash() const
{
    return SerializeHash(*this);
}

uint256 CTransaction::GetTxID() const
{
    return SignatureHash(*this);
}

bool CTransaction::IsNewerThan(const CTransaction& old) const
{
    if (vin.size() != old.vin.size())
        return false;
    for (unsigned int i = 0; i < vin.size(); i++)
        if (vin[i].pubKey != old.vin[i].pubKey)
            return false;

    return false;
}

uint64_t CTransaction::GetValueOut() const
{
    uint64_t nValueOut = 0;
    BOOST_FOREACH(const CTxOut& txout, vout)
    {
        if (!MoneyRange(txout.nValue+nValueOut) || (nValueOut + txout.nValue) < nValueOut)
            throw std::runtime_error("CTransaction::GetValueOut() : value out of range");
        nValueOut += txout.nValue;
    }
    return nValueOut;
}

uint64_t CTransaction::GetValueIn() const
{
    uint64_t nValueIn = 0;
    BOOST_FOREACH(const CTxIn& txin, vin)
    {
        if (!MoneyRange(txin.nValue+nValueIn) || (nValueIn+txin.nValue) < nValueIn)
            throw std::runtime_error("CTransaction::GetValueIn() : value in of range");
        nValueIn += txin.nValue;
    }
    return nValueIn;
}

double CTransaction::ComputePriority(double dPriorityInputs, unsigned int nTxSize) const
{
    // In order to avoid disincentivizing cleaning up the UTXO set we don't count
    // the constant overhead for each txin and up to 110 bytes of scriptSig (which
    // is enough to cover a compressed pubkey p2sh redemption) for priority.
    // Providing any more cleanup incentive than making additional inputs free would
    // risk encouraging people to create junk outputs to redeem later.
    if (nTxSize == 0)
        nTxSize = ::GetSerializeSize(*this, SER_NETWORK, PROTOCOL_VERSION);
    BOOST_FOREACH(const CTxIn& txin, vin)
    {
        unsigned int offset = 41U + std::min(110U, (unsigned int)txin.scriptSig.size());
        if (nTxSize > offset)
            nTxSize -= offset;
    }
    if (nTxSize == 0) return 0.0;
    return dPriorityInputs / nTxSize;
}

std::string CTransaction::ToString() const
{
    std::string str;
    str += strprintf("CTransaction(hash=%s, ver=%d, vin.size=%" PRIszu ", vout.size=%" PRIszu ", nLockHeight=%lu)\n",
        GetTxID().ToString(),
        nVersion,
        vin.size(),
        vout.size(),
        nLockHeight);
    for (unsigned int i = 0; i < vin.size(); i++)
        str += "    " + vin[i].ToString() + "\n";
    for (unsigned int i = 0; i < vout.size(); i++)
        str += "    " + vout[i].ToString() + "\n";
    return str;
}

void CTransaction::print() const
{
    LogPrintf("%s", ToString());
}

// Amount compression:
// * If the amount is 0, output 0
// * first, divide the amount (in base units) by the largest power of 10 possible; call the exponent e (e is max 9)
// * if e<9, the last digit of the resulting number cannot be 0; store it as d, and drop it (divide by 10)
//   * call the result n
//   * output 1 + 10*(9*n + d - 1) + e
// * if e==9, we only know the resulting number is not zero, so output 1 + 10*(n - 1) + 9
// (this is decodable, as d is in [1-9] and e is in [0-9])

uint64_t CTxOutCompressor::CompressAmount(uint64_t n)
{
    if (n == 0)
        return 0;
    int e = 0;
    while (((n % 10) == 0) && e < 9) {
        n /= 10;
        e++;
    }
    if (e < 9) {
        int d = (n % 10);
        assert(d >= 1 && d <= 9);
        n /= 10;
        return 1 + (n*9 + d - 1)*10 + e;
    } else {
        return 1 + (n - 1)*10 + 9;
    }
}

uint64_t CTxOutCompressor::DecompressAmount(uint64_t x)
{
    // x = 0  OR  x = 1+10*(9*n + d - 1) + e  OR  x = 1+10*(n - 1) + 9
    if (x == 0)
        return 0;
    x--;
    // x = 10*(9*n + d - 1) + e
    int e = x % 10;
    x /= 10;
    uint64_t n = 0;
    if (e < 9) {
        // x = 9*n + d - 1
        int d = (x % 9) + 1;
        x /= 9;
        // x = n
        n = x*10 + d;
    } else {
        n = x+1;
    }
    while (e) {
        n *= 10;
        e--;
    }
    return n;
}

uint256 CBlockHeader::GetHash() const
{
#if 0
    uint32_t i;
    for(i=0; i < 2 + (uint8_t*)&nVersion - (uint8_t*)&hashPrevBlock; i++){
   	printf("%2.2X ", ((uint8_t*)&nVersion)[i]);
    }
    printf("\n");
#endif
    return Hash7(BEGIN(hashPrevBlock), END(nVersion));
}

uint256 CBlock::BuildMerkleTree() const
{
    vMerkleTree.clear();
    BOOST_FOREACH(const CTransaction& tx, vtx)
        vMerkleTree.push_back(tx.GetHash());
    int j = 0;
    for (int nSize = vtx.size(); nSize > 1; nSize = (nSize + 1) / 2)
    {
        for (int i = 0; i < nSize; i += 2)
        {
            int i2 = std::min(i+1, nSize-1);
            vMerkleTree.push_back(Hash(BEGIN(vMerkleTree[j+i]),  END(vMerkleTree[j+i]),
                                       BEGIN(vMerkleTree[j+i2]), END(vMerkleTree[j+i2])));
        }
        j += nSize;
    }
    return (vMerkleTree.empty() ? 0 : vMerkleTree.back());
}

std::vector<uint256> CBlock::GetMerkleBranch(int nIndex) const
{
    if (vMerkleTree.empty())
        BuildMerkleTree();
    std::vector<uint256> vMerkleBranch;
    int j = 0;
    for (int nSize = vtx.size(); nSize > 1; nSize = (nSize + 1) / 2)
    {
        int i = std::min(nIndex^1, nSize-1);
        vMerkleBranch.push_back(vMerkleTree[j+i]);
        nIndex >>= 1;
        j += nSize;
    }
    return vMerkleBranch;
}

uint256 CBlock::CheckMerkleBranch(uint256 hash, const std::vector<uint256>& vMerkleBranch, int nIndex)
{
    if (nIndex == -1)
        return 0;
    BOOST_FOREACH(const uint256& otherside, vMerkleBranch)
    {
        if (nIndex & 1)
            hash = Hash(BEGIN(otherside), END(otherside), BEGIN(hash), END(hash));
        else
            hash = Hash(BEGIN(hash), END(hash), BEGIN(otherside), END(otherside));
        nIndex >>= 1;
    }
    return hash;
}

void CBlock::print() const
{
    LogPrintf("CBlock(hash=%s, ver=%d, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nNonce=%u, vtx=%" PRIszu ")\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nNonce,
        vtx.size());
    for (unsigned int i = 0; i < vtx.size(); i++)
    {
        LogPrintf("  ");
        vtx[i].print();
    }
    LogPrintf("  vMerkleTree: ");
    for (unsigned int i = 0; i < vMerkleTree.size(); i++)
        LogPrintf("%s ", vMerkleTree[i].ToString());
    LogPrintf("\n");
}
