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

void imprimirEncabezadoConductor(){
    cout<<setw(30)<<"CONDUCTOR"<<setw(50)<<"INFRACCIONES"<<endl;
    imprimirLineas('-');
    cout<<"Licencia No."<<setw(6)<<"Nombre"<<setw(20)<<"Placa";
    cout<<setw(10)<<"Fecha"<<setw(10)<<"Codigo"<<setw(10)<<"Gravedad";
    cout<<setw(10)<<"Puntos"<<setw(10)<<"Multa"<<endl;
    imprimirLineas('-');
}

void formatearNombre(char *nombre){
    for(int i=0;nombre[i]!='\0';i++){
        if(nombre[i]=='_'){
            nombre[i]=' '; 
        }
    }
}

void imprimirMulta(int numLicencia,char *nombreConductor,char *placa,int dd,int mm,int year,
        int codigoMulta,char gravedad,double montoUniMulta,int &cantGraves,int &cantLeves,int &cantMuyGraves,
        double &ptsLeve,double &ptsGrave,double &ptsMuyGrave,int primero){
    imprimirEncabezadoConductor();
    cout<<numLicencia<<setw(10)<<nombreConductor<<setw(10)<<placa<<setw(10);
    if(dd<0){
        cout<<"--/"<<mm<<"/"<<year;
    }else if(mm<0){
        cout<<"--/--/"<<year;
    }else if(year<0){
        cout<<"--/--/--";
    }
    cout<<setw(10)<<codigoMulta;
    imprimirGravedad(gravedad,)
    cout<<setw(10)<<montoUniMulta<<endl;
    
}


void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++){
        cout<<c;
    }
    cout<<endl;
}

void leerFecha(int &dd,int &mm,int &year){
    int vacio = -99;
    dd=mm=year = vacio;
    int temporal;
    while(1){
        cin>>temporal;
        if(cin.fail()){
            cin.clear();
            break;
        }
        dd=mm;
        mm=year;
        year=temporal;
    }
}

void imprimirResumen(int cantLeves,int cantGraves,int cantMuyGraves,double multaLeve,
                    double multaGrave,double multaMuyGrave,int ptsLeve,int ptsGrave,
                    int ptsMuyGrave){
    int cantTotal,puntosTotales;
    double totalMultasPagadas;
    cout<<setprecision(2)<<fixed;
    cout<<"RESUMEN:"<<endl;
    cout<<"Gravedad"<<setw(20)<<"Cantidad"<<setw(20)<<"Multas Pagadas"
            <<setw(20)<<"Puntos Perdidos"<<endl;
    cout<<"Multas leves:"<<setw(20)<<cantLeves<<setw(20)<<multaLeve<<setw(20)<<ptsLeve<<endl;
    cout<<"Multas graves:"<<setw(20)<<cantGraves<<setw(20)<<multaGrave<<setw(20)<<ptsGrave<<endl;
    cout<<"Multas muy graves:"<<setw(20)<<cantMuyGraves<<setw(20)<<multaMuyGrave<<setw(20)
                                <<ptsMuyGrave<<endl;
    imprimirLineas('-');
    cout<<"Total:"<<setw(20)<<cantTotal<<setw(20)<<totalMultasPagadas<<setw(20)<<puntosTotales<<endl;
    imprimirLineas('=');
}


void imprimirEncabezado(){
    cout<<setw(60)<<"REGULADORA DE TRANSPORTE URBANO"<<endl;
    imprimirLineas('=');
}

