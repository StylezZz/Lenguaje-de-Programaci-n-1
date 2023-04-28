/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 26 de abril de 2023, 10:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Estructuras.h"
#include "funcionesAplicacion.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct Estructura_ClienteRegistrado arrClientes[100];
    struct Estructura_ProductosEnAlmacen arrProductos[100];
    //Con esto se leen los clientes
    leerClientes(arrClientes);
    mostrarClientes(arrClientes);
    //Aqui ya esta lleno el arreglo de clientes, falta el de Productos
    cargarPedidosLeerProductos(arrProductos,arrClientes);
    
    mostrarProductos(arrProductos);
    
    
    
    return 0;
}

