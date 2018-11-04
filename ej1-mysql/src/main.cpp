#include <iostream>
#include <string>
// Formularios html
#include "getpost.h"
#include <typeinfo>
#include "persona.h"
#include "myconnection.h"

using namespace std;

int main (int argc, char* const argv[]) {
  // Para formularios
  // map<string,string> Post;
  // initializePost(Post);

  MyConnection myconnection;
  myconnection.connect();
  sql::ResultSet* personas = myconnection.query("SELECT persona.nombre, persona.apellido, persona.dni FROM persona");
  sql::ResultSet* organizaciones = myconnection.query("SELECT organizacion.nombre FROM organizacion");
  sql::ResultSet* domicilios = myconnection.query("SELECT domicilio.calle, domicilio.numero FROM domicilio");
  sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.nombre as nombre_persona, persona.apellido as apellido_persona, persona.dni as dni_persona, organizacion.nombre as organizacion_nombre FROM computacion.persona INNER JOIN computacion.organizacion ON persona.idorganizacion = organizacion.id Where organizacion.nombre = 'Google'");
  sql::ResultSet* personas_domicilios = myconnection.query("SELECT persona.nombre as nombre_persona, persona.apellido as apellido_persona, persona.dni as dni_persona, domicilio.calle as domicilio_calle, domicilio.numero as domicilio_numero FROM computacion.persona INNER JOIN computacion.domicilio ON persona.iddomicilio = domicilio.id Where domicilio.calle = 'Aristides'");

  cout << "Content-type: text/html" << endl << endl;
  cout << "<html>" << endl;
  cout << "<head>" << endl;

  cout << "<link href='http://localhost/bootstrap.css' rel='stylesheet'>" << endl;
  cout << "</head>" << endl;

  cout << "<div class='centrar'>" << endl;
  cout << "<h3>Personas</h3>" << endl;
  while (personas->next()) {
	  cout << personas->getString("nombre") << " " << personas->getString("apellido") << "<br>" << endl;
  }
  cout << "</div>" << endl;

  cout << "<div class='centrar'>" << endl;
  cout << "<h3>Organizaciones</h3>" << endl;
  while (organizaciones->next()) {
	  cout << organizaciones->getString("nombre") << "<br>" << endl;
  }
  cout << "</div>" << endl;

  cout << "<div class='centrar'>" << endl;
  cout << "<h3>Domicilios</h3>" << endl;
  while (domicilios->next()) {
      cout << domicilios->getString("calle") << " al " << domicilios->getString("numero") << "<br>" << endl;
  }
  cout << "</div>" << endl;

  cout << "<div class='centrar'>" << endl;
  cout << "<h3>Personas que trabajan en Google</h3>" << endl;
  while (personas_organizaciones->next()) {
      cout << personas_organizaciones->getString("nombre_persona") << ", " << personas_organizaciones->getString("apellido_persona") << ": " << personas_organizaciones->getString("dni_persona") << "<br>" << endl;
  }
  cout << "</div>" << endl;

  cout << "<div class='centrar'>" << endl;
  cout << "<h3>Personas que viven en Aristides</h3>" << endl;
  while (personas_domicilios->next()) {
      cout << personas_domicilios->getString("nombre_persona") << ", " << personas_domicilios->getString("apellido_persona") << ": " << personas_domicilios->getString("dni_persona") << "<br>" << endl;
  }
  cout << "</div>" << endl;
  cout << "</body>" << endl;
  cout << "</html>" << endl;
  return 0;
}
