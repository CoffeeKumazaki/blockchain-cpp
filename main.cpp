
#include "common.h"
#include "node.h"
#include "sha256.h"


int main(int argc, char** argv) {

    CNode  chain;

    Transaction trans1;
    trans1.amount = 100;
    trans1.senderKey = "John";
    trans1.receiverKey = "Bob";
    trans1.timestamp = time(NULL);
    chain.broadcastTransaction(trans1);

    Transaction trans2;
    trans2.amount = 200;
    trans2.senderKey = "Alice";
    trans2.receiverKey = "Lisa";
    trans2.timestamp = time(NULL);
    chain.broadcastTransaction(trans2);

    chain.mineBlock("Mike");

    Transaction trans3;
    trans3.amount = 30;
    trans3.senderKey = "Mike";
    trans3.receiverKey = "Lisa";
    trans3.timestamp = time(NULL);
    chain.broadcastTransaction(trans3);

    chain.mineBlock("Mike");

    cout << "Bob's Balance : " << chain.getBalance("Bob") << endl;
    cout << "Mike's Balance : " << chain.getBalance("Mike") << endl;
    cout << "Lisa's Balance : " << chain.getBalance("Lisa") << endl;

    chain.print();

}