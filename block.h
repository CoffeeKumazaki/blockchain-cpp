/**
 * @file block.h
 * @author Kohei Kumazaki 
 * @brief declear block data class
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once

#include "transaction.h"

using namespace std;

struct Transaction;

class CBlock {

public:
    CBlock(int index, Transaction data, size_t prevHash);
    ~CBlock();

public:
    // getter.
    int     getIndex()  { return index; }
    size_t  getHash()   { return blockHash; }
    size_t  getPrevHash() { return prevHash; }

    // Hashが有効かチェック.
    bool    isHashValid();

private:
    size_t  generateHash();

private:
    int         index;      // ブロック番号.
    size_t      blockHash;  // ブロックのハッシュ値.
    size_t      prevHash;   // 前ブロックのハッシュ値.
    Transaction transaction;// 含まれるトランザクションデータ.
};
