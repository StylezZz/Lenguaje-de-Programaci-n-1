/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define MAXLINEAS 150
#include "funciones.h"
using namespace std;

void imprimirLineas(char c,ofstream &arch){
    for(int i=0;i<=MAXLINEAS;i++){
        arch<<c;
    }
    arch<<endl;
}

void verificarClienteBin(){
    ifstream archBin("Clientes.bin",ios::in|ios::binary);
    ofstream archReporte("ReporteCliente-Bin.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR no se ha podido abrir el archivo ReporteCliente-Bin.txt"<<endl;
        exit(1);
    }
    if(not archBin.is_open()){  
        cout<<"ERROR no se ha podido abrir el archivo Clientes.bin"<<endl;
        exit(1);
    }
    int dni,telefono;
    char nombreCliente[150],categoria;
    double montoGastado;
    
    archReporte<<right<<setw(12)<<"DNI"<<setw(12)<<"Nombre"<<setw(57)<<"Categoria"<<setw(15)<<
            "Telefono"<<setw(20)<<"Monto Gastado"<<endl;
    imprimirLineas('=',archReporte);
    while(1){
        archBin.read(reinterpret_cast<char*>(&dni),sizeof(int));
        if(archBin.eof())break;
        archBin.read(reinterpret_cast<char*>(nombreCliente),sizeof(char)*150);
        archBin.read(reinterpret_cast<char*>(&categoria),sizeof(char));
        archBin.read(reinterpret_cast<char*>(&telefono),sizeof(int));
        archBin.read(reinterpret_cast<char*>(&montoGastado),sizeof(double));
        archReporte<<right<<setw(15)<<dni<<setw(3)<<" "<<left<<setw(53)<<nombreCliente<<
                right<<setw(5)<<categoria<<setw(19)<<telefono<<setw(15)<<montoGastado<<endl;
    }
    imprimirLineas('=',archReporte);
    archReporte.close();
}



void hallarCategoria(char *cadena,char &categoria){
    int i=0,cantPalabras;
    // Cantidad de caracteres:
    while(cadena[i]){
        i++;
    }
    cantPalabras=i;
    // Hallar caracter:
    if(cadena[cantPalabras-2]=='-'){
        categoria = cadena[i-1];
        cadena[cantPalabras-2]=cadena[cantPalabras];
    }else{
        categoria='D';
    }
    i=0;
    // Cambiar formato:
    for(int i=0;cadena[i];i++){
        if(cadena[i]=='_' or cadena[i]=='-'){
            cadena[i]=' ';
        }
    }
}
//Clientes.bin->  dni(int)    nombre(cadena)  categoria(char) telefono(int)   montoGastado(double)
//Productos.bin-> codigoPro(cadena) descripcionPro(cadena)  descuento(double)   precUnitario(double)
//Pedidos.bin-> dni(int)    codigoPro(cadena)   cantComprada(double)    fecha(int)

void crearClientesBin(){
    //Crear el archivo Clientes.bin
    ofstream archBorrar("Borrar.txt",ios::out);
    
    ofstream archClientesBin("Clientes.bin",ios::out|ios::binary);
    if(not archClientesBin.is_open()){
        cout<<"ERROR, no se pudo abrir Clientes.bin"<<endl;
        exit(1);
    }
    
    //Leer el archivo Leer.txt
    ifstream archLeer("Leer.txt",ios::in);
    if(not archLeer.is_open()){
        cout<<"ERROR, no se pudo abrir Leer.txt"<<endl;
        exit(1);
    }
    //Declarar variables
    int dni,telefono,codigoCliente,fecha,dd,mm,aa;
    double descuento,cant,precioUni,montoGastado=0;
    char nombreCliente[150],codigoProducto[20],descripcionProducto[120],car,categoria;
    
    //Leer los datos del archivo y pasarlos a Clientes.bin
    while(true){
        archLeer>>dni;
        if(archLeer.eof())break;
        if(not archLeer.is_open()){
            archLeer>>nombreCliente>>telefono;
            
            hallarCategoria(nombreCliente,categoria);
           
            archClientesBin.write(reinterpret_cast<const char*>(&dni),sizeof(int));
            archClientesBin.write(reinterpret_cast<const char*>(nombreCliente),sizeof(char)*150);
            archClientesBin.write(reinterpret_cast<const char*>(&categoria),sizeof(char));
            archClientesBin.write(reinterpret_cast<const char*>(&telefono),sizeof(int));
            archClientesBin.write(reinterpret_cast<const char*>(&montoGastado),sizeof(double));
        }else{
            archLeer.clear();
            archLeer>>codigoProducto>>descripcionProducto;
            archLeer>>cant;
            if(not archLeer.fail()){
                //No hay descuento
                archLeer>>precioUni>>codigoCliente>>dd>>car>>mm>>car>>aa;
                descuento=0;
            }else{
                //Si hay descuento
                archLeer.clear();
                archLeer>>car>>descuento>>cant>>precioUni>>codigoCliente>>dd>>car>>mm>>car>>aa;
                
            }
        }
    }
    archLeer.close();
    archClientesBin.close();
}


