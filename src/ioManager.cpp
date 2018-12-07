#include "../include/ioManager.h"

int *IOManager::countFrequencies(std::ifstream &input)
{
    int *ascii = new int[128];
    char c = '\0';

    while (input.get(c)) {
        if ((int) c == 10)
            continue;

        ascii[(int) c] +=1;
    }

    for (int i = 0; i < 128; ++i) {
       if (ascii[i] != 0) {
           c = i;
           std::cout << c << " " << ascii[i] << std::endl;
       }
    }

    return ascii;
}

void IOManager::readFile(std::ifstream &input)
{
    int *ascii = countFrequencies(input);
    std::vector<Node*> orderedNodes;

    for (int i = 0; i < 128; ++i) {
        if (ascii[i] != 0) {
            char character = i;
            Node *node = new Node(ascii[i], character);
            insertOrd(orderedNodes, node, pred); }
    }

    insertOrd(orderedNodes, new Node(1, '$'), pred);

    tree = new HuffmanTree(orderedNodes);
    tree->printTree();
    tree->fillMap();

    delete [] ascii;
}

std::string IOManager::charBitsToString(unsigned char c)
{
    unsigned char mask = 1;
    std::string bits = "";

    while(byteIndex != 8){
        if( (c & mask) == mask){
            bits += '1';
        }
        else {
            bits += '0';
        }
        byteIndex++;
        c = c >> 1;
    }

    byteIndex = 0;

    std::reverse(bits.begin(),bits.end());
    return bits;
}

/* TODO: get the string generated by the preOrder() method from the tree,
   compact it like it was done with the text in the compact() method and insert
   it in the beginning of the file, using '$' or some other char as the
   delimiter between where the tree starts and where the text starts */
void IOManager::encodeTree(std::ofstream &output)
{
    std::string treeString = tree->preOrder();
    std::string encodedString = "";
    std::istringstream input(treeString);

    std::cout << tree->preOrder() << std::endl;

    char c = '\0';

    while (input.get(c)) {
        if (c != '0' and c != '1')
            encodedString += charBitsToString(c);
        else
            encodedString += c;
    }

    std::cout << encodedString << std::endl;

    for (size_t i = 0; i < encodedString.size(); ++i) {
        if (encodedString[i] == '1') {
            c = c << 1;
            c += 1;
        }
        else {
            c = c << 1;
        }

        if(i + 1 == encodedString.size()) {
            while (++i % 8 != 0)
                c = c << 1;

            output << c;
        }
        else if ((i != 0 and (i + 1) % 8 == 0) or (i + 1) == encodedString.size()) {
            output << c;
            c = '\0';
        }
    }
    output << (char) 255;
}

void IOManager::compact(std::ifstream &input, std::ofstream &output)
{
    encodeTree(output);

    std::cout << tree->preOrder() << std::endl;

    // reset file stream
    input.clear();
    input.seekg(0, std::ios::beg);

    char c = '\0';
    std::string encodedString = "";

    while (input.get(c))
        encodedString += tree->findLetterPath(c);

    std::cout << encodedString << std::endl;

    c = '\0';
    for (size_t i = 0; i < encodedString.size(); ++i) {
        if (encodedString[i] == '1') {
            c = c << 1;
            c += 1;
        }
        else {
            c = c << 1;
        }

        if ((i != 0 and (i + 1) % 8 == 0) or (i + 1) == encodedString.size()) {
            output << c;
            c = '\0';
        }
    }
}

