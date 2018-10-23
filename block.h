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
    CBlock(int index, Transaction data, string prevHash);
    ~CBlock();

    void print();

public:
    // getter.
    int     getIndex()  { return index; }
    string  getHash()   { return blockHash; }
    string  getPrevHash() { return prevHash; }

    // Hashが有効かチェック.
    bool    isHashValid();

    // ブロックのマイニング.
    void    mineBlock(int difficulty);

private:
    string  generateHash();

private:
    int         index;      // ブロック番号.
    string      blockHash;  // ブロックのハッシュ値.
    string      prevHash;   // 前ブロックのハッシュ値.
    Transaction transaction;// 含まれるトランザクションデータ.
    uint64_t    nonce;      // マイニングのためのナンス値.
};
