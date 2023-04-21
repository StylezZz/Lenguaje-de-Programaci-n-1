/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de abril de 2023, 16:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
void imprimirLineas(ofstream &archivo,char c){
    for(int i=0;i<=100;i++){
        archivo<<c;
    }
    archivo<<endl;
}

int main(int argc, char** argv) {
    ofstream archReporte("primerReporte.txt",ios::out);
    if(not archReporte){
        cout<<"ERROR: No se pudo abrir el archivo primerReporte.txt"<<endl;
        exit(1);
    }
    archReporte<<setw(50)<<"PRIMER TITULO"<<endl;
    imprimirLineas(archReporte,'=');
    archReporte<<"Fin de la escritura"<<endl;
    archReporte.close();
    
    return 0;
}

