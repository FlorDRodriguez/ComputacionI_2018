#include <iostream>
#include <string>
#include <map>
#include "getpost.h"
#include "persona.h"
#include "fecha.h"
#include <typeinfo>

using namespace std;

int main (int argc, char* const argv[]) {

    Persona persona;
    Fecha fNacimiento;

	map<string,string> Post;
	initializePost(Post);



    if (Post.find("nombre")==Post.end() )
    {
        cout<<"Content-type: text/html"<<endl<<endl;
        cout<<"<html><head>"<<endl;
        cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
        cout << "</head>" <<endl;
        cout << "<body>   <div class='container'>"<<endl;
        cout<<"<div class='centrar'><h1>Complete los datos</h1></div>"<<endl;
        cout<<"<form class='form-signin' method='post'>"<<endl;
        cout<<"<label for='nombre' class='sr-only'>Nombre</label>"<<endl;
        cout<<"<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>"<<endl;
        cout<<"<label for='apellido' class='sr-only'>Apellido</label>"<<endl;
        cout<<"<input type='text' id='apellido' name='apellido' class='form-control' placeholder='Apellido' required>"<<endl;
        cout<<"<label for='dni' class='sr-only'>Dni</label>"<<endl;
        cout<<"<input type='text' id='dni' name='dni' class='form-control' placeholder='Dni' required>"<<endl;
        cout<<"<br>"<<endl;

        cout<<"<h3>Fecha de Nacimiento</h3><br>"<<endl;
        cout<<"<div class='row'>" <<endl;
        cout<<"<div class='col-md-4'><input type='text' id='dia' name='dia' class='form-control' placeholder='Dia' required>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"<div class='col-md-4'><input type='text' id='mes' name='mes' class='form-control' placeholder='Mes' required>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"<div class='col-md-4'><input type='text' id='anio' name='anio' class='form-control' placeholder='A&ntilde;o' required>"<<endl;
        cout<<"</div>"<<endl;
        cout<<"</div>"<<endl;

        cout<<"<br>"<<endl;
        cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Enviar</button>"<<endl;
        cout<<"</form>"<<endl;
        cout<<"</div></body></html>"<<endl;

    }

	if (Post.find("nombre")!=Post.end() && Post.find("apellido")!=Post.end()) {
        cout<<"Content-type: text/html"<<endl<<endl;
        cout<<"<html><head>"<<endl;
        cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
        cout << "</head>" <<endl;
        cout << "<body>   <div class='container'>"<<endl;
        cout<<"<div class='centrar'><div class='datos'>"<<endl;

		//cout<<"<p class='centrar pad-top'><h1> Hola "<<Post["nombre"]<<" "<<Post["apellido"]<<"</h1></p>"<<endl;
        persona.setNombre(Post["nombre"]);
        persona.setApellido(Post["apellido"]);
        persona.setDni(atol(Post["dni"].c_str()));
        persona.mostrar();

        fNacimiento.setdia(atoi(Post["dia"].c_str()));
        fNacimiento.setmes(atoi(Post["mes"].c_str()));
        fNacimiento.setanho(atoi(Post["anio"].c_str()));

        fNacimiento.mostrar();

        cout<<"</div></div></div></body></html>"<<endl;
	}

	return 0;
}

