#include <iostream>
#include "persona.h"

using namespace std;

int main(int argc, char* const argv[])
{
//	Persona* Persona1 = new Persona();
	Persona* Persona2 = new Persona("Tomas", "Gaute", new Fecha(30, 6, 1998));
//	Persona* Persona3 = new Persona("Gonzalo", "Tempra", new Fecha(26, 8, 1996));


    cout<< "Persona2 Apellido: " << Persona2->getApellido() << endl;
    cout<< "Persona2 Fecha de Nac.: " << Persona2->getNacimiento()->getDia() << "/" << Persona2->getNacimiento()->getMes() << "/" << Persona2->getNacimiento()->getAnho() << endl;
//    cout<<  "/" + Persona2->getNacimiento()->getAnho() << endl;

	/*Persona1->setApellido("Lopez");
	Persona1->setNombre("Juan");

    cout<< "Persona3: " << Persona1->getApellido() <<endl;*/

/*	  Persona* p[3] = {new Persona("Francisco", "Matile", new Fecha(2, 5, 1996)),
	                     new Persona("Tobias", "Crescitelli", new Fecha(29, 11, 1996)),
	                     new Persona("Juan", "Lopez", new Fecha(30, 6, 1997))};

	    for (int i = 0; i < 3; i++)
	        cout << p[i]->toString() << endl;

*/
    return 0;
}
