/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
#include <cstring>
using namespace std;

//char **codigoMed,**medicos;
//double *tarifas;

char * leeCadena (ifstream &arch, char car) {
    char buff[200], *cad;
    arch.getline(buff,200,car);
    if (arch.eof()) return nullptr;
    cad = new char [strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void cargarMedicos(char **&codigoMed,char **&medicos,double *&tarifas){
    ifstream archMedicos("RelacionMedicos.csv",ios::in);
    if(!archMedicos){
        cout<<"Error no se pudo abrir el archivo RelacionMedicos.csv"<<endl;
        exit(1);
    }
    char *medicoCodigo[200],*nombreMedico[200],*codigo,*nombre,*especialidad,
            limpiar[200];
    double tarifa[200],monto;
    int numDatos=0;
    while(1){
        codigo = leeCadena(archMedicos,',');
        if(codigo==nullptr)break;
        nombre = leeCadena(archMedicos,',');
        especialidad = leeCadena(archMedicos,',');
        archMedicos>>monto;
//        cout<<monto<<endl;
        tarifa[numDatos]=monto;
        medicoCodigo[numDatos]=codigo;
        nombreMedico[numDatos]=nombre;
        numDatos++;
    }
    //Se separa memoria 
    codigoMed = new char*[numDatos+1];
    medicos = new char*[numDatos+1];
    tarifas = new double[numDatos]; 
    for(int i=0;i<numDatos;i++){
        codigoMed[i]=medicoCodigo[i];
        medicos[i]=nombreMedico[i];
        tarifas[i]=tarifa[i];
    }
    
    
//    tarifas[numDatos]=0;
    codigoMed[numDatos]=nullptr;
    medicos[numDatos]=nullptr;
    
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<100;i++){
        arch<<c;
    }
    arch<<endl;
}

void reporteMedicos(char **codigoMed,char **medicos,double *tarifas){
    ofstream archReporte("ReporteMedicos.txt",ios::out);
    if(!archReporte){
        cout<<"Error no se pudo abrir el archivo ReporteMedicos.txt"<<endl;
        exit(1);
    }
    archReporte<<setw(30)<<"Reporte de Medicos"<<endl;
    imprimirLineas(archReporte,'=');
    archReporte<<left<<"CODIGO"<<setw(50)<<right<<"NOMBRE MEDICO"<<setw(30)<<right<<"TARIFA"<<endl;
    imprimirLineas(archReporte,'=');
    for(int i=0;medicos[i];i++){
        archReporte<<setw(10)<<left<<codigoMed[i];
        archReporte<<setw(50)<<right<<medicos[i];
        archReporte<<setw(30)<<right<<tarifas[i]<<endl;
    }
}


void reporteDeIngresos(char **codigoMed,char **medicos,double *tarifas){
    ifstream archCodigos("Medicos.csv",ios::in);
    if(!archCodigos){
        cout<<"ERROR no se pudo abri el archivo Medicos.csv"<<endl;
        exit(1);
    }
    ofstream archReporte("ReporteFinal.txt",ios::out);
    if(!archReporte){
        cout<<"ERROR no se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    int *codigoPac,*veces;
    char **pacientes,codMed[7];
    double *porcentajes;
    
    while(1){
        archCodigos>>codMed;
        if(archCodigos.eof())break;
        cargarPacientes(codMed,codigoPac,pacientes,porcentajes,veces);
        reporteDelMedico(codMed,codigoMed,medicos,tarifas,
                         codigoPac,pacientes,porcentajes,veces,archReporte);
        liberarEspacios(codigoPac,pacientes,porcentajes,veces);
    }
    
}

char* leeMedicos(ifstream &arch,char car,int &flag){
    int i = 0, len;
    char buff[10], *cad, carr;
    flag = 0;
    while (1) {   
        carr = arch.get();
        if (carr == car || carr == '\n') {
            if (carr == '\n') flag = 1;
            break;
        } else arch.unget();
        buff[i] = arch.get();
        i++;
    }
    buff[i] = '\0';
    len = strlen(buff);
    cad = new char[len+1];
    strcpy(cad,buff);
    return cad;
}

//1/01/2020,R,891472,Virginia Chumpitaz,9.33,GI8983,A,850963,Rafael Urbina,10.7,DE9939,R,733943,Alberto De,34.98,EN8770,A,637427,Enrique Durand,6.44,TR9491,R,683024,Richard Perez,7.45,GA7574,R,857268,Ofelia Zambrano,18.08,CA8575,A,881508,Lucero Arca,55.11,GA7574,R,907870,Walter Merel,23.16,EN2265,A,662589,Ericka Justino,24.27,OF1543,A,866312,Elizabeth Farfan,65.88,TR3914
void cargarPacientes(char *codMed,int *&codigoPac,char **&pacientes,
                     double *&porcentajes,int *&veces){
    ifstream archAtenciones("Pacientes-Atencion.csv",ios::in);
    if(!archAtenciones){
        cout<<"Error no se pudo abrir el archivo Pacientes-Atencion.csv"<<endl;
        exit(1);
    }
    char *fecha,estado,*bufferPacientes[200],*nombrePaciente,*medicoAtencionCod;
    char c;
    double archPorcentaje;
    int codigoPaciente,arrCodigosPaciente[200],arrVeces[200],numDatos=0,finLinea;
    while(1){
        fecha = leeCadena(archAtenciones,',');
        if(fecha==nullptr)break;
        while(1){
            archAtenciones>>estado>>c>>codigoPaciente;
            nombrePaciente = leeCadena(archAtenciones,',');
            archAtenciones>>archPorcentaje>>c;
            medicoAtencionCod = leeMedicos(archAtenciones,',',finLinea);
            if(estado=='A'){
                //Significa que ya fue atendido entonces se guardan en la estructura
                if(strcmp(medicoAtencionCod,codMed)==0){
                    //Si es que los códigos son iguales entonces 
                }
                
            }
            if(finLinea)break;
        }
    }
}

void reporteDelMedico(char *codMed,char **codigoMed,char **medicos,double *tarifas,
                      char *codigoPac,char **pacientes,double *porcentajes,
                      int *veces,ofstream &archRep){
    
}

void liberarEspacios(char *&codigoPac,char **&pacientes,double *&porcentajes,int *&veces);