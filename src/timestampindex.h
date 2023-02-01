// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef YERBAS_TIMESTAMPINDEX_H
#define YERBAS_TIMESTAMPINDEX_H

#include "uint256.h"

struct CTimestampBlockIndexKey {
    uint256 blockHash;

    size_t GetSerializeSize() const {
        return 32;
    }

    template<typename Stream>
    void Serialize(Stream& s) const {
        blockHash.Serialize(s);
    }

    template<typename Stream>
    void Unserialize(Stream& s) {
        blockHash.Unserialize(s);
    }

    CTimestampBlockIndexKey(uint256 hash) {
        blockHash = hash;
    }

    CTimestampBlockIndexKey() {
        SetNull();
    }

    void SetNull() {
        blockHash.SetNull();
    }
};

struct CTimestampBlockIndexValue {
    unsigned int ltimestamp;
    size_t GetSerializeSize() const {
        return 4;
    }

    template<typename Stream>
    void Serialize(Stream& s) const {
        ser_writedata32be(s, ltimestamp);
    }

    template<typename Stream>
    void Unserialize(Stream& s) {
        ltimestamp = ser_readdata32be(s);
    }

    CTimestampBlockIndexValue (unsigned int time) {
        ltimestamp = time;
    }

    CTimestampBlockIndexValue() {
        SetNull();
    }

    void SetNull() {
        ltimestamp = 0;
    }
};

#endif // YERBAS_TIMESTAMPINDEX_H
