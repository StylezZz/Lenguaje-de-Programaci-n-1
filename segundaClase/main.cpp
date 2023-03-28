/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 28 de marzo de 2023, 8:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a = 23, b=763, c=9;
    double p=3547.73621, q=1.735, r=0.005241;
    char car,nombre[50],apellido[50];
    int dd,mm,aa;
    
    cout.precision(2);
    cout<<fixed
    
    cin>>a>>b>>c;
    cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    
    return 0;
}

