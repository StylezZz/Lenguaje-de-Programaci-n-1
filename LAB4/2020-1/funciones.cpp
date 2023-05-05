/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "funciones.h"
using namespace std;

/*
 char **nombres,***cursos;
 int *codigos;
 */

char *leerCadena(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void leerAlumnos(int *&codigos,char **&nombres,char ***&cursos){
    ifstream arch("Alumnos.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    char tipo,*bufferNombre[200],*nombre,limpiar[200];
    int codigoAlumno,arrCodigos[200],numDatos=0;
    
    while(1){
        arch>>tipo;
        if(arch.eof())break;
        arch.get();//coma
        arch>>codigoAlumno;
        arch.get();//coma
        nombre = leerCadena(arch);
        arch.getline(limpiar,200);
        arrCodigos[numDatos]=codigoAlumno;
        bufferNombre[numDatos]= nombre;
        numDatos++;
    }
    codigos = new int[numDatos+1];
    nombres = new char*[numDatos+1];
    cursos = new char**[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        codigos[i]=arrCodigos[i];
        nombres[i]=bufferNombre[i];
    }
    codigos[numDatos]=0;
    nombres[numDatos]=nullptr;
}

void imprimirAlumnos(int *codigos,char **nombres){
    ofstream arch("ReporteAlumnos.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteAlumnos.txt"<<endl;
        exit(1);
    }
    arch<<"Reporte de Alumnos"<<endl;
    for(int a=0;a<100;a++)arch<<'=';
    arch<<endl;
    for(int i=0;codigos[i];i++){
        arch<<setw(15)<<right<<codigos[i]<<
                setw(40)<<right<<nombres[i]<<endl;
    }

}
//20110165
int buscarAlumno(int *codigos,int codBus){
    for(int i=0;codigos[i];i++){
        if(codBus==codigos[i]){
            return i;
        }
    }
    return -1;
}

void agregarCurso(char **&cursos,int &num,char *codigoCurso){
    cursos[num]=codigoCurso;
    num++;
}

void espacios(char **&cursos,int num){
    char **buffAux;
    int i;
    //No se habia inicializado el puntero como vacio XD pipipipipipipi
    buffAux = new char*[num+1]{};
    for(i=0;i<num;i++){
        buffAux[i]=cursos[i];
    }
    delete cursos;
    cursos = buffAux;
}

void leerCursos(int *codigos,char ***&cursos){
    ifstream arch("Cursos.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Cursos.csv"<<endl;
        exit(1);
    }
    int i,codArch,nota,year,pos,ti;
    char **bufferCursos[200],*codCurso,chi,limpiar[200];
    for(i=0;codigos[i];i++)cursos[i]= new char*[50]{};
    int numDatos[i+1]={};
    while(1){
        arch>>codArch;
        if(arch.eof())break;
        arch.get();
        codCurso=leerCadena(arch);
        arch>>nota>>chi;
        arch>>year;
        year*=1000;
        if(nota>=11 and codArch>=year){
            pos = buscarAlumno(codigos,codArch);
            agregarCurso(cursos[pos],numDatos[pos],codCurso);
            
        }
        arch.getline(limpiar,200);
    }
    for(int j=0;codigos[j];j++){
        espacios(cursos[j],numDatos[j]);
    }
}
void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

void imprimirReporte(int *codigos,char **nombres,char ***cursos){
    ofstream arch("ReporteFinal.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    for(int i=0;codigos[i];i++){
        arch<<"Código: "<<setw(20)<<right<<codigos[i]<<" Nombre: "<<setw(30)<<right
                <<nombres[i]<<endl;
        imprimeLinea(arch,100,'-');
        imprimeCursos(cursos[i],arch);
        imprimirLinea(arch,100,'-');
    }
}

void imprimeCursos(char **cursos,ofstream &arch){
    int i;
    arch<<setw(15)<<left<<"Cursos aprobados: ";
    for(i=0;cursos[i]!=nullptr;i++){
        arch<<setw(10)<<left<<cursos[i];
    }
    if(i==0)arch<<"El alumno no tiene cursos aprobados registrados";
    arch<<endl;
}