/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 12 de abril de 2023, 11:30
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#define MAXCANTLINEAS 100
using namespace std;

/*
 * 
 */
void imprimirLineas(char c){
    for(int i=0;i<MAXCANTLINEAS;i++){
        cout<<c;
    }
    cout<<endl;
}

void imprimirEncabezado(){
    cout<<"ESTADO DE CUENTAS DEL BANCO ABCD"<<endl;
    imprimirLineas('=');
}

void formatearMinusculas(char *nombre){
    int pos=1;
    while(nombre[pos]!='\0'){
        if(nombre[pos]>='A' && nombre[pos]<='Z'){
            nombre[pos]=nombre[pos]+32;
        }
        pos++;
    }  
}

void imprimirCabeceraCliente(){
    cout<<"CLIENTE"<<setw(50)<<"CODIGO DE CUENTA"<<setw(20)<<"MONEDA"<<setw(20)<<"SALDO INICIAL"<<endl;
}

bool esNumero(char *nombre){
    for(int i=0;nombre[i]!='\0';i++){
        if(nombre[i]<'0' || nombre[i]>'9'){
            return false;
        }
    }
    return true;
}

void imprimirSegundoEncabezado(char moneda){
    cout<<"FECHA"<<setw(30);
    if(moneda=='&'){
        cout<<"RETIROS EUROS"<<setw(20)<<"DEPOSITOS EUROS"<<setw(20)<<"SALDO EUROS"<<setw(20)<<"OBSERVACION"<<endl;
        imprimirLineas('-');
    }else if(moneda=='S'){
        cout<<"RETIROS SOLES"<<setw(20)<<"DEPOSITOS SOLES"<<setw(20)<<"SALDO SOLES"<<setw(20)<<"OBSERVACION"<<endl;
        imprimirLineas('-');
    }else if(moneda=='$'){
        cout<<"RETIROS DOLARES"<<setw(20)<<"DEPOSITOS DOLARES"<<setw(20)<<"SALDO DOLARES"<<setw(20)<<"OBSERVACION"<<endl;
        imprimirLineas('-');
    }
}

void leerCliente(char *nombreCompleto,char *nombreBorrar,char &moneda,double &saldoInicial){
    //El nombre puede variar, tipo un nombre o dos nombres o tres nombres asi como apellidos
    //El nombre completo se guarda en nombreCompleto
    int codigo;
    imprimirCabeceraCliente();
    while(1){
        cin>>nombreBorrar;
        //Si es numero entonces break;
        if(isdigit(nombreBorrar[0])){
            codigo=atoi(nombreBorrar);
            break;
        }
        formatearMinusculas(nombreBorrar);
        cout<<nombreBorrar<<" ";
    }
    cin>>moneda>>saldoInicial;
    cout<<setw(16)<<codigo<<setw(23);
    if(moneda=='&'){
        cout<<"Euros"<<setw(20)<<saldoInicial<<endl;
    }else if(moneda=='$'){
        cout<<"Dolares"<<setw(20)<<saldoInicial<<endl;
    }else if(moneda=='S'){
        cout<<"Soles"<<setw(20)<<saldoInicial<<endl;
    }
    imprimirLineas('=');
    imprimirSegundoEncabezado(moneda);
}

void imprimirFecha(int dd,int mm,int aa){
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<setw(30);
    cout.fill(' ');
}

double hallarFactor(char moneda,char simbolo,double euro,double dolar){
    if(moneda == 'S'){
        if(simbolo == 'S'){
            return 1;
        }else  if(simbolo == '$'){
            return dolar;
        }else if(simbolo == '&'){
            return euro;
        }
    }else if(moneda == '$'){
        if(simbolo == 'S'){
            return 1.0/dolar;
        }else  if(simbolo == '$'){
            return 1;
        }else if(simbolo == '&'){
            return euro/dolar;
        }
    }else if(moneda == '&'){
        if(simbolo == 'S'){
            return 1.0/euro;
        }else  if(simbolo == '$'){
            return dolar/euro;
        }else if(simbolo == '&'){
            return 1;
        }
    }
}

