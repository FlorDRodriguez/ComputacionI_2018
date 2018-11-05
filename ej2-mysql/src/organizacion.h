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
	int id;
public:
	Organizacion();
	Organizacion(string, int);

	int getId();
	void setId(int id);
	string getNombre();
	void setNombre(string nombre);

	void inicio_org();
	void listar_org();
	void alta_org();
	void modificacion_org();
	void baja_org(int);

};

#endif // ORGANIZACION_H
