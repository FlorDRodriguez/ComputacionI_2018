#include "persona.h"
#include <cstring>
#include <sstream>

using namespace std;

Persona::Persona()
{
    this->setNombre("");
    this->setApellido("");
    this->setNacimiento(new Fecha(1, 6, 1980));
}

Persona::Persona(string nombre, const char* apellido, Fecha* nacimiento)
{
    this->setNombre(nombre);
    this->setApellido(apellido);
    this->setNacimiento(nacimiento);
}

void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Persona::getNombre()
{
    return this->nombre;
}

void Persona::setApellido(const char* apellido)
{
    strncpy(this->apellido, apellido, 50);
}

char* Persona::getApellido()
{
    return this->apellido;
}

void Persona::setNacimiento(Fecha* nacimiento)
{
    if (nacimiento != NULL)
        delete this->nacimiento;
    this->nacimiento = nacimiento;
}

Fecha* Persona::getNacimiento()
{
    return this->nacimiento;
}

string Persona::toString()
{
    stringstream ss;

    ss << "Nombre: " << this->getNombre() << " " << this->getApellido() << " - Fecha de Nacimiento: " << this->nacimiento->toString();

    return ss.str();
}
