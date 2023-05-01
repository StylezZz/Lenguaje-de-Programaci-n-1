/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
#define INCREMENTO 5
using namespace std;

char *asignarCadena(char *cadena){
    char *st;
    st = new char[strlen(cadena)+1];
    strcpy(st,cadena);
    return st;
}

void incrementarEspacios(char **&productos,int &numProd,int &cap){
    char **aux;
    cap+=INCREMENTO;
    if(productos==nullptr){
        productos = new char*[cap];
        productos[0]=nullptr;
        numProd=1;
    }else{
        aux = new char*[cap];
        for(int i=0;i<numProd;i++){
            aux[i]=productos[i];
        }
        delete productos;
        productos=aux;
    }
}

char **leerAlmacen(ifstream &arch){
    static int codAlmAnt=0;
    static char codProdAnt[100];
    static bool cambio = false;
    
    int codAlm=0;
    char codProd[100],codPalet[100];
    
    char **productos=nullptr;
    int numProd=0,cap=0;
    
    if(cambio){
        if(numProd==cap){
            incrementarEspacios(productos,numProd,cap);
        }
        productos[numProd]=nullptr;
        productos[numProd-1]=asignarCadena(codProdAnt);
        numProd++;
        cambio=false;
    }
    
    while(!cambio){
        arch>>codAlm;
        if(arch.eof())break;
        arch>>codProd>>codPalet;
        if(codAlmAnt ==0 || codAlmAnt == codAlm){
            if(numProd == cap){
                incrementarEspacios(productos,numProd,cap);
            }
            productos[numProd]=nullptr;
            productos[numProd-1]=asignarCadena(codProd);
            numProd++;
        }else{
            cambio=true;
        }
        codAlmAnt = codAlm;
        strcpy(codProdAnt,codProd);
    }
    return productos;
}

void leerPalets(char ***&almacenes){
    char **buffer[200],**alm;
    int numAlmacenes=0;
    ifstream archLectura("Stock.txt",ios::in);
    if(!archLectura){
        cout<<"ERROR no se pudo abrir el archivo Stock.txt"<<endl;
        exit(1);
    }
    while(1){
        alm = leerAlmacen(archLectura);
//        if(alm==nullptr)break;  ==> no funciona
        buffer[numAlmacenes]= alm;
        numAlmacenes++;
        if(archLectura.eof())break;
    }
    buffer[numAlmacenes] = nullptr;
    numAlmacenes++;
    almacenes = new char **[numAlmacenes];
    for(int i=0;i<numAlmacenes;i++){
        almacenes[i]=buffer[i];
    }
    
}

void imprimirPalets(char ***almacenes){
    ofstream archAlmacenes("Reporte_Alm.txt",ios::out);
    if(!archAlmacenes){
        cout<<"ERROR no se pudo abrir el archivo Reporte_Alm.txt"<<endl;
        exit(1);
    }
    archAlmacenes<<"Productos en los almacenes"<<endl;
    for(int i=0;almacenes[i];i++){
        archAlmacenes<<"Almacen No. "<<setw(3)<<i+1<<endl;
        for(int j=0;almacenes[i][j];j++){
            archAlmacenes<<almacenes[i][j]<<endl;
        }
        archAlmacenes<<endl;
    }
}


char  *leerCadena(ifstream &in,char c){
    char buff[100],*cad;
    in.getline(buff,100,c);
    if(in.eof())return nullptr;
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void leerProductos(char **&codigoProd,char **&nombreProd){
    ifstream archLectura("producto.txt",ios::in);
    if(!archLectura){
        cout<<"ERROR no se pudo abrir el archivo producto.txt"<<endl;
        exit(1);
    }
    char *bufferCodigo[200],*bufferNombre[200],*codPro,*nombProd;
    int numProd=0;
    while(1){
        codPro = leerCadena(archLectura,',');
        if(codPro==nullptr)break;
        nombProd = leerCadena(archLectura);
        bufferCodigo[numProd]=codPro;
        bufferNombre[numProd]=nombProd;
        numProd++;
    }
    bufferCodigo[numProd]==nullptr;
    bufferNombre[numProd]==nullptr;
    numProd++;
    
    codigoProd = new char*[numProd];
    nombreProd = new char*[numProd];
    for(int i=0;i<numProd;i++){
        codigoProd[i]=bufferCodigo[i];
        nombreProd[i]=bufferNombre[i]; 
    }
}

void imprimirProductos(char **codigoProd,char **nombreProd){
    ofstream archProductos("Reporte_Prod.txt",ios::out);
    if(!archProductos){
        cout<<"ERROR no se pudo abrir el archivo Reporte_Prod.txt"<<endl;
        exit(1);
    }
    archProductos<<"Productos en el almacen"<<endl;
    archProductos<<left<<setw(10)<<"CODIGO"<<"NOMBRE"<<endl;
    for(int i=0;codigoProd[i];i++){
        archProductos<<setw(10)<<codigoProd[i]
                <<nombreProd[i]<<endl;
    }
    
}

void ordenarProductos(char **codigoProd,char **nombreProd){
    int numProd;
    for(numProd=0;codigoProd[numProd];numProd++);
    ordenar(codigoProd,nombreProd,0,numProd-1);
}

void ordenar(char **codigoProd,char **nombreProd,int izq,int der){
    int limite;
    if(izq>=der)return;
    cambiar(codigoProd,izq,(izq+der)/2);
    cambiar(nombreProd,izq,(izq+der)/2);
    limite=izq;
    for(int i=izq+1;i<=der;i++){
        if(strcmp(nombreProd[i],nombreProd[izq])<0){
            cambiar(codigoProd,++limite,i);
            cambiar(nombreProd,limite,i);
        }
    }
    cambiar(codigoProd,izq,limite);
    cambiar(nombreProd,izq,limite);
    ordenar(codigoProd,nombreProd,izq,limite-1);
    ordenar(codigoProd,nombreProd,limite+1,der);
}


void cambiar(char **st,int i,int k){
    char *aux;
    aux = st[i];
    st[i]=st[k];
    st[k]=aux;
}

void cuentaProductos(char ***almacenes,char **codigoProd,char **nombreProd){
    ofstream archReporte("ReporteFinal.txt",ios::out);
    if(!archReporte){
        cout<<"ERROR no se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    archReporte<<"Cuenta productos en los almacenes"<<endl;
    archReporte<<left<<setw(60)<<"Nombre del producto"<<setw(25)<<"Codigo del Producto"<<
            setw(20)<<"Cantidad de Palets"<<endl;
    for(int i=0;i<110;i++)archReporte.put('-');
    archReporte<<endl;
    
    for(int i=0;codigoProd[i];i++){
        archReporte<<left<<setw(65)<<nombreProd[i]
                <<setw(20)<<codigoProd[i]<<right<<setw(10)<<contar(codigoProd[i],almacenes)
                <<endl;
    }
}

int contar(char *codigoProd,char ***almacenes){
    int cant=0;
    for(int i=0;almacenes[i];i++){
        for(int j=0;almacenes[i][j];j++){
            if(strcmp(codigoProd,almacenes[i][j])==0){
                cant++;
            }
        }
    }
    return cant;
}
