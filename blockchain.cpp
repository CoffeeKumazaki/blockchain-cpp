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

#include "block.h"
#include "blockchain.h"

CBlockchain::CBlockchain() {

    CBlock genesisBlock = createGenesisBlock();
    chain.push_back(genesisBlock);
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
    CBlock genesisBlock(0, genesisTransaction, hash1(0));

    return genesisBlock;
}

CBlock* CBlockchain::getLatestBlock() {
    return &chain.back();
}

void CBlockchain::addBlock(Transaction data) {

    int index = getLatestBlock()->getIndex() + 1;
    CBlock newBlock(index, data, getLatestBlock()->getHash());
    chain.push_back(newBlock);
}

bool CBlockchain::isChainValid() {

    
    for(VIT_Block it = chain.begin(), itEnd = chain.end(); it != itEnd; ++it) {
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

    for ( VIT_Block it = chain.begin(), itEnd = chain.end(); it != itEnd; ++it  ) {
        CBlock block = (*it);
        block.print();
    }
}