class Node {

    int freq;

    public:

    Node (int frequencie) : freq(frequencie)
    {}

};

class LeafNode : public Node{

    char letter;
   
    LeafNode(int frequencie, char letter) : Node(frequencie)
    {
        this->letter = letter;
    }
};


