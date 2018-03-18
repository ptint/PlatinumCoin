// Copyright (c) 2009-2013 The Platinumcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PLATINUMCOIN_CHECKPOINT_H
#define PLATINUMCOIN_CHECKPOINT_H

#include <map>

class CBlockIndex;
class uint256;

/** Block-chain checkpoints are compiled-in sanity checks.
 * They are updated every release or three.
 */
namespace Checkpoints
{
    // Returns true if block passes checkpoint checks
    bool CheckBlock(int nHeight, const uint256& hash);

    // Return conservative estimate of total number of blocks, 0 if unknown
    int GetTotalBlocksEstimate();

    // Returns last CBlockIndex* in mapBlockIndex that is a checkpoint
    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex);
    int GetLastCheckpointHeight(int nHeight);

    double GuessVerificationProgress(CBlockIndex *pindex, bool fSigchecks = true);

    extern bool fEnabled;
}

#endif