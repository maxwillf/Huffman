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

 public:
    IOManager() : bitIndex(0) {}

    void readFile(std::ifstream &input);
    void compact(std::ifstream &input, std::ofstream &output);
    void encodeTree(std::ofstream &output);
};
