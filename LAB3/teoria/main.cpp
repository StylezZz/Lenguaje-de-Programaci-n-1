/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 24 de abril de 2023, 17:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Plantilla.h"
using namespace std;

int main(int argc, char** argv) {
    int a = 356789534, b = 780345563, c;
    float x= 28.45, y = 132.83,z;
    cout.precision(2);
    cout<<fixed;
    
    c = suma(a,b);
    z = suma(x,y);
    
    cout<<"c = "<<c<<endl;
    cout<<"z = "<<z<<endl;
    
    
    return 0;
}


