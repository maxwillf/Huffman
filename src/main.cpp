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
    std::ifstream input("res/input.txt");
    std::ofstream output("res/output.txt");

    std::ifstream decompress("res/output.txt");
    std::ofstream unpacked("res/unpacked.txt");
    IOManager io;

    io.readFile(input);
    io.compact(input, output);
    input.close();
    output.close();

    io.decodeTree(decompress, unpacked);
    decompress.close();
    unpacked.close();

    return 0;
}
