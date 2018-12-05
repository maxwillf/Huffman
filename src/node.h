#ifndef NODE_H
#define NODE_H

#include "ascii.h"

class Node
{
    int freq;
    char letter;
    Node *left;
    Node *right;

 public:
    Node (int frequencie, Node *lchild = nullptr, Node *rchild = nullptr)
          : freq(frequencie), left(lchild), right(rchild) {}

    Node (int frequencie, char character, Node *lchild = nullptr, Node *rchild = nullptr)
         : freq(frequencie), letter(character), left(lchild), right(rchild) {}

    int getFreq() const { return freq; }
    int getLetter() const { return letter; }
};

using Compare = bool (const Node &n1, const Node &n2);

bool pred(const Node &n1, const Node &n2)
{
    if( n1.getFreq() == n2.getFreq()){
        return n1.getLetter() > n2.getLetter();
    }
    else {
        return n1.getFreq() > n2.getFreq();
    }
}

template <typename T>
typename std::vector<T>::iterator insertOrd(std::vector<T> &vec, T &item, Compare pred)
{
    return vec.insert(std::upper_bound(vec.begin(), vec.end(), item, pred),
                      item);
}

#endif
