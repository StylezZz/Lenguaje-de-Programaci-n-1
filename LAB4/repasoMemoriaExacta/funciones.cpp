/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;

void leerDatosExactos(int *&datos,int &numDatos){
    ifstream arch("Datos.txt",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    int buffDatos[500];
    numDatos=0;
    int num;
    while(1){
        arch>>num;
        if(arch.eof())break;
        buffDatos[numDatos]=num;
        numDatos++;
    }
    datos= new int[numDatos];
    for(int i=0;i<numDatos;i++){
        datos[i]=buffDatos[i];
    }
}

void imprimirDatos(int *datos,int numDatos){
    for(int i=0;i<numDatos;i++){
        cout<<datos[i]<<endl;
    }
}

void leerDatosExactos(int *&datos){
    ifstream arch("Datos.txt",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Datos.txt"<<endl;
        exit(1);
    }
    int bufferDatos[100],dato,numDatos=0;
    while(1){
        arch>>dato;
        if(arch.eof())break;
        bufferDatos[numDatos]=dato;
        numDatos++;
    }
    //Y ahora en la posición que es numDatos se le asigna el cero
    //Que sera como mi señal para el fin de un arreglo
    cout<<numDatos<<"====";
    bufferDatos[numDatos]=0;
    
    cout<<numDatos<<endl;
    datos = new int[numDatos+1];
    for(int i=0;i<numDatos;i++){
        datos[i]=bufferDatos[i];
    }
}

void imprimirDatos(int *datos){
    for(int i=0;datos[i];i++){
        cout<<datos[i]<<endl;
    }
}

char *leeCadena(ifstream &in){
    char buffer[200],*cad;
    in.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

char *leeCa(ifstream &arch){
    char *cad=new char[7];
    arch.get(cad,7);
    return cad;
}

char **leeCurso(ifstream &in){
    char **cursos,*buffCurso[200],*cur;
    int numDatos=0;
    while(true){
        cur = leeCa(in);
        buffCurso[numDatos]=cur;
        numDatos++;
        if(in.get()=='\n')break;
    }
    cursos = new char*[numDatos+1];
    for(int i=0;i<numDatos;i++){
        cursos[i]=buffCurso[i];
    }
    cursos[numDatos]=nullptr;
    return cursos;
}

void cargarAlumnos(int *&codigos,char **&nombres,char ***&cursos){
    int buffCodigos[200],numDatos=0;
    char *nombre,**cur;
    char *buffNombres[200],**buffCursos[200];
    ifstream arch("Alumnos-Cursos.csv",ios::in);
    if(!arch){
        cout<<"Error, no se pudo abrir el archivo Alumnos-Cursos.csv"<<endl;
        exit(1);
    }
    int cod;
    while(1){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        buffCodigos[numDatos]=cod;
        buffNombres[numDatos]=leeCadena(arch);
        buffCursos[numDatos]=leeCurso(arch);
        numDatos++;
    }
    codigos = new int[numDatos+1];
    nombres = new char*[numDatos+1];
    cursos = new char**[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        codigos[i]=buffCodigos[i];
        nombres[i]=buffNombres[i];
        cursos[i]=buffCursos[i];
    }
    
    codigos[numDatos]=0;
    nombres[numDatos]=nullptr;
    cursos[numDatos]=nullptr;
    numDatos++;
}

void imprimirCursos(char **cursos){
    for(int i=0;cursos[i];i++){
        cout<<right<<setw(20)<<cursos[i]<<endl;
    }
}

void reporteDeAlumnos(int *codigos,char **nombres,char ***cursos){
    for(int i=0;codigos[i];i++){
        cout<<right<<setw(10)<<codigos[i]<<"  "<<left<<setw(45)<<
                nombres[i]<<endl;
        imprimirCursos(cursos[i]);
    }
}
