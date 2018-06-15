/*
  Archivo: main.cpp
  Autor: Manuel Diaz COD: 1741652 - Jeffrey Rios COD: 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-15
  Fecha ultima modificacion: 2018-06-15
  Version: 0.1
  Licencia: GPL
*/

#include <stdio.h>
#include "Juego.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Juego *juego = new Juego();
    juego->interfazPPal();

    return 0;
}