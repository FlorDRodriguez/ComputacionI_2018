#ifndef ORGANIZACION_H
#define ORGANIZACION_H

#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Organizacion {
private:
	string nombre;
public:
	Organizacion();
	Organizacion(string);

	string getNombre();
	void setNombre(string nombre);

	void agregar();
	void listar();
	void eliminar(string);
	void inicio();

};

#endif // ORGANIZACION_H
