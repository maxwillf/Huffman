#include "huffman.h"

HuffmanTree::HuffmanTree (std::vector<Node*> & nodes) {

    while(nodes.size() >= 2){
        Node *n1 = nodes.back();
        nodes.pop_back();
        Node *n2 = nodes.back();
        nodes.pop_back();
        Node *node = new Node(n1->getFreq() + n2->getFreq(), n1, n2);
        insertOrd(nodes, node,pred );
    }

    root = nodes.front();
    printTree();
}

void HuffmanTree::printTree(){

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

    std::cout << nodesByDepth;
}
