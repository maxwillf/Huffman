#include "../include/huffman.h"

HuffmanTree::HuffmanTree() { root = nullptr; }

HuffmanTree::~HuffmanTree() { delete root; }

HuffmanTree::HuffmanTree (std::vector<Node*> & nodes)
{
    while (nodes.size() >= 2) {
        Node *n1 = nodes.back();
        nodes.pop_back();
        Node *n2 = nodes.back();
        nodes.pop_back();
        Node *node = new Node(n1->getFreq() + n2->getFreq(), n1, n2);
        insertOrd(nodes, node,pred );
    }

    root = nodes.front();
}

std::string HuffmanTree::findLetterPath(unsigned char letter)
{
     auto it = pathsDict.find(letter);

     if (it != pathsDict.end()) return it->second;
     else return "";
}

std::map<char, std::string> HuffmanTree::getMap() { return pathsDict; }

void HuffmanTree::fillMap()
{
    fillMap(root);

    for (auto it = pathsDict.begin(); it != pathsDict.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void HuffmanTree::fillMap(Node *node, std::string string)
{
    if (node->getLChild() == nullptr and node->getRChild() == nullptr) {
        pathsDict[node->getLetter()] = string;
    }
    else {
        if (node->getLChild() != nullptr) {
            string += '0';
            fillMap(node->getLChild(), string);
        }

        string.erase(string.end()-1);

        if (node->getRChild() != nullptr) {
            string += '1';
            fillMap(node->getRChild(),string);
        }
    }
}

void HuffmanTree::printTree()
{
    std::string nodesByDepth;
    std::queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node *node = queue.front();
        queue.pop();
        nodesByDepth += std::to_string(node->getFreq()) + " ";

        if(node->getLChild() != nullptr)
            queue.push(node->getLChild());

        if(node->getRChild() != nullptr)
            queue.push(node->getRChild());
    }

    std::cout << nodesByDepth << std::endl;
}
