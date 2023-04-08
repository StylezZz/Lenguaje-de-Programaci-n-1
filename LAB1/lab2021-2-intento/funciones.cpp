/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <valarray>
#include "funciones.h"
#define MAXLINEAS 120
using namespace std;


void imprimirResumen(int cantLibros,double sumaDeudas){
    imprimirLineas('=');
    cout<<setw(15)<<"Cantidad de libros adeudados: ";
    cout<<setw(10)<<cantLibros<<endl;
    cout<<setw(15)<<"Total de deudas por multa: "<<setw(10)<<sumaDeudas<<endl;
    imprimirLineas('=');
}

void imprimirCurso(char *codLibro,int fechaRetiro,double deudaxLibro,int primero){
    int dd,mm,aa;
    sacarFecha(dd,mm,aa,fechaRetiro);
    cout<<setprecision(2)<<fixed;
    if(primero==1){
        cout<<setw(25)<<codLibro;
        cout<<"       ";
        cout.fill('0');
        cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm
                <<"/"<<setw(4)<<right<<aa;
        cout.fill(' ');
        if(deudaxLibro!=0){
            //Si hay deuda
            cout<<setw(21)<<"     EN DEUDA"<<endl;
            cout<<setw(121)<<"Multa: $"<<deudaxLibro<<endl;
        }else{
            cout<<"---"<<endl;
        }
    }else{
        cout<<setw(83)<<codLibro;
        cout<<"       ";
        cout.fill('0');
        cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm
                <<"/"<<setw(4)<<right<<aa;
        cout.fill(' ');
        if(deudaxLibro!=0){
            //Si hay deuda
            cout<<setw(21)<<"EN DEUDA"<<endl;
            cout<<setw(121)<<"Multa: $"<<deudaxLibro<<endl;
        }else{
            cout<<"---"<<endl;
        }
    }
}

void mostrarSubtitulos(){
    cout<<setw(20)<<"USUARIO"<<setw(50)<<"LIBROS PRESTADOS"<<endl;
    imprimirLineas('-');
    cout<<"Carne No."<<setw(11)<<"Nombre"<<setw(32)<<"Tipo"<<setw(30)
            <<"Codigo"<<setw(20)<<"F. de retiro"<<setw(20)<<"Observacion"<<endl;
    imprimirLineas('-');    
}

void imprimirSegundoEncabezado(int numCarnet,char tipo,char *nombre){
    mostrarSubtitulos();
    cout<<numCarnet<<setw(30)<<nombre<<setw(20);
    if(tipo=='E'){
        cout<<"Estudiante"<<setw(20);
    }else if(tipo=='D'){
        cout<<"Docente"<<setw(20);
    }else if(tipo=='A'){
        cout<<"Administrativo"<<setw(20);
    }
}

void calcularDeuda(int fechaAdm,int fechaDoc,int fechaEst,int fechaRetiro,
                    char tipo,double &deuda,double precioLibro){
    if(((fechaAdm-fechaRetiro)<0) or
            ((fechaDoc-fechaRetiro)<0) or
            ((fechaEst-fechaRetiro))<0){
        //Significa que si hay deuda
        if(tipo=='E'){
            deuda = precioLibro*0.01;
        }else if(tipo=='D'){
            deuda = precioLibro*(2.25/100);
        }else if(tipo=='A'){
            deuda = precioLibro*(1.5/100);
        }
    }else{
        //No hay deuda
        deuda=0;
    }
}

void leeCurso(char *codLibro,int &fechaRetiro,double &precioLibro,
        double &deudaxLibro,char tipo,int fechaAdm,int fechaDoc,int fechaEst){
    char c;
    int dd,mm,aa;
    cin>>codLibro;
    cin>>dd>>c>>mm>>c>>aa>>precioLibro;
    fechaRetiro= dd + mm*100 + aa*10000;
    //Calcular la deuda
    calcularDeuda(fechaAdm,fechaDoc,fechaEst,fechaRetiro,tipo,deudaxLibro,precioLibro);
}


void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++)cout<<c;
    cout<<endl;
}

void sacarFecha(int &dd,int &mm,int &aa,int fecha){
    dd= fecha%100;
    fecha/=100;
    mm=fecha%100;
    fecha/=100;
    aa=fecha;
}

void imprimirCabeceraYFechas(int fechaDoc,int fechaEst,int fechaAdm){
    cout<<setw(50)<<"BIBLIOTECA GENERAL DE LA UNIVERSIDAD"<<endl;
    imprimirLineas('=');
    cout<<"Fechas limite de devolucion:"<<endl;
    int dd,mm,aa;
    //Sacar la fecha
    sacarFecha(dd,mm,aa,fechaDoc);
    cout<<"          "<<setw(30)<<left<<"Docentes: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<endl;
    cout.fill(' ');
    
    sacarFecha(dd,mm,aa,fechaEst);
    cout<<"          "<<setw(30)<<left<<"Estudiantes: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<endl;
    cout.fill(' ');
    
    sacarFecha(dd,mm,aa,fechaAdm);
    cout<<"          "<<setw(30)<<left<<"Administrativo: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<endl;
    cout.fill(' ');
    
    imprimirLineas('-');
}


void leerUnaFecha(int &fecha){
    int dd,mm,aa;
    char c;
    cin>>dd>>c>>mm>>c>>aa;
    fecha = dd + mm*100 + aa*10000;
}

void leerFechas(int &fechaDoc,int &fechasEst,int &fechasAdm){
    leerUnaFecha(fechaDoc);
    leerUnaFecha(fechasEst);
    leerUnaFecha(fechasAdm);
}

