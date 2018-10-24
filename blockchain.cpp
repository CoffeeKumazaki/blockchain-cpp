/**
 * @file blockchain.cpp
 * @author Kohei Kumazaki 
 * @brief implement blockchain class
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "common.h"

#include "sha256.h"
#include "block.h"
#include "blockchain.h"

CBlockchain::CBlockchain()
: difficulty(4)
{
    pendingTransactions.clear();
    CBlock genesisBlock = createGenesisBlock();
    mineBlock();    
}

CBlockchain::~CBlockchain() {

}

CBlock CBlockchain::createGenesisBlock() {

    Transaction genesisTransaction;
    genesisTransaction.amount = 0;
    genesisTransaction.senderKey = "None";
    genesisTransaction.receiverKey = "None";
    genesisTransaction.timestamp = time(NULL);

    hash<int> hash1;
    CBlock genesisBlock(0, string(sha256("0").length(), '0'));
    broadcastTransaction(genesisTransaction);

    return genesisBlock;
}

int CBlockchain::getBlockHeight() {
    return chain.size();
}

CBlock* CBlockchain::getBlock(int index) {

    int height = getBlockHeight();
    if (IS_VALID(index, 0, height)) {
        return &chain[index];
    }

    return NULL;
}

void CBlockchain::broadcastTransaction(Transaction data){

    // 待機リストへ登録.
    pendingTransactions.push_back(data);
}

CBlock* CBlockchain::getLatestBlock() {
    return chain.empty() ? NULL : &chain.back();
}

void CBlockchain::mineBlock() {

    CBlock* pBlock = getLatestBlock();
    int index = pBlock ? pBlock->getIndex() + 1 : 0;
    CBlock newBlock(index, pBlock ? getLatestBlock()->getHash() : INVALID_HASH);
    newBlock.mineBlock(difficulty, pendingTransactions);

    if (newBlock.isHashValid()) { 
        pendingTransactions.clear();
        chain.push_back(newBlock);
    }
}

bool CBlockchain::isChainValid() {

    for(BV_IT it = chain.begin(), itEnd = chain.end(); it != itEnd; ++it) {
        CBlock curBlock = (*it);
        // ブロックのハッシュ値が不正ならエラー.
        if ( curBlock.isHashValid() ) return false;

        if ( chain.size() > 1 ) {
            CBlock prevBlock = *(it - 1);
            // 前回のブロックHashが、今回の前回Hashと一致しなければエラー.
            if ( prevBlock.getHash() != curBlock.getPrevHash() ) return false;
        }
    }

    return true;
    
}


void CBlockchain::print() {

    for ( BV_IT it = chain.begin(), itEnd = chain.end(); it != itEnd; ++it  ) {
        CBlock block = (*it);
        block.print();
    }
}