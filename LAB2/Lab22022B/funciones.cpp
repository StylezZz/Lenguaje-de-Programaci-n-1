/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: cueva.r
 * 
 * Created on 19 de abril de 2023, 11:21 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"

using namespace std;


double preciomed(int codmedicamento){
    char medicamento[100];
    double precio;
    int codmedic;
    
    ifstream medbin("medicinas.bin",ios::in|ios::binary);
    if(!medbin){
        cout << "No se puede abrir el archivo Medicinas";
        exit(1);
    }
    while(1){
        medbin.read(reinterpret_cast< char*>(&codmedic),sizeof(int));
        if(medbin.eof()) break;
        medbin.read(reinterpret_cast< char*>(medicamento),sizeof(char)*100);       
        medbin.read(reinterpret_cast< char*>(&precio),sizeof(double));          
        if(codmedic==codmedicamento) return precio;
    }
    return 0;
}

void actualiza_pac(int dni,double precio){
    char nombre[100];
    double gasto;
    int dni2;
    
    fstream pacbin("pacientes.bin",ios::in|ios::out|ios::binary);
    if(!pacbin){
        cout << "No se puede abrir el archivo Pacientes";
        exit(1);
    }   
    while(1){
        pacbin.read(reinterpret_cast<char*>(&dni2),sizeof(int));
        if(pacbin.eof()) break;
        pacbin.read(reinterpret_cast<char*>(nombre),sizeof(char)*100);       
        pacbin.read(reinterpret_cast<char*>(&gasto),sizeof(double));     
        if(dni==dni2){
           int mov=-1*sizeof(double);
           pacbin.seekg(mov,ios::cur);
            gasto+=precio;
            pacbin.write(reinterpret_cast<const char*>(&gasto),sizeof(double)); 
            break;
        }
    }
}

/*
  43704548   RY89213  9/ 9/2022         1     59121
  36471787   ST60049 16/ 1/2023         5     46919     92517     22232     26484     76596
  71422479   IH70367 17/ 8/2022         3     18672     75565     37007
  51465986   PX70233  5/ 8/2022         1     22842
 */ 
void actualiza(){
    int dni,dd,mm,aa,cantmed,codmedicamento;
    char nombre[100],medico[100],codmed[10],c,medicamento[100];
    double precio;
    
    ifstream cons("Consultas.txt",ios::in);
    if(!cons){
        cout << "No se puede abrir el archivo Consultas";
        exit(1);
    }    
    while(1){
        cons >> dni;
        if(cons.eof()) break;
        cons >> codmed >> dd >> c >> mm >> c >> aa >> cantmed;
        precio=0;
        for(int i=0;i<cantmed;i++){
            cons >> codmedicamento;
            precio += preciomed(codmedicamento);
        } 
        actualiza_pac(dni,precio);
    }
}

void  imprimirpacientes(){
    int dni;
    char nombre[100];
    double gasto;
    
    ifstream pacbin("pacientes.bin",ios::in|ios::binary);
    if(!pacbin){
        cout << "No se puede abrir el archivo Pacientes";
        exit(1);
    }
    ofstream arch("Reportes.txt",ios::out);
    if(!arch){
        cout << "No se puede abrir el archivo Reportes";
        exit(1);
    }    
    
    while(1){
        pacbin.read(reinterpret_cast<char*>(&dni),sizeof(int));
        if(pacbin.eof()) break;
        pacbin.read(reinterpret_cast<char*>(nombre),sizeof(char)*100);       
        pacbin.read(reinterpret_cast<char*>(&gasto),sizeof(double));    

        arch <<setw(10)<< dni <<setw(50) <<nombre<< setw(10)<<setprecision(2)
                <<fixed << gasto << endl;

    }
    
}
