/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesMatematicas.h"
#define LIMITE 0.00001
using namespace std;

int factorial(int n){
    if(n==1)return 1;
    return n*factorial(n-1);
}

double potencia(double base,int exp){
    double pot;int i;
    pot=1;
    for(int i=1;i<=exp;i++){
        pot = pot * base;
    }
    return pot;
}

double seno(double grados){
    double rad,serie,term; int i,n;
    rad = grados*3.1416/180;
    term = rad;
    serie = rad;
    for(i=3,n=1;i<=100;i+=2,n++){
        term *= rad*rad/(i*(i-1));
        if((n%2)!=0)serie = serie - term;
        else serie = serie + term;
    }
    return serie;
}

double abs(double x){
    return x>=0 ? x: -x;
}

double raizN(int n,double q){
    double x0=0.0,xN= 1.0;
    while(abs(x0-xN)>LIMITE){
        x0 = xN;
        xN = ((n-1)*x0 + q/potencia(x0,n-1))/n;
    }
    return x0;
}