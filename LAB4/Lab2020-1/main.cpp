/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 1 de mayo de 2023, 0:14
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
    char **nombres,***cursos;
    int *codigos;
    leerAlumnos(codigos,nombres,cursos);
    imprimirAlumnos(codigos,nombres);
    leerCursos(codigos,cursos);
    imprimirReporte(codigos,nombres,cursos);
    return 0;
}

