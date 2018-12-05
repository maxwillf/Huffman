#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "node.h"
#include "ascii.h"
#include "huffman.h"
//Node constructTree(std::vector<Node> & nodes);

int main(int argc, char *argv[])
{
    std::ifstream input("res/bombom.txt");

    int * ascii = countFrequencies(input);
    input.close(); 
    std::vector<Node*> orderedNodes;

    for (int i = 0; i < 128; ++i) {
        if (ascii[i] != 0) {
            char character = i;
            Node *node = new Node(ascii[i], character);
            insertOrd(orderedNodes, node, pred);
    //       newSize++;
    //        std::cout << c << " " <<  ascii[i] << std::endl;
        }
    }

    delete ascii;

    for (auto i : orderedNodes) {
        std::cout << i->getFreq() << " " << i->getLetter() << std::endl;
    }

    HuffmanTree tree(orderedNodes);
    tree.printTree();


    input.close();
    return 0;
}

/*Node constructTree(std::vector<Node> & nodes) {

    while(nodes.size() >= 2){
        Node *n1 = new Node(nodes.back());
        nodes.pop_back();
        Node *n2 = new Node(nodes.back());
        nodes.pop_back();
        Node node(n1->getFreq() + n2->getFreq(), n1, n2);
        insertOrd(nodes, node,pred );
    }

    nodes.front().printNode();
}*/
