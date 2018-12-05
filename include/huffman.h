#ifndef _HUFFMAN_H
#define _HUFFMAN_H 

#include "node.h"

class HuffmanTree {

    Node *root;
    std::map<char,std::string> pathsDict;
    
    private: 

    void fillMap(Node *node, std::string string = "");

    public:
    
    HuffmanTree (std::vector<Node*> & nodes);
    // func below may not be useful
    std::map<char,std::string> getMap();

    std::string findLetterPath(unsigned char letter);

    void printTree();
    void fillMap();
    HuffmanTree();
    ~HuffmanTree();
};

#endif /* ifndef _HUFFMAN_H */
