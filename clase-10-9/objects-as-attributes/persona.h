#ifndef PERSONA_H
#define PERSONA_H

#include "fecha.h"

class Persona
{
    public:
        Persona();
        Persona(string, const char*, Fecha*);
        void setNombre(string);
        string getNombre();
        void setApellido(const char*);
        char* getApellido();
        void setNacimiento(Fecha*);
        Fecha* getNacimiento();
        string toString();

    protected:

    private:
        string nombre;
        char apellido[50];
        Fecha* nacimiento;
};

#endif // PERSONA_H
