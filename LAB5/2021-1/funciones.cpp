/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
#define MAXLINEAS 100
#include "funciones.h"
using namespace std;

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++)arch<<c;
    arch<<endl;
}

char* leerCadenaSaltoLinea(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,'\n');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void cargarConductores(int *&licencia,char **&conductor){
    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cout<<"No se encontro el archivo Conductores.csv"<<endl;
        exit(1);
    }
    int numDat=0,cap=0,lic;
    char *nomb;
    licencia= nullptr;
    while(1){
        arch>>lic;
        if(arch.eof())break;
        arch.get();
        nomb=leerCadenaSaltoLinea(arch);
        
        if(numDat==cap)incrementarEspacios(licencia,conductor,numDat,cap);
        licencia[numDat]=0;
        licencia[numDat-1]=lic;
        conductor[numDat]=nullptr;
        conductor[numDat-1]=nomb;
        numDat++;
    }
}

void incrementarEspacios(int *&licencia,char **&conductor,int &numDatos,int &cap){
    int *auxLicencia;
    char **auxNombre;
    cap+=INCREMENTO;
    if(licencia==nullptr){
        licencia = new int[cap]{};
        conductor = new char*[cap]{};
        numDatos=1;
    }else{
        auxLicencia = new int[cap]{};
        auxNombre = new char*[cap]{};
        for(int i=0;i<numDatos;i++){
            auxLicencia[i]=licencia[i];
            auxNombre[i]=conductor[i];
        }
        delete licencia;
        delete conductor;
        licencia = auxLicencia;
        conductor = auxNombre;
    }
}

void reporteConductores(int *licencia,char **conductor){
    ofstream arch("ReporteConductores.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo crear el archivo ReporteConductores.txt"<<endl;
        exit(1);
    }
    arch<<setw(30)<<right<<"REPORTE DE CONDUCTORES"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(10)<<left<<"LICENCIA"<<setw(50)<<right<<"NOMBRE"<<endl;
    for(int i=0;licencia[i];i++){
        arch<<setw(10)<<left<<licencia[i]<<setw(50)<<right<<conductor[i]<<endl;
    }
}



