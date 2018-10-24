/**
 * @file block.cpp
 * @author Kohei Kumazaki 
 * @brief implement block class
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "common.h"
#include "transaction.h"
#include "block.h"
#include "sha256.h"

CBlock::CBlock(int _index, string _prevHash)
: index(_index)
, prevHash(_prevHash)
, nonce(0)
{
    transactions.clear();
}

CBlock::~CBlock() {

}

string CBlock::generateHash() {

    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash; 

    string toHash = to_string(nonce);
    for ( TL_IT it = transactions.begin(), itEnd = transactions.end(); it != itEnd; ++it) {
        Transaction data = (*it);
        toHash += data.getHashSeed();
    }

    return sha256( toHash + prevHash );
}

bool    CBlock::isHashValid() {

    return generateHash() == blockHash;
}

void  CBlock::mineBlock(int difficulty, TLIST& pendingTransactions) {

    string header(difficulty, '0');
    string finalHash;

    transactions.assign(pendingTransactions.begin(), pendingTransactions.end());

    while ( finalHash.compare(0, difficulty, header) != 0 ) {
        nonce++;
        finalHash = generateHash();
    }

    blockHash = finalHash;
}


void    CBlock::print() {

    cout << "----" << endl;
    cout << " index     : " << index << endl;
    cout << " prevHash  : " << prevHash << endl;
    cout << " blockHash : " << blockHash << endl;
    for ( TL_IT it = transactions.begin(), itEnd = transactions.end(); it != itEnd; ++it ) {
        Transaction transaction = (*it);
        transaction.print();
    }
}