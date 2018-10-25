/**
 * @file Node.cpp
 * @author Kohei Kumazaki 
 * @brief implement Node class
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "common.h"

#include "sha256.h"
#include "block.h"
#include "node.h"

CNode::CNode()
: difficulty(4)
, reward(100)
{
    pendingTransactions.clear();
    CBlock genesisBlock = createGenesisBlock();
    chain.push_back(genesisBlock);
}

CNode::~CNode() {

}

CBlock CNode::createGenesisBlock() {

    Transaction genesisTransaction;
    genesisTransaction.amount = 0;
    genesisTransaction.senderKey = "None";
    genesisTransaction.receiverKey = "None";
    genesisTransaction.timestamp = time(NULL);
    broadcastTransaction(genesisTransaction);

    CBlock genesisBlock(0, INVALID_HASH);
    genesisBlock.mineBlock( difficulty, pendingTransactions);
    pendingTransactions.clear();

    return genesisBlock;
}

void CNode::generateRewardTransaction(address miner) {

    Transaction rewardTransaction;
    rewardTransaction.amount = reward;
    rewardTransaction.senderKey = INVALID_HASH;
    rewardTransaction.receiverKey = miner;
    rewardTransaction.timestamp = time(NULL);

    broadcastTransaction(rewardTransaction);
}

int CNode::getBlockHeight() {
    return chain.size();
}

CBlock* CNode::getBlock(int index) {

    int height = getBlockHeight();
    if (IS_VALID(index, 0, height)) {
        return &chain[index];
    }

    return NULL;
}

void CNode::broadcastTransaction(Transaction data){

    // 待機リストへ登録.
    pendingTransactions.push_back(data);
}

CBlock* CNode::getLatestBlock() {
    return chain.empty() ? NULL : &chain.back();
}

void CNode::mineBlock(address miner) {

    CBlock* pBlock = getLatestBlock();
    int index = pBlock->getIndex() + 1;
    CBlock newBlock(index, pBlock->getHash());
    newBlock.mineBlock(difficulty, pendingTransactions);

    if (newBlock.isHashValid()) { 
        pendingTransactions.clear();
        chain.push_back(newBlock);
        generateRewardTransaction(miner);
    }
}

bool CNode::isChainValid() {

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

int  CNode::getBalance(address account) {

    int balance = 0;

    for (BV_CIT bit = chain.begin(), bitEnd = chain.end(); bit != bitEnd; ++bit ) {
        const CBlock block = (*bit);
        for ( TL_CIT tit = block.T_begin(), titEnd = block.T_end(); tit != titEnd; ++tit ) {
            const Transaction transaction = (*tit);
            if ( transaction.receiverKey == account ) {
                balance += transaction.amount;
            }
            
            if ( transaction.senderKey == account ) {
                balance -= transaction.amount;
            }
        }

    }

    return balance;

}


void CNode::print() {

    for ( BV_IT it = chain.begin(), itEnd = chain.end(); it != itEnd; ++it  ) {
        CBlock block = (*it);
        block.print();
    }
}