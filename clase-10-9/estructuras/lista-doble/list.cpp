#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
    lastInsert = NULL;
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
    newNode->setBefore(NULL);

    if (this->lastInsert == NULL) {
        this->lastInsert = newNode;
        return;
    }

    if (element->getValue() < this->lastInsert->getElement()->getValue())
        this->insertNext(newNode);
    else
        this->insertBefore(newNode);
}

void List::insertNext(Node* newNode) {
    while (this->lastInsert->getNext() != NULL && this->lastInsert->getElement()->getValue() > newNode->getElement()->getValue())
        this->lastInsert = this->lastInsert->getNext();

    // Acá se evalua el caso que el while sale porque llegó al borde
    if (this->lastInsert->getNext() == NULL) {
        this->lastInsert->setNext(newNode);
        newNode->setBefore(this->lastInsert);
        this->lastInsert = newNode;
        return;
    }

    // Acá entra cuando tiene que poner el elemento en el medio de otros dos
    newNode->setNext(this->lastInsert);
    newNode->setBefore(this->lastInsert->getBefore());
    this->lastInsert->getBefore()->setNext(newNode);
    this->lastInsert->setBefore(newNode);
    this->lastInsert = newNode;
}

void List::insertBefore(Node* newNode) {
    while (this->lastInsert->getBefore() != NULL && this->lastInsert->getElement()->getValue() < newNode->getElement()->getValue())
        this->lastInsert = this->lastInsert->getBefore();

    // Acá se evalua el caso que el while sale porque llegó al borde
    if (this->lastInsert->getBefore() == NULL) {
        this->lastInsert->setBefore(newNode);
        newNode->setNext(this->lastInsert);
        this->lastInsert = newNode;
        return;
    }

    // Acá entra cuando tiene que poner el elemento en el medio de otros dos
    newNode->setBefore(this->lastInsert);
    newNode->setNext(this->lastInsert->getNext());
    this->lastInsert->getNext()->setBefore(newNode);
    this->lastInsert->setNext(newNode);
    this->lastInsert = newNode;
}

Element* List::remove(int value)
{
	return 0;
}

void List::free()
{
}

void List::show()
{
     this->goInit();

     while (this->lastInsert->getNext() != NULL) {
         cout << this->lastInsert->getElement()->toString() << endl;
         this->lastInsert = this->lastInsert->getNext();
     }
}

void List::goInit() {
     while (this->lastInsert->getBefore() != NULL)
        this->lastInsert = this->lastInsert->getBefore();
}
