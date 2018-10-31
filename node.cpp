#include "node.h"

int Node::getValue() const
{
    return this-> value;
}

Node *Node::getPrev() const
{
    return prev;
}

Node::Node(int value)
{
    this->value = value;
    prev = nullptr;
}

void Node::setPreviousNode(Node * node)
{
    this->prev = node;

}
