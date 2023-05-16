/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Proyect: Expression proyect is undefined on line 7, column 15 in Templates/cppFiles/main.cc.
 * File:   main.cpp
 * Author: Diego Bernardo Castilla Arnao , 20196342
 *
 * Created on 13 de mayo de 2023, 11:35 PM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.hpp"
#include "MuestraPunteros.h"

/*
 * 
 */
int main(int argc, char** argv) {

    void*productos,*pedidos,*clientes;
    
    cargaproductos(productos);
    cargapedidos(pedidos);
    imprimepedidos(pedidos);
    imprimeproductos(productos);
    procesaclientes(productos, pedidos, clientes);
    imprimerepfinal(clientes);
//    imprimereporte(clientes);
    
    
    return 0;
}

