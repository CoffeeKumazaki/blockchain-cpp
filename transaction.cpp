/**
 * @file transaction.cpp
 * @author Kohei Kumazaki 
 * @brief 
 * @version 0.1
 * @date 2018-10-30
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "common.h"
#include "sha256.h"
#include "transaction.h"

Transaction::Transaction()  {
    amount = 0;
    senderKey = "";
    receiverKey = "";
    timestamp = 0;
}

string Transaction::getHash() const {
    string toHash = 
            to_string(amount) 
            + senderKey 
            + receiverKey 
            + to_string(timestamp);

    return sha256(toHash);
}

bool Transaction::isValid() const {

    if ( senderKey == INVALID_HASH ) {
        // reward for mining.
        return true;
    }

    if ( receiverKey.empty() || senderKey.empty() ) {
        return false;
    }

    return true;
}