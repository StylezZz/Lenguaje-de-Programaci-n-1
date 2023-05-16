/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEx01_20211_Preg02.cpp
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 25 de mayo de 2021, 09:43 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesEx01_20211_Preg02.h"
#define MAX_LINEA 200
enum Conductor{LICENCIA,NOMBRE};
enum Falta{CODINFRACCION,DESCRIPCION,MONTO};
enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};

void cargadatos(void *&conductor,void *&falta){
    leerConductores(conductor);
    imprimeConductor(conductor);
    leerFaltas(falta);
    imprimefalta(falta);
}

void leerConductores(void *&conductor){
    ifstream archConductores("Conductores.csv",ios::in);
    if(!archConductores){
        cout<<"ERROR: NO se puede abrir el archivo Conductores.csv"<<endl;
    }
    
    int numConductores=0;
    void *conductorBuff[200], **aux, *auxConductor;
    
    while(1){
        auxConductor=leeConductor(archConductores);
        if(archConductores.eof()) break;
        conductorBuff[numConductores]=auxConductor;
        numConductores++;
    }
    
    conductorBuff[numConductores]=nullptr;
    aux=new void*[numConductores+1];
    
    for(int i=0;i<numConductores+1;i++){
        aux[i]=conductorBuff[i];
    }
    
    conductor=aux;
    
}

void* leeConductor(ifstream &archConductores){
    
    int licenciaAux,*licencia;
    char *nombre;
    
    archConductores>>licenciaAux;
    if(archConductores.eof()) return nullptr;
    licencia=new int;
    *licencia=licenciaAux;
    archConductores.get();
    nombre=leerCadena(archConductores,'\n');
    
    void **registro;
    registro=new void*[2];
    //enum Conductor{LICENCIA,NOMBRE};
    registro[LICENCIA]=licencia;
    registro[NOMBRE]=nombre;
    
    return registro;
}

char * leerCadena(ifstream &archConductores,char car){
    char aux[500],*ptAux;
    archConductores.getline(aux,500,car);
    if(archConductores.eof()) return nullptr;
    ptAux=new char[strlen(aux)+1];
    strcpy(ptAux,aux);
    return ptAux;
}

void imprimeConductor(void *conductor){
    ofstream archMuestraConductores("MuestraConductores.txt",ios::out);
    if(!archMuestraConductores){
        cout<<"ERROR: NO se puede abrir el archivo MuestraConductores.txt"<<endl;
    }
    
    void **lconductor=(void **)conductor;
    
    archMuestraConductores<<"Licencia"<<setw(11)<<"Nombre"<<endl;
    for(int i=0;lconductor[i];i++){
        imprimirConductor(lconductor[i],archMuestraConductores);
    }
}

void imprimirConductor(void *conductorReg,ofstream &archMuestraConductores){
    void **registroConductor=(void **)conductorReg;
    int *licencia;
    char *nombre;
    
    licencia=(int *)registroConductor[LICENCIA];
    nombre=(char *)registroConductor[NOMBRE];
    
    archMuestraConductores<<*licencia<<setw(5)<<" "<<left<<setw(50)<<nombre<<endl<<right;
}

void leerFaltas(void *&falta){
    ifstream archInfracciones("Infracciones.csv",ios::in);
    if(!archInfracciones){
        cout<<"ERROR: NO se puede abrir el archivo Infracciones.csv"<<endl;
    }
    
    int numInfracciones=0;
    void *infraccionesBuff[200], **aux, *auxInfraccion;
    
    while(1){
        auxInfraccion=leeInfraccion(archInfracciones);
        if(archInfracciones.eof()) break;
        infraccionesBuff[numInfracciones]=auxInfraccion;
        numInfracciones++;
    }
    
    infraccionesBuff[numInfracciones]=nullptr;
    aux=new void*[numInfracciones+1];
    
    for(int i=0;i<numInfracciones+1;i++){
        aux[i]=infraccionesBuff[i];
    }
    
    falta=aux;
}

void* leeInfraccion(ifstream &archInfracciones){
    int codInfraccionAux, *codInfraccion;
    char *descripcion,aux[50];
    double *monto;
    
    archInfracciones>>codInfraccionAux;
    if(archInfracciones.eof()) return nullptr;
    codInfraccion=new int;
    *codInfraccion=codInfraccionAux;
    archInfracciones.get();
    descripcion=leerCadena(archInfracciones,',');
    archInfracciones.getline(aux,50,',');
    monto=new double;
    archInfracciones>>*monto;
    
    void **registro;
    //enum Falta{CODINFRACCION,DESCRIPCION,MONTO};
    registro=new void*[3];
    registro[CODINFRACCION]=codInfraccion;
    registro[DESCRIPCION]=descripcion;
    registro[MONTO]=monto;
    
    return registro;
}

