#include "persona.h"
#include <iostream>

using namespace std;

Persona::Persona() {
    dni = 0;
    apellido = "";
    nombre = "";
}

Persona::Persona(long dni, string apellido, string nombre) {
    this->setDni(dni);
    this->setApellido(apellido);
    this->setNombre(nombre);
}

void Persona::setDni(long  dni) {
    this->dni = dni;
}

long  Persona::getDni() {
    return this->dni;
}

void Persona::setApellido(string apellido) {
    this->apellido = apellido;
}

string Persona::getApellido() {
    return this->apellido;
}

void Persona::setNombre(string  nombre) {
    this->nombre = nombre;
}

string Persona::getNombre() {
    return this->nombre;
}

void Persona::ingresar() {
    long  dni;
    string apellido, nombre;

    cout << "Ingrese el dni: " << endl;
    cin >> dni;
    this->setDni(dni);
    cout << "Ingrese el apellido: " << endl;
    cin >> apellido;
    this->setApellido(apellido);
    cout << "Ingrese el nombre: " << endl;
    cin >> nombre;
    this->setNombre(nombre);
}

void Persona::mostrar() {
    cout << "Los datos de la persona son: " << endl;
    cout << "<br> DNI: " << this->getDni() << "" << endl;
    cout << "<br> Apellido: " << this->getApellido() << "" << endl;
    cout << "<br> Nombre: " << this->getNombre() << "" << endl;
}

void Persona::crear() {
}

void Persona::modificar() {
}

void Persona::eliminar() {
}
