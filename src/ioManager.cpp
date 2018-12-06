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
            insertOrd(orderedNodes, node, pred);
        }
    }

    insertOrd(orderedNodes, new Node(1, '$'), pred);

    tree = new HuffmanTree(orderedNodes);
    tree->printTree();
    tree->fillMap();

    delete ascii;
}

void IOManager::encodeTree(std::ofstream &output)
{

}

void IOManager::compact(std::ifstream &input, std::ofstream &output)
{
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
