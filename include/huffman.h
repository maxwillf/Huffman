#include "node.h"

class HuffmanTree {

    Node *root;

    public:
    
    HuffmanTree (std::vector<Node*> & nodes);
    void printTree();
    ~HuffmanTree(){ delete root;}
};
