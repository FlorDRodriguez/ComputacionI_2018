#ifndef FECHA_H
#define FECHA_H

#include <string>

using namespace std;

class Fecha
{
    public:
        Fecha();
        Fecha(int, int, int);
        void setDia(int);
        int getDia();
        void setMes(int);
        int getMes();
        void setAnho(int);
        int getAnho();
        string toString();

    protected:

    private:
        int dia;
        int mes;
        int anho;
};

#endif // FECHA_H
