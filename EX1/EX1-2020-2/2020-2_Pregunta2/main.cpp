/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 15:49
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesPreg2.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **clientes,***strProductos;
    int ***intProductos;
    leerDatos(clientes,intProductos,strProductos);
    imprimirDatos(clientes,intProductos,strProductos);
    return 0;
}

