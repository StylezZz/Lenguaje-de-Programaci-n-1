/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 8 de mayo de 2023, 10:51 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Funciones.h"

int main(int argc, char** argv) {
    char ***medicoDatos,****citaPaciente;
    int **citaCantidad;
    double *medicoTarifaHora, ***citaTiempoYPago;
    
    cargarCitas("Citas.csv",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,
            citaTiempoYPago);
    pruebaDeCargaDeCitas("PruebaDeCargaDeCitas.txt",medicoDatos,medicoTarifaHora,
            citaPaciente,citaCantidad,
            citaTiempoYPago);
    ReporteDeCitasPorMedico("ReporteDeCitasPorMedico.txt",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,
            citaTiempoYPago);
    return 0;
}

