/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 30 de abril de 2023, 17:00
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char **nombres;
    int numDatos;
    
    leerNombres(nombres,numDatos,"Personas.txt");
    ordenar(nombres,0,numDatos-1);
    imprimir(nombres,numDatos,"Reporte.txt");
    return 0;
}

