#ifndef Fecha_H
#define Fecha_H

class Fecha {
private:
	int dia;
    int mes;
    int anho;
public:
    Fecha();
    Fecha(int, int, int);

    void setdia(int);
    int getdia();
    void setmes(int);
    int getmes();
    void setanho(int);
    int getanho();

    void ingresar();
    void mostrar();
};

#endif // Fecha_H
