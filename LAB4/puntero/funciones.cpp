/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;


char* leerCadena(ifstream &arch){
    char cadena[500],*cad;
    arch.getline(cadena,500);
    if(arch.eof())return nullptr;
    cad = new char[strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad; 
}

void leerNombres(char **&nombres,int &numDatos,const char *nombArch){
    char *buffer[500],*nomb;
    numDatos = 0;
    ifstream arch(nombArch,ios::in);
    if(!arch){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    //Primer nivel, asemejarlo a un arreglo de enteros
    while(1){
        nomb = leerCadena(arch);
        if(nomb == nullptr)break;
        buffer[numDatos] = nomb;
        numDatos++;
    }
    nombres = new char*[numDatos];
    for(int i=0;i<numDatos;i++){
        nombres[i] = buffer[i];
    }
}

void cambiar(char **nombres,int i,int k){
    char *aux;
    aux = nombres[i];
    nombres[i] = nombres[k];
    nombres[k] = aux;
}

void ordenar(char **nombres,int izq,int der){
    int limite;
    if(izq>=der)return;
    cambiar(nombres,izq,(izq+der)/2);
    limite =izq;
    for(int i=izq+1;i<=der;i++){
        if(strcmp(nombres[i],nombres[izq])<0){
            cambiar(nombres,++limite,i);
        }
    }
    cambiar(nombres,izq,limite);
    ordenar(nombres,izq,limite-1);
    ordenar(nombres,limite+1,der);
}

void formatearNombres(char *nombres){
    for(int i=0;nombres[i];i++){
        if(nombres[i]=='/'){
            nombres[i]=' '; 
        }
    }
}

void imprimir(char **nombres,int numDatos,const char *nombreArch){
    ofstream arch(nombreArch,ios::out);
    if(!arch){
        cout<<"No se pudo abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    arch<<setw(30)<<"Nombres Final"<<endl<<endl;
    for(int i=0;i<numDatos;i++){
        formatearNombres(nombres[i]);
        arch<<nombres[i]<<endl;
    }
}
