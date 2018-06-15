/*
  Archivo: Carta.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-15
  Fecha ultima modificacion: 2018-06-15
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad:
// Colaboracion: ninguna


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