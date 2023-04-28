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
    
    struct Estructura_ClienteRegistrado clientes[30],cliente1,cliente2;
    
    //La primera sobrecarga si funciona
    //Probar la siguiente sobrecarga
//    while(1){
//        archClientes>>cliente;
//        if(archClientes.eof())break;
//        clientes+=cliente;
//    }
//    
//    //La impresion del arreglo de estructuras de clientes
//    for(int i=0;clientes[i].dni;i++){
//        archReporte<<clientes[i];
//    }
    
    //La segunda sobrecarga si funciona
    
//    archClientes>>cliente1>>cliente2;
//    struct Estructura_PedidoRealizado ped1,ped2;
//    ped1.cantidad =10.5;
//    ped1.fecha = 20200626;
//    strcpy(ped1.codigo,"ABABAB");
//    
//    ped2.cantidad =15.5;
//    ped2.fecha = 20210116;
//    strcpy(ped2.codigo,"XYZ321");
//    
//    cliente1+=ped1;
//    cliente1+=ped2;
//    
//    cliente2+=ped2;
//    cliente2+=ped1;
//    
//    archReporte<<cliente1<<cliente2;
    
    //La tercera Sobrecarga funciona
    struct Estructura_ProductosEnAlmacen productos[30],prod1,prod2,prod3,prodPrueba;
    
    strcpy(prod1.codigo,"DOB245");
    strcpy(prod1.descripcion,"LECHE_LALA_SEMI_DESLACTOSADA_1LT");
    prod1.descuento=0;
    prod1.precioUnitario=16.98;
    
    strcpy(prod2.codigo,"QBL949");
    strcpy(prod2.descripcion,"YOGHURT_NATURAL_LIGHT_LALA_1KG");
    prod2.descuento=4.7;
    prod2.precioUnitario=25.86;
    
    strcpy(prod3.codigo,"DOB245");
    strcpy(prod3.descripcion,"LECHE_LALA_SEMI_DESLACTOSADA_1LT");
    prod3.descuento=0;
    prod3.precioUnitario=16.98;
    strcpy(productos[0].codigo,"X");
    productos+=prod1;
    productos+=prod2;
    productos+=prod3;
    //Todas las sobrecargas funcionan
    archReporte<<productos;
    
    
    return 0;
}

