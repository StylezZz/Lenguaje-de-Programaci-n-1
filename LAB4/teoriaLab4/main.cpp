/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 28 de abril de 2023, 16:53
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesAuxiliares.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    Uso getline y get
//    char nombre[100],*nomb,n[9];
//    nomb = new char[100];
//    int num;
//    
//    cin.getline(nombre,100);
//    cin.getline(nomb,100);
//    cout<<nombre<<endl;
//    cout<<nomb<<endl;
//    
//    cin.getline(n,9);
//    cin.getline(nomb,100);
//    cout<<n<<endl;
//    cout<<nomb<<endl;
//    
//    int *datos,numDatos;
//    leerDatosExactos(datos,numDatos);
//    imprimirDatos(datos,numDatos);
//    
//    char *nombre;
//    leeDatosExactosSt(nombre);
//    cout<<nombre<<endl;
    
    char **nombres;
    int numDatos;
    
    leerNombres(nombres,numDatos,"personas.txt");
    ordenar(nombres,0,numDatos-1);
    imprimir(nombres,numDatos,"Reporte.txt");
    
    return 0;
}

