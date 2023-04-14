/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
#define MAXLINEAS 100
using namespace std;

void imprimirLineas(char c){
    for(int i=0;i<=MAXLINEAS;i++)cout<<c;
    cout<<endl;
}

void leerPrimeraLinea(char *pediatria,char *ginecologia,int &fecha){
    char c;
    int dd,mm,aa;
    cin>>pediatria>>ginecologia>>dd>>c>>mm>>c>>aa;
    fecha = dd + mm*100 + aa*10000;
}

void sacarFecha(int fecha,int &dd,int &mm,int &aa){
    dd = fecha%100;
    fecha/=100;
    mm = fecha%100;
    fecha/=100;
    aa=fecha;
}

void imprimirEncabezado(char *pediatria,char *ginecologia,int fecha){
    int dd,mm,aa;
    cout<<setw(50)<<"EMPRESA PRESTADORA DE SALUD"<<endl;
    imprimirLineas('=');
    cout<<"ESPECIALIDADES A VERIFICAR: "<<pediatria<<" Y "<<ginecologia<<endl;
    sacarFecha(fecha,dd,mm,aa);
    cout<<"FECHA DEL PROCESO: ";
    cout.fill('0');
    cout<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<endl;
    cout.fill(' ');
    imprimirLineas('=');
}

void formatearEspecialidad(char *nombreCompleto,char *especialidad){
    int pos=-1;
    //Con esto tengo la ultima posicion del _
    for(int i=0;nombreCompleto[i]!='\0';i++){
        if(nombreCompleto[i]=='_'){
            pos=i;
        }
    }
    int j=0;
    for(int i=pos+1;nombreCompleto[i]!='\0';i++){
        especialidad[j]= nombreCompleto[i];
    }
}

bool validarEspecialidad(char *especialidad,char *pediatria,char *ginecologia){
    //Cambiar a mayusculas
    for(int i=0;especialidad[i]!='\0';i++){
        especialidad[i] = toupper(especialidad[i]);
    }
    for(int i=0;pediatria[i]!='\0';i++){
        pediatria[i] = toupper(pediatria[i]);
    }
    for(int i=0;especialidad[i]!='\0';i++){
        ginecologia[i] = toupper(ginecologia[i]);
    }
    
    if(strcmp(especialidad,pediatria) or strcmp(especialidad,ginecologia)){
        return true;
    }else{
        return false;
    }
}

void imprimirSubtitulos(){
    cout<<setw(20)<<"Pacientes atendidos"<<setw(50)<<"Medicinas recibidas"<<endl;
    imprimirLineas('-');
    cout<<setw(10)<<"DNI"<<setw(10)<<"Nombre"<<setw(20)<<"Cantidad"<<
            setw(5)<<"Codigo"<<"  Descripción"<<setw(20)<<"F. de V"<<
            setw(10)<<"Observacion"<<endl;
    imprimirLineas('-');
}

void imprimirDoctor(char *nombreCompleto,char *codigoMedico,char *especialidad){
    cout<<"Medico: "<<nombreCompleto<<" ["<<codigoMedico<<" ]";
    cout<<setw(20)<<"Especialidad: "<<especialidad<<endl;
    imprimirLineas('-');
    imprimirSubtitulos();
}

void imprimirPaciente(int pos,int dniPaciente,char *nombrePaciente,int cantMedicamentos){
    cout<<pos+1<<") "<<dniPaciente<<" "<<nombrePaciente<<setw(20)<<cantMedicamentos;
}

void imprimirMedicamento(int codMedicina,char *nombreCompleto,
        int dd,int mm,int aa,int bandera){
    if(bandera==0){
        
    }
}

