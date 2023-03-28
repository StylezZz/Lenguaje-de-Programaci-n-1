/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 24 de marzo de 2023, 12:09
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>    
#define PI 3.14
#define MIN -9999
#define MAX_CAR 150
#define NUM 40
#define VACIO -999999999

using namespace std;

/*
 * 
 */

void imprimirLines(char c,int cant){
    for(int i=0;i<cant;i++)cout<<c;
    cout<<endl;
}

void imprimirCabecera(){
    cout<<setw(70)<<"REGISTRO CLIMATICO DEL PAIS"<<endl;
    imprimirLineas('=',100);
}

int main(int argc, char** argv) {
    char lugar[20];
    int ciudad,dd,mm,aa,cantidadGrados, cantidadHumedad, cantidadTiempo, 
            cantidadVolumen;
    double celsius, farenheit, humedad, tiempo, cantidad, promedioHumedad,
            promedioCelsius, promedioFarenheit, promedioTiempo, promedioCantidad;
    int len, contador;
    char car;
    cout<<setw(80)<<"REGISTRO CLIMATICO DEL PAIS"<<endl;
    imprimirCabecera();
    cout.precision(2);
    cout<<fixed;
    while(1){
        car = cin.get();
        if(cin.eof())break;
        cin.unget();
        cout<<left;
        len=0;
        while(1){
            cin>>ciudad;
            if(cin.fail()){
                cin.clear();
                cin>>lugar;
                len+=strlen(lugar);
                cout<<lugar<<" ";
                len++;
            }else break;
        }
        while(len<NUM){
            cout<<" ";
            len++;
        }
        contador=0;
        cout<<setw(10)<<ciudad;
        cout<<right;
        promedioHumedad=0;
        promedioCelsius=0;
        promedioFarenheit=0;
        promedioTiempo=0;
        promedioCantidad=0;
        cantidadGrados=0;
        cantidadHumedad=0;
        cantidadTiempo=0;
        cantidadVolumen=0;
        while(1){
            car=cin.get();
            if(car=='\n')break;
            cin>>ws;
            car= cin.get();
            celsius = MIN;
            farenheit = MIN;
            if(contador>0) cout<<setw(NUM+10)<<" ";
            if(car=='T'){
                leerTemperatura(&celsius,&farenheit);
                cin>>ws;
                car=cin.get();
                
            }
        }
    } 
    return 0;
}



void imprimirCabecera(){
    
}

int areaCirculo(double radio){
    return PI*radio*radio;
}

