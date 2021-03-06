
#include "persona.h"
#include <iostream>
#include "myconnection.h"

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
    stringstream stringSQL;

    //sql::ResultSet* personas = myconnection.query("INSERT INTO persona VALUES ('+x','+apellido','+nombre')");
    //mysql_query(personas);
//    personas = "INSERT INTO persona (dni,apellido,nombre) VALUES('" + x + "','" + apellido +"','"+ nombre"')" ;
  //  stringSQL <<"INSERT INTO persona (dni,apellido,nombre) VALUES('" + x + "','" + apellido +"','"+ nombre"')" ;
    stringSQL<< "INSERT INTO persona (dni,apellido,nombre) VALUES ( x, 'apellido', 'nombre')";
    myconnection.query(stringSQL.str());

  }

void Persona::mostrar()
{
    cout << "Los datos de la persona  son:";
    cout << "<br> DNI: "<< this->getDni() << "";
    cout << "<br> Apellido: "<< this->getApellido() << "";
    cout << "<br> Nombre: "<< this->getNombre() << "";
}

void Persona::eliminar(long x){
    MyConnection myconnection;
    myconnection.connect();
    stringstream stringSQL;
    stringSQL <<"DELETE FROM persona WHERE dni = "<< x <<";";
    myconnection.query(stringSQL.str());
}

void Persona::setDni(long  dni)
{
    this->dni = dni;
}

long Persona::getDni()
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
