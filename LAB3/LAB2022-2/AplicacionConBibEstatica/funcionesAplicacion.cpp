/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funcionesBiblioteca.h"
#include "funcionesAplicacion.h"
#define MAXLINEAS 100
using namespace std;

//Parte A
void leerMedicos(struct StMedico *arrMedicos,int &numMedicos){
    ifstream archMedicos;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(archMedicos,"MedicosLab3.txt");
    while(archMedicos>>arrMedicos[i]){
        i++;
    }
    numMedicos=i;
}

//Parte B
void leerPacientes(struct StPaciente *arrPacientes,int &numPacientes){
    ifstream archPacientes;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(archPacientes,"PacientesLab3.txt");
    while(archPacientes>>arrPacientes[i]){
        i++;
    }
    numPacientes=i;
}

//Parte C
void leerCitas(struct StCita *arrCitas,int &numCitas,struct StPaciente *arrPacientes,
        int numPacientes){
    //La sobrecarga me regresa el DNI del paciente
    ifstream archCitas;
    struct StPaciente pac;
    int dni,i=0;
    AperturaDeUnArchivoDeTextosParaLeer(archCitas,"ConsultasLab3.txt");
    while(1){
        dni = (archCitas>>arrCitas[i]);
        if(dni==-1){
            break;
        }
        completarPacientes(dni,arrPacientes,numCitas,numPacientes,arrCitas);
        i++;
    }  
    numCitas = i;
}

bool buscarCodigo(int codigo,struct StPaciente *arrPacientes,int numPac,int &pos){
    for(int i=0;i<numPac;i++){
        if(codigo == arrPacientes[i].dni){
            pos = i;
            return true;
        }
    }
    return false;
}

void completarPacientes(int dniBusqueda,struct StPaciente *arrPacientes,int numCitas
                        ,int numPac,struct StCita *arrCitas){
    //Primero buscar el código introducido y si no se encuentra no se hace nada
    int pos=0;
    if(buscarCodigo(dniBusqueda,arrPacientes,numPac,pos)){
        //Con la pos entonces ya se tiene donde ingresar las citas
        arrPacientes[pos]+=arrCitas[pos];
    }
}

//Función de impresión de caracteres
void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++){
        arch<<c;
    }
    arch<<endl;
}

void emitirReporte(struct StPaciente *arrPacientes,struct StCita *arrCitas,
                   struct StMedico *arrMedicos,int numPacientes,int &numCitas,
                   int numMedicos){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"ReporteAplicacion.txt");
    archReporte<<setw(40)<<"EMPRESA PRESTADORA DE SALUD LP1"<<endl;
    archReporte<<setw(50)<<"PACIENTES QUE FUERON ATENDIDOS"<<endl;
    imprimirLineas(archReporte,'=');
    for(int i=0;i<numPacientes;i++){
        archReporte<<arrPacientes[i];
    }
    
}






