#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include "node.h"
#include <stack>

class HuffmanTree
{
 private:
    void fillMap(Node *node, std::string string = "");

 public:
    Node *root;
    std::map<char,std::string> pathsDict;

    HuffmanTree (std::vector<Node*> & nodes);
    HuffmanTree();
    HuffmanTree(Node * root){
     this->root = root;   
    };

    // func below may not be useful
    std::map<char, std::string> getMap();

    std::string findLetterPath(unsigned char letter);

    void printTree();
    void fillMap();
    std::string preOrder();
    ~HuffmanTree();
};

#endif /* ifndef _HUFFMAN_H */
