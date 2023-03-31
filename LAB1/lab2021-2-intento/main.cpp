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
    int fechaAdm,fechaDoc,fechaEst,carnet;
    int fechaRetiro;
    char tipoUsuario,nombrePersona[100],codLibro[20];
    double precioLibro;
    leerFechas(fechaAdm,fechaDoc,fechaEst);
    imprimirPrimerEncabezado(fechaAdm,fechaDoc,fechaEst);
    while(1){
        //Se leerá 123456789A
        cin>>carnet>>tipoUsuario;
        if(cin.fail()){
            leerLibro()
        }else{
            //Si es que no se halla fail entonces se lee un nombre
            cin>>nombrePersona;
            leerLibro(codLibro,fechaRetiro,precioLibro);
            imprimirLibro(carnet,nombrePersona,tipoUsuario,codLibro,fechaRetiro
                    fechaAdm,fechaDoc,fechaEst);
        }
    }
    return 0;
}

