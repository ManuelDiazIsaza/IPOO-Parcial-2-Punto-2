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
    Carta *cabMazoOrd; // cabeza del Mazo ordenado
    Carta *cabMazoDes; // cabeza del Mazo desordenado
public:
    Juego();
    ~Juego();
    //Mazo Ordenado
    void crearMazoOrd(); // Crea un mazo ordenado con las 48 cartas
    void imprimirMazoOrd(); // Imprime el mazo ordenado
    int cantidadMazoOrd(); // cantidad de cartas en el mazo ordenado
    void borrarMazoOrd(int pos); // borrar una carta en una posicion pos
    Carta* cartaMazoOrd(int pos); // devuelve un apuntador a una carta en una posicion pos

    //Mazo Desordenado
    void crearMazoDes(); // crea un mazo desordenado a partir del mazo ordenado
    void imprimirMazoDes(); // imprime el mazo desordenado
    int cantidadMazoDes(); // cantidad de cartas en el mazo desordenado
    void destaparMazoAut(); // destapa una a una las cartas del mazo desordenado cada cierto tiempo
    void destaparMazoMan(); // pide que el usuario escriba algo para seguir destapando el mazo
    void interfazPPal(); // maneja el menu o interfaz del programa

};

#endif