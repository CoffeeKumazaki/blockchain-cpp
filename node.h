/**
 * @file node.h
 * @author Kohei Kumazaki 
 * @brief declear node class
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

class CNode {

public:
    CNode();
    ~CNode();

    void print();

public:
    int     getBlockHeight();           // ブロック数取得.
    CBlock* getBlock(int index);        // 指定番号のブロック取得. 
    CBlock* getLatestBlock();           // 最新のブロック取得.

    void broadcastTransaction(Transaction data);    // トランザクションの発行.
    void mineBlock(address miner);                  // ブロックの追加.
    bool isChainValid();                // 有効なチェーンかチェック.
    int  getBalance(address account);   // 残高照会.

private:
    CBlock createGenesisBlock();        // genesis blockの作成. 
    void   generateRewardTransaction(address miner);    // 報酬トランザクションの発行.


public:
    BVECTOR     chain;                  // ブロックチェーン.

private:
    TLIST       pendingTransactions;    // ブロック格納前のトランザクション.
    uint32_t    difficulty;             // マイニングの難易度.
    uint32_t    reward;                 // マイニングの報酬.

};