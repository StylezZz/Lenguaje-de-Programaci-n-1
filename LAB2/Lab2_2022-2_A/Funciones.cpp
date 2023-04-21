/* 
 * File:   Funciones.cpp
 * Author: Jhoyfer Melendez Torres (20203823)
 * 
 * Created on 18 de abril de 2023, 07:12 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Funciones.h"
#define MAXCAD 100

void leerArchivo(){
    ifstream arch("Medico-Paciente-Medicinas.txt", ios::in);
    if(not arch.is_open()){
        cout<< "ERROR: no se pudo abrir el archivo "
                "Medico-Paciente-Medicinas.txt" << endl;
        exit(1);
    }
    ofstream archMedicos("Medicos.txt", ios::out);
    if(not archMedicos.is_open()){
        cout<< "ERROR: no se pudo abrir el archivo "
                "Medicos.txt" << endl;
        exit(1);
    }
    ofstream archPacientes("Pacientes.bin", ios::out | ios::binary);
    if(not archPacientes.is_open()){
        cout<< "ERROR: no se pudo abrir el archivo "
                "Pacientes.bin" << endl;
        exit(1);
    }
    ofstream archMedicinas("Medicinas.bin", ios::out | ios::binary);
    if(not archMedicinas.is_open()){
        cout<< "ERROR: no se pudo abrir el archivo "
                "Medicinas.bin" << endl;
        exit(1);
    }
    ofstream archConsultas("Consultas.txt", ios::out);
    if(not archConsultas.is_open()){
        cout<< "ERROR: no se pudo abrir el archivo "
                "Consultas.txt" << endl;
        exit(1);
    }
    int dni, dd, mm, aa, cantidad;
    double precio;
    char codigo[10], codigoAtencion[10], medico[60], nombrePaciente[100];
    char c, codigoMedicamento[10], medicamento[50];
    while(true){
        arch>> dni;
        if(arch.eof()) break;
        if(arch.fail()){
            arch.clear();
            arch>> codigo >> medico;
            insertaMedico(archMedicos, codigo, medico);
        } else{
            arch>> nombrePaciente>> codigoAtencion>> dd>> c>> mm>> c>> 
                    aa>> cantidad;
            insertaPaciente(archPacientes, dni, nombrePaciente);
            for(int i=0;i<cantidad;i++)
                arch>> codigoMedicamento>> medicamento>> precio;
        }
    }
}

void insertaMedico(ofstream &archMedicos, char *codigo, char *medico){
    char especialidad[50];
    divideCadenas(medico, especialidad);
    archMedicos<< setw(10)<< codigo<< setw(10) << " " << left<< setw(45)
            << medico << especialidad << endl << right;
}

void insertaPaciente(ofstream &archPacientes,int dni, char *nombrePaciente){
    int flag;
    double gasto=0;
    flag=verifica(dni);
    if(not flag){
        archPacientes.write(reinterpret_cast<const char*>(&dni), sizeof(int));
        archPacientes.write(reinterpret_cast<const char*>(nombrePaciente), sizeof(char)*100);
        archPacientes.write(reinterpret_cast<const char*>(&gasto), sizeof(double));
        //archPacientes.flush();
    }
}

int verifica(int dni){
    double gasto;
    int dni2;
    char nombre[100];
    ifstream paciente("Pacientes.bin", ios::in | ios::binary);
    if(not paciente.is_open()){
        cout<< "ERROR: no se pudo abrir el archivo "
                "Pacientes.bin" << endl;
        exit(1);
    }
    while(1){
        paciente.read(reinterpret_cast<char*>(&dni2),sizeof(int));
        if(paciente.eof()) break;
        paciente.read(reinterpret_cast<char*>(nombre), sizeof(char)*100);
        paciente.read(reinterpret_cast<char*>(&gasto), sizeof(double));
        if(dni==dni2) return 1;
    }
}
void crearReportesSimples(){
    ifstream binPacientes("Pacientes.bin",ios::in |ios::binary);
    verificacionBinario(binPacientes,"Clientes.bin");
    
    ofstream reporte("Reporte_Simple.txt",ios::out);
    verificacionReporte(reporte,"Reporte_Simple.txt");
    
    binPacientes.seekg(0, ios::beg);
    verificaPaciente(binPacientes, reporte);
}

void verificaPaciente(ifstream &paciente, ofstream &reporte){
    char dni, nombre[100], gasto; 
    reporte << "Reporte paciente" << endl;
    while(true){
        paciente.read(reinterpret_cast<char *>(&dni), sizeof(int));
        if(paciente.eof()) break;
        paciente.read(reinterpret_cast<char *>(nombre), sizeof(char)*100);
        paciente.read(reinterpret_cast<char *>(&gasto), sizeof(double));
        reporte<<setw(10)<<dni<<setw(15)<<nombre<<setw(10)<<gasto<<endl;
    }
}

void verificaMedicina(){
    
}

void divideCadenas(char *medico, char *especialidad){
    int flag=0, j=0;
    for(int i=0;medico[i];i++){
        if(medico[i]=='_' and medico[i+2]>='a' and medico[i+2]<='z'){
            medico[i]='\0';
            flag=1;
        }
        if(flag){
            especialidad[j] = medico[i+1];
            j++;
            if(medico[i+1]=='\0') break;
        }
    }
}

void verificacionReporte( ofstream & nombreArch, const char * nombre ){ /*Verificar los archivos de Escritura*/
    
       if(!nombreArch){
        
        cout << "No se pudo abrir el archivo " << nombre;
        exit(1);
        
    }
}

void verificacionBinario( ifstream & nombreArch, const char * nombre ){ /*Verificar los archivos binarios*/
    
    if(!nombreArch){
        
        cout << "No se pudo abrir el archivo " << nombre;
        exit(1);
        
    }
}