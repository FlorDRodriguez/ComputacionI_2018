#ifndef LIST_H
#define LIST_H

#include "node.h"

class List
{
    public:
        List();
        void setStart(Node*);
        Node* getStart();
        void setLastInsert(Node*);
        Node* getLastInsert();
        void insert(Element*);
        Element* remove(int);
        void free();
        void show();

    protected:

    private:
        Node* start;
        Node* lastInsert;
};

#endif // LIST_H
