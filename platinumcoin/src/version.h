// Copyright (c) 2012 The Platinumcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef PLATINUMCOIN_VERSION_H
#define PLATINUMCOIN_VERSION_H

#include "clientversion.h"

#include <string>

//
// client versioning
//

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

//
// network protocol versioning
//

static const int PROTOCOL_VERSION = 12001;

// initial proto version, to be increased after version/verack negotiation
static const int INIT_PROTO_VERSION = 12000;

// version where slice requests would cause ban
static const int BROKEN_SLICE_VERSION = 11999;

// disconnect from peers older than this proto version
static const int MIN_PEER_PROTO_VERSION = 11999;

// "mempool" command, enhanced "getdata" behavior starts with this version:
static const int MEMPOOL_GD_VERSION = 60002;

#endif