void IOManager::binaryToString(std::ifstream &input)
{
    unsigned char mask = 0b10000000;
    unsigned char delim = (char) 255;
    while(input.get(byte)){

        if((byte & delim) == delim){
            std::cout << "broke free" << std::endl;
            break;
        }

        for (int i = 0; i < 8; ++i) {

            if( (byte & mask) == 0){
                byte = byte << 1;
                decodingString += '0';
            }

            else {
                byte = byte << 1;
                decodingString += '1';
            }
        }
    }

    std::cout << decodingString << std::endl;
    std::vector<std::string> StringNodes;
    stringToVec(decodingString.begin(),StringNodes);

    for (auto i : StringNodes) {
        std::cout << i << std::endl;
    }
    std::cout << StringNodes.size() << std::endl;

    byteIndex = 0;

    delete tree;
    this->tree = new HuffmanTree(constructTree(StringNodes));

    std::cout << tree->preOrder() << std::endl;
}

Node * IOManager::constructTree(std::vector<std::string> & vec)
{
    if(byteIndex < vec.size()){
        if(vec[byteIndex] == "0"){
            byteIndex++;
            Node * left = constructTree(vec);
            byteIndex++;
            Node * right = constructTree(vec);
            return new Node(0,left,right);
        }

        else return new Node(0,stringToChar(vec[byteIndex]));
    }

    return nullptr;
}

char IOManager::stringToChar(std::string str)
{
    unsigned char byte = 0;

    for (auto i = str.begin(); i < str.end(); ++i) {
        if(*i == '0'){
           byte = byte << 1;
        }
        else {
            byte = byte << 1;
            byte += 1;
        }
    }

    //std::cout << byte << std::endl;
    return byte;
}

void IOManager::stringToVec(std::string::iterator curr_symbol, std::vector<std::string> & vec)
{
    if(curr_symbol != decodingString.end()){
        if(*curr_symbol == '0'){
            vec.push_back("0");
            stringToVec(++curr_symbol,vec);
        }

        else {
            curr_symbol++;
            int beginIndex = std::distance(decodingString.begin(),curr_symbol);
            std::string letter = decodingString.substr(beginIndex,8);
            vec.push_back(letter);
            stringToVec(curr_symbol+8,vec);
        }
    }
}

void IOManager::decodeTree(std::ifstream &input){

    binaryToString(input);
    readCompressed(input);
/*    delete tree;
    tree = new HuffmanTree(decodeTreeR(input));
    std::cout << tree->preOrder();*/
}

void IOManager::readCompressed(std::ifstream & input)
{
    unsigned char mask = 0x80;
    std::string file;
    char temp = '\0';

    while(input.get(byte)){
       // std::cout << byte << std::endl;

        for (int i = 0; i < 8; ++i) {
            if( (byte & mask) == mask){
                //std::cout << "1";

                 temp = tree->searchByBit(mask);
            }

            else {
                //std::cout << "0" ;
                temp = tree->searchByBit(0);
            }

            if (temp != (char) 255) {
                file += temp;
            }
            byte = byte << 1;
        }
    }

    std::cout << file << std::endl;

}

Node* IOManager::decodeTreeR(std::ifstream &input){

    if(byteIndex % 8 == 0){
        input.get(byte);
        //std::cout << "urgh" <<  byte << std::endl;
        if(byte == '\0'){
            //std::cout << "null " <<  byte << std::endl;
            return nullptr;
        }

        byteIndex = 0;
    }

    unsigned char mask = 0b10000000;

    if( (byte & mask) == 0){
        byte = byte << 1;
        byteIndex++;
//        std::cout << "ue" << std::endl;
        return new Node(0,decodeTreeR(input),decodeTreeR(input));
    }

    else {
        nodeChar = 0;

        while(currentNodeIndex < 8){

            if( (byte & mask) == mask){
                nodeChar += 1;
                nodeChar = nodeChar << 1;
                byte = byte << 1;
                byteIndex++;
                currentNodeIndex++;
            }

            else {
                nodeChar = nodeChar << 1;
                byte = byte << 1;
                byteIndex++;
                currentNodeIndex++;
            }

            if(byteIndex % 8 == 0){
                input.get(byte);
                if(byte == '\0'){
                    return nullptr;
                }
                byteIndex = 0;
            }
        }

        currentNodeIndex = 0;
        return new Node(0,nodeChar);
    }
}
