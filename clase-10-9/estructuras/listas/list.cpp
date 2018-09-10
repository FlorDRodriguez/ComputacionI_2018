#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
    start = lastInsert = NULL;
}

void List::setStart(Node* start)
{
    this->start = start;
}

Node* List::getStart()
{
    return this->start;
}

void List::setLastInsert(Node* lastInsert)
{
    this->lastInsert = lastInsert;
}

Node* List::getLastInsert()
{
    return this->lastInsert;
}

void List::insert(Element* element)
{
    Node* newNode = new Node();

    newNode->setElement(element);
    newNode->setNext(NULL);

    if (this->start == NULL) {
        start = lastInsert = newNode;
        return;
    }

    if (this->start->getElement()->getValue() < element->getValue()) {
        newNode->setNext(start);
        start = lastInsert = newNode;
        return;
    }

    if (lastInsert->getElement()->getValue() < element->getValue())
        lastInsert = start;

    while (lastInsert->getNext() != NULL && lastInsert->getNext()->getElement()->getValue() > element->getValue())
        lastInsert = lastInsert->getNext();

    newNode->setNext(lastInsert->getNext());
    lastInsert->setNext(newNode);
    lastInsert = newNode;
}

Element* List::remove(int value)
{
    if (this->start == NULL)
        return NULL;

    if (this->lastInsert->getElement()->getValue() < value)
        this->lastInsert = this->start;

    Node* xx = this->lastInsert;
    while (this->lastInsert->getElement()->getValue() != value) {
        xx = this->lastInsert;
        this->lastInsert = this->lastInsert->getNext();
        if (this->lastInsert == NULL) {
            this->lastInsert = this->start;
            return NULL;
        }
    }

    Element* vl = this->lastInsert->getElement();
    xx->setNext(this->lastInsert->getNext());
    delete this->lastInsert;
    this->lastInsert = this->start;
    return vl;
}

void List::free()
{
    if (this->start == NULL)
        return;
    while (this->start != NULL) {
        this->lastInsert = this->start;
        this->start = this->start->getNext();
        delete this->lastInsert;
    }
}

void List::show()
{
    if (this->start == NULL)
        return;

    Node* aux = this->start;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
