/*
  Archivo: Juego.h
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-15
  Fecha ultima modificacion: 2018-06-15
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad:
// Colaboracion: ninguna


#ifndef JUEGO_H
#define JUEGO_H
#include "Carta.h"


using namespace std;


class Juego
{
private:
    Carta *cabMazoOrd; // Transacciones Hechas
    Carta *cabMazoDes; // Clientes en cola
public:
    Juego();
    ~Juego();
    //Mazo Ordenado
    void crearMazoOrd();
    void imprimirMazoOrd();
    int cantidadMazoOrd();
    void borrarMazoOrd(int pos);
    Carta* cartaMazoOrd(int pos);

    //Mazo Desordenado
    void crearMazoDes();
    void imprimirMazoDes();
    int cantidadMazoDes();
    void destaparMazoAut();
    void interfazPPal();

};

#endif