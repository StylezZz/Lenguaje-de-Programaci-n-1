/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesAuxiliares.h"
#define INCREMENTO 5
using namespace std;

void leerDatosExactos(int *&datos,int &numDatos){
    int buffer[1000];
    numDatos = 0;
    while(1){
        cin>>buffer[numDatos];
        if(cin.eof())break;
        numDatos++;
    }
    datos = new int[numDatos];
    for(int i=0;i<numDatos;i++){
        datos[i] = buffer[i];
    }
}
void imprimirDatos(const int *datos,int numDatos){
    for(int i=0;i<numDatos;i++){
        cout<<setw(5)<<right<<datos[i]<<endl;
    }
}

void leeDatosExactosSt(char *&nombre){
    char buffer[200];
    int numCar;
    cin.getline(buffer,200);
    numCar= strlen(buffer);
    nombre = new char[numCar+1];
    strcpy(nombre,buffer);
}

void incrementarEspacios(int *&datos,int numDatos,int &cap){
    int *aux;
    cap+=INCREMENTO;   
    if(datos==NULL){
        datos=new int [cap];
    }else{
        aux = new int[cap];
        for(int i=0;i<numDatos;i++){
            aux[i] = datos[i];
        }
        delete datos;
        datos = aux;
    }
}

void leerDatosPorIncremento(int *&datos,int &numDatos){
    int cap=0,dato;
    numDatos = 0;
    datos = nullptr;
    
    while(1){
        cin>>dato;
        if(cin.eof())break;
        if(numDatos==cap){
            incrementarEspacios(datos,numDatos,cap);
        }
        datos[numDatos]= dato;
        numDatos++;
    }
}


void leerNombres(char **&nombres,int &numDatos,const char *arch){
    char *buff[500],*nomb;
    numDatos = 0;
    ifstream archLectura(arch,ios::in);
    if(!archLectura){
        cout<<"ERROR, no se pudo abrir el archivo "<<arch<<endl;
        exit(1);
    }
//    while(1){
//        archLectura>>
//    }
    
}

void ordenar(char **nombres,int izq,int derecha ){
    
}

void imprimir(char **nombres,int numDatos,const char *arch){
    ofstream archReporte(arch,ios::out);
    if(!archLectura){
        cout<<"ERROR, no se pudo abrir el archivo "<<arch<<endl;
        exit(1);
    }
}