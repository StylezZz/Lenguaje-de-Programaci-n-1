/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>    
#include "funciones.h"
#define MAXLINEAS 100
#define BORRAR -17
using namespace std;

void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++)cout<<c;
    cout<<endl;
}

void leerHumedad(double &humedad){
    char c;
    double valor;
    cin>>c>>valor;
    if(cin.fail()){
        //Solo encontró un H% por lo que se pondrá 
        cin.clear();
        humedad = BORRAR;
    }else{
        
    }
}

void pasarTemperaturas(double &tempC,double &tempF){
    if(tempC == BORRAR or tempF == BORRAR){
        return;
    }
    if(tempF>0){
        tempC = ((5*tempF)-32)/9;
    }
    if(tempC>0){
        tempF = ((9*tempC)+32)/5;
    }
}

void leerTemperatura(double &tempC,double &tempF){
    char c;
    double valor;
    cin>>c>>valor;
    if(cin.fail()){
        //Hubo un error lo más probable es que haya leido TF o TC
        cin.clear();
        tempC = BORRAR;
        tempF = BORRAR;
    }else{
        cin>>c;
        if(c=='C'){
            //Leyó C
            tempC = valor;
        }else if(c=='F'){
            tempF = valor;
        }
    }
    pasarTemperaturas(tempC,tempF);
}

void leerDatos(double &tempC,double &tempF,double &humedad,double &precSeg,
        double &precCant,int &dd,int &mm,int  &aa){
    leerTemperatura(tempC,tempF);
    leerHumedad(humedad);
    leerPrecipitaciones(precSeg,precCant);
    leerFecha(dd,mm,aa);
}

void imprimirCiudad(char *nombre,int codigo){
    cout<<nombre<<setw(20)<<codigo;
}

void imprimirSubtitulos(){
    cout<<setw(10)<<"CIUDAD"
            <<setw(15)<<"CODIGO"
            <<setw(15)<<"FECHA"
            <<setw(20)<<"TEMPERATURA"
            <<setw(10)<<"HUMEDAD"
            <<setw(20)<<"PRECIPITACIONES"<<endl;
    cout<<setw(70)<<"°C   °H"
            <<setw(10)<<"  %  "
            <<setw(20)<<"TIEMPO(seg)  CANTIDAD"<<endl;
    imprimirLineas('-');
}

void imprimirEncabezado(){
    cout<<setw(60)<<"REGISTRO CLIMATICO DEL PAIS"<<endl;
    imprimirLineas('=');
    imprimirSubtitulos();
}






