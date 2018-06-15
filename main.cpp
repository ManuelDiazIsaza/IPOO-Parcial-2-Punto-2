#include <iostream>

/*
  Archivo: main.cpp
  Autor: Manuel Diaz COD: 1741652 - Jeffrey Rios COD: 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creaciÃ³n: 2018-05-11
  Fecha Ãšltima modificaciÃ³n: 2018-05-15
  VersiÃ³n: 0.1
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
    /* Carta carta1(1,"As de Bastos");
     Carta carta2(2,"As de Copas");
     Carta carta3(3,"As de Espadas");
     Carta carta4(4,"As de Oros");
     Carta carta5(5,"Dos de Bastos");
     Carta carta6(6,"Dos de Copas");
     Carta carta7(7,"Dos de Espadas");
     Carta carta8(8,"Dos de Oros");
     Carta carta9(9,"Tres de Bastos");
     Carta carta10(10,"Tres de Copas");
     Carta carta11(11,"Tres de Espadas");
     Carta carta12(12,"Tres de Oros");
     Carta carta13(13,"Cuatro de Bastos");
     */
    juego->crearMazoOrd();
    //juego->imprimirMazoOrd();

    juego->crearMazoDes();
    juego->imprimirMazoDes();

    cout << juego->cantidadMazoDes() << endl;

    return 0;
}