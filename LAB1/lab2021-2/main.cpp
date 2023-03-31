/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 29 de marzo de 2023, 9:21
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define MAXLINEAS 100
/*
 * 
 */
//dni nombre precio apellido

void 

void leerLibro(char *codigoLibro,int &fecha,double &precioLibro){
    int dd,mm,aa;
    char c;
    cin>>codigoLibro;
    cin>>dd>>c>>mm>>c>>aa>>precioLibro;
    fecha = dd + mm*100 + aa*10000;
}

void sacarFecha(int &dia,int &mes,int &year,int fecha){
    dia = fecha %100;
    fecha/=100;
    mes = fecha%100;
    fecha/=100;
    year=fecha;
}

void imprimirFecha(int fecha){
    int dd,mm,aa;
    sacarFecha(dd,mm,aa,fecha);
    cout<<setfill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<aa;
    cout<<setfill(' ');
}

void imprimirSegundoEncabezado(int fechaAdm,int fechaDoc,int fechaEst){
    cout<<"          "<<setw(20)<<right<<"Docentes: ";
    imprimirFecha(fechaDoc);cout<<endl;
    cout<<"          "<<setw(20)<<right<<"Estudiantes: ";
    imprimirFecha(fechaEst);cout<<endl;
    cout<<"          "<<setw(20)<<right<<"Administrativa: ";
    imprimirFecha(fechaAdm);cout<<endl;
    imprimirLineas('-');
}

void leerFecha(int &fecha){
    char c;
    int dd,mm,aa;
    cin>>dd>>c>>mm>>c>>aa;
    fecha = aa*10000 + mm*100 + dd;
}

void leerFechas(int &fechaAdm,int &fechaDoc,int &fechaEst){
    leerFecha(fechaAdm);
    leerFecha(fechaDoc);
    leerFecha(fechaEst);
}

void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++)cout<<c;
    cout<<endl;
}

void imprimirEncabezado(){
    cout<<setw(50)<<"BIBLIOTECA GENERAL DE LA UNIVERSIDAD"<<endl;
    imprimirLineas('=');
    cout<<"Fechas limite de devolucion:"<<endl;
}

int main(int argc, char** argv) {
    imprimirEncabezado();
    int fechaAdm,fechaDoc,fechaEst,carne,fechaRetiro;
    char tipoUsuario,codigoLibro[20],nombrePersona[100];
    double precioLibro;
    int diaR,mesR,anioR;
    char slash;
    leerFechas(fechaAdm,fechaDoc,fechaEst);
    imprimirSegundoEncabezado(fechaAdm,fechaDoc,fechaEst);
    while(1){
        cin>>carne>>tipoUsuario;
        /*Se lee primero el numero del carnet y junto esta el tipo de usuario
         que seria un caracter*/
        if(cin.eof())break;
        if(cin.fail()){
            //Sigue leyendo libros
            cin.clear();
            //Se limpia el buffer
            leerLibro(codigoLibro,fechaRetiro,precioLibro);
        }else{
            //Si es que no se ha leido mal los datos entonces se lee el nombre
            cin>>nombrePersona;
            leerLibro(codigoLibro,fechaRetiro,precioLibro);
            imprimirCabeceraUsuario(nombrePersona,carne,)
        }
    }
    
    return 0;
}

