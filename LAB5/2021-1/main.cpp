/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 7 de mayo de 2023, 0:14
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
    char **conductor, ***placa;
    int *licencia, **falta;
    double **multa;
    cargarConductores(licencia, conductor);
    reporteConductores(licencia, conductor);
    cargarFaltas(licencia, placa, falta);
    reporteFaltas(licencia, conductor, placa, falta);
    resumenMultas(licencia, falta, multa);
    cout<<"Llegue 1"<<endl;
    reporteMultas(licencia, conductor, multa);
    cout<<"Llegue 2"<<endl;
    return 0;
}

