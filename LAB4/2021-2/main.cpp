/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 4 de mayo de 2023, 8:30
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
#include "FuncionesFecha.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **codigo,**titulo,*tipo,**nombre;
    int *carne,*cantEnBibl;
    double *precio;
    estructurasParaLosLibros_CargaDeDatos(codigo,titulo,cantEnBibl,precio);
    
    estructurasParaLosLibros_Reporte(codigo,titulo,cantEnBibl,precio);
    usuariosDeLaBiblioteca_CargaDeDatos(carne,tipo,nombre);
    usuariosDeLaBiblioteca_Reporte(carne,tipo,nombre);
    librosYUsuariosInhabilitados_Reporte(codigo,titulo,cantEnBibl,precio,carne,
                                         tipo,nombre);
    return 0;
}

