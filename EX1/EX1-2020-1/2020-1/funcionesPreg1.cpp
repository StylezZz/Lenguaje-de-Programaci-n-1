/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
#include "funcionesPreg1.h"
using namespace std; 

//char ***cursos,**profesores;
//    int *codProfesores;
    
void leerDatos(char ***&cursos,int *&codProfesores,char **&profesores){
    ifstream archCursos("Cursos.csv",ios::in);
    if(!archCursos){
        cout<<"Error no se pudo abrir el archivo Cursos.csv"<<endl;
        exit(1);
    }
    ifstream archProf("Profesores.csv",ios::in);
    if(!archCursos){
        cout<<"Error no se pudo abrir el archivo Profesores.csv"<<endl;
        exit(1);
    }
    
    //Inicializamos los punteros
    cursos = nullptr;
    codProfesores = nullptr;
    profesores = nullptr;
    
    //Variables para la lectura del archivo
    char *codCurso,*nombCurso,*facu;
    int numCur=0,capCur=0;
    while(1){
        codCurso = leerCadena(archCursos);
        if(archCursos.eof())break;
        nombCurso = leerCadena(archCursos);
        facu = leerCadenaFin(archCursos);
        if(numCur==capCur){
            incrementarEspacios(cursos,numCur,capCur);
        }
        cursos[numCur]=nullptr;
        char **auxDatoCur;
        auxDatoCur = new char*[3];
        auxDatoCur[0]=codCurso;
        auxDatoCur[1]=nombCurso;
        auxDatoCur[2]=facu;
        cursos[numCur-1]=auxDatoCur;
        
        numCur++;
    }
    
//    cout<<"Termine de leer los cursos"<<endl;
    
    //Lectura de los profesores
    int codProfe,numProf=0,capProf=0;
    char *nombreProfe,c;
    while(1){
        archProf>>codProfe>>c; 
        if(archProf.eof())break;
        nombreProfe = leerCadenaFin(archProf);
        if(numProf==capProf){
            incrementarEspacios2(codProfesores,profesores,numProf,capProf);
        }
        codProfesores[numProf]=0;
        codProfesores[numProf-1]=codProfe;
        profesores[numProf]=nullptr;
        profesores[numProf-1]=nombreProfe;
        numProf++;
    }
//    cout<<"Termine de leer a los profesores"<<endl;
}

void incrementarEspacios2(int *&codProfesores,char **&profesores,int &numDat,int &cap){
    cap+=INCREMENTO;
    char **auxP;
    int *auxCP;
    if(codProfesores==nullptr){
        codProfesores = new int[cap];
        profesores = new char*[cap];
        codProfesores[0]=0;
        profesores[0]=nullptr;
        numDat=1;
    }else{
        auxCP = new int[cap];
        auxP = new char*[cap];
        for(int i=0;i<numDat;i++){
            auxP[i]=profesores[i];
            auxCP[i]=codProfesores[i];
        }
        delete profesores;
        delete codProfesores;
        profesores = auxP;
        codProfesores = auxCP;
    }
}

void incrementarEspacios(char ***&cursos,int &numCur,int &cap){
    cap+=INCREMENTO;
    char ***auxCur;
    
    if(cursos==nullptr){
        cursos = new char**[cap];
        cursos[0]=nullptr;
        numCur=1;
    }else{
        auxCur = new char**[cap];
        for(int i=0;i<numCur;i++){
            auxCur[i]=cursos[i];
        }
        delete cursos;
        cursos = auxCur;
    }
}

char *leerCadenaFin(ifstream &arch){
    char *cad,buff[200];
    arch.getline(buff,200,'\n');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char *leerCadena(ifstream &arch){
    char *cad,buff[200];
    arch.getline(buff,200,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimirDatos(char ***cursos,int *codProfesores,char **profesores){
    ofstream arch("ReporteCursosProfesores.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteCursosProfesores.txt"<<endl;
        exit(1);
    }
    
    arch<<setw(40)<<right<<"CURSOS DE LA INSTITUCION"<<endl;
    arch<<setw(13)<<right<<"CODIGO"<<setw(15)<<right<<"CURSO"<<setw(50)<<right<<"ESPECIALIDAD"<<endl;
    for(int i=0;cursos[i];i++){
        arch<<setw(2)<<right<<i+1<<")"<<setw(10)<<right<<cursos[i][0]<<"    "<<
                setw(40)<<left<<cursos[i][1]<<"   "<<setw(50)<<left<<cursos[i][2]<<endl;
    }
    arch<<endl;
    arch<<setw(40)<<right<<"PROFESORES DE LA INSTITUCION"<<endl;
    arch<<setw(12)<<right<<"CODIGO"<<setw(15)<<right<<"NOMBRE"<<endl;
    for(int i=0;codProfesores[i];i++){
        arch<<setw(2)<<right<<i+1<<")"<<setw(10)<<right<<codProfesores[i]<<setw(8)<<"   "
                <<left<<profesores[i]<<endl;
    }
    
}
