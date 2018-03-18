// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Platinumcoin developers
// Copyright (c) 2014 The Mini-Blockchain Project
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"
#include "trie.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0x3ed28ad9, 0x3ed24b19,
    0x3ed26c80
};

void MineGenesis(CBlock genesis){
    // This will figure out a valid hash and Nonce if you're creating a different genesis block:
    uint256 hashTarget = CBigNum().SetCompact(Params().ProofOfWorkLimit().GetCompact()).getuint256();
    printf("Target: %s\n", hashTarget.GetHex().c_str());
    uint256 newhash = genesis.GetHash();
    uint256 besthash;
    memset(&besthash,0xFF,32);
    while (newhash > hashTarget) {
    	++genesis.nNonce;
        if (genesis.nNonce == 0){
            printf("NONCE WRAPPED, incrementing time");
            ++genesis.nTime;
        }
	newhash = genesis.GetHash();
	if(newhash < besthash){
	    besthash=newhash;
	    printf("New best: %s\n", newhash.GetHex().c_str());
	}
    }
    printf("Found Genesis, Nonce: %ld, Hash: %s\n", genesis.nNonce, genesis.GetHash().GetHex().c_str());
    exit(0);
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xf9;
        pchMessageStart[1] = 0xbe;
        pchMessageStart[2] = 0xb4;
        pchMessageStart[3] = 0xd9;
        vAlertPubKey = ParseHex("038b1e94fa4d647bb8ea50b1540b2a04846181fd10d87e35b609311054ab02cba3");
        nDefaultPort = 8668;
        nRPCPort = 8669;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        nSubsidyHalvingInterval = 210000;

//printf("Target: %s\n", GetTargetWork(4096.0).GetHex().c_str()); exit(0);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        // CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
        //   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
        //     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
        //   vMerkleTree: 4a5e1e
        CTransaction txNew;
        txNew.vin.resize(0);
        txNew.vout.resize(1);
        txNew.vout[0].nValue = MAX_MONEY; //All coins created in genesis
        txNew.vout[0].pubKey = 0; //Genesis target is coinbase
        txNew.nLockHeight=0;	
	string msg = "PlatinumCoin Is Created on 2018/01/15, And Looks The Best One. Ev3ryb0dy W1ll Enjoyi It!";
	txNew.msg = vector<char>(msg.begin(),msg.end());
	genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();

	//Build a single trienode to find the hash of the coinbase only trie
	TrieNode *coinbase = new TrieNode(NODE_LEAF);
	coinbase->SetKey(0);
	coinbase->SetBalance(txNew.vout[0].nValue);

	genesis.hashAccountRoot = coinbase->Hash(); //TODO: get the trie hash
	delete coinbase;
        genesis.nVersion = 1;
	genesis.nHeight  = 0;
        genesis.nTime    = 1516924800;
        genesis.nNonce   = 3926226;

        hashGenesisBlock = genesis.GetHash();
//        printf("CMainParams Genesis : %s\n", genesis.GetHash().ToString().c_str());
//        printf("CMainParams Merkle  : %s\n", genesis.hashMerkleRoot.ToString().c_str());
        assert(genesis.hashMerkleRoot == uint256("0xcaa00271f234894d74016aacbb40915a7a9eedf0374d1f8dd2ead7f89c7afa2f"));
        if(hashGenesisBlock != uint256("0x000007eb8c5feb3322a4d2b6d9eae21fd1c7a37c34b1b8a2a5ad5c487ac43d27"))
		MineGenesis(genesis);


	vSeeds.push_back(CDNSSeedData("plc-node-01.okk26.com", "plc-node-01.okk26.com"));
	vSeeds.push_back(CDNSSeedData("plc-node-02.okk26.com", "plc-node-02.okk26.com"));
        vSeeds.push_back(CDNSSeedData("node-a.kamalium.com", "node-a.kamalium.com"));

        //sa ToDO: Review. The convert_to_container stuff was added as a quick fix to get it building in c++11. it should work
        // 	but not 100% certain and haven't tested
        base58Prefixes[PUBKEY_ADDRESS] = (list_of(28)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[SCRIPT_ADDRESS] = (list_of(5)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[SECRET_KEY] =     (list_of(128)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[EXT_PUBLIC_KEY] = (list_of(0x04)(0x88)(0xB2)(0x1E)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = (list_of(0x04)(0x88)(0xAD)(0xE4)).convert_to_container<vector<unsigned char> >();

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x0c;
        pchMessageStart[1] = 0x12;
        pchMessageStart[2] = 0x09;
        pchMessageStart[3] = 0x07;
        vAlertPubKey = ParseHex("038b1e94fa4d647bb8ea50b1540b2a04846181fd10d87e35b609311054ab02cba3");
        nDefaultPort = 18668;
        nRPCPort = 18668;
        strDataDir = "PlatinumCoin Is Created on 2018/01/15 And Looks The Best One. Ev3ryb0dy W1ll Enjoyi It!";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1516924800;
        genesis.nNonce = 1822090;
	string msg = "foo";
	genesis.vtx[0].msg = vector<char>(msg.begin(),msg.end());
	genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        hashGenesisBlock = genesis.GetHash();

//        printf("CTestNetParams Genesis : %s\n", genesis.GetHash().ToString().c_str());
//        printf("CTestNetParams Merkle  : %s\n", genesis.hashMerkleRoot.ToString().c_str());


        //printf("%s\n", genesis.GetHash().ToString().c_str());
//        assert(hashGenesisBlock == uint256("0xcc9c9f3b61e8422bc54b86925238262a2994f265aea14b5e10e3d2fd4cb413a8"));

	if(hashGenesisBlock!= uint256("0x00000edb7ef45795e50149d5cd4bbf9d5000ab168d9b31c34a86bed094a3b72b")){
		MineGenesis(genesis);
	}

        vFixedSeeds.clear();
	vSeeds.push_back(CDNSSeedData("plc-node-01.okk26.com", "plc-node-01.okk26.com"));
	vSeeds.push_back(CDNSSeedData("plc-node-02.okk26.com", "plc-node-02.okk26.com"));
 
	//sa ToDO: Review. The convert_to_container stuff was added as a quick fix to get it building in c++11. it should work
	// 	but not 100% certain and haven't tested
        base58Prefixes[PUBKEY_ADDRESS] = (list_of(87)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[SCRIPT_ADDRESS] = (list_of(196)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[SECRET_KEY]     = (list_of(239)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[EXT_PUBLIC_KEY] = (list_of(0x04)(0x35)(0x87)(0xCF)).convert_to_container<vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = (list_of(0x04)(0x35)(0x83)(0x94)).convert_to_container<vector<unsigned char> >();
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
