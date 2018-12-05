#include "IOManager.h"

void IOManager::readFile(std::ifstream& input){

    int * ascii = countFrequencies(input);
    input.close(); 
    std::vector<Node*> orderedNodes;

    for (int i = 0; i < 128; ++i) {
        if (ascii[i] != 0) {
            char character = i;
            Node *node = new Node(ascii[i], character);
            insertOrd(orderedNodes, node, pred);
        }
    }
    HuffmanTree tree(orderedNodes);
    tree.printTree();
    tree.fillMap();

    delete ascii;
}

int* IOManager::countFrequencies(std::ifstream& input)
{
    int *ascii = new int[128];
    char c;

    while(input >> c){
        if(ascii[c] == 0) {
        }

        ascii[c] +=1;
    }
    return ascii;
}
