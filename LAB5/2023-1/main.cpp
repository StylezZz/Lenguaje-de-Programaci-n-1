/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 11 de mayo de 2023, 8:46
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
    char **alumno_Nombre, **curso_Nombre, *alumno_Modalidad;
    int *alumno_Codigo, *alumno_Porcentaje, *alumno_Escala;
    int ***curso_Alumnos;
    double *curso_Creditos;
    char ***alumno_cursos;
    
    lecturaAlumnos("alumnos.csv",alumno_Codigo,alumno_Nombre,alumno_Modalidad,
            alumno_Porcentaje,alumno_Escala,alumno_cursos);
    
    pruebaLecturaAlumnos("Reportealumnos.txt",alumno_Codigo,alumno_Nombre,
            alumno_Modalidad,alumno_Porcentaje,alumno_Escala,alumno_cursos);
//    
//    
    lecturaCursos("alumnos_cursos.csv",alumno_Codigo,alumno_Escala,curso_Nombre
            ,curso_Creditos,curso_Alumnos,alumno_cursos);
    
    return 0;
}