void imprimefalta(void *falta){
    int i=0;
    void **laux = (void**)falta;
    ofstream arch("repfalta.txt",ios::out);
    if(!arch){
        cout << "No se puede leer";
        exit(1);
    }

    while(1){
        if(laux[i]==NULL) break; 
        imprimefaltareg(arch,laux[i]);
        i++;
    }
      
}

void imprimefaltareg(ofstream &arch,void *registro){
    void **laux = (void**)registro;
    int *codigo;
    char *nombre;
    double *monto;
    
    codigo = (int*)laux[0];
    nombre = (char*)laux[1];
    monto = (double*)laux[2];
    
    arch <<left<<setw(20)<< *codigo << setw(200)<< nombre 
            << setprecision(2) << fixed << setw(20)<< *monto << endl;
    
}


void registrafaltas(void *&consolidado,void *conductor,void *falta){
    ifstream archRegistroDeFaltas("RegistroDeFaltas.csv",ios::in);
    if(!archRegistroDeFaltas){
        cout<<"ERROR: NO se puede abrir el archivo RegistroDeFaltas.csv"<<endl;
    }
    
    void *consolidadoBuff[1000]{},**aux;
    
    int licenciaArch,dd,mm,aa,codInfraccionArch,pos,fechaArch,numConsolidados=0;
    char placaArch[20],car;
    
    while(1){
        archRegistroDeFaltas>>licenciaArch;
        if(archRegistroDeFaltas.eof()) break;
        archRegistroDeFaltas.get();
        archRegistroDeFaltas.getline(placaArch,20,',');
        archRegistroDeFaltas>>dd>>car>>mm>>car>>aa;
        archRegistroDeFaltas.get();
        archRegistroDeFaltas>>codInfraccionArch;
        
        asignarConductoresConsolidado(consolidadoBuff,conductor,falta,licenciaArch,mm,aa,codInfraccionArch,
                numConsolidados);
        numConsolidados++;
    }
    
    consolidadoBuff[numConsolidados]=nullptr;
    aux=new void*[numConsolidados+1]{};
    
    for(int i=0;i<numConsolidados+1;i++){
        aux[i]=consolidadoBuff[i];
    }

    consolidado=aux;
    
}

void asignarConductoresConsolidado(void **consolidadoBuff,void *conductor,void *falta,int licenciaArch,
        int mmArch,int aaArch,int codInfraccionArch,int numConsolidados){
    void **lfalta=(void **)falta;
    int pos,posInfraccion;
    pos=buscarConductorConsolidado(consolidadoBuff,licenciaArch,mmArch,aaArch);
    if(pos!=-1){ //Existe en el consolidado, se acumula
        void **registroConsolidado=(void **)consolidadoBuff[pos];
        //enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
        double *monto=(double *)registroConsolidado[MONTOTOTAL];
        posInfraccion=buscarFalta(codInfraccionArch,falta);
        //enum Falta{CODINFRACCION,DESCRIPCION,MONTO};
        void **registroInfraccion=(void **)lfalta[posInfraccion];
        double *montoInfraccion=(double *)registroInfraccion[MONTO];
        *monto+=*montoInfraccion;
    }
    else{
        void **registroNuevo;
        registroNuevo=new void*[5];
        int *licencia, *mm, *aa;
        char *nombre;
        double *montoConsolidado;
        licencia=new int;
        mm=new int;
        aa=new int;
        nombre=asignarNombre(conductor,licenciaArch);
        montoConsolidado=new double{};
        *licencia=licenciaArch;
        *aa=aaArch;
        *mm=mmArch;
        *montoConsolidado=0;
        
        registroNuevo[CODLICENCIA]=licencia;
        registroNuevo[NOMBRECOND]=nombre;
        registroNuevo[AA]=aa;
        registroNuevo[MM]=mm;
        registroNuevo[MONTOTOTAL]=montoConsolidado;
        
        consolidadoBuff[numConsolidados]=registroNuevo;
    }
}

int buscarFalta(int codInfraccionArch,void *falta){
    void **lfalta=(void **)falta;
    for(int i=0;lfalta[i];i++){
        void **registroFalta=(void **)lfalta[i];
        //enum Falta{CODINFRACCION,DESCRIPCION,MONTO};
        int *codInfraccion=(int *)registroFalta[CODINFRACCION];
        if(*codInfraccion==codInfraccionArch) return i;
    }
    return -1;
}

