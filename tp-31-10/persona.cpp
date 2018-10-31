
#include "persona.h"
#include "myconnection.h"
#include <iostream>

using namespace std;

Persona::Persona()
{
    dni=0;
    apellido="";
    nombre="";

}

Persona::Persona(long dni, string apellido, string nombre)
{
    this->setDni(dni);
    this->setApellido(apellido);
    this->setNombre(nombre);
}

void Persona::ingresar()
{
  string personas;
    long  x;
    string apellido, nombre;
    cout << "Ingrese el dni: ";
    cin >> x;
    this->setDni(x);
    cout << "Ingrese el apellido: ";
    cin >> apellido;
    this->setApellido(apellido);
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    this->setNombre(nombre);

    MyConnection myconnection;
    myconnection.connect();
    //sql::ResultSet* personas = myconnection.query("INSERT INTO persona VALUES ('+x','+apellido','+nombre')");
    //mysql_query(personas);
    personas = "INSERT INTO persona (dni,apellido,nombre) VALUES('" + x + "','" + apellido +"','"+ nombre"')" ;
    mysql_query(personas);
}

void Persona::mostrar()
{
    cout << "Los datos de la persona  son:";
    cout << "<br> DNI: "<< this->getDni() << "";
    cout << "<br> Apellido: "<< this->getApellido() << "";
    cout << "<br> Nombre: "<< this->getNombre() << "";
}

void Persona::eliminar(){

}

void Persona::setDni(long  dni)
{
    this->dni = dni;
}

long  Persona::getDni()
{
    return this->dni;
}

void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

string Persona::getApellido()
{
    return this->apellido;
}

void Persona::setNombre(string  nombre)
{
    this->nombre = nombre;
}

string Persona::getNombre()
{
    return this->nombre;
}
