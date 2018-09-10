#ifndef NODE_H
#define NODE_H

#include "element.h"

class Node
{
    public:
        Node();
        void setElement(Element*);
        Element* getElement();
        void setNext(Node*);
        Node* getNext();

    protected:

    private:
        Element* element;
        Node* next;
};

#endif // NODE_H
