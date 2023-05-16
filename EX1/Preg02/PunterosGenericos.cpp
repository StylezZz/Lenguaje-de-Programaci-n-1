/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.cpp
 * Author: Diego Bernardo Castilla Arnao Monteagudo - 20196342
 *
 * Created on 13 de mayo de 2023, 11:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "PunterosGenericos.hpp"
#include "MuestraPunteros.h"

enum Pedido{CODIGO, NOMBRE, CANTIDAD, DNI, FECHA, ESTADO};
enum Cliente{DNI_CLI, NOMBRE_CLI, PEDIDOS_CLI};

void cargaproductos(void *&productos){
    
    ifstream arch("productos2.csv", ios::in);
    if(!arch){
        cout<<"ERROR: El archivo productos2.csv no pudo abrirse"<<endl;
        exit(1);
    }
    void **arrProductos;
    void *buff[100];
    void *p;
    int numDat=0;
    
    while(1){
        p = leerProducto(arch);
        if(p == nullptr) break;
        buff[numDat] = p;
        numDat++;
    }
    buff[numDat] = nullptr;
    numDat++;
    arrProductos = new void*[numDat];
    for(int i=0; buff[i]; i++){
        arrProductos[i] = buff[i];
    }
    productos = arrProductos;
    
}

void * leerProducto(ifstream& arch){
    int *cod, codigo,cantidad, *cant;
    char nombre[100], *nom, car;
    double precio, *prec;
    void **producto;
    arch>>codigo;
    if(arch.eof()) return nullptr;
    cod = new int;
    *cod = codigo;
    arch.get();
    arch.getline(nombre, 100, ',');
    nom = memExacta(nombre);
    arch>>precio>>car>>cantidad;
    
    prec = new double;
    *prec = precio;
    cant = new int;
    *cant = cantidad;
    
    producto = new void*[4];
    producto[0] = cod;
    producto[1] = nom;
    producto[2] = prec;
    producto[3] = cant;
    
    return producto;
    
}

char *memExacta(char *nombre){
    char *aux;
    aux = new char[strlen(nombre)+1];
    strcpy(aux, nombre);
    return aux;
}

void cargapedidos(void *&pedidos){
    
    ifstream arch("pedidos2.csv", ios::in);
    if(!arch){
        cout<<"ERROR: El archivo productos2.csv no pudo abrirse"<<endl;
        exit(1);
    }
    void **arrPedidos;
    void *buff[200];
    void *p;
    int numDat=0;
    
    while(1){
        p = leerPedido(arch);
        if(p == nullptr) break;
        buff[numDat] = p;
        numDat++;
        //cout<<numDat<<endl;
    }
    buff[numDat] = nullptr;
    numDat++;
    arrPedidos = new void*[numDat];
    for(int i=0; buff[i]; i++){
        arrPedidos[i] = buff[i];
    }
    pedidos = arrPedidos;
    
}
void* leerPedido(ifstream &arch){
    
    int codigo, *cod, *canti, cant, dni_Est, *dni,*fecha, dd, mm, yy;
    char nombre[100],*nom, car, *est;
    void **pedido;
    pedido = new void*[6];
    
    arch>>codigo;
    if(arch.eof()) return nullptr;
    cod = new int;
    *cod = codigo;
    arch>>car;
    arch.getline(nombre, 100, ',');
    nom = memExacta(nombre);
    canti = new int;
    dni = new int;
    arch>>cant>>car>>dni_Est>>car>>dd>>car>>mm>>car>>yy;
    *canti = cant;
    *dni = dni_Est;
    fecha = new int;
    *fecha = yy*10000+mm*100+dd;
    est = new char;
    *est = 'N';
    pedido[0] = cod;
    pedido[1] = nom;
    pedido[2] = canti;
    pedido[3] = dni;
    pedido[4] = fecha;
    pedido[5] = est;
    
    //cout<<*cod<<"   "<<nom<<"   "<<*canti<<"   "<<*dni<<"  "<<*fecha<<"  "<<*est<<endl;
    
    return pedido;
    
    
}

void procesaclientes(void *&productos, void *&pedidos, void *&clientes){
    
    actualizarPedidosAtendidos(productos, pedidos);
    asignarPedidosAClientes(pedidos, clientes);
}

