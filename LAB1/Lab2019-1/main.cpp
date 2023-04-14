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
#include "funciones.h"
using namespace std;


int main(int argc, char** argv) {
    char nombreCiudad[100];
    int codigoCiudad,dd,mm,aa;
    double tempC,tempF,humedad,precSeg,precCant;
    double promTempC,promTempF,promHumedad,promPrecSeg,promPrecCant;
    int cantTempC,cantTempF,cantHumedad,cantPrecSeg,cantPrecCant;
    while(1){
        cin>>nombreCiudad>>codigoCiudad;
        if(cin.eof()){
            
            break;
        }
        if(cin.fail()){
            //Esta leyendo datos
            leerDatos(tempC,tempF,humedad,precSeg,precCant,dd,mm,aa);
          
        }else{
            //Leyo otra ciudad
            imprimirCiudad(nombreCiudad,codigoCiudad);
        }
    }
    
    return 0;
}



