/*
  Archivo: Juego.cpp
  Autor: Manuel Diaz COD 1741652 - Jeffrey Rios COD 1744831
  Email: manuel.isaza@correounivalle.edu.co - jeffrey.rios@correounivalle.edu.co
  Fecha creacion: 2018-06-15
  Fecha ultima modificacion: 2018-06-15
  Version: 0.1
  Licencia: GPL
*/

// Responsabilidad:
// Colaboracion: ninguna

#include "Juego.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

Juego::Juego()
{
    cabMazoOrd = nullptr;
    cabMazoDes = nullptr;
    crearMazoOrd();
    crearMazoDes();
}

Juego::~Juego()
{
    Carta *desplaza = cabMazoOrd;
    Carta *borrar;
    while (desplaza != nullptr)
    {
        borrar = desplaza;
        desplaza = desplaza->getSig();
        delete borrar;
        borrar = nullptr;
    }

    Carta *desplaza2 = cabMazoDes;
    Carta *borrar2;
    while (desplaza2 != nullptr)
    {
        borrar2 = desplaza2;
        desplaza2 = desplaza2->getSig();
        delete borrar2;
        borrar = nullptr;
    }
}

void Juego::interfazPPal()
{
    int opcion = 0;

    do
    {
        cout << ":::::::::::::::: MENU PRINCIPAL ::::::::::::::::" << endl;
        cout << "--------------- Juego de Cartas --------------" << endl;
        cout << "1: Destapar Cartas Automaticamente." << endl;
        cout << "2: Destapar Cartas Manualmente." << endl;
        cout << "3: Mostrar Mazo." << endl;
        cout << "4: Juego Nuevo (Barajar)." << endl;
        cout << "5: Salir." << endl;

        cout << "Su opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                destaparMazoAut();
                break;
            case 2:
                destaparMazoMan();
                break;
            case 3:
                imprimirMazoDes();
                break;
            case 4:
            {
                Juego *juego = new Juego();
                juego->interfazPPal();
                break;
            }
            default:
                if (opcion != 5)
                    cout << endl << "=== Opcion no valida ===" << endl;
        }

    } while (opcion != 5);
}

//Metodos Mazo Ordenado

void Juego::crearMazoOrd()
{
    for(int i=1;i<5;i++)
    {

        string pinta;

        if(i==1)
        {
            pinta="Bastos";
        }
        else if(i==2)
        {
            pinta="Copas";
        }
        else if(i==3)
        {
            pinta="Espadas";
        }
        else
        {
            pinta="Oros";
        }


        for(int j=1;j<13;j++)
        {

            Carta *nuevo = new Carta();
            nuevo->setPinta(pinta);
            Carta *desplaza = cabMazoOrd;
            nuevo->setIndice(j);

            {
                if(cabMazoOrd==nullptr)
                {
                    cabMazoOrd = nuevo;
                }
                else
                {
                    while(desplaza!= nullptr)
                    {
                        if(desplaza->getSig()== nullptr)
                        {
                            desplaza->setSig(nuevo);
                            nuevo->setAnt(desplaza);
                            desplaza= nullptr;
                        }
                        else
                        {
                            desplaza=desplaza->getSig();
                        }
                    }
                }
            }
        }
    }
}

void Juego::imprimirMazoOrd(){
    Carta *desplaza = cabMazoOrd;
    cout << "================== MAZO DE CARTAS ==================" << endl;
    cout << setw(25) << "Nombre" << endl;
    cout << "==================================================== " << endl;
    if (cabMazoOrd == nullptr) {
        cout << endl << "El mazo de cartas esta vacio" << endl << endl;
    } else {
        while (desplaza != nullptr)
        {
            cout << setw(25);
            if(desplaza->getIndice() == 1)
            {
                cout << "As de ";
            }
            else if(desplaza->getIndice() == 10)
            {
                cout << "Sota de ";
            }
            else if(desplaza->getIndice() == 11)
            {
                cout << "Caballo de ";
            }
            else if(desplaza->getIndice() == 12)
            {
                cout << "Rey de ";
            }
            else
            {
                cout << desplaza->getIndice() << " de ";
            }
            cout << desplaza->getPinta() << endl;

            desplaza = desplaza->getSig();
        }
    }
}

int Juego::cantidadMazoOrd(){
    Carta *desplaza = cabMazoOrd;
    int cant = 0;
    while (desplaza != nullptr)
    {
        cant++;
        desplaza = desplaza->getSig();
    }
    return cant;
}

void Juego::borrarMazoOrd(int pos)
{
    if (pos <= cantidadMazoOrd())
    {
        Carta *borrar;
        if (pos == 1)
        {
            borrar = cabMazoOrd;
            cabMazoOrd = cabMazoOrd->getSig();
            if (cabMazoOrd != nullptr)
                cabMazoOrd->setAnt(nullptr);
        }
        else
        {
            Carta *desplaza;
            desplaza = cabMazoOrd;
            for (int f = 1; f <= pos - 2; f++)
                desplaza = desplaza->getSig();
            Carta *proximo = desplaza->getSig();
            borrar = proximo;
            desplaza->setSig(proximo->getSig());
            Carta *siguiente = proximo->getSig();
            if (siguiente != nullptr)
                siguiente->setAnt(desplaza);
        }
        delete borrar;
        borrar = NULL;
    }
}

