#include "huffman.h"

class IOManager {

    //FILE *fp;
    int bitIndex;
    unsigned char bit;
    HuffmanTree *tree;

    /*encode(unsigned char letter){

    }*/

 private:
    int *countFrequencies(std::ifstream &input);
    std::string charBitsToString(unsigned char c);

 public:
    IOManager() : bitIndex(0) {}

    void readFile(std::ifstream &input);
    void decodeTree(std::ifstream &input);
    void compact(std::ifstream &input, std::ofstream &output);
    void encodeTree(std::ofstream &output);
};
