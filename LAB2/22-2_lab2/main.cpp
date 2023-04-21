/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MAURICIO
 *
 * Created on 11 de abril de 2023, 08:33 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "funciones.h"


int main(int argc, char** argv) {
    
    cout.precision(2);
    cout<<fixed;
    
    crearBinarios("Pacientes.bin","Medicinas.bin");
    
    
    separarArchivo("Medico-Paciente-Medicinas.txt","Medicos.txt","Pacientes.bin",
            "Medicinas.bin","Consultas.txt");
    generarReporteMed("Reporte.txt","Medicos.txt");
    generarReportePac("Reporte.txt","Pacientes.bin");
    generarReporteMedicinas("Reporte.txt","Medicinas.bin");
    generarReporteConsultas("Reporte.txt","Consultas.txt");
    
    return 0;
}

