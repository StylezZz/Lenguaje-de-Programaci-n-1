/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 19 de abril de 2023, 10:19
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"

//Clientes.bin->  dni(int)    nombre(cadena)  categoria(char) telefono(int)   montoGastado(double)
//Productos.bin-> codigoPro(cadena) descripcionPro(cadena)  descuento(double)   precUnitario(double)
//Pedidos.bin-> dni(int)    codigoPro(cadena)   cantComprada(double)    fecha(int)

int main(int argc, char** argv) {
    crearClientesBin();
    verificarClienteBin();
    
    return 0;
}

