/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <set>
#include "funcione.h"
#define MAXLINEAS 100
using namespace std;

char* leerCadenaSaltoLinea(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,'\n');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

char* leerCadena(ifstream &arch){
    char buffer[300],*cad;
    arch.getline(buffer,300,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void cargarConductores(int *&licencia,char **&conductor){
    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo hallar el archivo Conductores.csv"<<endl;
        exit(1);
    }
    
    int buffLicencia[200],numDatos=0,numLicencia;
    char *bufferConductor[200],*nombre;
    
    while(1){
        arch>>numLicencia;
        if(arch.eof())break;
        arch.get();
        nombre = leerCadenaSaltoLinea(arch);
        buffLicencia[numDatos]=numLicencia;
        bufferConductor[numDatos]=nombre;
        numDatos++;
    }
    licencia = new int[numDatos+1];
    conductor = new char*[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        licencia[i]=buffLicencia[i];
        conductor[i]=bufferConductor[i];
    }
    licencia[numDatos]=0;
    conductor[numDatos]=NULL;
}

void imprimirLineas(ofstream &out,char c){
    for(int i=0;i<MAXLINEAS;i++){
        out<<c;
    }
    out<<endl;
}

void reporteConductores(int *licencia,char **conductor){
    ofstream arch("ReporteConductores.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el ReporteConductores.txt"<<endl;
        exit(1);
    }
    arch<<setw(40)<<"REPORTE DE CONDUCTORES"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(10)<<left<<"LICENCIA"<<setw(40)<<right<<"NOMBRE"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;licencia[i];i++){
        arch<<setw(10)<<left<<licencia[i]<<setw(40)<<right<<conductor[i]<<endl;
    }
}


