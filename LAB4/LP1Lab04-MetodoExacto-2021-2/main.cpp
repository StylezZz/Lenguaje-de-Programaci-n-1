/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 2 de mayo de 2023, 14:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char **cli_Nombre,*cli_Categoria,**pro_Descripcion;
    int *cli_DNI,**cli_CodigoProFechaPedido,*pro_Codigo;
    double *pro_Precio,*pro_Descuento,**cli_CantidadPedido;
    CargaDeClientes(cli_DNI,cli_Nombre,cli_Categoria);
    ReporteDeClientes(cli_DNI,cli_Nombre,cli_Categoria);
//    CargaDePedidosYProductos(cli_DNI, pro_Codigo, pro_Descripcion,
//                             pro_Descuento, pro_Precio, cli_CodigoProFechaPedido, 
//                             cli_CantidadPedido);
//    ReporteDePedidosYProductos(cli_DNI, pro_Codigo, pro_Descripcion,
//                               pro_Descuento, pro_Precio, cli_CodigoProFechaPedido, 
//                               cli_CantidadPedido);
//    ReporteRlacionDePedidos (cli_DNI, cli_Nombre, cli_Categoria,
//                             cli_CodigoProFechaPedido, cli_CantidadPedido, pro_Codigo,
//                             pro_Descripcion, pro_Descuento, pro_Precio);
    return 0;
}

