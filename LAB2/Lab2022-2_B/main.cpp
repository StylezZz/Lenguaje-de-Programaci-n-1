/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 20 de abril de 2023, 10:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    leerArchivo();
    verficarPacientesBin();
    verificarMedicinasBin();
    mostrarReporte();
    
    return 0;
}

