/*
  Archivo: Carta.cpp
  Autor: Manuel Diaz COD: 1741652 - Jeffrey Rios COD: 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creación: 2018-06-15
  Fecha Última modificación: 2018-06-15
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Taxi
// Responsabilidad: Manejo de taxi
// Colaboracion: ninguna

#include <stdio.h>
#include <iostream>
#include "Carta.h"
#include <string>
#include <iomanip>

Carta::Carta()
{
    indice = 0;
    pinta = " ";
    sig = nullptr;
    ant = nullptr;
}

Carta::Carta(int indice,string pinta)
{
    this->indice = indice;
    this->pinta = pinta;
}

Carta::~Carta()
{
    //Método destructor
}

void Carta::setIndice(int indice){
    this -> indice = indice;
}
int Carta::getIndice(){
    return indice;
}
void Carta::setPinta(string pinta){
    this -> pinta = pinta;
}
string Carta::getPinta(){
    return pinta;
}

void Carta::setSig(Carta *sig){
    this -> sig = sig;
}

Carta* Carta::getSig(){
    return this -> sig;
}

void Carta::setAnt(Carta *ant){
    this -> ant = ant;
}

Carta* Carta::getAnt(){
    return this -> ant;
}

