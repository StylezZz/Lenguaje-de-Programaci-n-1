/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 * Codigo: 20203371
 * Nombre: Gabriel Omar Duran Ruiz
 * Created on 23 de septiembre de 2022, 08:04 AM
 */


#include <iomanip>
#include <iostream>
#include "MetodoDinamicoExacto.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **med_Nombre,**med_Especialidad,**pac_Nombre;
    int *med_Codigo,*pac_Dni,**pac_Citas;
    double *med_Tarifa;
    lecturaDeMedicos("Medicos.csv",med_Codigo,med_Nombre,med_Especialidad,med_Tarifa);
    pruebaDeLecturaMedicos("ReporteDeMedicos.txt",med_Codigo,med_Nombre,
            med_Especialidad,med_Tarifa);
    lecturaDeCitas("Citas.csv",pac_Dni,pac_Nombre,pac_Citas);
    pruebaDeLecturaDeCitas("ReporteDeCitas.txt",pac_Dni,pac_Nombre,pac_Citas);
//    reporteDeIngresosMedicosYGastosDeLosPacientes("ReporteDeIngresoMedicos.txt",
//            med_Codigo,med_Nombre,med_Especialidad,med_Tarifa,pac_Dni,pac_Nombre,
//            pac_Citas);
            
    return 0;
}

