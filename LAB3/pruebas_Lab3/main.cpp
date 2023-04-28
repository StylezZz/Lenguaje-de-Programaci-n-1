/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 21 de abril de 2023, 14:19
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
#include "Persona.h"
using namespace std;

/*
 * 
 */

void imprimirLineas(int=1,int=1,int=2000);

int main(int argc, char** argv) {
    struct Persona persona1{
        20202692,"Christian Edgardo Carrillo Aburto",3456.6
    };
    struct Persona persona2{
        20203523,"Maria Pia Saavedra Chavez",2000.5
    };
    struct Persona persona3{
        20202526,"Viviana Geraldine Orellana",1500.3
    };
    
    persona1*20;
    cout<<persona1.dni<<endl;
    cout<<persona1.nombre<<endl;
    cout<<persona1.sueldo<<endl;
     
    persona3 = persona1 + persona2;
    cout<<persona3.dni<<endl;
    cout<<persona3.nombre<<endl;
    cout<<persona3.sueldo<<endl;
    
    return 0;
}

void imprimirLineas(int dd,int mm,int aa){
    cout<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/';
    cout<<setw(4)<<aa<<setfill(' ')<<endl;
}

