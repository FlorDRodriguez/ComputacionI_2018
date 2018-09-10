#include "node.h"

Node::Node()
{
    this->element = NULL;
    this->next = NULL;
}

void Node::setElement(Element* element)
{
    this->element = element;
}

Element* Node::getElement()
{
    return this->element;
}

void Node::setNext(Node* next)
{
    this->next = next;
}

Node* Node::getNext()
{
    return this->next;
}
