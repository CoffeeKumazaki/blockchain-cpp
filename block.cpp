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

CBlock::CBlock(int _index, Transaction _data, size_t _prevHash)
: index(_index)
, transaction(_data)
, prevHash(_prevHash)
{
    blockHash = generateHash();
}

CBlock::~CBlock() {

}

size_t CBlock::generateHash() {

    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash; 

    string toHash = to_string(transaction.amount) + transaction.senderKey + transaction.receiverKey + to_string(transaction.timestamp);

    return finalHash( hash1(toHash) + hash2(prevHash) );
}

bool    CBlock::isHashValid() {

    return generateHash() == blockHash;
}

void    CBlock::print() {

    cout << "----" << endl;
    cout << " index     : " << index << endl;
    cout << " prevHash  : " << prevHash << endl;
    cout << " blockHash : " << blockHash << endl;
    transaction.print();
}