/**
 * @file transaction.h
 * @author Kohei Kumazaki 
 * @brief declear transaction data
 * @version 0.1
 * @date 2018-10-23
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once

#include <ctime>
#include <string>

using namespace std;

struct Transaction {
    double amount;      // 送付額.
    string senderKey;   // 送信元.
    string receiverKey; // 送信先.
    time_t timestamp;   // 送信時刻.

    Transaction() {
        amount = 0;
        senderKey = "";
        receiverKey = "";
        timestamp = 0;
    }
};