void cargarInfracciones(int *&infraccion,char *&gravedad,double *&multa){
    ifstream arch("Infracciones.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int buffInfraccion[200],numDatos=0;
    char *descripcion,auxGravedad[300];
    char buffGravedad[200];
    double buffMulta[200],auxMulta;
    int codInfracion;
    while(1){
        arch>>codInfracion;
        if(arch.eof())break;
        arch.get();
        descripcion = leerCadena(arch);
        arch.getline(auxGravedad,20,',');
        if(strcmp(auxGravedad,"Grave")==0){
            buffGravedad[numDatos]='G';
        }else if(strcmp(auxGravedad,"Leve")==0){
            buffGravedad[numDatos]='L';
        }else if(strcmp(auxGravedad,"Muy Grave")==0){
            buffGravedad[numDatos]='M';
        }
        arch>>auxMulta;
        buffInfraccion[numDatos]=codInfracion;
        buffMulta[numDatos]=auxMulta;
        numDatos++;
    }
    
    infraccion = new int[numDatos+1];
    gravedad = new char[numDatos+1];
    multa = new double[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        infraccion[i]=buffInfraccion[i];
        gravedad[i]=buffGravedad[i];
        multa[i]=buffMulta[i];
    }
    infraccion[numDatos]=0;
    gravedad[numDatos]=0;
    multa[numDatos]=0;
}

//    char **conductor,*gravedad;
//    int *licencia, *infraccion;
//    double *multa;
void reporteInfracciones(int *infraccion,char *gravedad,double *multa){
    ofstream arch("ReporteInfracciones.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteInfracciones.txt"<<endl;
        exit(1);
    }
    arch<<setw(40)<<"Reporte de Infracciones"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(15)<<left<<"Cod.Infraccion"<<setw(30)<<"Gravedad"<<setw(30)<<"Multa"<<endl;
    imprimirLineas(arch,'=');
    arch.precision(2);
    arch<<fixed;
    for(int i=0;infraccion[i];i++){
        arch<<setw(15)<<left<<infraccion[i]<<setw(30)<<right<<gravedad[i]<<setw(30)<<right<<multa[i]<<endl;
    }
}


int esTipoFalta(char c,int *licencia,char *gravedad){
    for(int i=0;licencia[i];i++){
        if(c==gravedad[i]){
            return i;
        }
    }
    return -1;
}


int buscarPlaca(char **buffPlaca,char *placa,int cantidad){
    for(int i=0;i<cantidad;i++){
        if(strcmp(buffPlaca[i],placa)==0){
            return i;
        }
    }
    return -1;
}

int buscarInfraccion(int *arreglo,int num){
    for(int i=0;i<num;i++){
        if(num==arreglo[i]){
            return i;
        }
    }
    return -1;
}

void abrirArchivo(int *&licenciaReporte,char **&placa,int *&cantidad,double *&monto,
                  int *licencia,char **conductor,int *infraccion,char *gravedad,
                  double *multa,char car){
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(!arch){
        cout<<"Error no se puede abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    int buffLicenciaRep[800],buffCantidad[800]={0},auxLicencia,auxNumInfraccion;
    int numDatos=0;
    char *buffPlaca[800],*auxPlaca,*fecha;
    double buffMonto[800]={0},suma=0;
    while(1){
        arch>>auxLicencia;
        if(arch.eof())break;
        arch.get();
        auxPlaca = leerCadena(arch);
        fecha = leerCadena(arch);
        arch>>auxNumInfraccion;
        int posInfraccion= buscarInfraccion(infraccion,auxNumInfraccion);
        if(gravedad[posInfraccion]==car){
            int posPlaca = buscarPlaca(buffPlaca,auxPlaca,numDatos); 
            if(posPlaca!=-1){
                //Lo encontro
                buffCantidad[posPlaca]++;
                buffMonto[posPlaca]+=multa[posInfraccion];
            }else{
                //No lo encontro
                buffLicenciaRep[numDatos]=auxLicencia;
                buffPlaca[numDatos]= auxPlaca;
                buffCantidad[numDatos]++;
                buffMonto[numDatos]+=multa[posInfraccion];
                numDatos++;
            }
        }
    }
    
    licenciaReporte = new int[numDatos+1];
    placa = new char*[numDatos+1];
    cantidad = new int[numDatos+1];
    monto = new double[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        licenciaReporte[i]=buffLicenciaRep[i];
        placa[i]=buffPlaca[i];
        cantidad[i]=buffCantidad[i];
        monto[i]=buffMonto[i];
    }
    
    licenciaReporte[numDatos]=0;
    placa[numDatos]=nullptr;
    cantidad[numDatos]=0;
    monto[numDatos]=0;
}

void mostrarReporte(ofstream &arch,int *licencia,char **placa,int *cant,double *monto,char car){
    arch.precision(2);
    arch<<fixed;
    if(car=='L'){
        arch<<"FALTAS LEVES"<<endl;
    }else if(car=='G'){
        arch<<"FALTAS GRAVES"<<endl;
    }else if(car=='M'){
        arch<<"FALTAS MUY GRAVES"<<endl;
    }
    imprimirLineas(arch,'=');
    arch<<setw(10)<<left<<"No."<<setw(10)<<left<<"Licencia"<<setw(13)<<right<<"Placa";
    arch<<setw(17)<<"Cantidad"<<setw(15)<<"Monto"<<endl;
    imprimirLineas(arch,'-');
    
    for(int i=0;licencia[i];i++){
        arch<<setfill('0')<<setw(3)<<right<<i+1<<setfill(' ')<<")"<<setw(15)<<right<<licencia[i]<<setw(15)
                <<right<<placa[i]<<setw(12)<<cant[i]<<setw(20)<<monto[i]<<endl;
    }
    imprimirLineas(arch,'*');
}

void limpiarArchivos(int *&licencia,int *&cantidad,char **&placa,double *&monto){
    delete licencia;
    delete cantidad;
    delete placa;
    delete monto;
}

void reporteDeFaltas(int *licencia,char **conductor,int *infraccion,char *gravedad,
                     double *multa){
    ofstream archReporte("ReporteFaltasFinal.txt",ios::out);
    if(!archReporte){
        cout<<"Error no se puede abrir el archivo ReporteFaltasFinal.txt"<<endl;
        exit(1);
    }
    int *licenciaReporte, *cantidad;
    char **placa,car;
    double *monto;
    int cod,i=0;
    while(1){
        if(i==0)car='L';
        else if(i==1)car='G';
        else if(i==2)car='M';
        else break;
        abrirArchivo(licenciaReporte,placa,cantidad,monto,licencia,conductor,infraccion,gravedad,multa,car);
        mostrarReporte(archReporte,licenciaReporte,placa,cantidad,monto,car);
        limpiarArchivos(licenciaReporte,cantidad,placa,monto);
        i++;
    }
    
}