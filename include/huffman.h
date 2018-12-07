#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include "node.h"
#include <stack>

class HuffmanTree
{
 private:
    void fillMap(Node *node, std::string string = "");
    // pointer to be used when uncompressing;
    Node *searchNode;

 public:

    Node *root;
    std::map<char,std::string> pathsDict;

    HuffmanTree (std::vector<Node*> & nodes);
    HuffmanTree();
    HuffmanTree(Node * root){
        this->root = root;   
        searchNode = root;
    };

    // func below may not be useful
    std::map<char, std::string> getMap();

    std::string findLetterPath(unsigned char letter);

    void printTree();
    void fillMap();
    char searchByBit(unsigned char bit);
    std::string preOrder();
    ~HuffmanTree();
};

#endif /* ifndef _HUFFMAN_H */
