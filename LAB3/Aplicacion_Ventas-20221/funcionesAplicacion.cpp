/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "funciones.h"
#include "funcionesAplicacion.h"
using namespace std;


void leerClientes(struct Estructura_ClienteRegistrado *arrClientes){
    ifstream archClientes;
    ofstream archClientesPrueba;
    int i=0;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    arrClientes[0].dni = 0;
    while(1){
        archClientes>>arrClientes[i];
        if(archClientes.eof()){
            arrClientes[i].dni =0;
            break;
        }
        i++;
    }
}

void cargarPedidosLeerProductos(struct Estructura_ProductosEnAlmacen *arrProductos,
                                struct Estructura_ClienteRegistrado *arrClientes){
    
    //Se lee el archivo
    ifstream archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
    
    char codigoPro[7],descripcion[80],dato;
    int dni,dd,mm,aa,fecha;
    double descuento,cantidad,precioUnitario,c;
    int i=0;
    while(1){
        archPedidos>>codigoPro;
        if(archPedidos.eof()){
            break;
        }
        descuento = 0;
        archPedidos>>descripcion>>cantidad;
        if(archPedidos.fail()){
            archPedidos.clear();
            archPedidos>>dato>>descuento>>cantidad;
        }
        archPedidos>>precioUnitario>>dni>>dd>>c>>mm>>c>>aa;
        fecha = dd+mm*100+aa*10000;
        //Una vez llenado los datos de los pedidos y del producto se pasa a la siguiente función
        llenarClientesAlmacen(arrClientes,arrProductos,codigoPro,descripcion,descuento,cantidad,precioUnitario,dni,fecha);
        
    }
}

void llenarClientesAlmacen(struct Estructura_ClienteRegistrado *arrClientes,
                           struct Estructura_ProductosEnAlmacen *arrProductos,
                           char *codigoPro,char *descripcion,double descuento,
                           double cantidad,double precioUnitario,int dniPedido,int fecha){
    //Primero se guarda el producto en una variable aux y se usa la sobrecarga para añadirlo al arregloPro
    struct Estructura_ProductosEnAlmacen pro;
    struct Estructura_PedidoRealizado ped;
    strcpy(pro.codigo,codigoPro);
    strcpy(pro.descripcion,descripcion);
    pro.descuento = descuento;
    pro.precioUnitario = precioUnitario;
    
    //Añadirlo al final 
    arrProductos+=pro;
    
    int i=0;
    cout<<"A buscar"<<endl;
    for(i=0;arrClientes[i].dni;i++){
        if(dniPedido == arrClientes[i].dni){
            cout<<"DNI arreglo: "<<arrClientes[i].dni<<endl<<"DNI encontrado: "<<dniPedido<<endl;
            cargarPedidoCliente(arrClientes[i],codigoPro,cantidad,fecha);
            
            break;
        }
    }

    cout<<"No se encontro el DNI de la persona: "<<dniPedido<<endl;
}

void cargarPedidoCliente(struct Estructura_ClienteRegistrado &cli,char *codigoPro,
                         double cantidad,int fecha){
    struct Estructura_PedidoRealizado ped;
    ped.cantidad = cantidad;
    ped.fecha = fecha;
    strcpy(ped.codigo,codigoPro);
    cli+=ped;
}

void mostrarReporte(struct Estructura_ClienteRegistrado *arrClientes,
                    struct Estructura_ProductosEnAlmacen *arrProductos){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"ReporteFinal.txt");
    archReporte<<setw(40)<<"EMPRESA COMERCIALIZADORE ABC"<<endl;
    archReporte<<setw(50)<<"PRODUCTOS ALMACENADOS"<<endl;
    archReporte<<"No."<<setw(20)<<"Codigo"<<setw(20)<<"Descripcion"<<setw(60);
    archReporte<<"Precio Unitario"<<setw(40)<<"Descuento"<<endl;
    archReporte<<arrProductos;
    
    for(int i=0;arrClientes[i].dni;i++){
        archReporte<<arrClientes[i];
    }
}

void mostrarProductos(struct Estructura_ProductosEnAlmacen *arrProd){
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Productos-Pruebas.txt");
    
    archReporte<<arrProd;
}

void mostrarClientes(struct Estructura_ClienteRegistrado *arrClientes){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,"Reporte-Clientes.txt");
    for(int i=0;arrClientes[i].dni;i++){
        arch<<arrClientes[i];
    }
}

