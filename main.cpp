
#include "common.h"
#include "blockchain.h"
#include "sha256.h"

int main(int argc, char** argv) {

    CBlockchain  chain;

    Transaction trans1;
    trans1.amount = 100;
    trans1.senderKey = "John";
    trans1.receiverKey = "Bob";
    trans1.timestamp = time(NULL);
    chain.addBlock(trans1);

    Transaction trans2;
    trans2.amount = 200;
    trans2.senderKey = "Alice";
    trans2.receiverKey = "Lisa";
    trans2.timestamp = time(NULL);
    chain.addBlock(trans2);

    chain.print();

}