void actualizarPedidosAtendidos(void *productos, void *pedidos){
    
    void **arrProductos = (void**)productos;
    void **arrPedidos = (void**)pedidos;
    void **pedido;
    
    for(int i=0; arrPedidos[i]; i++){
        pedido = (void**)arrPedidos[i];
        actualizarPedido(pedido, arrProductos);
    }
    
}
void actualizarPedido(void *pedido, void *productos){
    void **datosPed = (void**)pedido;
    int *codPed = (int*)(datosPed[CODIGO]);
    char *estado = (char*)(datosPed[ESTADO]);
    int *cantidadPedida = (int *)(datosPed[CANTIDAD]);
    int seAtiende=0;
    seAtiende = validarStock(codPed, cantidadPedida,productos);
    if(seAtiende!= 0){
        *estado = 'A';
        datosPed[ESTADO] = estado;
    }
}

int validarStock(int *codPed, int*cantidadPedida, void* productos){
    void **arrProd = (void**)productos;
    void **prod;
    int *stock;
    for(int i=0; arrProd[i]; i++){
        prod = (void**)arrProd[i];
        if(*codPed == *(int*)(prod[0]) ){
            stock = (int*)(prod[3]);
            if( (*stock) >= (*cantidadPedida) ){
                (*stock) -= (*cantidadPedida);
                return 1;
            }else return 0;
        }
    }
    return 0;
}

void asignarPedidosAClientes(void *pedidos, void *&clientes){
    
    ifstream arch("clientes2.csv", ios::in);
    if(!arch){
        cout<<"ERROR:El archivo clientes2 no se pudo leer"<<endl;
        exit(1);
    }
    
    void**arrClientes, *buffClientes[200], *cli;
    int numDat=0;
    while(1){
        cli = leerCliente(arch);
        if(cli == nullptr) break;
        cargarPedidosCliencte(cli, pedidos);
        buffClientes[numDat] = cli;
        numDat++;
    }
    buffClientes[numDat] = nullptr;
    numDat++;
    arrClientes = new void*[numDat];
    for(int i=0; i<numDat; i++){
        arrClientes[i] = buffClientes[i];
    }
    
    clientes = arrClientes;
}

void* leerCliente(ifstream & arch){
    void **cliente;
    int dniEst, *dni;
    char name[100], *nomb;
    
    arch>>dniEst;
    
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(name, 100, '\n');
    dni = new int;
    *dni = dniEst;
    nomb = memExacta(name);
    //cout<<dniEst<<"  "<<name<<endl;
    
    cliente = new void*[3];
    cliente[DNI_CLI] = dni;
    cliente[NOMBRE_CLI] = nomb;
    cliente[PEDIDOS_CLI] = nullptr;
    
    return cliente;
    
}

void cargarPedidosCliencte(void *cli, void *pedidos){
    
    void **cliDatos = (void**)cli;
    void **arrPedidos = (void**)pedidos;
    
    int *dni = (int*)(cliDatos[DNI_CLI]);
    int esCliente, atendido, numPedidos = 0;
    
    void**pedidosCliente, *pedsCliente[100], *pedido;
    
    for(int i=0; arrPedidos[i]; i++){
        esCliente = validarClientePedido(*dni, arrPedidos[i]);
        if(esCliente){
            atendido = validarPedidoAtendido(arrPedidos[i]);
            if(atendido){
                pedido = asignarPed(arrPedidos[i]);
                pedsCliente[numPedidos] = pedido;
                numPedidos++;
            }
        }
        
    }
    pedsCliente[numPedidos] = nullptr;
    numPedidos++;
    pedidosCliente = new void*[numPedidos];
    for (int i=0; i<numPedidos; i++){
        pedidosCliente[i] = pedsCliente[i];
    }
    cliDatos[PEDIDOS_CLI] = pedidosCliente;
    
}

int validarClientePedido(int dni, void *pedido){
    void **datosPedido = (void**)pedido;
    int *ptrDni = (int*)(datosPedido[DNI]);
    
    if (dni ==*ptrDni) return 1;
    return 0;
}

int validarPedidoAtendido( void *pedido){
    void **datos = (void**)pedido;
    
    char *est = (char*)(datos[ESTADO]);
    
    if (*est =='A') return 1;
    else return 0;
}


//enum Pedido{CODIGO, NOMBRE, CANTIDAD, DNI, FECHA, ESTADO};
//enum Cliente{DNI_CLI, NOMBRE_CLI, PEDIDOS_CLI};

void * asignarPed(void *pedido){
    void **datos = (void**)(pedido);
    void **newPed = new void*[4];
    
    newPed [0] = datos[FECHA];
    newPed [1] = datos[CODIGO];
    newPed [2] = datos[NOMBRE];
    newPed [3] = datos[CANTIDAD];
    
    return newPed;
    
}

void imprimereporte(void *clientes){
    
    
    imprimereporte(clientes);
}