Carta* Juego::cartaMazoOrd(int pos)
{
    Carta *carta;
    if (pos <= cantidadMazoOrd())
    {
        if (pos == 1)
        {
            carta = cabMazoOrd;
        }
        else
        {
            Carta *desplaza;
            desplaza = cabMazoOrd;
            for (int f = 1; f <= pos - 1; f++)
            {
                desplaza = desplaza->getSig();
            }
            carta = desplaza;
        }
        return carta;
    }
}

// Metodos Mazo Desordenado

void Juego::crearMazoDes()
{
    srand(time(nullptr));
    for(int i=1;i<49;i++)
    {
        int pos = rand()%cantidadMazoOrd()+1;
        Carta *carta = cartaMazoOrd(pos);

        Carta *nuevo = new Carta();
        nuevo->setPinta(carta->getPinta());
        nuevo->setIndice(carta->getIndice());
        Carta *desplaza = cabMazoDes;
        if(cabMazoDes==nullptr)
        {
            cabMazoDes = nuevo;
        }
        else
        {
            cabMazoDes->setAnt(nuevo);
            nuevo->setSig(cabMazoDes);
            cabMazoDes = nuevo;
            nuevo->setAnt(nullptr);
        }
        borrarMazoOrd(pos);
    }
}

void Juego::imprimirMazoDes(){
    Carta *desplaza = cabMazoDes;
    cout << "================== MAZO DE CARTAS ==================" << endl;
    cout << setw(25) << "Nombre" << endl;
    cout << "==================================================== " << endl;
    if (cabMazoDes == nullptr) {
        cout << endl << "El mazo de cartas esta vacio" << endl << endl;
    } else {
        while (desplaza != nullptr)
        {
            cout << setw(25);
            if(desplaza->getIndice() == 1)
            {
                cout << "As de ";
            }
            else if(desplaza->getIndice() == 10)
            {
                cout << "Sota de ";
            }
            else if(desplaza->getIndice() == 11)
            {
                cout << "Caballo de ";
            }
            else if(desplaza->getIndice() == 12)
            {
                cout << "Rey de ";
            }
            else
            {
                cout << desplaza->getIndice() << " de ";
            }
            cout << desplaza->getPinta() << endl;

            desplaza = desplaza->getSig();
        }
    }
}

void Juego::destaparMazoAut(){
    Carta *desplaza = cabMazoDes;
    cout << "================== MAZO DE CARTAS ==================" << endl;
    cout << setw(25) << "Nombre" << endl;
    cout << "==================================================== " << endl;
    if (cabMazoDes == nullptr) {
        cout << endl << "El mazo de cartas esta vacio" << endl << endl;
    } else {
        while (desplaza != nullptr)
        {
            cout << setw(25);
                 if(desplaza->getIndice() == 1)
                 {
                     cout << "As de ";
                 }
                 else if(desplaza->getIndice() == 10)
                 {
                     cout << "Sota de ";
                 }
                 else if(desplaza->getIndice() == 11)
                 {
                     cout << "Caballo de ";
                 }
                 else if(desplaza->getIndice() == 12)
                 {
                     cout << "Rey de ";
                 }
                 else
                 {
                     cout << desplaza->getIndice() << " de ";
                 }
            cout << desplaza->getPinta() << endl;

            desplaza = desplaza->getSig();
            Sleep(500);
        }
        cabMazoDes = nullptr;
    }
}

int Juego::cantidadMazoDes(){
    Carta *desplaza = cabMazoDes;
    int cant = 0;
    while (desplaza != nullptr)
    {
        cant++;
        desplaza = desplaza->getSig();
    }
    return cant;
}

void Juego::destaparMazoMan(){
    Carta *borrar = cabMazoDes;
    bool seguir = true;
    cout << "================== MAZO DE CARTAS ==================" << endl;
    cout << setw(25) << "Nombre" << endl;
    cout << "==================================================== " << endl;
    if (cabMazoDes == nullptr) {
        cout << endl << "El mazo de cartas esta vacio" << endl << endl;
    } else {
        while (seguir)
        {
            cout << setw(25);
            if(cabMazoDes->getIndice() == 1)
            {
                cout << "As de ";
            }
            else if(cabMazoDes->getIndice() == 10)
            {
                cout << "Sota de ";
            }
            else if(cabMazoDes->getIndice() == 11)
            {
                cout << "Caballo de ";
            }
            else if(cabMazoDes->getIndice() == 12)
            {
                cout << "Rey de ";
            }
            else
            {
                cout << cabMazoDes->getIndice() << " de ";
            }
            cout << cabMazoDes->getPinta() << endl;

            borrar = cabMazoDes;
            cabMazoDes = cabMazoDes->getSig();
            delete borrar;

            bool valido = true;
            while(valido)
            {
            string opci;
            cout << "Desea Destapar la siguiente Carta (s/n)";
            cin >> opci;
            if(opci=="n")
            {
                valido = false;
                seguir = false;
            }
            else if(opci=="s")
            {
                valido = false;
            }
            else
            {
                cout << "Pulsaste una opcion incorrecta." << endl;
            }
            }

        }
    }
}