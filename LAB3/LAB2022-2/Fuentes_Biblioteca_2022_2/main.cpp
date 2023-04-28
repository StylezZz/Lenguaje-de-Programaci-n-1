/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 26 de abril de 2023, 12:14
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funcionesBiblioteca.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Pruebas de las funciones
    ifstream archMedicos,archPacientes,archConsultas;
    ofstream archPruebas;
    
    AperturaDeUnArchivoDeTextosParaLeer(archMedicos,"MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPacientes,"PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archConsultas,"ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archPruebas,"Pruebas.txt");
    struct StMedico med[40];
    struct StPaciente pac[40];
    struct StCita cita[40];
   
    archMedicos>>med[0];
    archMedicos>>med[1];
    archMedicos>>med[2];
    archMedicos>>med[3];
    
    archPacientes>>pac[0];
    archPacientes>>pac[1];
    archPacientes>>pac[2];
    archPacientes>>pac[3];
    
    archConsultas>>cita[0];
    archConsultas>>cita[1];
    archConsultas>>cita[2];
    archConsultas>>cita[3];
    
    
    //Con eso deberia se debería probar las sobrecargas que son lectura
    
    //Impresión de un paciente -> Si se imprime correctamente
    archPruebas<<pac[0];
    
    med[0].codigo=892133;
    med[0].tarifaPoxConsulta=389.91;
    pac[1]+=cita[0];
    int DNI1=43704548;
    cita[0].codigoDelMedico=892133;
    cita[0].fecha=20220909;
    DNI1=43704548;
    cita[1].codigoDelMedico=892133;
    cita[1].fecha=20221009;
    
    cout<<"Se hallo el medico en la cita"<<(cita[0]<=med)<<endl;
    cita[0]<=med;
    cita[1]<=med;
    pac[1]+=cita[0];
    pac[1]+=cita[1];
    ++pac[1];
    cout<<"Total gastado paciente 2: "<<pac[1].totalGastado<<endl;
    cout<<"Listo"<<endl;
    
    return 0;
}

