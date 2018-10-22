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

typedef vector<CBlock> VBlock;
typedef vector<CBlock>::iterator VIT_Block;

class CBlockchain {

public:
    CBlockchain();
    ~CBlockchain();

public:
    CBlock* getLatestBlock();    

    void addBlock(Transaction data);        // ブロックの追加.
    bool isChainValid();    // 有効なチェーンかチェック.
private:
    CBlock createGenesisBlock();

public:
    VBlock  chain;  // ブロックチェーン.

private:

};