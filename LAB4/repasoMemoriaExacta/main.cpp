/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de mayo de 2023, 10:20 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;

void leerDatosConGetline(){
    ifstream archLectura("Personas.csv",ios::in);
    if(!archLectura){
        cout<<"Error no se pudo abrir el archivo Personas.csv"<<endl;
        exit(1);
    }
    
    ifstream file("Personas2.csv",ios::in);
    if(!file){
        cout<<"Error no se pudo abrir el archivo Personas2.csv"<<endl;
        exit(1);
    }
    int codigo;
    char nombre[100];
    double sueldo;
    cout.precision(2);
    cout<<fixed;
    cout<<"Primer archivo de Personas"<<endl;
    for(int i=0;i<100;i++)cout<<"=";
    cout<<endl;
    while(1){
        archLectura>>codigo;
        if(archLectura.eof())break;
        archLectura.get();
        archLectura.getline(nombre,100,',');
        archLectura>>sueldo;
        cout<<setw(10)<<left<<codigo<<setw(40)<<right<<nombre<<setw(20)<<right<<sueldo<<endl;
    }
    
    for(int i=0;i<100;i++)cout<<"=";
    cout<<endl;
    
    cout<<"Otro archivo de Personas"<<endl;
    for(int i=0;i<100;i++)cout<<"=";
    cout<<endl;
    
    while(1){
        file.getline(nombre,100,',');
        if(file.eof())break;
        file>>codigo;
        file.get();
        file>>sueldo;
        file>>ws;
        cout<<setw(10)<<left<<codigo<<setw(40)<<right<<nombre<<setw(20)<<right<<sueldo<<endl;
    }
}
void leerAlumnosCursosEsp(){
    ifstream arch("Alumnos-CursoEsp.txt",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Alumnos-CursoEsp.txt"<<endl;
        exit(1);
    }
    int codigo;
    char nombre[150],codigoCurso[10];
    while(1){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        arch.getline(nombre,150,',');
        cout<<setw(10)<<left<<codigo<<setw(70)<<right<<nombre;
        while(1){
            arch>>codigoCurso;
            
            cout<<right<<setw(10)<<codigoCurso;
            if(arch.get()=='\n' or arch.eof())break;
        }
        cout<<endl;
    }
}
void leerAlumnosCursosCSV(){
    ifstream arch("Alumnos-Cursos.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Alumnos-Cursos.csv"<<endl;
        exit(1);
    }
    int codigo;
    char nombre[120],curso[7];
    while(1){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        arch.getline(nombre,120,',');
        cout<<right<<setw(10)<<codigo<<" "<<left<<setw(40)<<nombre<<endl;
        while(1){
            arch.get(curso,7);
            cout<<setw(15)<<curso<<endl;
            if(arch.get()=='\n' )break;
        }
    }
}

int main(int argc, char** argv) {
//    int *datos,numDatos=0;
//    leerDatosExactos(datos,numDatos);
//    imprimirDatos(datos,numDatos);
//    
//    leerDatosExactos(datos);
//    imprimirDatos(datos);
    
    int *codigos;
    char **nombres,***cursos;
    
    cargarAlumnos(codigos,nombres,cursos);
    reporteDeAlumnos(codigos,nombres,cursos);
    
    return 0;
}