char* leerCadena(ifstream &arch){
    char *cad,buffer[200];
    arch.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void cargarFaltas(int *licencia, char ***&placa,int **&falta){
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(!arch){
        cout<<"Error en RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    int auxLicencia,auxFalta,posLicencia;
    char *auxPlaca,*auxFecha;
    int numLicencias;
    for(numLicencias=0;licencia[numLicencias];numLicencias++);
    placa = new char**[numLicencias+1]{};
    falta = new int*[numLicencias+1]{};
    int numDatos[numLicencias+1]{},cap[numLicencias+1]{};
    while(1){
        arch>>auxLicencia;
        if(arch.eof())break;
        arch.get();
        auxPlaca = leerCadena(arch);
        auxFecha = leerCadena(arch);
        arch>>auxFalta;
        
        posLicencia = buscarLicencia(auxLicencia,licencia);
        agregarFalta(placa[posLicencia],falta[posLicencia],numDatos[posLicencia],
                     cap[posLicencia],auxPlaca,auxFalta);
    }
}

void agregarFalta(char **&placa,int *&falta,int &numDatos,int &cap,char *auxPlaca,
                  int auxFalta){
    if(numDatos==cap)incrementarEspacios(placa,falta,numDatos,cap);
    placa[numDatos-1]=auxPlaca;
    falta[numDatos-1]=auxFalta;
    numDatos++;
}

void incrementarEspacios(char **&placa,int *&falta,int &numDatos,int &cap){
    char **auxPlaca;
    int *auxFalta;
    cap+=INCREMENTO;
    if(placa==nullptr){
        placa = new char*[cap]{};
        falta = new int[cap]{};
        numDatos=1;
    }else{
        auxPlaca = new char*[cap]{};
        auxFalta = new int[cap]{};
        for(int i=0;i<numDatos;i++){
            auxFalta[i]=falta[i];
            auxPlaca[i]=placa[i];
        }
        delete falta;
        delete placa;
        placa = auxPlaca;
        falta = auxFalta;
    }
}

int buscarLicencia(int dato,int *licencias){
    for(int i=0;licencias[i];i++){
        if(dato==licencias[i]){
//            cout<<"Concordancia: "<<dato<<" "<<licencias[i]<<endl;
            return i;
        }
    }
//    cout<<"Error no se encontro al usuario: "<<dato<<endl;
//    exit(1);
}


void reporteFaltas(int *licencia,char **conductor,char ***placa,int **falta){
    ofstream arch("ReporteFaltas.txt",ios::out);
    if(!arch){
        cout<<"ERROR no se pudo abrir el archivo ReporteFalta.txt"<<endl;
        exit(1);
    }
    arch<<setw(40)<<right<<"REPORTE DE FALTAS"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(10)<<left<<"CONDUCTOR"<<setw(40)<<right<<"NOMBRE"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;licencia[i];i++){
        arch<<setw(10)<<left<<licencia[i]<<setw(40)<<right<<conductor[i]<<endl;
        imprimirLineas(arch,'-');
        arch<<setw(10)<<left<<"PLACA"<<setw(20)<<right<<"FALTA"<<endl;
        if(placa[i]){
            imprimirFaltas(placa[i],falta[i],arch);
        }
        imprimirLineas(arch,'=');
    }
}

void imprimirFaltas(char **placa,int *falta,ofstream &arch){
    for(int i=0;placa[i];i++){
        arch<<setw(25)<<left<<placa[i]<<setw(20)<<falta[i]<<endl;
    }
}

//char **conductor, ***placa;
//    int *licencia, **falta;
//    double **multa;

void resumenMultas(int *licencia,int **falta,double **&multa){
    ifstream arch("Infracciones.csv",ios::in);
    if(!arch){
        cout<<"ERROR no se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int k;
    for(k=0;licencia[k];k++);
    multa = new double*[k+1]{};
    for(int i=0;licencia[i];i++){
        cargarMultas(falta[i],multa[i],arch);
    }
}

void cargarMultas(int *&falta,double *&multa,ifstream &arch){
    int i,j;
    if(falta==nullptr)return;
    multa = new double[3]{};
    double pago;
    for(i=0;falta[i];i++){
        pago = buscarFalta(falta[i],arch,j);
        multa[j]+=pago;
    }
}

double buscarFalta(int num,ifstream &arch,int &pos){
    arch.seekg(0,ios::beg);
    int infraccion;
    double valor;
    char c,*descripcion;
    while(1){
        arch>>infraccion;
        if(arch.eof())break;
        arch>>c;
        char limpieza[400];
        if(num==infraccion){
            char buff[250];
            arch.getline(buff,250,',');
            arch.getline(buff,250,',');
            arch>>valor;
            if(strcmp(buff,"Leve")==0){
                pos=0;
            }else if(strcmp(buff,"Grave")){
                pos=1;
            }else{
                pos=2;
            }
            return valor;
        }
        arch.getline(limpieza,400,'\n');
    }
}

void reporteMultas(int *licencia,char **conductor,double **multa){
    ofstream archRep("ReporteMultas.txt",ios::out);
    imprimirLineas(archRep,'=');
    for(int i=0;licencia[i];i++){
        archRep<<setw(12)<<left<<"LICENCIA"<<left<<"CONDUCTOR"<<endl;
        imprimirLineas(archRep,'=');
        archRep<<setw(12)<<left<<licencia[i]<<left<<conductor[i]<<endl;
        imprimirLineas(archRep,'-');
        if(multa[i])imprimeMultas(multa[i],archRep);
        else archRep<<"No se registraron multas"<<endl;
        imprimirLineas(archRep,'=');
    }
}
//Preguntar set precision
void imprimeMultas(double *multa,ofstream &arch){
    arch<<setw(20)<<left<<"Multas leves: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<multa[0]<<endl;
    arch<<setw(20)<<left<<"Multas graves: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<multa[1]<<endl;
    arch<<setw(20)<<left<<"Multas muy graves: "<<setw(10)<<right<<setprecision(2)
            <<fixed<<multa[2]<<endl;
}