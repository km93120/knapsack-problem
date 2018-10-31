#ifndef NODE_H
#define NODE_H


class Node
{
    int   value;
    Node * prev;

public:

    Node(int value);
    void setPreviousNode(Node * node);


    int    getValue() const;
    Node * getPrev() const;
};

#endif // NODE_H