void procesarMovimiento(double saldoInicial,char moneda,double euro,double dolar,double &totalRetiro
                    ,double &totalDeposito,int &cantRetiros,int &cantDepositos){
    char tipoMovimiento,simbolo;
    double monto,factor;
    while(cin.get()!='\n'){
        cin>>tipoMovimiento;
        if(cin.fail()){
            cin.clear();
            break;
        }else{
            if(tipoMovimiento=='R' || tipoMovimiento=='D'){
                cin>>simbolo>>monto;
                factor = hallarFactor(moneda,simbolo,euro,dolar);
                if(tipoMovimiento=='R'){
                    totalRetiro+=monto*factor;
                    saldoInicial-=monto*factor;
                    cantRetiros++;
                }else if(tipoMovimiento=='D'){
                    totalDeposito+=monto*factor;
                    saldoInicial+=monto*factor;
                    cantDepositos++;
                }
            }
        }
        
    }
}

void imprimirResumen(int cantRetiros,int cantDepositos,double totalRetiro,double totalDeposito,double saldoInicial,char moneda){
    imprimirLineas('=');
    cout<<"RESUMEN:"<<endl;
    cout<<"CANTIDAD TOTAL DE RETIROS:"<<setw(10)<<cantRetiros;
    cout<<"TOTAL DE RETIROS:"<<setw(20)<<moneda<<totalRetiro<<endl;
    cout<<"CANTIDAD TOTAL DE DEPOSITOS:"<<setw(10)<<cantDepositos;
    cout<<"TOTAL DE DEPOSITOS:"<<setw(10)<<moneda<<totalDeposito<<endl;
    cout<<"SALDO FINAL:"<<setw(10)<<moneda<<saldoInicial;
    cout<<setw(20)<<"OBSERVACION FINAL:"<<"  ";
    if(saldoInicial<0){
        cout<<"CUENTA EN SOBREGIRO"<<endl;
    }else{
        cout<<"---"<<endl;
    }
    imprimirLineas('=');
}

void leerMovimiento(double saldoInicial,char moneda,double euro,double dolar){
    int dd,mm,aa;
    char c;
    int cantRetiro=0,cantDeposito=0;
    double totalRetiro=0,totalDeposito=0,factor;
    while(1){
        cin>>dd;
        if(cin.fail()){
            cin.clear();
            break;
        }
        cin>>c>>mm>>c>>aa;
        imprimirFecha(dd,mm,aa);
        totalRetiro=0, totalDeposito=0;
        procesarMovimiento(saldoInicial,moneda,euro,dolar,totalRetiro,totalDeposito,cantRetiro,cantDeposito);
        totalDeposito += saldoInicial;
        totalRetiro += saldoInicial;
        cout<<setw(20)<<moneda<<totalRetiro<<setw(20)<<moneda<<totalDeposito<<setw(20)<<moneda<<saldoInicial<<endl;
        factor = hallarFactor(moneda,'$',euro,dolar);
        if(saldoInicial>0 && saldoInicial<1000){
            cout<<setw(20)<<"BAJO EL MINIMO"<<endl;
        }else if(saldoInicial<0){
            cout<<setw(20)<<"SOBREGIRO"<<endl;
        }
        imprimirResumen(cantRetiro,cantDeposito,totalRetiro,totalDeposito,saldoInicial,factor);
    }
}
    
int main(int argc, char** argv) {
    double euro,dolar;
    char moneda;
    double saldoInicial;
    char nombreCompleto[120];
    char nombreBorrar[30];
    cin>>dolar>>euro;
    imprimirEncabezado();
    while(1){
        if(cin.eof()){
            break;
        }
        leerCliente(nombreCompleto,nombreBorrar,moneda,saldoInicial);
        leerMovimiento(saldoInicial,moneda,euro,dolar);

        
    }
    
    return 0;
}

