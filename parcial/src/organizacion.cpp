#include <string>
#include <iostream>
#include "myconnection.h"
#include "organizacion.h"

using namespace std;

Organizacion::Organizacion() {
	nombre = "";
	id = 0;
}

Organizacion::Organizacion(string nombre, int id) {
	this->setNombre(nombre);
	this->setId(id);
}

int Organizacion::getId() {
	return id;
}

void Organizacion::setId(int id) {
	this->id = id;
}

string Organizacion::getNombre() {
	return nombre;
}

void Organizacion::setNombre(string nombre) {
	this->nombre = nombre;
}

void Organizacion::inicio_org() {
	cout << "<html>" << endl;
	cout << "<head>" << endl;
	cout << "<link href='http://localhost/bootstrap.css' rel='stylesheet'>" << endl;
	cout << "</head>" << endl;
	cout << "<body>" << endl;
	cout << "<div class='container'>" << endl;

	cout << "<div class='centrar'> <h2>Organizaciones Cargadas</h2> </div>" << endl;
	cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
	cout << "<thead>" << endl;
	cout << "<tr>" << endl;
	cout << "<th> Nombre </th>" << endl;
	cout << "<th> Cantidad empleados </th>" << endl;
	cout << "</tr>";
	cout << "</thead>" << endl;
	cout << "<tbody>" << endl;
	cout << "<tr>" << endl;
	this->listar_org();
	cout << "</tr>" << endl;
	cout << "<tr>" << endl;
	this->contar();
	cout << "</tr>" << endl;
	cout << "</tbody>" << endl;
	cout << "</table>" << endl;

	cout << "<div class='centrar'> <h2>Agregar Organizacion</h2> </div>" << endl;
	cout << "<form class='form-signin' method='post'>" << endl;
	cout << "<label for='nombre' class='sr-only'> Nombre </label>" << endl;
	cout << "<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>" << endl;
	cout << "<br>" << endl;
	cout << "<br>" << endl;
	cout << "<button class='btn btn-lg btn-primary btn-block' type='submit'> Enviar </button>" << endl;
	cout << "</form>" << endl;
	cout << "</div>" << endl;

	cout << "</body>" << endl;
	cout << "</html>" << endl;
}

void Organizacion::listar_org() {
	MyConnection myconnection;
	myconnection.connect();
	sql::ResultSet* organizaciones = myconnection.query("SELECT organizacion.nombre FROM organizacion");

	while (organizaciones->next()) {
		cout << "<td>" << organizaciones->getString("nombre") << "</td>" << endl;
	}

}

void Organizacion::alta_org() {
	 string stringSQL;
	 stringstream values;
	 values << this->getNombre();
	 stringSQL = "INSERT INTO organizacion (nombre) VALUES ('"+values.str()+"');";
	 MyConnection::instance()->execute(stringSQL);
	 this->inicio_org();
}

void Organizacion::baja_org(string id) {
	stringstream stringSQL;
	stringSQL << "DELETE FROM organizacion WHERE id = " << id << ";";
	MyConnection::instance()->execute(stringSQL.str());
}

void Organizacion::contar() {
	MyConnection myconnection;
	myconnection.connect();
	sql::ResultSet* personas_organizaciones = myconnection.query("SELECT COUNT(*) FROM computacion.persona INNER JOIN computacion.organizacion ON persona.idorganizacion = organizacion.id");

	while (personas_organizaciones->next()) {
		cout << "<td>" << personas_organizaciones->getString("COUNT(persona.nombre)") << "</td>" << endl;
		cout << "<a href='parcial2?eliminar=" + personas_organizaciones->getString("nombre") + "'" << endl;
		cout << ">Eliminar</a></tr><tr>" << endl;
	}

}
