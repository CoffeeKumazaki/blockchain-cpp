
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
    chain.mineBlock("Mike");

    chain.print();

}