/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
#include <cstdlib>

using namespace std;

#include "funciones.h"

#define MAX_COD 10
#define MAX_NOM 55
#define MAX_MEDICINA 40
#define MAX_ESP 20
#define MAX_LINEA 120

void actualizarGastosPac(const char *nombArchPacientesB,const char *nombArchMedicinasB,
        const char *nombArchConsultasT){
    
    fstream archPacientesB(nombArchPacientesB,ios::in|ios::out|ios::binary);
    if( not archPacientesB.is_open()){
        cout<<"ERROR: El archivo "<<nombArchPacientesB<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    ifstream archMedicinasB(nombArchMedicinasB,ios::in|ios::binary);
    if( not archMedicinasB.is_open()){
        cout<<"ERROR: El archivo "<<nombArchMedicinasB<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    ifstream archConsultasT(nombArchConsultasT,ios::out);
    if( not archConsultasT.is_open()){
        cout<<"ERROR: El archivo "<<nombArchConsultasT<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    
    int tamRegPac = sizeof(int) + sizeof(char)*MAX_NOM + sizeof(double);
    archPacientesB.seekg(0,ios::end);
    int tamArchPac = archPacientesB.tellg();
    archPacientesB.seekg(0,ios::beg);
    int cantRegPac = tamArchPac/tamRegPac;
    
    int tamRegMed = sizeof(int) + sizeof(char)*MAX_MEDICINA + sizeof(double);
    archMedicinasB.seekg(0,ios::end);
    int tamArchMed = archMedicinasB.tellg();
    archMedicinasB.seekg(0,ios::beg);
    int cantRegMed = tamArchMed/tamRegMed;
        
    int dni,idPac,num,cantMedicinas,codMedicina;
    char cod[MAX_COD];
    double precioMed;
    while(true){
        archConsultasT>>dni;
        if(archConsultasT.eof()) break;
        archConsultasT>>cod>>num>>cantMedicinas;
        for(int i=0;i<cantMedicinas;i++){
            archConsultasT>>codMedicina;
            precioMed = buscarPrecioMed(codMedicina,archMedicinasB,cantRegMed);
            actualizarPaciente(dni,archPacientesB,cantRegPac,precioMed,tamRegPac);
        }
    }
    
}

void actualizarPaciente(int dniBuscado,fstream &arch,int cantReg,double precioMed,
        int tamRegPac){
    int dni;
    double gasto;
    arch.seekg(0,ios::beg);
    for(int i=0;i<cantReg;i++){
        arch.read(reinterpret_cast<char*>(&dni),sizeof(int));
        if(dni==dniBuscado){
            arch.seekg(MAX_NOM*sizeof(char),ios::cur);
            arch.read(reinterpret_cast<char*>(&gasto),sizeof(double));
            gasto += precioMed;
            arch.seekg(tamRegPac*i + sizeof(int) + sizeof(char)*MAX_NOM);
            arch.write(reinterpret_cast<const char*>(&gasto),sizeof(double));
            arch.flush();
            return;
        }
        else arch.seekg(MAX_NOM*sizeof(char)+sizeof(double),ios::cur);
    }
}

double buscarPrecioMed(int codBuscado,ifstream &arch,int cantReg){
    int cod;
    double precio;
    arch.seekg(0,ios::beg);
    for(int i=0;i<cantReg;i++){
        arch.read(reinterpret_cast<char*>(&cod),sizeof(int));
        if(cod==codBuscado) {
            arch.seekg(MAX_MEDICINA*sizeof(char),ios::cur);
            arch.read(reinterpret_cast<char*>(&precio),sizeof(double));
            return precio;
        }
        arch.seekg(MAX_MEDICINA*sizeof(char)+sizeof(double),ios::cur);
    }
    return -1;
}

void generarReporteMed(const char *nombArchReporte,const char *nombArchMed){
    ifstream archMed(nombArchMed,ios::in);
    if( not archMed.is_open()){
        cout<<"ERROR: El archivo "<<nombArchMed<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    ofstream archReporte(nombArchReporte,ios::out);
    if( not archReporte.is_open()){
        cout<<"ERROR: El archivo "<<nombArchReporte<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    int cont=1;
    char nombre[MAX_NOM],especialidad[MAX_ESP],codMed[MAX_COD];
    
    archReporte<<setw(75)<<"EMPRESA PRESTADORA DE SALUD EPS-LP1"<<endl;
    imprimeLinea(archReporte,'=',MAX_LINEA);
    archReporte<<setw(60)<<"STAF DE MEDICOS"<<endl;
    archReporte<<setw(20)<<"CODIGO"<<setw(15)<<"NOMBRE"<<setw(60)<<"ESPECIALIDAD"<<endl;
    
    while(true){
        archMed>>codMed;
        if(archMed.eof()) break;
        archMed>>nombre>>especialidad;
        separadoresEspacios(nombre);
        archReporte<<setw(10)<<cont<<")   "<<left<<setw(15)<<codMed<<setw(56)<<nombre
                <<setw(15)<<especialidad<<right<<endl;
        cont++;
    }
}

void generarReportePac(const char *nombArchReporte,const char *nombArchPac){
    ifstream archPac(nombArchPac,ios::in|ios::binary);
    if( not archPac.is_open()){
        cout<<"ERROR: El archivo "<<nombArchPac<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    ofstream archReporte(nombArchReporte,ios::app);
    if( not archReporte.is_open()){
        cout<<"ERROR: El archivo "<<nombArchReporte<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    
    archReporte.precision(2);
    archReporte<<fixed;
    
    int tamReg = sizeof(int) + MAX_NOM*sizeof(char) + sizeof(double);
    archPac.seekg(0,ios::end);
    int tamArch = archPac.tellg();
    archPac.seekg(0,ios::beg);
    int numReg = tamArch/tamReg;
    
    int dni,cont=1;
    double gastoMedPac;
    char nombre[MAX_NOM];
    
    imprimeLinea(archReporte,'=',MAX_LINEA);
    archReporte<<setw(64)<<"PACIENTES REGISTRADOS"<<endl;
    archReporte<<setw(19)<<"DNI"<<setw(16)<<"NOMBRE"<<setw(65)<<"GASTOS POR MEDICINAS"<<endl;

    for(int i=0;i<numReg;i++){
        archPac.read(reinterpret_cast<char*>(&dni),sizeof(int));
        archPac.read(reinterpret_cast<char*>(nombre),sizeof(char)*MAX_NOM);
        archPac.read(reinterpret_cast<char*>(&gastoMedPac),sizeof(double));
        archReporte<<setw(10)<<cont<<")   "<<setw(8)<<dni<<"       "<<left<<setw(50)<<nombre<<right
                <<setw(12)<<gastoMedPac<<endl;
        cont++;
    }
}

void generarReporteMedicinas(const char *nombArchReporte,const char *nombArchMedi){
    ifstream archMed(nombArchMedi,ios::in|ios::binary);
    if( not archMed.is_open()){
        cout<<"ERROR: El archivo "<<nombArchMedi<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    ofstream archReporte(nombArchReporte,ios::app);
    if( not archReporte.is_open()){
        cout<<"ERROR: El archivo "<<nombArchReporte<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    
    archReporte.precision(2);
    archReporte<<fixed;
    
    int tamReg = sizeof(int) + MAX_MEDICINA*sizeof(char) + sizeof(double);
    archMed.seekg(0,ios::end);
    int tamArch = archMed.tellg();
    archMed.seekg(0,ios::beg);
    int numReg = tamArch/tamReg;
    
    int cod,cont=1;
    double precio;
    char descripcion[MAX_MEDICINA];
    
    imprimeLinea(archReporte,'=',MAX_LINEA);
    archReporte<<setw(65)<<"MEDICINAS EN STOCK"<<endl;
    archReporte<<setw(20)<<"CODIGO"<<setw(20)<<"DESCRIPCION"<<setw(52)<<"PRECIO"<<endl;

    for(int i=0;i<numReg;i++){
        archMed.read(reinterpret_cast<char*>(&cod),sizeof(int));
        archMed.read(reinterpret_cast<char*>(descripcion),sizeof(char)*MAX_MEDICINA);
        archMed.read(reinterpret_cast<char*>(&precio),sizeof(double));
        archReporte<<setw(10)<<cont<<")"<<setw(9)<<cod<<"         "<<left<<setw(52)<<descripcion<<right
                <<setw(10)<<precio<<endl;
        cont++;
    }
    
}

void generarReporteConsultas(const char *nombArchReporte, const char *nombArchConsultas){
    ifstream archConsultas(nombArchConsultas,ios::in);
    if(not archConsultas.is_open()){
        cout<<"ERROR: El archivo "<<nombArchConsultas<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    ofstream archReporte(nombArchReporte,ios::app);
    if(not archReporte.is_open()){
        cout<<"ERROR: El archivo "<<nombArchReporte<<" no se pudo leer correctamente"<<endl;
        exit(1);
    }
    int dni,fechaConsulta,cantMedicamentos,codMedicina,cont=0,dia,mes,anio;
    char codMedico[MAX_COD];
    
    imprimeLinea(archReporte,'=',MAX_LINEA);
    archReporte<<setw(68)<<"RELACION DE CONSULTAS"<<endl;
    archReporte<<setw(21)<<"PACIENTES"<<setw(11)<<"MEDICO"<<setw(11)<<"FECHA"<<setw(26)<<
            "CANTIDAD DE MEDICINAS"<<setw(27)<<"CODIGOS DE MEDICAMENTOS"<<endl;
    while(1){
        archConsultas>>dni;
        if(archConsultas.eof()) break;
        archConsultas>>codMedico>>fechaConsulta>>cantMedicamentos;
        cont++;
        descomponerFecha(fechaConsulta,dia,mes,anio);
        
        archReporte<<setw(10)<<cont<<')'<<setw(10)<<dni<<"     "<<left<<setw(10)<<codMedico<<right;
        archReporte<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<setw(4)<<anio<<setfill(' ');
        archReporte<<setw(13)<<cantMedicamentos<<setw(11)<<' ';
        
        for(int i=0;i<cantMedicamentos;i++){
            archConsultas>>codMedicina;
            archReporte<<setw(8)<<codMedicina;
        }
        archReporte<<endl;
    }
}

void imprimeLinea(ofstream &arch,char c,int n){
    for(int i=0;i<n;i++)arch<<c;
    arch<<endl;
}

void descomponerFecha(int fecha,int &dia,int &mes,int &anio){
    dia = fecha%100;
    fecha = fecha/100;
    mes = fecha%100;
    fecha = fecha/100;
    anio = fecha;
}

void separadoresEspacios(char *cadena){
    int i=0;
    char c = cadena[i];
    
    while(c!='\0'){
        if(c=='_') cadena[i]=' ';
        i++;
        c = cadena[i];
    }
}
