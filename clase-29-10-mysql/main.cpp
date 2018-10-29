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
  sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.nombre as nombre_persona,persona.apellido as apellido_persona,organizacion.nombre  as organizacion_nombre FROM computacion.persona INNER JOIN organizacion ON persona.idorganizacion = organizacion.id Where organizacion.nombre = 'Google'");

  cout<<"Content-type: text/html"<<endl<<endl;
  cout<<"<html>"<<endl;
  cout<<"<head>"<<endl;

  cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
  cout<<"</head>"<<endl;

  cout<<"<div class='centrar'>"<<endl;
  cout<<"<h3>Todas las Personas con dni</h1>"<<endl;
  while (personas->next()) {
    cout << personas->getString("dni") << ": " << personas->getString("nombre") << ", " << personas->getString("apellido") << "<br>" << endl;
  }

  cout<<"</div>"<<endl;

  cout<<"<div class='centrar'>"<<endl;
  cout<<"<h3>Personas que trabajan en Google</h1>"<<endl;
  while (personas_organizaciones->next()) {
    cout << personas_organizaciones->getString("nombre_persona") << ": " << personas_organizaciones->getString("apellido_persona") << ", " << personas_organizaciones->getString("organizacion_nombre") << "<br>" << endl;
  }

  cout<<"</div>"<<endl;
  cout<<"</body>"<<endl;
  cout<<"</html>"<<endl;


  return 0;
}
