#include <string>
#include <iostream>
#include "myconnection.h"
#include "organizacion.h"

using namespace std;

Organizacion::Organizacion() {
	nombre = "";
}

Organizacion::Organizacion(string nombre) {
	this->setNombre(nombre);
}

string Organizacion::getNombre() {
	return nombre;
}

void Organizacion::setNombre(string nombre) {
	this->nombre = nombre;
}

void Organizacion::agregar() {
	string stringSQL;
	stringstream values;
	values << this->getNombre();
	stringSQL = "INSERT INTO organizacion (nombre) VALUES ('"+values.str()+"');";
	MyConnection::instance()->execute(stringSQL);
	this->inicio();
}

void Organizacion::inicio() {

	cout << "<html>" << endl;
	cout << "<head>" << endl;
	cout << "<link href='http://localhost/bootstrap.css' rel='stylesheet'>" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
	cout << "<div class='container'>" << endl;
	cout << "<br> <br> <br>" << endl;
	cout << "<div class='centrar'> <h2>Organizaciones</h2> </div>" << endl;
	cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
	cout << "<thead>" << endl;
	cout << "<tr>" << endl;
	cout << "<th> Nombre </th>" << endl;
	cout << "<th> Cant. empleados </th>" << endl;
	cout << "</tr>" << endl;
	cout << "</thead>" << endl;
	cout << "<tbody>" << endl;
	cout << "<tr>" << endl;
	this->listar();
	cout << "</tr>" <<endl;
	cout << "</tbody>" << endl;
	cout << "</table>" << endl;

    cout << "<div class='centrar'> <h3>Agregar Organizacion</h3> </div>" << endl;
	cout << "<form class='form-signin' method='post'>" << endl;
	cout << "<label for='nombre_org' class='sr-only'> Nombre </label>" << endl;
	cout << "<input type='text' id='nombre_org' name='nombre_org' class='form-control' placeholder='Nombre' required autofocus>" << endl;
	cout << "<br>" << endl;
	cout << "<br>" << endl;
	cout << "<button class='btn btn-lg btn-primary btn-block' type='submit'> Enviar </button>" << endl;
	cout << "</form>" << endl;
	cout << "</div>" << endl;
	cout << "</body>" << endl;
	cout << "</html>" << endl;
}

void Organizacion::listar() {
	MyConnection myconnection;
	myconnection.connect();
	sql::ResultSet* personasxorg = myconnection.query("SELECT persona.idorganizacion, count(*) as cont, organizacion.id as id, organizacion.nombre as organizacion FROM persona INNER JOIN organizacion ON persona.idorganizacion = organizacion.id group by idorganizacion ORDER BY organizacion.nombre ASC");

	while (personasxorg->next()) {
		cout << "<tr>" << endl;
		cout << "<td>" << endl;
		cout << personasxorg->getString("organizacion") << endl;
		cout << "</td>" << endl;
		cout << "<td>" << endl;
		cout << personasxorg->getString("cont") << endl;
		cout << "</td>" << endl;
		cout << "<td>" << endl;
		cout << "<a href='parcial2?eliminarorg=" + personasxorg->getString("id") + "'" << endl;
		cout << ">Eliminar</a>"<<endl;
		cout << "</td>" << endl;
		cout << "</tr>" << endl;
	}
}

void Organizacion::eliminar(string id) {
	stringstream stringSQL;
	stringSQL <<"DELETE FROM organizacion WHERE id = "<< id <<";";
	MyConnection::instance()->execute(stringSQL.str());
}
