/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 29 de abril de 2023, 18:35
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***almacenes,**codigoProd,**nombreProd;
    leerPalets(almacenes);
    imprimirPalets(almacenes);
    leerProductos(codigoProd,nombreProd);
    imprimirProductos(codigoProd,nombreProd);
    ordenarProductos(codigoProd,nombreProd);
    cuentaProductos(almacenes,codigoProd,nombreProd);
    return 0;
}

