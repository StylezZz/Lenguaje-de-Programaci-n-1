/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 12 de abril de 2023, 23:50
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    imprimirEncabezado();
    char nombreConductor[120],placa[20],codigoMulta[20],texto[20],gravedad;
    int numLicencia,dd,mm,year;
    int cantLeves,cantGraves,cantMuyGraves,ptsLeve,ptsGrave,ptsMuyGrave;
    double multaLeve,multaGrave,multaMuyGrave,montoUniMulta;
    while(true){
        cin>>numLicencia>>nombreConductor;
        if(cin.eof()){
            imprimirResumen(cantLeves,cantGraves,cantMuyGraves,multaLeve,
                    multaGrave,multaMuyGrave,ptsLeve,ptsGrave,ptsMuyGrave);
            break;
        }
        if(cin.fail()){
            cin.clear();
            //Lee las placas
            cin>>placa;
            leerFecha(dd,mm,year);
            cin>>gravedad>>codigoMulta>>texto>>montoUniMulta;
            imprimirMulta(numLicencia,nombreConductor,placa,dd,mm,year,codigoMulta,
                    gravedad,montoUniMulta,cantGraves,cantLeves,cantMuyGraves,
                    ptsLeve,ptsGrave,ptsMuyGrave);
        }
    }
    return 0;
}

