#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "node.h"
#include "util.h"
#include "huffman.h"
#include "IOManager.h"
int main(int argc, char *argv[])
{
    std::ifstream input("res/bombom.txt");
    IOManager io;

    io.readFile(input);

    input.close();
    return 0;
}
