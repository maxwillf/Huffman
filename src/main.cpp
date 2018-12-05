#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "node.h"
#include "ascii.h"

Node constructTree(std::vector<Node> & nodes);

int main(int argc, char *argv[])
{
    std::ifstream input("bombom.txt");
    
 //   auto pair = countFrequencies(input);
//    int * ascii = pair.get(0);
  //  int size = pair.get(1);
    int * ascii = countFrequencies(input);
    input.close(); 
   
    std::vector<Node> orderedNodes;

    for (int i = 0; i < 128; ++i) {
        if(ascii[i] != 0){
            char character = i;
            Node node(ascii[i], character);
            insertOrd(orderedNodes, node, pred);
        }
    }

    for (auto i : orderedNodes) {
        std::cout << i.getFreq() << " " << i.getLetter() << std::endl; 
    }

    constructTree(orderedNodes);

    return 0;
}

Node constructTree(std::vector<Node> & nodes) {

    while(nodes.size() >= 2){
        Node *n1 = new Node(nodes.back());
        nodes.pop_back();
        Node *n2 = new Node(nodes.back());
        nodes.pop_back();
        Node node(n1->getFreq() + n2->getFreq(), n1, n2);
        insertOrd(nodes, node,pred );
    }

    nodes.front().printNode();
}
