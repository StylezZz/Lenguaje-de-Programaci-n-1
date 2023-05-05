/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 3 de mayo de 2023, 22:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcione.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **conductor,*gravedad;
    int *licencia, *infraccion;
    double *multa;
    cargarConductores(licencia, conductor);
    reporteConductores(licencia, conductor);
    cargarInfracciones(infraccion, gravedad, multa);
    reporteInfracciones(infraccion, gravedad, multa);
    reporteDeFaltas(licencia, conductor, infraccion, gravedad, multa);
    return 0;
}

