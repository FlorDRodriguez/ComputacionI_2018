#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Persona {
private:
	long  dni;
    string apellido;
    string nombre;
public:
    Persona();
    Persona(long , string, string);

    void setDni(long);
    long getDni();
    void setApellido(string);
    string getApellido();
    void setNombre(string);
    string getNombre();

    void inicio_p();
    void listar_p();
    void alta_p();
    void baja_p(string);

};

#endif // PERSONA_H
