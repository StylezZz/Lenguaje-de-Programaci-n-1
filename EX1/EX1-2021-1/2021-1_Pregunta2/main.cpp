/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 20:05
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesPregunta2.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *conductor,*falta,*consolidado;
    cargarDatos(conductor,falta);
    registraFaltas(consolidado,conductor,falta);
    cout<<"Fin de faltas"<<endl;
    imprime(consolidado);
    return 0;
}

