/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 25 de abril de 2023, 11:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    ifstream archClientes;
    ofstream archReporte;
    
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    
    struct Estructura_ClienteRegistrado cliente1,cliente2;
    archClientes>>cliente1>>cliente2;
    
    
    //Probadas con exito
    //Probar la función de impresión de productos
    struct Estructura_PedidoRealizado ped1,ped2,ped3;
    ped1.cantidad = 10.45;
    strcpy(ped1.codigo,"ABC123");
    ped1.fecha = 20220425;
    
    ped2.cantidad = 10.5;
    strcpy(ped2.codigo,"ABC456");
    ped2.fecha = 20220426;
    
    ped3.cantidad = 10.34;
    strcpy(ped3.codigo,"ABC789");
    ped3.fecha = 20220430;
    
    cliente1+=ped1;
    cliente1+=ped2;
    cliente1+=ped3;
    
    archReporte<<cliente1;
    
    //Ingreso de un pedido a un cliente con exito
    
    
    
    return 0;
}

