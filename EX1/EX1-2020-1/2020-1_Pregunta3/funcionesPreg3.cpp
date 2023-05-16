/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesPreg1.h"
#include "funcionesPreg2.h"
#include "funcionesPreg3.h"
using namespace std;
enum reg{CURSO,HORARIO,CANTALUMNOS,PROFESOR,SESIONES};
//char ***cursos,**profesores;
//    int *codProfesores;
//    void *sesiones;
void reporteCargaHorariaDeProf(char ***cursos,int *codProfesores,
        char **profesores,void *sesiones){
    ofstream arch("ReporteCargaHorarioDeProfesor.txt",ios::out);
    void **auxSesion =(void**)sesiones;
    arch<<setw(40)<<right<<"CARGA HORARIA DE PROFESORES"<<endl;
    for(int i=0;codProfesores[i];i++){
        cout<<i<<endl;
        encabezadoProfesor(codProfesores[i],profesores[i],arch);
        for(int j=0;auxSesion[j];j++){
            imprimirSesiones(codProfesores[i],auxSesion[j],cursos,arch,i);
        }
        arch<<endl;
    }
}

//enum reg{CURSO,HORARIO,CANTALUMNOS,PROFESOR,SESIONES};
void imprimirSesiones(int codProfe,void *sesion, char ***cursos,ofstream &arch,
        int posI){
    void **auxS = (void**)sesion;
    char *ptrCodCurso = (char*)(auxS[CURSO]);
    char *horarioCurso = (char*)(auxS[HORARIO]);
    int *cantAlu = (int*)(auxS[CANTALUMNOS]);
    int *ptrCodProfe = (int*)(auxS[PROFESOR]);
    int *horas = (int*)(auxS[SESIONES]);
    
    if(codProfe== *ptrCodProfe){
        int pos = buscarCurso(ptrCodCurso,cursos);
        arch<<setw(2)<<pos+1<<") "
            <<left <<setw(40)<<cursos[pos][1]
            <<setw(15)<<ptrCodCurso
            <<cursos[pos][2]<<endl
            <<right<<setw(15)<<" Horario: "<<horarioCurso<<endl;
            imprimirHorasProfesor(horas,*cantAlu,arch);
        
    }
    
}

void imprimirHorasProfesor (int *horas, int numAl, ofstream &arch) {
    int totalHoras = 0;
    for (int i = 0; horas[i] != -1 ; i++) {
        arch << setw(6) << i+1 << ") ";
        formatoHorarioProfesor(horas[i],arch,totalHoras);       
    }
    arch << setw(5) << " " << "Horas dictadas: ";
    arch.fill('0');
    arch << setw(2) << totalHoras/60 << ':' << setw(2) << totalHoras%60 << endl;
    arch.fill(' ');
    arch << setw(5) << " " << "Matriculados: " << numAl << endl << endl;
}

void formatoHorarioProfesor (int datoNum, ofstream &arch, int &totalHoras) {
    int mf = datoNum%100;
    datoNum /= 100;
    int hf = datoNum%100;
    datoNum /= 100;
    int mi = datoNum%100;
    datoNum /= 100;
    int hi = datoNum%100;
    datoNum /= 100;
    int dia = datoNum;
    arch << left;
    if (dia == 1) arch << setw(10) << "Lunes";
    else if (dia == 2) arch << setw(10) << "Martes";
    else if (dia == 3) arch << setw(10) << "Miercoles";
    else if (dia == 4) arch << setw(10) << "Jueves";
    else if (dia == 5) arch << setw(10) << "Viernes";
    else if (dia == 6) arch << setw(10) << "Sabado";
    else arch << setw(10) << "Domingo";
    arch << right;
    arch.fill('0');
    arch << setw(2) << hi << ':' << setw(2) << mi;
    arch.fill(' '); 
    arch << setw(5) << " ";
    arch.fill('0');
    arch << setw(2) << hf << ':' << setw(2) << mf;
    arch.fill(' ');
    arch << endl;
    totalHoras += (hf*60+mf)-(hi*60+mi);
}


int buscarCurso(char *cadena,char ***cursos){
    for(int i=0;cursos[i];i++){
        if(strcmp(cadena,cursos[i][0])==0){
            return i;
        }
    }
}

void encabezadoProfesor(int numero,char *nombre,ofstream &arch){
    arch<<"Codigo: "<<numero<<setw(30)<<right<<"Nombre: "<<nombre<<endl;
    arch<<"Horarios asignados: "<<endl;
    arch<<"No."<<setw(10)<<right<<"Curso"<<setw(30)<<right<<"Codigo"<<setw(15)<<right<<"Especialidad"<<endl;
}