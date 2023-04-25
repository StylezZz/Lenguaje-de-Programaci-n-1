/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funciones.h"
using namespace std;

//Del archivo de Clientes.txt
//DNI   NOMBRE  TELEFONO    
ifstream &operator >>(ifstream &in,struct Estructura_ClienteRegistrado &cliente){
    int dni,telefono;
    char nombre[100];
    in>>dni>>nombre>>telefono;
    if(in.eof())return in;
    char categoria='N';
    int cantCaracteres = strlen(nombre);
    if(nombre[cantCaracteres-2]){
        nombre[cantCaracteres-2]=0;
        categoria = nombre[cantCaracteres-1];
    }
    
    cliente.dni = dni;
    cliente.montoTotalGastado = 0;
    strcpy(cliente.nombre,nombre);
    cliente.numeroDePedidos = 0;
    if(categoria=='N'){
        strcpy(cliente.categoria,"Cliente Nuevo");
    }else if(categoria == 'A'){
        strcpy(cliente.categoria,"Cliente muy frecuente");
    }else if(categoria == 'B'){
        strcpy(cliente.categoria,"Cliente frecuente");
    }else if(categoria == 'C'){
        strcpy(cliente.categoria,"Cliente Ocasional");
    }
    return in;
}

void operator +=(struct Estructura_ClienteRegistrado *cli,
                 struct Estructura_ClienteRegistrado cliVar){
    int i;
    for(i=0;cli[i].dni;i++);
    cli[i].dni = cliVar.dni;
    cli[i].montoTotalGastado = cliVar.montoTotalGastado;
    strcpy(cli[i].nombre,cliVar.nombre);
    cli[i].numeroDePedidos = cliVar.numeroDePedidos;
    strcpy(cli[i].categoria,cliVar.categoria);
    cli[i+1].dni = 0;
}

void operator +=(struct Estructura_ClienteRegistrado &cli,
                 struct Estructura_PedidoRealizado ped){
    int i= cli.numeroDePedidos;
    strcpy(cli.pedidosRealizados[i].codigo,ped.codigo);
    cli.pedidosRealizados[i].fecha = ped.fecha;
    cli.numeroDePedidos++;
    cli.montoTotalGastado +=ped.cantidad;
    cli.pedidosRealizados[i].cantidad = ped.cantidad;
}

void operator +=(struct Estructura_ProductosEnAlmacen *arrPro,
                 struct Estructura_ProductosEnAlmacen pro){
    int i;
    for(i=0;strcmp(arrPro[i].codigo,"X")!=0;i++){
        if(strcmp(arrPro[i].codigo,pro.codigo)==0)return;
    }
    strcmp(arrPro[i].codigo,pro.codigo);
    strcmp(arrPro[i].descripcion,pro.descripcion);
    arrPro[i].descuento = pro.descuento;
    arrPro[i].precioUnitario = pro.precioUnitario;
    strcpy(arrPro[i+1].codigo,"X");
}

void imprimirFecha(ofstream &out,int fecha){
    int dd,mm,aa;
    dd = fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    out<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
       <<setw(4)<<right<<aa<<setfill(' ');
}


ofstream &operator <<(ofstream &out,
                      struct Estructura_ClienteRegistrado c){
    out<<setw(10)<<"DNI"<<setw(20)<<"NOMBRE"<<endl;
    out<<setw(10)<<right<<c.dni<<"         "<<left<<c.nombre<<endl<<c.categoria<<endl;
    out<<"No."<<setw(10)<<"CODIGO"<<setw(20)<<"CANTIDAD"<<setw(20)<<"FECHA"<<endl;
    for(int i=0;i<c.numeroDePedidos;i++){
        out<<i+1<<")"<<setw(10)<<right<<c.pedidosRealizados[i].codigo<<
                setw(20)<<right<<c.pedidosRealizados[i].cantidad;
        imprimirFecha(out,c.pedidosRealizados[i].fecha);
        out<<endl;
    }
    out<<"Monto total comprado: "<<setw(12)<<right<<setprecision(2)<<fixed
            <<c.montoTotalGastado<<endl;
    return out;
}


ofstream &operator <<(ofstream &out,
                      struct Estructura_ProductosEnAlmacen *arr){
    out<<setw(40)<<"PRODUCTOS ALMACENADOS"<<endl;
    out<<"No."<<setw(10)<<"Codigo"<<setw(20)<<"Descripcion"<<setw(20)
       <<"Precio Unitario"<<setw(10)<<"Descuento"<<endl;
    
    
    for(int i=0;strcmp(arr[i].codigo,"X")!=0;i++){
        out<<i+1<<")"<<setw(10)<<left<<arr[i].codigo<<setw(20)<<left<<arr[i].descripcion<<
                setw(20)<<left<<arr[i].precioUnitario<<setw(10)<<arr[i].descuento<<endl;
    }
    return out;
}












