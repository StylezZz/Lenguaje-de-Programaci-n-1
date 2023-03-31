/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "funciones.h"
#define MAXLINEAS 120
using namespace std;

//codigo año nombre/apellido/.. codigoCurso numCreditos notaObtenida fechaUltEva
void imprimirResumen(int cantCursos,double cantCreditosAprobados,double cantCreditosDesaprobados,
                    double cantCreditos,int sumaNotas,int sumaNotasApro,
        int cantCursosError){
    double porcentaje = (cantCreditosAprobados/cantCursos)*100;
    double promedio = sumaNotas/cantCursos;
    double promedioAprobados = sumaNotasApro / cantCursos;
    imprimirLineas('=');
    cout<<"     "<<"RESUMEN:"<<endl;
    cout<<"     "<<setw(15)<<"Cursos matriculados: "<<cantCursos;
    cout<<setw(10)<<"                 Total de creditos: "<<cantCreditos<<endl;
    cout<<"     "<<setw(15)<<"Creditos aprobados: "<<cantCreditosAprobados;
    cout<<setw(10)<<"                 Creditos desaprobados: "<<cantCreditosDesaprobados<<endl;
    cout<<"     "<<setw(15)<<"Creditos aprobados/matriculados: "<<porcentaje<<"%"<<endl;
    imprimirLineas('-');
    cout<<"     "<<"Promedio general: "<<setw(20)<<promedio<<endl;
    cout<<"     "<<"Promedio general de aprobados"<<setw(20)<<promedioAprobados<<endl;
    imprimirLineas('-');
    cout<<"     "<<"Cursos con error no considerados: "<<cantCursosError<<endl;
    imprimirLineas('=');
    cout<<endl;
    imprimirLineas('=');
    
}



void sacarFecha(int &dia,int &mes,int &anio,int fecha){
    dia = fecha%100;
    fecha/=100;
    mes = fecha%100;
    fecha/=100;
    anio= fecha;
}

void imprimoCurso(int pos,char *codCurso,double cantCreditos,int nota,int fechaUltEva,
        int yearIngreso,int falla){
    int dd,mm,aa;
    sacarFecha(dd,mm,aa,fechaUltEva);
    cout.fill('0');
    cout<<pos;
    cout.fill(' ');
    if(nota>=11){
        //Aprobo el curso
        cout<<"  "<<codCurso<<"    "<<cantCreditos<<"         "<<nota;
        
        cout<<"     "<<setw(4)<<right<<aa;
        cout.fill('0');
        cout<<"/"<<setw(2)<<right<<mm<<"/"<<setw(2)<<
                right<<dd;
        cout.fill(' ');
        if(yearIngreso>aa){
            cout<<setw(40)<<"ERROR FECHA";
            falla = 1;
        }
        cout<<endl;
    }else{
        //Desaprobo el curso
        cout<<"                                                  "
                <<codCurso<<
                "    "<<cantCreditos<<"     "<<nota;
        cout.fill('0');
        cout<<"     "<<setw(4)<<right<<aa<<"/"<<setw(2)<<right<<mm<<"/"<<setw(2)<<
                right<<dd;
        cout.fill(' ');
        if(yearIngreso>aa){
            cout<<setw(20)<<"ERROR FECHA";
            falla=1;
        }
        cout<<endl;
    }
}

void leerCurso(char *codCurso,double &cantCreditos,int &nota,int &fechaUltEva){
    int dd,mm,aa;
    char c;
    cin>>codCurso>>cantCreditos>>nota>>dd>>c>>mm>>c>>aa;
    fechaUltEva = dd + mm*100 + aa*10000;
    
}

void imprimirSegundaCabecera(){
    cout<<setw(20)<<"CURSOS APROBADOS"<<setw(50)<<"CURSOS DESAPROBADOS";
    cout<<setw(40)<<"OBSERVACION"<<endl;
    cout<<"No.  CODIGO    CREDITOS   NOTA   FECHA";
    cout<<setw(45)<<"CODIGO    CREDITOS   NOTA   FECHA"<<endl;
    imprimirLineas('-');
}

void formatearNombre(char *nombre){
    int i=0;
    while(nombre[i]!=' '){
        if(nombre[i]=='/' or nombre[i]=='-'){
            nombre[i]=' ';
        }
        i++;
    }
}

void imprimirCabeceraAlumno(char *nombreAlumno,int codigoAlum,int yearIngreso){
    formatearNombre(nombreAlumno);
    cout<<setw(10)<<"Alumno: "<<nombreAlumno;
    cout<<"                 "<<setw(20)<<"Codigo: "<<yearIngreso<<" - ";
    cout.fill('0');
    cout<<setw(6)<<codigoAlum<<endl;
    cout.fill(' ');
    imprimirLineas('-');
    imprimirSegundaCabecera();
}

void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++){
        cout<<c;
    }
    cout<<endl;
}

void imprimirCabecera(){
    cout<<setw(70)<<"INFORMACION ACADEMICA DE LOS ESTUDIANTES"<<endl;
    imprimirLineas('=');
}

