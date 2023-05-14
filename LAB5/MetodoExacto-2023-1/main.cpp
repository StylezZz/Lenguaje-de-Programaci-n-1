/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de mayo de 2023, 08:05 AM
 */

#include "MetodoDinamicoExacto.h"
int main(int argc, char** argv) {
    char**alumno_Nombre,**curso_Nombre,*alumno_Modalidad;
    int*alumno_Codigo,*alumno_Porcentaje,*alumno_Escala;
    int**curso_Alumnos;
    double*curso_Credito;
    lecturaAlumnos("alumnos.csv",alumno_Codigo,alumno_Nombre,alumno_Modalidad,alumno_Porcentaje,alumno_Escala);
    pruebaLecturaAlumnos("ReporteAlumnos.txt",alumno_Codigo,alumno_Nombre,alumno_Modalidad,alumno_Porcentaje,alumno_Escala);
    lecturaCursos("alumnos_cursos.csv",alumno_Codigo,alumno_Escala,curso_Nombre,curso_Credito,curso_Alumnos);
    pruebaDeLecturaCursos("ReporteCursos.txt",curso_Nombre,curso_Credito,curso_Alumnos);
    reporteDeRecaudacionPorModalidad("ReporteRecaudacionModalidad.txt",alumno_Codigo,alumno_Modalidad,alumno_Porcentaje,alumno_Nombre,curso_Nombre,curso_Credito,curso_Alumnos);
    return 0;
}

