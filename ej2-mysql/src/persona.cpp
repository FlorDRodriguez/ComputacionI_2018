#include "persona.h"
#include <iostream>
#include "myconnection.h"

using namespace std;

Persona::Persona() {
    dni = 0;
    apellido = "";
    nombre = "";
}

Persona::Persona(long dni, string apellido, string nombre) {
    this->setDni(dni);
    this->setApellido(apellido);
    this->setNombre(nombre);
}

void Persona::setDni(long dni) {
    this->dni = dni;
}

long Persona::getDni() {
    return this->dni;
}

void Persona::setApellido(string apellido) {
    this->apellido = apellido;
}

string Persona::getApellido() {
    return this->apellido;
}

void Persona::setNombre(string  nombre) {
    this->nombre = nombre;
}

string Persona::getNombre() {
    return this->nombre;
}

void Persona::inicio_p() {
	cout << "<html>" << endl;
    cout << "<head>" << endl;
    cout << "<link href='http://localhost/bootstrap.css' rel='stylesheet'>" << endl;
    cout << "</head>" << endl;
    cout << "<body>" << endl;
    cout << "<div class='container'>" << endl;

    cout << "<div class='centrar'> <h2>Personas Cargadas</h2> </div>" << endl;
    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
    cout << "<thead>" << endl;
    cout << "<tr>" << endl;
    cout << "<th> DNI </th>" << endl;
    cout << "<th> Apellido </th>" << endl;
    cout << "<th> Nombre </th>" << endl;
    cout << "<th> Organizaci&oacute;n </th>" << endl;
    cout << "</tr>";
    cout << "</thead>" << endl;
    cout << "<tbody>" << endl;
    cout << "<tr>" << endl;
    this->listar_p();
    cout << "</tr>" << endl;
    cout << "</tbody>" << endl;
    cout << "</table>" << endl;

    cout << "<div class='centrar'> <h2>Agregar Persona</h2> </div>" << endl;
    cout << "<form class='form-signin' method='post'>" << endl;
    cout << "<label for='nombre' class='sr-only'> Nombre </label>" << endl;
    cout << "<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>" << endl;
    cout << "<label for='apellido' class='sr-only'> Apellido </label>" << endl;
    cout << "<input type='text' id='apellido' name='apellido' class='form-control' placeholder='Apellido' required>" << endl;
    cout << "<label for='dni' class='sr-only'> Dni </label>" << endl;
    cout << "<input type='text' id='dni' name='dni' class='form-control' placeholder='Dni' required>" << endl;
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    cout << "<button class='btn btn-lg btn-primary btn-block' type='submit'> Enviar </button>" << endl;
    cout << "</form>" << endl;
    cout << "</div>" << endl;

    cout << "<div class='centrar'> <h2>Modificar Persona</h2> </div>" << endl;
    cout << "<form class='form-signin' method='post'>" << endl;
    cout << "<label for='nombre' class='sr-only'> Nombre </label>" << endl;
    cout << "<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>" << endl;
    cout << "<label for='apellido' class='sr-only'> Apellido </label>" << endl;
    cout << "<input type='text' id='apellido' name='apellido' class='form-control' placeholder='Apellido' required>" << endl;
    cout << "<label for='dni' class='sr-only'> Dni </label>" << endl;
    cout << "<input type='text' id='dni' name='dni' class='form-control' placeholder='Dni' required>" << endl;
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    cout << "<button class='btn btn-lg btn-primary btn-block' type='submit'> Enviar </button>" << endl;
    cout << "</form>" << endl;
    cout << "</div>" << endl;

    cout << "</body>" << endl;
    cout << "</html>" << endl;
}

void Persona::listar_p() {
    MyConnection myconnection;
    myconnection.connect();
    sql::ResultSet* personas = myconnection.query("SELECT persona.nombre, persona.apellido, persona.dni FROM persona");
    //sql::ResultSet* organizaciones = myconnection.query("SELECT organizacion.nombre FROM organizacion");

    while (personas->next()) {
        cout << "<td>" << personas->getString("dni") << "</td>" << endl;
        cout << "<td>" << personas->getString("nombre") << "</td>" << endl;
        cout << "<td>" << personas->getString("apellido") << "</td>" << endl;
        cout << "<td>" << "..." << "<td>" << endl;
        cout << "<a href='ej2?eliminar=" + personas->getString("dni") + "'" << endl;
        cout << ">Eliminar</a>" << endl;
        cout << "<a href='ej2?modificar=" + personas->getString("dni") + "'" << endl;
        cout << ">Modificar</a></td></tr><tr>" << endl;
    }
}

void Persona::alta_p() {
    string stringSQL;
    stringstream values;
    values << this->getDni() << "','" << this->getNombre() << "','" << this->getApellido() << "','" << '1';
    stringSQL = "INSERT INTO persona (dni, nombre, apellido, idorganizacion) VALUES ('"+values.str()+"');";
    MyConnection::instance()->execute(stringSQL);
    this->inicio_p();
}

void Persona::modificacion_p(string dni) {
	stringstream stringSQL;
	stringSQL << "UPDATE FROM persona WHERE dni = " << dni << ";";
	MyConnection::instance()->execute(stringSQL.str());
}

void Persona::baja_p(string dni) {
    stringstream stringSQL;
    stringSQL << "DELETE FROM persona WHERE dni = " << dni << ";";
    MyConnection::instance()->execute(stringSQL.str());
}
