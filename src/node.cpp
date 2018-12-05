#include "node.h"

Node::~Node(){

    if(left != nullptr){
        delete left;
    }

    if(right != nullptr){
        delete right;
    }
}

bool pred(const Node *n1, const Node *n2){
    
    return n1->getFreq() > n2->getFreq();
}
