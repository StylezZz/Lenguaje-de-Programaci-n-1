/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 26 de abril de 2023, 14:57
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funcionesBiblioteca.h"
#include "funcionesAplicacion.h"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    int numMedicos=0,numPacientes=0,numCitas=0;
    
    struct StMedico arrMedicos[100];
    struct StPaciente arrPacientes[100];
    struct StCita arrCitas[350];
    
    leerMedicos(arrMedicos,numMedicos);
    arrMedicos[numMedicos].codigo = 0;
    leerPacientes(arrPacientes,numPacientes);
    leerCitas(arrCitas,numCitas,arrPacientes,numPacientes);
    emitirReporte(arrPacientes,arrCitas,arrMedicos,numPacientes,numCitas,
                  numMedicos);
    
    cout<<numMedicos<<endl<<numCitas<<endl<<numPacientes;
    
   
    return 0;
}

