/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define MAXLINEAS 100
#include "funcionesPreg1.h"
using namespace std;
enum reg{FECHA,RUC,CODPRODUCTO,NOMBREPROD,CANTSOL,CANTATEN};

void leerDatos(void *&pedidos,void *&stock){
    ifstream archPedidos("pedidos.csv",ios::in);
    if(!archPedidos){
        cout<<"Error no se pudo abrir el archivo pedidos.csv"<<endl;
        exit(1);
    }
    ifstream archStock("stock.csv",ios::in);
    if(!archStock){
        cout<<"Error no se pudo abrir el archivo stock.csv"<<endl;
        exit(1);
    }
    ofstream archReporteStock("ReporteStock.txt",ios::out);
    if(!archReporteStock){
        cout<<"Error no se pudo abrir el archivo ReporteStock.txt"<<endl;
        exit(1);
    }
    ofstream archReportePedidos("ReportePedidos.txt",ios::out);
    if(!archReporteStock){
        cout<<"Error no se pudo abrir el archivo ReportePedidos.txt"<<endl;
        exit(1);
    }
    //Leer el stock primero
    leerPedidos(pedidos,archPedidos);
//    cout<<"Termine de leer los pedidos"<<endl;
    imprimirPedidos(pedidos,archReportePedidos);
    leerStock(stock,archStock);
//    cout<<"Termine de leer el stock"<<endl;
    imprimirStock(stock,archReporteStock);
    
}

char *leerCadena(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void leerPedidos(void *&pedidos,ifstream &arch){
    void **auxPedido,*buffPedido[200],*var;
    int numDatos=0,codRuc,dd,mm,aa,codProd,cantPedida,cantSolicitada=0;
    char *nombreTienda,*nombreProd,c;
    while(1){
        arch>>codRuc>>c;
        if(arch.eof())break;
        nombreTienda = leerCadena(arch);
        while(1){
            arch>>dd>>c>>mm>>c>>aa>>c>>codProd>>c;
            nombreProd = leerCadena(arch);
            arch>>cantPedida;
            var = devolverPedido(codRuc,dd,mm,aa,codProd,nombreProd,cantPedida,cantSolicitada);
            buffPedido[numDatos]=var;
            numDatos++;
            if(arch.get()=='\n')break;
        }
    }
    buffPedido[numDatos]=nullptr;
    numDatos++;
    auxPedido = new void*[numDatos];
    for(int i=0;i<numDatos;i++){
        auxPedido[i]=buffPedido[i];
    }
    pedidos = auxPedido;
}

void *devolverPedido(int codRuc,int dd,int mm,int aa,int codProd,char *nomProd,int cantPedida,
        int cantSolicitada){
    void **ped;
    ped = new void*[6];
    int *ptrCodRuc,*ptrFecha,*ptrCodProd,*ptrCantPedida,*ptrCantSolicitada;
    ptrCodRuc = new int;
    ptrFecha = new int;
    ptrCodProd = new int;
    ptrCantPedida = new int;
    ptrCantSolicitada = new int;
    
    *ptrCodRuc = codRuc;
    *ptrFecha = aa*10000+mm*100+dd;
    *ptrCodProd = codProd;
    *ptrCantPedida = cantPedida;
    *ptrCantSolicitada = cantSolicitada;
    
    ped[FECHA] = ptrFecha;
    ped[RUC] = ptrCodRuc;
    ped[CODPRODUCTO]= ptrCodProd;
    ped[NOMBREPROD]= nomProd;
    ped[CANTSOL]=ptrCantPedida;
    ped[CANTATEN]=ptrCantSolicitada;
    return ped;
}

void imprimirPedidos(void *pedidos,ofstream &arch){
    arch<<"Reporte de pedido"<<endl;
    imprimirLineas(arch,'=');
    arch<<"Fecha"<<setw(15)<<right<<"RUC"<<setw(15)<<right<<"Cod.Producto"<<
            setw(15)<<right<<"Nombre-Prod"<<setw(15)<<right<<"Cant.Sol"<<setw(15)
            <<right<<"Cant.Atendida"<<endl;
    void **auxPed = (void**)pedidos;
    for(int i=0;auxPed[i];i++){
        imprimirPedido(auxPed[i],arch);
    }
}

void imprimirPedido(void *ped,ofstream &arch){
    void **aux = (void**)ped;
    int *fecha = (int*)(aux[FECHA]);
    int *ruc = (int*)(aux[RUC]);
    int *codProd = (int*)(aux[CODPRODUCTO]);
    char *nombreProd = (char*)(aux[NOMBREPROD]);
    int *cantSol = (int*)(aux[CANTSOL]);
    int *cantAten = (int*)(aux[CANTATEN]);
    
    arch<<*fecha<<setw(15)<<right<<*ruc<<setw(15)<<right<<*codProd<<
            setw(15)<<right<<nombreProd<<setw(15)<<right<<*cantSol<<setw(15)
            <<right<<*cantAten<<endl;
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++)arch<<c;
    arch<<endl;
}

