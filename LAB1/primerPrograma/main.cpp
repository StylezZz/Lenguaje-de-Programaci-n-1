/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 21 de marzo de 2023, 9:18
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

/*
 * 
 */
void imprimirLineas(char letra,int cantidad);

//Datos:
//Los números decimales y enteros se alinean a la derecha
//En decimales se truncan a dos decimales (?)
//Las cadenasde caracteres se alinean a la izquierda
int main(int argc, char** argv) {
    //Primera impresión
    int a=23, b=765, c=9;
//    cout<<a;
//    cout<<b;
//    cout<<c;
//    imprimirLineas('=',20);
//    cout<<endl<<endl;
    
    //Segunda impresión
//    a= 2351, b=765;
//    cout.width(10);
//    cout<<a<<endl;
//    cout<<b<<endl;
//    imprimirLineas('=',20);
    
    //Tercera impresión
//    a=2351 , b=765, c=1234;
//    cout.width(10);
//    cout<<a<<b<<endl;
//    cout<<c<<endl;
    
    //Cuarta impresión
//    a=2351, b=765, c=1234;
//    cout.width(10);
//    cout<<a;
//    cout.width(10);
//    cout<<b<<endl;
//    cout.width(10);
//    cout<<c<<endl;    

    //Quinta impresión
//    a=2351, b=765, c=1234;
//    cout<<setw(10)<<a<<setw(10)<<b<<endl;
//    cout<<setw(10)<<c<<endl;
    
    //Sexta impresión
//    a= 39963, b=765, c=1234;
//    cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
//    cout<<left<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
//    cout<<right<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    
    a= 39963, b=765, c=1234;
    cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    cout.fill('0');
    cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    cout.fill(' ');
    
    cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    cout<<setfill('X');
    cout<<setw(10)<<a<<setw(10)<<b<<setw(10)<<c<<endl;
    cout<<setfill(' ');
    
  
    return 0;
}

void imprimirLineas(char letra,int cantidad){
    cout<<endl;
    for(int i=0;i<=cantidad;i++){
        cout<<"=";
    }
    cout<<endl;
    
}

void ordenarArreglo(int arreglo[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if()
        }
    }
}








