#include "organizacion.h"
#include <iostream>
#include "myconnection.h"

using namespace std;
Organizacion::Organizacion()
{
    nombre="";

}

Organizacion::Organizacion(string nombre)
{
    this->setNombre(nombre);
}

void Organizacion::agregar()
{

}

void Organizacion::inicio(){

}

void Organizacion::listar()
{

}

void Organizacion::eliminar(int x){

}

void Organizacion::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Organizacion::getNombre()
{
    return this->nombre;
}