void imprimirStock(void *stock,ofstream &arch){
    arch<<"Reporte de Stock"<<endl;
    imprimirLineas(arch,'=');
    arch<<"Cod.Producto"<<setw(30)<<right<<"Cantidad"<<endl;
    imprimirLineas(arch,'=');
    void **auxStock = (void**)stock;
    
    for(int i=0;auxStock[i];i++){
        mostrarStock(auxStock[i],arch);
    }
}

void mostrarStock(void *stock,ofstream &arch){
    void **aux = (void**)stock;
    int *codProd = (int*)(aux[0]);
    int *cant = (int*)(aux[1]);
    
    arch<<*codProd<<setw(30)<<right<<*cant<<endl;
}

void leerStock(void *&stock,ifstream &arch){
    void **auxStock,*buff[200],*aux;
    int numDatos=0;
    while(1){
        aux = leerDato(arch);
        if(aux==nullptr)break;
        buff[numDatos]=aux;
        numDatos++;
    }
    buff[numDatos]=nullptr;
    numDatos++;
    auxStock = new void*[numDatos];
    for(int i=0;i<numDatos;i++){
        auxStock[i]=buff[i];
    }
    stock = auxStock;
}

void* leerDato(ifstream &arch){
    void **stock;
    char c;
    int codPro,cantPro;
    int *ptrCodPro,*ptrCantPro;
    ptrCantPro = new int;
    ptrCodPro = new int;
    
    stock = new void*[2];
    arch>>codPro>>c;
    if(arch.eof())return nullptr;
    arch>>cantPro;
    
    *ptrCantPro = cantPro;
    *ptrCodPro = codPro;
    stock[0]=ptrCodPro;
    stock[1]=ptrCantPro;
    return stock;
    
}

void atiende(void *pedidos,void *stock){
    
    ofstream archPedidos("ReportePedidosAtendidos.txt",ios::out);
    ofstream archStock("ReporteStockAtendidos.txt",ios::out);
    ordenarPedidos(pedidos,1);
    
    void **auxPedidos = (void**)pedidos;
    
    for(int i=0;auxPedidos[i];i++){
        atenderPedido(auxPedidos[i],stock);
    }
    imprimirPedidos(pedidos,archPedidos);
    imprimirStock(stock,archStock);
}

//enum reg{FECHA,RUC,CODPRODUCTO,NOMBREPROD,CANTSOL,CANTATEN};
void atenderPedido(void *ped,void *stock){
    void **pedido = (void **)ped;
    int *codP = (int *)pedido[CODPRODUCTO];
    int *cantS = (int *)pedido[CANTSOL];
    int *cantA = (int *)pedido[CANTATEN];
    int despacho = actualizarStock(*codP,*cantS,stock);
    (*cantA) = despacho;
}

