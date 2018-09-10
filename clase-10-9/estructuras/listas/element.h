#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

using namespace std;

class Element
{
    public:
        Element();
        Element(int);
        void setValue(int);
        int getValue();
        string toString();

    protected:

    private:
        int value;
};

#endif // ELEMENT_H
