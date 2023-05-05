/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;



char* leerCadena(ifstream &in){
    char buffer[200],*cad;
    in.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void formatearNombre(char *&nombre,char &cat){
    int len = strlen(nombre);
    if(nombre[len-2]==' '){
        cat = nombre[len-1];
        nombre[len-2]=0;
    }else{
        cat = '-';
    }
}

void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    ifstream arch("Clientes.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Clientes.csv"<<endl;
        exit(1);
    }
    int arrDni[100],numDatos=0,dni,telefono;
    char *bufferNombre[100],bufferCategoria[100],*nombre,cat,limpiar[100];
    while(1){
        arch>>dni;
        if(arch.eof())break;
        arch.get();
        nombre = leerCadena(arch);
        formatearNombre(nombre,cat);
        arch.getline(limpiar,100);
        bufferNombre[numDatos]=nombre;
        bufferCategoria[numDatos]=cat;
        arrDni[numDatos]=dni;
        numDatos++;
    }
    cli_DNI = new int[numDatos+1];
    cli_Nombre=new char*[numDatos+1];
    cli_Categoria=new char[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        cli_DNI[i]=arrDni[i];
        cli_Categoria[i]=bufferCategoria[i];
        cli_Nombre[i]=bufferNombre[i];
    }
    
    cli_DNI[numDatos]=0;
    cli_Categoria[numDatos]=0;
    cli_Nombre[numDatos]=nullptr;
}

void ReporteDeClientes(int *cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    ofstream arch("ReporteClientes.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteClientes.txt"<<endl;
        exit(1);
    }
    arch<<"Reporte de Clientes:"<<endl;
    for(int i=0;i<100;i++)arch<<'=';
    arch<<endl;
    arch<<left<<setw(10)<<"DNI"<<setw(30)<<right<<"NOMBRE"<<setw(20)<<"    CATEGORIA"<<endl;
    for(int i=0;i<100;i++)arch<<'=';
    arch<<endl;
    for(int i=0;cli_DNI[i];i++){
        arch<<left<<setw(10)<<cli_DNI[i]<<right<<setw(40)<<cli_Nombre[i]<<right<<
                setw(10)<<cli_Categoria[i]<<endl;
    }
}
    
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,char **&pro_Descripcion,
                             double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido, 
                             double **&cli_CantidadPedido){
    
}

void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,char **pro_Descripcion,
                                double *pro_Descuento,double *pro_Precio,int **cli_CodigoProFechaPedido, 
                                double **cli_CantidadPedido){
    
}

void ReporteRlacionDePedidos(int *cli_DNI, char **cli_Nombre,char *cli_Categoria,
                             int **cli_CodigoFechaPedido,double **cli_CantidadPedido, 
                             int *pro_Codigo,char **pro_Descripcion,
                             double *pro_Descuento,double *pro_Precio){
    
}




