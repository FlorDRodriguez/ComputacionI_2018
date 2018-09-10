#include "fecha.h"

#include <sstream>

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->anho = 1980;
}

Fecha::Fecha(int dia, int mes, int anho)
{
    this->dia = dia;
    this->mes = mes;
    this->anho = anho;
}

void Fecha::setDia(int dia)
{
    this->dia = dia;
}

int Fecha::getDia()
{
    return this->dia;
}

void Fecha::setMes(int mes)
{
    this->mes = mes;
}

int Fecha::getMes()
{
    return this->mes;
}

void Fecha::setAnho(int anho)
{
    this->anho = anho;
}

int Fecha::getAnho()
{
    return this->anho;
}

string Fecha::toString()
{
    stringstream ss;

    ss << this->dia << "/" << this->mes << "/" << this->anho;

    return ss.str();
}
