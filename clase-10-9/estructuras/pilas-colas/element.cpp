#include "element.h"

#include <sstream>

using namespace std;

Element::Element()
{
    this->nombre = "";
    this->apellido = "";
}

Element::Element(string nombre, string apellido)
{
    this->nombre = nombre;
    this->apellido = apellido;
}

void Element::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Element::getNombre()
{
    return this->nombre;
}

void Element::setApellido(string apellido)
{
    this->apellido = apellido;
}

string Element::getApellido()
{
    return this->apellido;
}

string Element::toString()
{
    stringstream ss;

    ss << this->apellido << ", " << this->nombre;

    return ss.str();
}
