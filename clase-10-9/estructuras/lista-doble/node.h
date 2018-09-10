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
        void setBefore(Node*);
        Node* getBefore();

    protected:

    private:
        Element* element;
        Node* next;
        Node* before;
};

#endif // NODE_H
