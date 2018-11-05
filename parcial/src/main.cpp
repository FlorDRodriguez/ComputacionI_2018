#include <iostream>
#include <string>
// Formularios html
#include <typeinfo>
#include "getpost.h"
#include "myconnection.h"
#include "persona.h"
#include "organizacion.h"

using namespace std;

int main (int argc, char* const argv[]) {
  Organizacion organizacion;

  map<string, string> Post;
  initializePost(Post);
  map<string, string> Get;
  initializeGet(Get);

  cout << "Content-type: text/html" << endl << endl;

  if (Get.find("eliminar") != Get.end()) {
      organizacion.baja_org(Get["eliminar"]);
  }

  if (Post.find("nombre") == Post.end() ) {
      (new Organizacion())->inicio_org();
  }

  if (Post.find("nombre") != Post.end()) {
        cout << "<html>" << endl;
        cout << "<head>" << endl;
        cout << "<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>" << endl;
        cout << "<link href='http://localhost/css/signin.css' rel='stylesheet'>" << endl;
        cout << "<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>" << endl;
        cout << "</head>" << endl;
        cout << "<body>" << endl;
        cout << "<div class='container'>" << endl;
        cout << "<div class='centrar'>" << endl;
        cout << "<div class='datos'>" << endl;

        organizacion.setNombre(Post["nombre"]);
        organizacion.alta_org();

        cout << "</div>" << endl;
        cout << "</div>" << endl;
        cout << "</div>" << endl;
        cout << "</body>" << endl;
        cout << "</html>" << endl;
  }
  return 0;
}
