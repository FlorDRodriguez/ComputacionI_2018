#ifndef LIST_H
#define LIST_H

#include "node.h"

class List
{
    public:
        List();
        void setLastInsert(Node*);
        Node* getLastInsert();
        void insert(Element*);
        Element* remove(int);
        void free();
        void show();

    protected:

    private:
        void insertNext(Node*);
        void insertBefore(Node*);
        void goInit();

        Node* lastInsert;
};

#endif // LIST_H
