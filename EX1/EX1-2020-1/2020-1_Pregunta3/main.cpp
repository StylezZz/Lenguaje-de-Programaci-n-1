/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 0:51
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesPreg1.h"
#include "funcionesPreg2.h"
#include "funcionesPreg3.h"
using namespace std;

int main(int argc, char** argv) {
    char ***cursos,**profesores;
    int *codProfesores;
    void *sesiones;
    leerDatos(cursos,codProfesores,profesores);
    imprimirDatos(cursos,codProfesores,profesores);
    leerSesiones(sesiones);
    imprimirSesiones(sesiones);
    reporteCargaHorariaDeProf(cursos,codProfesores,profesores,sesiones);
    return 0;
}

