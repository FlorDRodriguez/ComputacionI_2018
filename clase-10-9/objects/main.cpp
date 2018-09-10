#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main (int argc, char* const argv[]) {
	Persona persona1;
	Persona persona2;
	Persona persona3;
	Persona persona4;

	persona1.setApellido("Rodriguez");
	persona1.setNombre("Florencia");
	persona1.setEdad(20);

	persona2.setApellido("Ortiz");
	persona2.setNombre("Martín");
	persona2.setEdad(19);

	persona3.setApellido("Balda");
	persona3.setNombre("Daniel");
	persona3.setEdad(23);

	persona4.setApellido("Gonzalez");
	persona4.setNombre("Luis");
	persona4.setEdad(22);

	persona2.getAnhoNacimiento();

	persona3.mostrarDatos();
}
