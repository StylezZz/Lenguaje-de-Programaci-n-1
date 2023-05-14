/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 29 de abril de 2023, 13:24
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "FuncionesActividad04.h"
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

