#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main (int argc, char* const argv[]) {
	Persona persona1;
	Persona persona2;
	Persona persona3;

	persona1.setApellido("Pangaro");
	persona1.setNombre("Karina");
	persona1.setEdad(31);

	persona2.setApellido("Andreuccetti");
	persona2.setNombre("Maxi");
	persona2.setEdad(19);

	persona3.setApellido("Mosqueira");
	persona3.setNombre("Martin");
	persona3.setEdad(22);

	persona3.mostrarDatos();
	persona3.getAnhoNacimiento();
}
