/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: alulab14
 * 
 * Created on 5 de mayo de 2023, 08:07 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MetodoDinamicoExacto.h"


void lecturaAlumnos(const char*nombreArch,int*&alumno_Codigo,char**&alumno_Nombre,char*&alumno_Modalidad,int*&alumno_Porcentaje,int*&alumno_Escala){
    ifstream arch(nombreArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    int buffCodigo[100],buffProcentaje[100],buffEscala[100],pos=0,codigo,escala,porcentaje;
    char*buffNombre[100],buffModalidad[100],nombre[200],*auxNombre,aux;
    while(1){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();//coma
        buffNombre[pos]=leeCadena(arch);
        arch>>escala;
        aux='P';
        porcentaje=100;
        if(arch.fail()){
            arch.clear();
            arch>>aux;
            arch.get();//coma
            if(aux=='S'){
                arch>>porcentaje;
                arch.get();//coma
            }
            arch>>escala;
        }
        buffCodigo[pos]=codigo;
        buffEscala[pos]=escala;
        buffModalidad[pos]=aux;
        buffProcentaje[pos]=porcentaje;
        pos++;
    }
    guardarDatosAlumno(alumno_Codigo,alumno_Nombre,alumno_Modalidad,alumno_Porcentaje,alumno_Escala,buffCodigo,buffEscala,buffModalidad,buffNombre,buffProcentaje,pos);
}


void pruebaLecturaAlumnos(const char*nombreArch,int*alumno_Codigo,char**alumno_Nombre,char*alumno_Modalidad,int*alumno_Porcentaje,int*alumno_Escala){
    ofstream arch(nombreArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    for(int i=0;alumno_Codigo[i]!=0;i++){
        arch<<left<<setw(12)<<alumno_Codigo[i]<<setw(40)<<alumno_Nombre[i]<<setw(12)<<alumno_Modalidad[i]<<setw(12)<<alumno_Porcentaje[i]<<setw(12)<<alumno_Escala[i]<<endl;
    }
}
void lecturaCursos(const char*nombreArch,int*alumno_Codigo,int*alumno_Escala,char**&curso_Nombre,double*&curso_Credito,int**&curso_Alumnos){
    ifstream arch(nombreArch,ios::in);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    int codigo,*buffCursosAlumnos[200],cant_cursos=0,posicion,cantAlumnos[200]={};
    char curso[200],*buffCursos[200],*auxCurso;
    double buffCreditos[200],creditos;
    while(true){
        arch>>codigo;
        if(arch.eof())break;
        arch.get();
        arch.getline(curso,200,',');
        arch>>creditos;
        posicion=se_encuentra_curso(curso,buffCursos,cant_cursos);
        if(posicion==-1){
            auxCurso=cadenaExacta(curso);
            buffCursos[cant_cursos]=auxCurso;
            buffCreditos[cant_cursos]=creditos;
            buffCursosAlumnos[cant_cursos]=new int[200]{};//son 100 alumnos base
            cant_cursos++;
        }
        insertarAlumno(codigo,alumno_Codigo,alumno_Escala,curso,buffCursos,buffCursosAlumnos,cantAlumnos);
    }
    curso_Nombre=new char*[cant_cursos+1];
    curso_Credito=new double[cant_cursos+1];
    curso_Alumnos=new int*[cant_cursos+1];
    for(int i=0;i<cant_cursos;i++){
        curso_Nombre[i]=buffCursos[i];
        curso_Credito[i]=buffCreditos[i];
        curso_Alumnos[i]=buffCursosAlumnos[i];
    }
    curso_Nombre[cant_cursos]=nullptr;
    recortarAlumnos(cant_cursos,curso_Alumnos,cantAlumnos);
}
void pruebaDeLecturaCursos(const char*nombreArch,char**curso_Nombre,double*curso_Credito,int**curso_Alumnos){
    ofstream arch(nombreArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    for(int i=0;curso_Nombre[i]!=nullptr;i++){
        arch<<left<<setw(30)<<curso_Nombre[i]<<right<<setw(10)<<curso_Credito[i]<<endl;
        for(int j=0;curso_Alumnos[i][j]!=0;j+=2)
            arch<<right<<setw(15)<<curso_Alumnos[i][j]<<'-'<<curso_Alumnos[i][j+1]<<endl;
    }
}
void reporteDeRecaudacionPorModalidad(const char*nombreArch,int*alumno_Codigo,char*alumno_Modalidad,int*alumno_Porcentaje,char**alumno_Nombre,char**curso_Nombre,double*curso_Credito,int**curso_Alumnos){
    ofstream arch(nombreArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error al abrir el archivo "<<nombreArch<<endl;
        exit(1);
    }
    arch<<"ENTIDAD EDUCATIVA LP1"<<endl<<"LISTADOS DE CLASE"<<endl;
    imprimir_linea('=',arch);
    for(int i=0;curso_Nombre[i]!=nullptr;i++){
        arch<<i+1<<')'<<left<<"Cursos:"<<setw(30)<<curso_Nombre[i]<<right<<setw(10)<<"Creditos:"<<curso_Credito[i]<<endl;
        imprimir_linea('-',arch);
        arch<<"ALUMNOS Matriculados"<<endl;
        imprimir_linea('-',arch);
        arch<<setw(70)<<"PAGOS"<<endl<<setw(12)<<"CODIGO"<<setw(30)<<"NOMBRE"<<setw(10)<<"ESCALA"<<setw(15)<<"PRESENCIAL"<<setw(15)<<"SEMI PRESENCIAL"<<setw(12)<<"VIRTUAL"<<endl;
        imprimir_linea('-',arch);
        for(int j=0;curso_Alumnos[i][j]!=0;j+=2){
            arch<<right<<setw(2)<<j+1<<')'<<setw(10)<<curso_Alumnos[i][j]<<"   ";
            int pos=se_encuentra_alumno(curso_Alumnos[i][j],alumno_Codigo);
            arch<<left<<setw(40)<<alumno_Nombre[pos]<<setw(10)<<curso_Alumnos[i][j+1];
            arch<<endl;
        }
    }
}
char*leeCadena(ifstream&arch){
    char*cad,buff[200];
    arch.getline(buff,200,',');
    cad=new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}
int se_encuentra_curso(char*curso,char**buffCursos,int limite){
   for(int i=0;i<limite;i++){
       if(strcmp(curso,buffCursos[i])==0)return i;
   }
   return -1;
}
void insertarAlumno(int codigo,int*alumno_Codigo,int*alumno_Escala,char*curso,char**buffCursos,int**buffCursosAlumnos,int*cantAlumnos){
    int pos_alumno=se_encuentra_alumno(codigo,alumno_Codigo);
    int pos_curso=se_encuentra_curso(curso,buffCursos,200);
    int i,*ptrCurso;
    ptrCurso=buffCursosAlumnos[pos_curso];
    for(i=0;ptrCurso[i]!=0;i++);
    ptrCurso[i]=codigo;
    ptrCurso[i+1]=alumno_Escala[pos_alumno];
    ptrCurso[i+2]=0;
    cantAlumnos[pos_curso]++;
}
int se_encuentra_alumno(int codigo,int*alumno_Codigo){
    for(int i=0;alumno_Codigo[i];i++){
        if(alumno_Codigo[i]==codigo)return i;
    }
    return -1;
}
char*cadenaExacta(char*cad){
    char*aux;
    aux=new char[strlen(cad)+1];
    strcpy(aux,cad);
    return aux;
}
void guardarDatosAlumno(int*&alumno_Codigo,char**&alumno_Nombre,char*&alumno_Modalidad,int*&alumno_Porcentaje,int*&alumno_Escala,int*buffCodigo,int*buffEscala,char*buffModalidad,char**buffNombre,int*buffProcentaje,int cant_alumnos){
    int pos=cant_alumnos;
    alumno_Codigo=new int[pos+1];
    alumno_Nombre=new char*[pos+1];
    alumno_Modalidad=new char[pos+1];
    alumno_Porcentaje=new int[pos+1];
    alumno_Escala=new int[pos+1];
    for(int i=0;i<pos;i++){
        alumno_Codigo[i]=buffCodigo[i];
        alumno_Nombre[i]=buffNombre[i];
        alumno_Modalidad[i]=buffModalidad[i];
        alumno_Porcentaje[i]=buffProcentaje[i];
        alumno_Escala[i]=buffEscala[i];        
    }
    alumno_Codigo[pos]=0;    
}
void recortarAlumnos(int cant_cursos,int**curso_Alumnos,int*cantAlumnos){
    int*ptrCurso,*aux;
    for(int i=0;i<cant_cursos;i++){
        aux=new int[cantAlumnos[i]*2+1];
        aux[cantAlumnos[i]*2]=0;
        ptrCurso=curso_Alumnos[i];
        for(int j=0;j<cantAlumnos[i]*2;j++){
            aux[j]=ptrCurso[j];
        }
        curso_Alumnos[i]=aux;
        delete ptrCurso;
    }
}
void imprimir_linea(char c,ofstream&arch){
    for(int i=0;i<120;i++)arch<<c;
    arch<<endl;
}