char * asignarNombre(void *conductor,int licenciaArch){
    void **lconductor=(void **)conductor;
    for(int i=0;lconductor[i];i++){
        void **registroConductor=(void **)lconductor[i];
        //enum Conductor{LICENCIA,NOMBRE};
        int *licencia=(int *)registroConductor[LICENCIA];
        char *nombre=(char *)registroConductor[NOMBRE];
        if(*licencia==licenciaArch){
            char *ptAux;
            ptAux=new char[strlen(nombre)+1];
            strcpy(ptAux,nombre);
            return ptAux;
        }
    }
    return nullptr;
}

int buscarConductorConsolidado(void **consolidadoBuff,int licenciaArch,int mmArch,int aaArch){
    if(consolidadoBuff==nullptr);
    for(int i=0;consolidadoBuff[i];i++){
        void **registroConsolidado=(void **)consolidadoBuff[i];
        //enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
        int *licencia=(int *)registroConsolidado[CODLICENCIA];
        int *aa=(int *)registroConsolidado[CODLICENCIA];
        int *mm=(int *)registroConsolidado[CODLICENCIA];
        if(*licencia==licenciaArch && *aa==aaArch && *mm==mmArch) return i;
    }
    return -1;
}

void imprime(void *consolidado){
    //Ordenamos segun lo pedido
    ordenarConsolidado(consolidado);
    //Ya está ordenado, falta imprimir
    ofstream archReporte("Reporte.txt",ios::out);
    if(!archReporte){
        cout<<"ERROR: NO se puede abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    void **lconsolidado=(void **)consolidado;
    
    archReporte<<setw(45)<<"REPORTE CONSOLIDADO DE MULTAS"<<endl;
    for(int i=0;lconsolidado[i];i++){
        imprimirCadaConsolidado(lconsolidado[i],archReporte);
    }
    
}

void imprimirCadaConsolidado(void *consolidadoReg,ofstream &archReporte){
    void **registroConsolidado=(void **)consolidadoReg;
    
    //enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
    
    int *licencia=(int *)registroConsolidado[CODLICENCIA];
    char *nombre=(char *)registroConsolidado[NOMBRECOND];
    
    imprimirLinea('=',MAX_LINEA,archReporte);
    archReporte<<*licencia<<setw(5)<<" "<<left<<setw(50)<<nombre<<endl;
    imprimirLinea('=',MAX_LINEA,archReporte);
    
}

void ordenarConsolidado(void *consolidado){
    void **lconsolidado=(void **)consolidado;
    int numConductores=0;
    for(numConductores=0;lconsolidado[numConductores];numConductores++);
    qsortConductores(consolidado,0,numConductores-1);
}

void qsortConductores(void *consolidado,int izq,int der){
    void **lconsolidado=(void **)consolidado;
    int limite;
    if(izq>=der) return;
    cambiar(lconsolidado[izq],lconsolidado[(izq+der)/2]);
    limite=izq;
    for(int i=izq+1;i<=der;i++){
        if(comparar(lconsolidado[i],lconsolidado[izq])<0){
            cambiar(lconsolidado[++limite],lconsolidado[i]);
        }
    }
    cambiar(lconsolidado[izq],lconsolidado[limite]);
    qsortConductores(lconsolidado,izq,limite-1);
    qsortConductores(lconsolidado,limite+1,der);
}

void cambiar(void *&i, void *&k){
    void *aux;
    aux=i;
    i=k;
    k=aux;
}

int comparar(void *registroI,void *registroK){
    void **registroConductorI=(void **)registroI;
    void **registroConductorK=(void **)registroK;
    //enum Consolidado{CODLICENCIA,NOMBRECOND,AA,MM,MONTOTOTAL};
    int *licenciaI=(int *)registroConductorI[CODLICENCIA];
    int *licenciaK=(int *)registroConductorK[CODLICENCIA];
    int *aaI=(int *)registroConductorI[AA];
    int *aaK=(int *)registroConductorK[AA];
    int *mmI=(int *)registroConductorI[MM];
    int *mmK=(int *)registroConductorK[MM];
    if(*licenciaI==*licenciaK){
        if(*aaI==*aaK)
            return *aaI-*aaK;
        else
            return *mmI-*mmK;
    }
    else
        return *licenciaI-*licenciaK;
}


void imprimirLinea(char car,int cant,ofstream &arch){
    for(int i=0;i<cant;i++){
        arch<<car;
    }
    arch<<endl;
}