int actualizarStock(int codigo,int cantSol, void *stock){
    void **auxStock = (void**)stock;
    int devuelve;
    for(int i=0;auxStock[i];i++){
        void **sto = (void**)auxStock[i];
        int *cod = (int*)sto[0];
        int *ss = (int*)sto[1];
        if(codigo == *cod){
            if((*ss)-cantSol>0){
                devuelve = cantSol;
                (*ss)-=cantSol;
            }else{
                devuelve = (*ss);
                (*ss)=0;
            }
            return devuelve;
        }
    }
}

void ordenarPedidos(void *pedidos,int opc){
    int cant=0;
    void **aux = (void**)pedidos;
    for(cant=0;aux[cant];cant++);
    qsortPedidos(aux,0,cant-1,opc);
//    cout<<"Termine de ordenar"<<endl;
}

void qsortPedidos(void **pedidos,int izq,int der,int opc){
    int limite;
    if (izq >= der) return;
    cambiar (pedidos[izq],pedidos[(izq+der)/2]);
    limite = izq;
    for (int i = izq+1; i <= der ; i++) {
        if (comparar(pedidos[i],pedidos[izq],opc) < 0) {
            cambiar(pedidos[++limite],pedidos[i]);
        }
    }
    cambiar(pedidos[izq],pedidos[limite]);
    qsortPedidos(pedidos,izq,limite-1,opc);
    qsortPedidos(pedidos,limite+1,der,opc);
}

void cambiar(void *&pedido1,void *&pedido2){
    void *aux;
    aux = pedido1;
    pedido1 = pedido2;
    pedido2 = aux;
}

int comparar(void *p1,void *p2,int opc){
    void **user1 = (void**)p1;
    void **user2 = (void**)p2;
    if(opc==1){
        int *fecha1 = (int*)user1[FECHA];
        int *fecha2 = (int*)user2[FECHA];
        return (*fecha1)-(*fecha2);
    }else{
        int *ruc1 = (int*)user1[RUC];
        int *ruc2 = (int*)user2[RUC];
        return (*ruc1)-(*ruc2);
    }
}

void imprimirDatos(void *pedidos,void *stock){
    ofstream arch("ReporteFinal.txt",ios::out);
    ordenarPedidos(pedidos,2);
    void **pedido = (void **)pedidos;
    int rucAnt = -1;
    for (int i = 0; pedido[i] ; i++) {
        void **ped = (void **)pedido[i];
        int *ruc = (int *)ped[RUC];
        int *fecha = (int *)ped[FECHA];
        int *codP = (int *)ped[CODPRODUCTO];
        char *nombP = (char *)ped[NOMBREPROD];
        int *cantS = (int *)ped[CANTSOL];
        int *cantA = (int *)ped[CANTATEN];
        if (rucAnt == -1 || (*ruc) != rucAnt) {
            arch << endl << "RUC: " << *ruc << endl;
            imprimirLineas(arch,'=');
            arch << "  Fecha" << setw(25) << "Cod. Producto"
                << setw(25) << "Producto" << setw(50) << "Cant. solicitada"
                << setw(20) << "Cant. Atendida" << endl;
            imprimirLineas(arch,'=');
            rucAnt = *ruc;
        } 
        imprimePedidoF(*ruc,*fecha,*codP,nombP,*cantS,*cantA,arch);
    }
}

void imprimePedidoF (int ruc, int fecha, int codP, char *nombP, int cantS, int cantA,
        ofstream &arch) {
    int f = fecha;
    int aa = f/10000;
    f = f%10000;
    int mm = f/100;
    int dd = f%100;
    arch << setw(5) << " ";
    arch.fill('0');
    arch << aa << '/' << setw(2) << mm << '/' << setw(2) << dd;
    arch.fill(' ');
    arch << setw(10) << codP
            << setw(10) << " "
            << left << setw(55) << nombP
            << right << setw(10) << cantS
            << setw(15) << cantA << endl;
}