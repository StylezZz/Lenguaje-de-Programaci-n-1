/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 28 de marzo de 2023, 15:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define MAX_CARACTERES 100

/*
 * 
 */

void imprimirLineas(char c,int cant){
    for(int i=0;i<cant;i++){
        cout<<c;
    }
    cout<<endl;
}

void imprimirCabecera(){
    cout<<setw(50)<<"REPORTE KADEX"<<endl;
    imprimirLineas('=',MAX_CARACTERES);
}

void imprimirNombreTienda(int ruc,char *nombreTienda){
    cout<<ruc<<setw(4)<<"     "<<nombreTienda<<endl;
    imprimirLineas('=',MAX_CARACTERES);
    cout<<"FECHA"<<setw(20)<<right<<"CODIGO"<<setw(30)<<right<<"DESCRIPCION"<<setw(30)
            <<"CANTIDAD"<<setw(12)<<"UNIDAD"<<endl;
    imprimirLineas('-',MAX_CARACTERES);
}

void leerDatos(int &mm,int &aa,int &tipoMov,int &codProd,
        char *nomProd,double &cantProd,char *unidad){
    char caracter;
    cin>>caracter;
    cin>>mm>>caracter>>aa>>tipoMov>>codProd>>nomProd;
    cin>>cantProd;
    if(cin.fail()){
        cin.clear();
        cantProd=1;
    }
    cin>>unidad;
}

int cantDigitos(int codigo,int &ultimoDigito){
    int cant=0;
    while(codigo!=0){
        ultimoDigito=codigo;
        codigo/=10;
        cant++;
    }
    return cant;
}



bool validarDatosMovimiento(int tipoMov,double &cantProd){
    int ultimoDigito;
    if(cantDigitos(tipoMov,ultimoDigito)==3){
        //Con esto aseguramos los datos que nos pide el problema
        if(ultimoDigito==3){
            //Salida de productos
            cantProd*=-1;
            return true;
        }else if(ultimoDigito==5){
            return true;
        }
    }else{
        return false;
    }
        
}

void imprimirReporte(int dd,int mm,int aa,int tipoMov,int codProd,char *nombreProducto,
                        double cantProd,char *unidad){
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(2)<<right<<aa;
    cout<<"         "<<setw(8)<<right<<codProd<<"                 ";
    cout.fill(' ');
    cout<<setw(30)<<left<<nombreProducto;
    cout<<setw(8)<<setprecision(2)<<fixed<<right<<cantProd<<"           "<<
            setw(12)<<left<<unidad<<endl;
}


int main(int argc, char** argv) {
    int valor,dd,mm,aa,dato,ruc,codProd,tipoMov;
    double cantProd;
    char nombreTienda[100],nombreProducto[100],unidad[30];
    
    imprimirCabecera();

    while(1){
        cin>>valor;
        if(cin.eof())break;
        if(valor>31){
            //En ese caso es un código RUC caso contrario será una fecha
            ruc= valor;
            cin>>nombreTienda;
            imprimirNombreTienda(ruc,nombreTienda);
        }else{
            dd=valor;
            leerDatos(mm,aa,tipoMov,codProd,nombreProducto,cantProd,unidad);
            if(validarDatosMovimiento(tipoMov,cantProd)){
                //Con el filtro de if se muestran las cantidades pedidas por el
                //problema
                imprimirReporte(dd,mm,aa,tipoMov,codProd,nombreProducto,
                        cantProd,unidad);
            }
        }
        imprimirLineas('-',MAX_CARACTERES);
        
    }
    return 0;
}

