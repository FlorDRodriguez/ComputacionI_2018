#include <iostream>
#include <string>
// Formularios html
#include "getpost.h"
#include <typeinfo>
#include "persona.h"
#include "myconnection.h"

using namespace std;

int main (int argc, char* const argv[]) {
  Persona persona;
  map<string,string> Post;
  initializePost(Post);
  map<string,string> Get;
  initializeGet(Get);

  cout<<"Content-type: text/html"<<endl<<endl;

  if (Get.find("eliminar")!=Get.end()){
      persona.eliminar(Get["eliminar"]);
  }

  if (Post.find("nombre")==Post.end() )
  {
      (new Persona())->inicio();
  }

  if (Post.find("nombre")!=Post.end() && Post.find("apellido")!=Post.end()) {
        cout<<"<html><head>"<<endl;
        cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
        cout << "</head>" <<endl;
        cout << "<body>   <div class='container'>"<<endl;
        cout<<"<div class='centrar'><div class='datos'>"<<endl;

        persona.setNombre(Post["nombre"]);
        persona.setApellido(Post["apellido"]);
        persona.setDni(atol(Post["dni"].c_str()));
        persona.agregar();
        cout<<"</div></div></div></body></html>"<<endl;
  }

  return 0;
}
