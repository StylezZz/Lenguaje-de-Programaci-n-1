/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 25 de mayo de 2021, 08:03 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "BibCargaConductores.h"
#include "BibCargaFaltas.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char **conductor, ***placa;
    int *licencia, ***falta, ***fecha;
    
    cargarConductores(licencia,conductor,placa);
    reporteConductores(licencia,conductor,placa);
    cargarFaltas(licencia,placa,falta,fecha);
    reporteFaltas(licencia,conductor,placa,falta,fecha);
    
    return 0;
}

