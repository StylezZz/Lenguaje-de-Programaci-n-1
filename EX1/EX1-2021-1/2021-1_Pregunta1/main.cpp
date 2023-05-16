/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 18:47
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibCargaConductores.h"
#include "BibCargaFaltas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **conductor,***placa;
    int *licencia,***falta,***fecha;
    cargarConductores(licencia,conductor,placa);
    reporteConductores(licencia,conductor,placa);
    cargarFaltas(licencia,placa,falta,fecha);
    reporteFaltas(licencia,conductor,placa,falta,fecha);
    return 0;
}

