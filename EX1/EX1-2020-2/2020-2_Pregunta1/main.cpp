/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 12:28
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesPreg1.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *pedidos,*stock;
    leerDatos(pedidos,stock);
    atiende(pedidos,stock);
    imprimirDatos(pedidos,stock);
    return 0;
}

