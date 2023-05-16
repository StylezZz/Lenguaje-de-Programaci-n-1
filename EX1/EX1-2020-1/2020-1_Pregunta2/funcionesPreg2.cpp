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
using namespace std;
enum reg{CURSO,HORARIO,CANTALUMNOS,PROFESOR,SESIONES};

void leerSesiones(void *&sesiones){
    ifstream arch("Sesiones.txt",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Sesiones.txt"<<endl;
        exit(1);
    }
    void **auxSesion,*var,*buffSesiones[200];
    int numDatos=0;
    while(1){
//        cout<<"Primer while"<<endl;
        var = leerSesion(arch);
        if(var==nullptr)break;
        buffSesiones[numDatos]=var;
        numDatos++;
    }
//    cout<<"Salgo del while"<<endl;
    buffSesiones[numDatos]=nullptr;
    numDatos++;
    auxSesion = new void*[numDatos+1];
    for(int i=0;i<numDatos;i++){
        auxSesion[i]=buffSesiones[i];
    }
    sesiones = auxSesion;
}

void* leerSesion(ifstream &arch){
    
    char *codCursoEx,*horarioCursoEx,codCurso[10],horarioCurso[10];
    int cantAlum,*ptrCantAlum,codProfe,*ptrCodProfe;
    int *horas;
    ptrCantAlum = new int;
    ptrCodProfe = new int;
    
    arch>>codCurso;
    if(arch.eof())return nullptr;
    arch>>horarioCurso;
    codCursoEx = asignarCadenaExacta(codCurso);
    horarioCursoEx = asignarCadenaExacta(horarioCurso);
    arch>>cantAlum>>codProfe;
//    cout<<codCursoEx<<" "<<horarioCursoEx<<" "<<cantAlum<<" "<<codProfe<<endl;
    horas = obtenerSesiones(arch);
    
    *ptrCantAlum = cantAlum;
    *ptrCodProfe = codProfe;
    
    void **sesiones;
    sesiones = new void*[5];
    sesiones[CURSO]= codCursoEx;
    sesiones[HORARIO]=horarioCursoEx;
    sesiones[CANTALUMNOS]= ptrCantAlum;
    sesiones[PROFESOR]=ptrCodProfe;
    sesiones[SESIONES]=horas;
    return sesiones;
}

char *asignarCadenaExacta(char *cadena){
    char *cad;
    cad = new char[strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}

int *obtenerSesiones(ifstream &arch){
    int *ptr;
    int numDatos=0,dia,hi,mi,hf,mf;
    char c;
    int buff[200];
    while(1){
        arch>>dia>>hi>>c>>mi>>hf>>c>>mf;
        buff[numDatos]= mf + hf*100+mi*10000+hi*1000000+dia*100000000;
        numDatos++;
        if(arch.get()=='\n')break;
    }
    buff[numDatos]=-1;
    numDatos++;
    ptr = new int[numDatos+1];
    for(int i=0;i<numDatos;i++){
        ptr[i]=buff[i];
    }
    return ptr;
}


void imprimirSesiones(void *sesiones){
    ofstream arch("ReporteSesiones.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteSesiones.txt"<<endl;
        exit(1);
    }
    void **auxSesiones = (void**)sesiones;
    arch<<setw(40)<<right<<"SESIONES DE CLASE"<<endl;
    for(int i=0;auxSesiones[i];i++){
        imprimirSesion(auxSesiones[i],i+1,arch);
    }
}
//enum reg{CURSO,HORARIO,CANTALUMNOS,PROFESOR,SESIONES};

void imprimirSesion(void *sesion,int num,ofstream &arch){
    void **aux = (void **)sesion;
    char *codCurso = (char*)(aux[CURSO]);
    char *horarioCurso = (char*)(aux[HORARIO]);
    int *cantAlumnos = (int*)(aux[CANTALUMNOS]);
    int *codProfe = (int*)(aux[PROFESOR]);
    int *horas = (int*)(aux[SESIONES]);
    
    arch<<num<<")"<<"  CODIGO"<<"  "<<codCurso<<setw(10)<<right<<" HORARIO: "<<
            " "<<horarioCurso<<setw(10)<<right<<"  No.ALUMNOS: "<<*cantAlumnos<<
            setw(10)<<right<<"  PROFESOR: "<<*codProfe<<endl;
    arch<<"    SESIONES"<<endl;
    imprimirHoras(horas,arch);
    arch<<endl;
}

void imprimirHoras(int *horas,ofstream &arch){
    for(int i=0;horas[i]!=-1;i++){
        formatoHorario(horas[i],arch);
    }
}

void formatoHorario(int datoNum,ofstream &arch){
    int mf = datoNum%100;
    datoNum /= 100;
    int hf = datoNum%100;
    datoNum /= 100;
    int mi = datoNum%100;
    datoNum /= 100;
    int hi = datoNum%100;
    datoNum /= 100;
    int dia = datoNum;
    arch << setw(10) << "DIA: " << left;
    if (dia == 1) arch << setw(10) << "LUNES";
    else if (dia == 2) arch << setw(10) << "MARTES";
    else if (dia == 3) arch << setw(10) << "MIERCOLES";
    else if (dia == 4) arch << setw(10) << "JUEVES";
    else if (dia == 5) arch << setw(10) << "VIERNES";
    else if (dia == 6) arch << setw(10) << "SABADO";
    else arch << setw(10) << "DOMINGO";
    arch << right << setw(20) << "INICIO: ";
    arch.fill('0');
    arch << setw(2) << hi << ':' << setw(2) << mi;
    arch.fill(' ');
    arch << setw(15) << "FIN: ";
    arch.fill('0');
    arch << setw(2) << hf << ':' << setw(2) << mf;
    arch.fill(' ');
    arch << endl;
}