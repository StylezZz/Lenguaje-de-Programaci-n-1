/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 7 de mayo de 2023, 22:38
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Clientes.h"
#include "funciones.h" 
using namespace std;


int main(int argc, char** argv) {
    char ***cli_NombreCategoria,***pro_CodigoDescripcion,***ped_Codigo;
    int **cli_DniTelefono,***ped_FechaCantidad;
    double **pro_PrecioDescuento;
    //Las dos primeras funciones son con la libreria estatica
    CargaDeClientes(cli_DniTelefono,cli_NombreCategoria,"Clientes.csv");
    ReporteDeClientes(cli_DniTelefono,cli_NombreCategoria,"PruebaClientes.txt");
    //Funciones a completar
    CargaDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,
            pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,"Pedidos.csv");
    ReporteDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,
            pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,
            "PruebaProductosPedidos.txt");
    ReporteRelacionDePedidos(cli_DniTelefono,cli_NombreCategoria,pro_CodigoDescripcion,
                             pro_PrecioDescuento,ped_Codigo,ped_FechaCantidad,
                             "ReporteDeRelacionDePedidos.txt");
    return 0;
}

