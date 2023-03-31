/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>

#include "funciones.h"
#define MAXLINEAS 100
using namespace std;

// dd/mm/aa dd/mm/aa dd/mm/aa
// codigo letra nombre codLibro ddR/mmR/aaR precioLibro y así 

void imprimirCabeceraUsuario(){
    imprimirLineas('-');
    cout<<setw(20)<<"USUARIO"<<setw(40)<<"LIBROS PRESTADOS"<<endl;
    imprimirLineas('-');
    cout<<"Carne No."<<setw(15)<<"Nombre"<<setw(40)<<"Tipo"<<setw(20)<<"Codigo";
    cout<<setw(10)<<
}


void imprimirLibro(int carnet,char *nombrePersona,char tipoUsuario,
                    char *codLibro,int fechaRetiro,int fechaAdm,int fechaDoc,
                    int fechaEst){
    imprimirCabeceraUsuario();
}

void leerLibro(char *codLibro,int &fechaRetiro,double &precioLibro){
   int dd,mm,aa;
   char c;
   cin>>codLibro>>dd>>c>>mm>>c>>aa>>precioLibro;
   fechaRetiro = dd + mm*100 + aa*10000;
}

void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++){
        cout<<c;
    }
    cout<<endl;
}

void sacarFecha(int &dd,int &mm,int &aa,int fecha){
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    fecha/=100;
    aa=fecha;
}

void imprimirFechas(int fechaAdm,int fechaDoc,int fechaEst){
    int dd,mm,aa;
    sacarFecha(dd,mm,aa,fechaDoc);
    cout<<setw(20)<<"Docentes: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<endl;
    cout.fill(' ');
    
    sacarFecha(dd,mm,aa,fechaEst);
    cout<<setw(20)<<"Estudiante: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<endl;
    cout.fill(' ');
    
    sacarFecha(dd,mm,aa,fechaAdm);
    cout<<setw(20)<<"Administrativo: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<endl;
    cout.fill(' ');
}

void imprimirPrimerEncabezado(int fechaAdm,int fechaDoc,int fechaEst){
    cout<<setw(50)<<"BIBLIOTECA GENERAL DE LA UNIVERSIDAD"<<endl;
    imprimirLineas('=');
    cout<<"Fechas limites de devolucion:"<<endl;
    imprimirFechas(fechaAdm,fechaDoc,fechaEst);
}

void leerFecha(int &fecha){
    char c;
    int dd,mm,aa;
    cin>>dd>>c>>mm>>c>>aa;
    fecha = dd + mm*100 + aa*10000;
}

void leerFechas(int &fechaAdm,int &fechaDoc,int &fechaEst){
    leerFecha(fechaAdm);
    leerFecha(fechaDoc);
    leerFecha(fechaEst);
}
