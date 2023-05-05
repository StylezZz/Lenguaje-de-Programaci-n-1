/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 4 de mayo de 2023, 15:48
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;


int main(int argc, char** argv) {
    char **codCursos,**profNombres,**cursos;
    double *creditos;
    int *idProfes;
    cargarCursos(codCursos,cursos,creditos,idProfes,profNombres);
    reporteCursos(codCursos,cursos,creditos,idProfes,profNombres);
    
    int *semestre,*codigoAlumno,*escala;
    char **nombreAlumno,*modalidad;
    double *porcentaje;
    cargarAlumnos(semestre,codigoAlumno,nombreAlumno,modalidad,porcentaje,escala);
    imprimirAlumnos(semestre,codigoAlumno,nombreAlumno,modalidad,porcentaje,escala);
    
    
    
    return 0;
}

