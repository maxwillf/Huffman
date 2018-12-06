#include "huffman.h"

class IOManager {

    //FILE *fp;
    std::string decodingString;
    int currentNodeIndex;
    unsigned char nodeChar;
    int byteIndex = 0;
    char byte;
    HuffmanTree *tree;

    /*encode(unsigned char letter){

    }*/

 private:
    int *countFrequencies(std::ifstream &input);
    std::string charBitsToString(unsigned char c);
    Node *decodeTreeR(std::ifstream &input);
    void binaryToString(std::ifstream &input);
    void stringToVec(std::string::iterator curr_symbol, std::vector<std::string> & vec);
    Node * constructTree(std::vector<std::string> & vec);
    char stringToChar(std::string str);

 public:
    IOManager() : byteIndex(0) {}

    void readFile(std::ifstream &input);
    void decodeTree(std::ifstream &input);
    void compact(std::ifstream &input, std::ofstream &output);
    void encodeTree(std::ofstream &output);
};
