/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibCargaFaltas.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 25 de mayo de 2021, 08:13 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibCargaConductores.h"
#include "BibCargaFaltas.h"
#define MAX_LINEA 200

void cargarFaltas(int *licencia,char ***placa,int ***&falta,int ***&fecha){
    ifstream archRegistroDeFaltas("RegistroDeFaltas.csv",ios::in);
    if(!archRegistroDeFaltas){
        cout<<"ERROR: NO se puede abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    
    int numConductores=0;
    for(numConductores=0;placa[numConductores];numConductores++);
    
    falta=new int**[numConductores+1]{};
    fecha=new int**[numConductores+1]{};
    falta[numConductores]=nullptr;
    fecha[numConductores]=nullptr;
    
    int licenciaArch,dd,mm,aa,codInfraccionArch,pos,fechaArch;
    char placaArch[20],car;
    
    while(1){
        archRegistroDeFaltas>>licenciaArch;
        if(archRegistroDeFaltas.eof()) break;
        archRegistroDeFaltas.get();
        archRegistroDeFaltas.getline(placaArch,20,',');
        archRegistroDeFaltas>>dd>>car>>mm>>car>>aa;
        archRegistroDeFaltas.get();
        archRegistroDeFaltas>>codInfraccionArch;
        pos=buscarConductor(licencia,licenciaArch);
        if(pos!=-1){
            fechaArch=aa*10000+mm*100+dd;
            asignarFaltas(falta[pos],fecha[pos],placa[pos],placaArch,fechaArch,codInfraccionArch);
        }
    }
    
    achicarMemoria(falta,fecha,placa,numConductores);
    
}

void achicarMemoria(int ***falta,int ***fecha,char ***placa,int numConductores){
    for(int i=0;i<numConductores;i++){
        if(falta[i]!=nullptr){
            achicarMemoriaConductor(falta[i],fecha[i],placa[i]);
        }
    }
}

void achicarMemoriaConductor(int **&falta,int **&fecha,char **placa){
    int **arrFaltas,**arrFechas;
    int numInfracciones=0;
    for(numInfracciones=0;placa[numInfracciones];numInfracciones++);
    for(int i=0;i<numInfracciones;i++){
        if(falta[i]!=nullptr){
            achicarMemoriaInfraccciones(falta[i],fecha[i]);
        }
    }
    arrFaltas=new int*[numInfracciones+1];
    arrFechas=new int*[numInfracciones+1];
    
    for(int i=0;i<numInfracciones+1;i++){
        arrFaltas[i]=falta[i];
        arrFechas[i]=fecha[i];
    }
    
    arrFaltas[numInfracciones]=nullptr;
    arrFechas[numInfracciones]=nullptr;
    
    delete falta;
    delete fecha;
    
    falta=arrFaltas;
    fecha=arrFechas;
}

void achicarMemoriaInfraccciones(int *&falta,int *&fecha){
    int *arrFalta,*arrFecha;
    int numFaltas=falta[0];
    arrFalta=new int[numFaltas+1]; //El espacio extra es para el primer elemento que guarda el numero de faltas
    arrFecha=new int[numFaltas];
    
    for(int i=0;i<numFaltas+1;i++){
        arrFalta[i]=falta[i];
        if(i<numFaltas){
            arrFecha[i]=fecha[i];
        }
    }
    
    delete falta;
    delete fecha;
    
    falta=arrFalta;
    fecha=arrFecha;
}

int buscarConductor(int *licencia,int licenciaArch){
    //El archivo licencia acaba en un 0
    for(int i=0;licencia[i]!=0;i++){
        if(licencia[i]==licenciaArch) return i;
    }
    return -1;
}

void asignarFaltas(int **&falta,int **&fecha,char **placa,char *placaArch,int fechaArch,int codInfraccionArch){
    int posPlaca;
    posPlaca=buscarPlaca(placaArch,placa);
    if(posPlaca!=-1){ //Existe la placa para ese conductor     
        if(falta==nullptr){ //Aun no ha sido creado la estructura
            falta=new int*[50]{}; //Estos buffers luego se acortarán para que esten exactos
            fecha=new int*[50]{}; //Estos buffers luego se acortarán para que esten exactos
        }
        
        if(falta[posPlaca]==nullptr){ //Aun no existen faltas para esa placa
            falta[posPlaca]=new int[50]{}; //Estos buffers luego se acortarán para que esten exactos
            fecha[posPlaca]=new int[50]{}; //Estos buffers luego se acortarán para que esten exactos

            falta[posPlaca][falta[posPlaca][0]+1]=codInfraccionArch;
            fecha[posPlaca][falta[posPlaca][0]]=fechaArch;
            falta[posPlaca][0]=1;
        }
        else{ //Ya existen faltas para esa placa, se añaden más
            falta[posPlaca][falta[posPlaca][0]+1]=codInfraccionArch;
            fecha[posPlaca][falta[posPlaca][0]]=fechaArch;
            falta[posPlaca][0]++;
        }
    }
}

double obtenerMontoMulta(int codInfraccionArch){
    ifstream archInfracciones("Infracciones.csv",ios::in);
    if(!archInfracciones){
        cout<<"ERROR: NO se puede abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    
    int codInfraccionAux;
    char descripcion[500],gravedad[50];
    double monto;
    
    while(1){
        archInfracciones>>codInfraccionAux;
        if(archInfracciones.eof()) break;
        archInfracciones.get();
        archInfracciones.getline(descripcion,500,',');
        archInfracciones.getline(gravedad,50,',');
        archInfracciones>>monto;
        if(codInfraccionArch==codInfraccionAux) return monto;
    }
    return 0.0;
}

int buscarPlaca(char *placaArch,char **placa){
    if(placa==nullptr) return -1;
    for(int i=0;placa[i];i++){
        if(strcmp(placa[i],placaArch)==0) return i;
    }
    return -1;
}

void reporteFaltas(int *licencia,char **conductor,char ***placa,int ***falta,int ***fecha){
    ofstream archReporte("ReporteFaltas.txt",ios::out);
    if(!archReporte){
        cout<<"ERROR: NO se puede abrir el archivo ReporteFaltas.txt"<<endl;
        exit(1);
    }
    
    archReporte.precision(2);
    archReporte<<fixed;
    
    int fecha1,fechaN;
    double montoTotal;
    
    //Falta achicar memoria
    for(int i=0;conductor[i];i++){
        archReporte<<"Conductor: "<<conductor[i]<<endl;
        archReporte<<"Licencia No.: "<<licencia[i]<<endl;
        imprimirLinea('=',MAX_LINEA,archReporte);
        archReporte<<"Infracciones cometidas:"<<endl;
        imprimirLinea('-',MAX_LINEA,archReporte);
        archReporte<<"No."<<setw(15)<<"Placa"<<setw(15)<<"Cantidad"<<setw(30)<<"Monto total a pagar"<<setw(20)<<"Fecha 1"
                <<setw(15)<<"Fecha N"<<endl;
        if(falta[i]!=nullptr){ //Solo si existe faltas
            for(int k=0;falta[i][k];k++){
                if(falta[i][k]!=nullptr){ //Solo si existen faltas con esa palca
                    montoTotal=obtenerMontoTotal(falta[i][k],fecha[i][k],fecha1,fechaN);
                    archReporte<<setw(2)<<k+1<<")"<<setw(17)<<placa[i][k]<<setw(9)<<falta[i][k][0]
                            <<setw(26)<<montoTotal<<setw(29)<<fecha1<<setw(15)<<fechaN<<endl;
                }
            }
        }
        imprimirLinea('=',MAX_LINEA,archReporte);
    }
}

double obtenerMontoTotal(int *falta,int *fecha,int &fecha1,int &fechaN){
    double montoTotal=0.0;
    fecha1=fecha[0];
    //Los codigos de las faltas estan a partir de la posicion 1
    for(int i=1;i<falta[0];i++){
        montoTotal+=obtenerMontoMulta(falta[i]);
    }
    fechaN=fecha[falta[0]-1];
    return montoTotal;
}

void imprimirLinea(char car,int cant,ofstream &arch){
    for(int i=0;i<cant;i++){
        arch<<car;
    }
    arch<<endl;
}