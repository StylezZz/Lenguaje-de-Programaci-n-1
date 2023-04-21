/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MAURICIO
 *
 * Created on 18 de abril de 2023, 12:53 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>

using namespace std;

#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    actualizarGastosPac("Pacientes.bin","Medicinas.bin","Consultas.txt");
    generarReporteMed("ReporteFinal.txt","Medicos.txt");
    generarReportePac("ReporteFinal.txt","Pacientes.bin");
    generarReporteMedicinas("ReporteFinal.txt","Medicinas.bin");
    generarReporteConsultas("ReporteFinal.txt","Consultas.txt");
    return 0;
}

