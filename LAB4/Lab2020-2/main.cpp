/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 1 de mayo de 2023, 21:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    char **codigoMed,**medicos;
    double *tarifas;
    cargarMedicos(codigoMed,medicos,tarifas);
    reporteMedicos(codigoMed,medicos,tarifas);
    reporteDeIngresos(codigoMed,medicos,tarifas);
    return 0;
}

