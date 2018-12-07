#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "../include/node.h"
#include "../include/util.h"
#include "../include/huffman.h"
#include "../include/ioManager.h"

int main(int argc, char *argv[])
{
    std::ifstream input("res/bombom.txt");
    std::ofstream output("res/bombom_compact.txt");
    
//    std::ofstream outputTree("res/tree_compact.txt");
    std::ifstream decompressTree("res/tree_compact.txt");
    IOManager io;

    io.readFile(input);
    io.compact(input, output);
    input.close();
 //   io.encodeTree(outputTree);
//    io.decodeTree(decompressTree);

    return 0;
}
