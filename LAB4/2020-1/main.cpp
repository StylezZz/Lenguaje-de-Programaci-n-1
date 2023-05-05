/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de mayo de 2023, 04:23 PM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
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

