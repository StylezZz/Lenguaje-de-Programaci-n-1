/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funcionesPreg2.h"
#define MAXLINEAS 100
#define INCREMENTO 5
using namespace std;

//char **clientes,***strProductos;
//    int ***intProductos;
void leerDatos(char **&clientes,int ***&intProductos,char ***&strProductos){
    ifstream arch("pedidos.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo pedidos.csv"<<endl;
        exit(1);
    }
    //Inicializacion de los punteros
    clientes = nullptr;
    intProductos = nullptr;
    strProductos = nullptr;
    
    int ruc,numCliente=0,capClientes=0,codProducto,cant;
    int capProd[20]{0}, numProd[20]{0};
    char c,*nombre,fecha[20],*nombreProd;
    int ind;
    while(1){
        arch>>ruc>>c;
        if(arch.eof())break;
        nombre = leerCadena(arch);
        if(numCliente==capClientes){
            cout<<"Entrar a incrementar"<<endl;
            incrementarEspacios(clientes,intProductos,strProductos,numCliente,capClientes);
        }
        clientes[numCliente]=nullptr;
        clientes[numCliente-1]=nombre;
        numCliente++;
        //El numCliente despues del incremento es 1, por eso se pone el nullptr
        //Se guarda en el numDatos-1 el valor del nombre del cliente y se aumenta
        //Y como sería 2 el valor final y los pedidos estan en orden de cliente
        //Osea en la linea estan los pedidos que pidio un cliente con dif fecha
        //La posicion siempre sera la final - 2
        //En la primera iteración sería el numClientes acabaría en 2
        int posCliente = numCliente-2;
        while(arch.get()!='\n'){
            arch.getline(fecha,20,',');
            arch>>codProducto>>c;
            nombreProd = leerCadena(arch);
            arch>>cant;
            if(capProd[posCliente]==numProd[posCliente]){
                incrementarEspacios2(intProductos[posCliente],strProductos[posCliente],
                        numProd[posCliente],capProd[posCliente]);
            }
            ind = buscarProducto(intProductos[posCliente],codProducto,numProd[posCliente]);
            if(ind==-1){
                agregarProducto(intProductos[posCliente],strProductos[posCliente],codProducto,nombreProd,cant,numProd[posCliente]);
            }else{
                intProductos[posCliente][ind][1]+=cant;
            }
        }
    }
}

void agregarProducto(int **intProd,char **strProd,int cod,char *nombre,int cant,int &num){
    int *infoP;
    infoP = new int[2];
    infoP[0]=cod;
    infoP[1]=cant;
    intProd[num-1]=infoP;
    intProd[num]=nullptr;
    strProd[num]=nullptr;
    strProd[num-1]=nombre;
    num++;
}

int buscarProducto(int **intProducto,int cod,int num){
    for(int i=0;i<num-1;i++){
        if(cod==intProducto[i][0]){
            return i;
        }
    }
    return -1;
}

void incrementarEspacios2(int **&intProd, char **&strProd,int &numDat,int &cap){
    char **auxStProd;
    int **auxIntProd;
    cap+=INCREMENTO;
    if(intProd==nullptr){
        intProd = new int*[cap]{};
        strProd = new char*[cap]{};
        
        intProd[0]=nullptr;
        strProd[0]=nullptr;
        numDat=1;
    }else{
        auxIntProd = new int*[cap]{};
        auxStProd = new char*[cap]{};
        for(int i=0;i<numDat;i++){
            auxIntProd[i]=intProd[i];
            auxStProd[i]=strProd[i];
        }
        delete intProd;
        delete strProd;
        intProd = auxIntProd;
        strProd = auxStProd;
    }
}

void incrementarEspacios(char **&clientes,int ***&intProductos,char ***&strProducto,int &numDatos,int &cap){
    char **auxClientes,***auxStrProducto;
    int ***auxProductos;
    cap+=INCREMENTO;
    if(clientes==nullptr){
        clientes = new char*[cap]{};
        intProductos = new int**[cap]{};
        strProducto = new char**[cap]{};
        clientes[0]=nullptr;
        intProductos[0]=nullptr;
        strProducto[0]=nullptr;
        numDatos=1;
    }else{
        auxClientes = new char*[cap]{};
        auxStrProducto= new char**[cap]{};
        auxProductos = new int**[cap]{};
        for(int i=0;i<numDatos;i++){
            auxClientes[i]=clientes[i];
            auxStrProducto[i]=strProducto[i];
            auxProductos[i]=intProductos[i];
        }
        delete clientes;
        delete strProducto;
        delete intProductos;
        clientes = auxClientes;
        strProducto = auxStrProducto;
        intProductos = auxProductos;
    }
}

char* leerCadena(ifstream &arch){
    char buff[200],*cad;
    arch.getline(buff,200,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void imprimirDatos(char **clientes,int ***intProductos,char ***strProductos){
    ofstream arch("ReportePregunta2.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReportePregunta2.txt"<<endl;
        exit(1);
    }
     ordenarPedidos(clientes,intProductos,strProductos);
    arch << setw(60) << "REPORTE DE ATENCION" << endl;
    for (int i = 0; clientes[i] ; i++) {
        arch << "Cliente: " << clientes[i] << endl;
        imprimirLineas(arch,'=');
        arch << setw(15) << "Cod. Producto"
                << setw(20) << "Producto"
                << setw(55) << "Cant. Solicitada" << endl;
        imprimirLineas(arch,'=');
        for (int j = 0; intProductos[i][j]; j++) {
            arch << setw(12) << intProductos[i][j][0]
                    << setw(10) << " "
                    << left << setw(50) << strProductos[i][j]
                    << right << setw(15) << intProductos[i][j][1] << endl;
        }
        arch << endl;
    }
    
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++){
        arch<<c;
    }
    arch<<endl;
}

void ordenarPedidos (char **clientes, int ***intProductos, char ***strProductos) {
    int numPedidos;
    for (int i = 0; clientes[i] ; i++) {
        for (numPedidos = 0; intProductos[i][numPedidos] ; numPedidos++);
        ordenar(intProductos[i],strProductos[i],0,numPedidos-1);
    }
}

void ordenar (int **intProductos, char **strProductos, int izq, int der) {
    int limite;
    if (izq >= der) return;
    cambiarINT(intProductos,izq,(izq+der)/2);
    cambiarSTR(strProductos,izq,(izq+der)/2);
    limite = izq;
    for (int i = izq; i <= der; i++) {
        if (intProductos[i][1] > intProductos[izq][1]) {
            cambiarINT(intProductos,++limite,i);
            cambiarSTR(strProductos,limite,i);
        }
    }
    cambiarINT(intProductos,izq,limite);
    cambiarSTR(strProductos,izq,limite);
    ordenar(intProductos,strProductos,izq,limite-1);
    ordenar(intProductos,strProductos,limite+1,der);
}

void cambiarINT (int **num, int i, int k) {
    int *auxINT;
    auxINT = num[i];
    num[i] = num[k];
    num[k] = auxINT;
}

void cambiarSTR (char **str, int i, int k) {
    char *auxSTR;
    auxSTR = str[i];
    str[i] = str[k];
    str[k] = auxSTR;
}

