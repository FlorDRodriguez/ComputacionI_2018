#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Persona {
private:
        long  dni;
        string apellido;
        string nombre;
public:
        Persona();
        Persona(long , string, string);

        void setDni(long );
        long getDni();
        void setApellido(string);
        string getApellido();
        void setNombre(string);
        string getNombre();

        void ingresar();
        void mostrar();

        void crear();
        void modificar();
        void eliminar();
};

#endif // PERSONA_H
