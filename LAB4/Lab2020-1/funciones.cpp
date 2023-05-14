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

void limpiaCadena(ifstream &arch){
    char buff[50];
    arch.getline(buff,50);
}

char * leerCadena(ifstream &arch,char c){
    char buffer[200],*cadena;
    int numDat=0;
    arch.getline(buffer,200,c);
    cadena = new char [strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
//tipoAlumno -> R: Regular  I: Intercambio
//codigo -> numero
//nombreAlumno -> char[]
//especialidad
//facultad
void leerAlumnos(int *&codigos,char **&nombres,char ***&cursos){
    ifstream archAlumnos("Alumnos.csv",ios::in);
    if(!archAlumnos){
        cout<<"ERROR no se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    //Declaración de variables
    char *bufferNombre[200],**bufferCurso[200],miniBuffer[100];
    int arrCodigos[100],numDatos=0,cod;
    char tipo;
    while(1){
        archAlumnos>>tipo;
        if(archAlumnos.eof())break;
        archAlumnos.get();
        archAlumnos>>cod;
        arrCodigos[numDatos]=cod;
        archAlumnos.get();
        bufferNombre[numDatos] = leerCadena(archAlumnos,',');
        archAlumnos.getline(miniBuffer,100);
        numDatos++;
    }
    codigos = new int[numDatos];
    nombres = new char*[numDatos];
    cursos = new char**[numDatos];
    
    for(int i=0;i<numDatos;i++){
        codigos[i]=arrCodigos[i];
        nombres[i]=bufferNombre[i];
    }
    codigos[numDatos]=0;
    nombres[numDatos]=nullptr;
    cursos[numDatos]=nullptr;
}

void formatearNombre(char *nombre){
    //Buscar el ultimo /
    int ultimoSlash=0;
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='/'){
            ultimoSlash = i;
        }
    }
    //Iteramos
    for(int j=0;nombre[j];j++){
        if(nombre[j]=='/' and j==ultimoSlash){
            nombre[j]=',';
        }
        if(nombre[j]=='/' or nombre[j]=='-'){
            nombre[j]=' ';
        }
    }
}

void imprimirAlumnos(int *codigos,char **nombres){
    ofstream arch("Reporte-1.txt",ios::out);
    if(!arch){
        cout<<"ERROR no se pudo abrir el archivo Reporte-1.txt"<<endl;
        exit(1);
    }
    arch<<left<<setw(15)<<"CODIGOS"<<setw(20)<<"NOMBRES"<<endl;
    for(int i=0;codigos[i];i++){
        arch<<left<<setw(15)<<codigos[i];
        formatearNombre(nombres[i]);
        arch<<setw(20)<<left<<nombres[i]<<endl;
    }
}

int buscarEntero(int codAlumno,int *codigo){
    int pos;
    for(int i=0;codigo[i];i++){
        if(codAlumno==codigo[i]){
            pos= i;
            return pos;
        }
    }
    return -1;
    
}

void agregarCurso(char **&cursos,char *codCurso,int &numDatos){
    cursos[numDatos]=codCurso;
    numDatos++;
}

void agregarDatos(char **&cursos,int num){
    char **buff;
    int i;
    buff = new char*[num+1]{};
    for(int i=0;i<num;i++){
        buff[i]=cursos[i];
    }
    delete cursos;
    cursos=buff;
}

void leerCursos(int *codigos,char ***&cursos){
    ifstream arch("Cursos.csv",ios::in);
    int auxCod,nota,pos,aa,i;
    char *codCur,c;
    //Se crea por cada alumno un arreglo de punteros char de 50 espacios
    //Que almacenarán las direcciones hacia los códigos de los cursos aprobados
    //Y se los inicializa en nullptr
    for(i=0;codigos[i];i++)cursos[i]= new char *[50]{};
    int numDat[i+1]={};
    while(1){
        arch>>auxCod;
        if(arch.eof())break;
        arch.get();
        codCur=leerCadena(arch,',');
        arch>>nota>>c;
        arch>>aa;
        aa*=1000;
        if(nota>=11&&auxCod>=aa){
            pos=buscarEntero(auxCod,codigos);
            agregarCurso(cursos[pos],codCur,numDat[pos]);
        }
        limpiaCadena(arch);
    }
    cout<<"uwu";
    for(int j=0;j<i;j++){
        agregarDatos(cursos[j],numDat[j]);
    }
    cout<<"llegue owo";
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<100;i++){
        arch<<c;
    }
    arch<<endl;
}

void imprimirReporte(int *codigos,char **nombres,char ***cursos){
    ofstream arch("ReporteAlumnos-Cursos.txt",ios::out);
    if(!arch){
        cout<<"No se pudo abrir el archivo ReporteAlumnos-Cursos.txt"<<endl;
        exit(1);
    }
    for(int i=0;codigos[i];i++){
        arch<<setw(20)<<left<<"Código:"<<setw(10)<<left<<codigos[i];
        arch<<setw(10)<<left<<"Nombre:"<<setw(30)<<left<<nombres[i]<<endl;
        imprimirLineas(arch,'-');
        imprimeCursos(cursos[i],arch);
        arch<<endl;
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