/*
  Archivo: Carta.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2018-02-09
  Fecha Cltima modificaciC3n: 2018-02-09
  VersiC3n: 0.1
  Licencia: GPL
*/

// Clase: Nodo
// Responsabilidad: elemento (nodo) de una lista
// ColaboraciCB3n: ninguna


#ifndef CARTA_H
#define CARTA_H
#include <string>


using namespace std;


class Carta
{
protected:
    int indice;
    string pinta;
    Carta *sig;
    Carta *ant;

public:
    Carta();
    Carta(int indice,string pinta);
    ~Carta();
    void setIndice(int indice);
    int getIndice();
    void setPinta(string pinta);
    string getPinta();
    Carta *getSig();
    void setSig(Carta *sig);
    Carta *getAnt();
    void setAnt(Carta *ant);

};

#endif