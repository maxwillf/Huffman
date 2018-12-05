#ifndef _NODE_H
#define _NODE_H

#include "ascii.h"

#include <queue>
#include <string>
class Node {

    int freq;
    char letter;
    Node *left;
    Node *right;
    public:

    Node (int frequencie, Node *lchild = nullptr, Node *rchild = nullptr) :
        freq(frequencie),left(lchild), right(rchild)
    {}

    Node(const Node &node) : freq(node.getFreq()), letter(getLetter()),
                       left(node.getLChild()), right(node.getRChild())
    {}

    Node(int frequencie, char character,Node *lchild = nullptr, Node *rchild = nullptr)
        : freq(frequencie), letter(character), left(lchild), right(rchild)
    { }

    int getFreq() const{ return freq; } 
    char getLetter() const{ return letter; } 
    Node *getLChild() const{ return left; } 
    Node *getRChild() const{ return right; } 
    void printNode();
};

void Node::printNode(){

    std::string nodesByDepth;
    std::queue<Node*> queue;
    queue.push(this); 
    /*if (root != nullptr) {
        queue.push(*root);
*/
        while (!queue.empty()) {
            Node *node = queue.front();
            queue.pop();
            nodesByDepth += std::to_string(node->getFreq()) + " ";

            if(node->left != nullptr)
                queue.push(node->left);

            if(node->right != nullptr)
                queue.push(node->right);
        }
    
    std::cout << nodesByDepth;
}
using Compare  = bool (const Node &n1, const Node &n2);

//Node operator>(const Node &n1, const Node &n2){
bool pred(const Node &n1, const Node &n2){
    
    return n1.getFreq() > n2.getFreq();
}

template <typename T>
typename std::vector<T>::iterator insertOrd(std::vector<T> & vec, T & item, Compare pred){

    return vec.insert(
         std::lower_bound(vec.begin(),vec.end(),item,pred),
         item 
         );
}

#endif
