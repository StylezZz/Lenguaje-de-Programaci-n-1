/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 30 de marzo de 2023, 19:34
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

/*
 * 
 */

// dd/mm/aa dd/mm/aa dd/mm/aa
// codigo letra nombre codLibro ddR/mmR/aaR precioLibro y así 
int main(int argc, char** argv) {
    int fechaDoc,fechaEst,fechaAdm;
    leerFechas(fechaDoc,fechaEst,fechaAdm);
    imprimirCabeceraYFechas(fechaDoc,fechaEst,fechaAdm);
    
    int numCarnet,fechaRetiro,cantLibrosAdeudados=0;
    double totalDeudas=0,deudaxLibro=0,precioLibro;
    char nombre[100],codLibro[20],tipo;
    int primero=1,flag=0,inicio=0;
    while(1){
        cin>>numCarnet>>tipo>>nombre;
        if(cin.eof()){
            imprimirResumen(cantLibrosAdeudados,totalDeudas);
            break;
        }
        if(cin.fail()){
            //Sigue leyendo cursos
            cin.clear();
            leeCurso(codLibro,fechaRetiro,precioLibro,deudaxLibro,tipo
                    ,fechaAdm,fechaDoc,fechaEst);
            if(deudaxLibro>0){
                cantLibrosAdeudados++;
                totalDeudas+=deudaxLibro;
            }
            imprimirCurso(codLibro,fechaRetiro,deudaxLibro,primero);
            primero++;
        }else{
            //Lee otro nombre
            if(flag!=0){
                imprimirResumen(cantLibrosAdeudados,totalDeudas);
            }
            imprimirSegundoEncabezado(numCarnet,tipo,nombre);
            cantLibrosAdeudados=0;
            totalDeudas=0;
            primero=1;
            flag=1;
            
        }
    }
    
    return 0;
}

