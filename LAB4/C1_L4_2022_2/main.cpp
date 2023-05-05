/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author:  Soluciones rapidas y matematicas
 *          
 * Created on 30 de abril de 2023, 07:23
 */
/*Codigo :12787218
 Nombre: Olarzaga Joaquin Ramires Gutierrez
 */
#include <iomanip>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "MetodoDinamicoExacto.h"
#define MAXLIN 100
using namespace std;

/*
 * no mas de 20 lineas 
 * no pasarse de linea roja
 * no cuentan las declaraciones de las variables
 */
int main(int argc, char** argv) {
    char **med_Nombre,**med_Especialidad,**pac_Nombre;
    int*med_Codigo,*pac_Dni,**pac_Citas;
    double *med_Tarifa;
    
    lecturaDeMedicos("Medicos.csv",med_Codigo,med_Nombre,med_Especialidad
            ,med_Tarifa);
    pruebaDeLecturaDeMedicos("ReporteDeMedicos.txt"
            ,med_Codigo,med_Nombre,med_Especialidad
            ,med_Tarifa);
    lecturaDeCitas("Citas.csv",pac_Dni,pac_Nombre,pac_Citas);
    pruebaDeLecturaDeCitas("ReporteDeCitas.txt",pac_Dni,pac_Nombre,pac_Citas);
    reporteDeIngresosMedicosYGastosDeLosPacientes("ReporteDeIngresosMedicos.txt"
            ,med_Codigo,med_Nombre,med_Especialidad,med_Tarifa,pac_Dni
            ,pac_Nombre,pac_Citas);
    
    return 0;
}

