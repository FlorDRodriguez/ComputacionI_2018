#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

using namespace std;

class Element
{
    public:
        Element();
        Element(string, string);
        void setNombre(string);
        string getNombre();
        void setApellido(string);
        string getApellido();
        string toString();

    protected:

    private:
        string nombre;
        string apellido;
};

#endif // ELEMENT_H
