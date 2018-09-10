#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
#include <map>


using namespace std;

class Persona
{
    public:
        Persona();
        Persona(long , string, string, int);

        int getAnhoNacimiento();
        void ingresar();
        void mostrar();
        void mostrarDatos();

        void setEdad(int);
        int getEdad();

        void setDni(long );
        long  getDni();
        void setApellido(string);
        string getApellido();
        void setNombre(string);
        string getNombre();

    protected:

    private:
        long  dni;
        string apellido;
        string nombre;
        int edad;
};
#endif // PERSONA_H
