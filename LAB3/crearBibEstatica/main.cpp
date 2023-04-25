/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 25 de abril de 2023, 1:08
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesMatematicas.h"
using namespace std;

//Pasos para crear una biblioteca estática
//1.- Probar tus funciones en un proyecto normal


int main(int argc, char** argv) {
    int n = 5,f;
    f = factorial(n);
    cout<<"Factorial: "<<f<<endl;
    
    double x=14.5,y;
    y = potencia(x,2);
    cout<<"Y = "<<y<<endl;
    
    double s,ang=37;
    s = seno(ang);
    cout<<"Seno("<<ang<<") = "<<s<<endl;
    
    double na=-23.56,nAbs;
    nAbs = abs(na);
    cout<<"|"<<na<<"| = "<<nAbs<<endl;
    
    double nr= 72.89,r;
    r= raizN(3,nr);
    cout<<"Raíz cúbica de "<<nr<<" = "<<r<<endl;
    
    
    
    return 0;
}

