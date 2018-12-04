#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "node.h"
#include "ascii.h"

int main(int argc, char *argv[])
{
    std::ifstream input("bombom.txt");
    
 //   auto pair = countFrequencies(input);
//    int * ascii = pair.get(0);
  //  int size = pair.get(1);
    int * ascii = countFrequencies(input);
   
    std::vector<Node> orderedNodes;

    for (int i = 0; i < 128; ++i) {
        if(ascii[i] != 0){
            char character = i;
            Node node(ascii[i], character);
            insertOrd(orderedNodes, node, pred);
    //       newSize++;
    //        std::cout << c << " " <<  ascii[i] << std::endl; 
        }
    }
    for (auto i : orderedNodes) {
        std::cout << i.getFreq() << " " << i.getLetter() << std::endl; 
    }
    


    input.close(); 
    return 0;
}
