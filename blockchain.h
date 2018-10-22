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

using namespace std;

class CBlock;

class CBlockchain {

public:
    CBlockchain();
    ~CBlockchain();

public:
    CBlock* getLatestBlock();
    

    void addBlock();        // ブロックの追加.
    bool isChainValid();    // 有効なチェーンかチェック.

public:
    vector<CBlock>  chain;  // ブロックチェーン.

private:

};

CBlockchain::CBlockchain(/* args */)
{
}

CBlockchain::~CBlockchain()
{
}
