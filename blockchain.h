/**
 * @file blockchain.h
 * @author Kohei Kumazaki 
 * @brief declear blockchain class
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#pragma once

#include <vector>

#include "transaction.h"
#include "block.h"
using namespace std;

class CBlockchain {

public:
    CBlockchain();
    ~CBlockchain();

    void print();

public:
    int     getBlockHeight();           // ブロック数取得.
    CBlock* getBlock(int index);        // 指定番号のブロック取得. 
    CBlock* getLatestBlock();           // 最新のブロック取得.

    void broadcastTransaction(Transaction data);    // トランザクションの発行.
    void mineBlock();                   // ブロックの追加.
    bool isChainValid();                // 有効なチェーンかチェック.
private:
    CBlock createGenesisBlock();

public:
    BVECTOR     chain;                  // ブロックチェーン.
    TLIST       pendingTransactions;    // ブロック格納前のトランザクション.
    uint32_t    difficulty;             // マイニングの難易度.


private:

};