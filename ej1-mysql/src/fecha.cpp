#include "fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    anho = 0;
}

Fecha::Fecha(int dia, int mes, int anho) {
    this->setdia(dia);
    this->setmes(mes);
    this->setanho(anho);
}

void Fecha::setdia(int dia) {
    this->dia = dia;
}

int Fecha::getdia() {
    return this->dia;
}

void Fecha::setmes(int mes) {
    this->mes = mes;
}

int Fecha::getmes() {
    return this->mes;
}

void Fecha::setanho(int  anho) {
    this->anho = anho;
}

int Fecha::getanho() {
    return this->anho;
}

void Fecha::ingresar() {
    int d, m, a;
    cout << "Ingrese el dia: " << endl;
    cin >> d;
    this->setdia(d);
    cout << "Ingrese el mes: " << endl;
    cin >> m;
    this->setmes(m);
    cout << "Ingrese el anho: " << endl;
    cin >> a;
    this->setanho(a);
}

void Fecha::mostrar() {
    cout << "<BR>";
    cout << "Fecha de Nacimiento: " << this->getdia() << "/" << this->getmes() << "/" << this->getanho() << "" << endl;
}
