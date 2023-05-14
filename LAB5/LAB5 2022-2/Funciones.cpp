/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Funciones.h"
#define INCREMENTO 5
#define CANT 100

void AbrirArchivoL(ifstream &arch, const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch){
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

void AbrirArchivoE(ofstream &arch, const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch){
        cout<<"ERROR: No se ha podido abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
}

void cargarCitas(const char *nombArch, char ***&medicoDatos, double *&medicoTarifaHora,
            char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago){
    ifstream arch;
    AbrirArchivoL(arch,nombArch);
    //Asigno los NULLS:
    medicoDatos=nullptr;
    medicoTarifaHora=nullptr;
    citaTiempoYPago=nullptr;
    citaPaciente=nullptr;
    citaCantidad=nullptr;
    
    int dd,mm,aa,h1,m1,s1,h2,m2,s2;
    char codPaciente[20],nombrePaciente[120],codMedico[10],nombreMedico[120],car;
    double tarifa;
    
    int numProd=0, tamprod=0; // Para los MEDICOS
    int nd[1000]{}, tam[1000]{}; //Para los PACIENTES X cada MEDICO
    
    int posMedico;
    double montoPagar,tiempo;
    
    char *codigo,*nombre;
    while(true){
        arch>>ws;
        //Se puede usar el leerCadena, para ahorra lineas y 
        //tenerlo listo en un puntero a cadena
        arch.getline(codPaciente,20,',');
        if(arch.eof()) break;
        arch.getline(nombrePaciente,120,',');
        arch.getline(codMedico,10,',');
        arch.getline(nombreMedico,120,',');
        arch>>tarifa>>car>>dd>>car>>mm>>car>>aa;
        arch>>car>>h1>>car>>m1>>car>>s1>>car>>h2>>car>>m2>>car>>s2;
        
        //
        
        posMedico = buscar(codMedico,medicoDatos,numProd);
        if(posMedico == -1){// NO ENCUENTRO AL MEDICO
            
            codigo=asignar(codMedico);
            nombre=asignar(nombreMedico);

            // Para: medicoDatos
            char **aux1;
            aux1 = new char *[2];
            aux1[0] = codigo;
            aux1[1] = nombre;
 
            if(numProd==tamprod){
                incremento(medicoDatos,medicoTarifaHora, citaPaciente, citaCantidad,citaTiempoYPago,
                        numProd,tamprod);
            }

            medicoDatos[numProd] = nullptr;
            medicoDatos[numProd-1] = aux1;
            
            medicoTarifaHora[numProd] = 0;
            medicoTarifaHora[numProd-1] = tarifa;
            
            citaTiempoYPago[numProd] = nullptr;
            citaPaciente[numProd] = nullptr;
            citaCantidad[numProd] = nullptr;
            
            posMedico=numProd-1;
            numProd++; 
            hallarMonto(h1,m1,s1,h2,m2,s2,medicoTarifaHora[posMedico],montoPagar,tiempo);
            agregarPacientes(citaPaciente[posMedico],citaCantidad[posMedico],citaTiempoYPago[posMedico],
                        codPaciente,nombrePaciente,tiempo,montoPagar,
                        nd[posMedico],tam[posMedico]);
            
        }else{
            hallarMonto(h1,m1,s1,h2,m2,s2,medicoTarifaHora[posMedico],montoPagar,tiempo);
            agregarPacientes(citaPaciente[posMedico],citaCantidad[posMedico],citaTiempoYPago[posMedico],
                            codPaciente,nombrePaciente,tiempo,montoPagar,
                            nd[posMedico],tam[posMedico]);
        }     
    }
    
}


void incremento(char ***&medicoDatos,double *&medicoTarifaHora, char ****&citaPaciente, 
                int **&citaCantidad,double ***&citaTiempoYPago,
                    int &num,int &tam){
    char ***auxMD;
    double *auxTH;
    char ****auxP;
    int **auxC;
    double ***auxTP;
    
    tam += INCREMENTO;
    if(medicoDatos==nullptr){
        medicoDatos = new char **[tam];
        medicoTarifaHora = new double [tam];
        citaPaciente = new char ***[tam];
        citaCantidad = new int *[tam];
        citaTiempoYPago = new double **[tam];
    
        medicoDatos[0] = nullptr;
        medicoTarifaHora[0] = 0;
        citaPaciente[0] = nullptr;
        citaCantidad[0] = nullptr;
        citaTiempoYPago[0]= nullptr;
        
        num=1;
    }else{
        auxMD = new char **[tam];
        auxTH = new double [tam];
        auxP = new char ***[tam];
        auxC = new int *[tam];
        auxTP = new double **[tam];
        
        for(int i=0;i<num;i++){
            auxMD[i] = medicoDatos[i];
            auxTH[i] = medicoTarifaHora[i];
            auxP[i] = citaPaciente[i];
            auxC[i] = citaCantidad[i];
            auxTP[i] = citaTiempoYPago[i];
        }
        delete medicoDatos;
        delete medicoTarifaHora;
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        medicoDatos =auxMD;
        medicoTarifaHora =auxTH;
        citaPaciente =auxP;
        citaCantidad =auxC;
        citaTiempoYPago =auxTP;
    }
}

void agregarPacientes(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempoYPago,
                            char *codPaciente,char *nombrePaciente,double tiempo,double montoPagar,
                            int &nd,int &tam){
    int posPac;
    // Las cadenas deben ser DINÁMICAS:
    char *dni,*nombre;
    dni=asignar(codPaciente);
    nombre=asignar(nombrePaciente);

    //Buscamos la posicion del paciente dentro del Medico:
    posPac = buscarPaciente(codPaciente,citaPaciente,nd);

    if(posPac!=-1){// EXISTE
        citaCantidad[posPac] += 1;
        citaTiempoYPago[posPac][0] += tiempo;
        citaTiempoYPago[posPac][1] += montoPagar;
    }else{// NO EXISTE
        
        // 1) Para: medicoDatos
        char **aux1;
        aux1 = new char *[2];
        aux1[0] = dni;
        aux1[1] = nombre;
        
        // 2) Para: citaCantidad

        // 3) Para: citaTiempoYPago
        double *aux2;
        aux2 = new double [2];
        aux2[0] = tiempo;
        aux2[1] = montoPagar;
        
        if(nd==tam){
            incrementarEspacios2(citaPaciente,citaCantidad,citaTiempoYPago,
                    nd,tam);
        }
        
        citaPaciente[nd]=nullptr;
        citaPaciente[nd-1]= aux1;
        
        citaCantidad[nd]=0;
        citaCantidad[nd-1]= 1;
        
        citaTiempoYPago[nd]=nullptr;
        citaTiempoYPago[nd-1]= aux2;
        
        nd++;
    }
}

void incrementarEspacios2(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempoYPago,
                    int &nd,int &tam){
    char ***auxC;
    int *auxCant;
    double **auxCT;
    
    tam += INCREMENTO; // tam es CAPacidad
    
    if(citaPaciente == nullptr){
        citaPaciente = new char **[tam];
        citaCantidad = new int [tam];
        citaTiempoYPago = new double *[tam];
        
        citaPaciente[0] = nullptr;
        citaCantidad[0] = 0;
        citaTiempoYPago[0] = nullptr;
        nd=1;
    }else{
        auxC = new char **[tam];
        auxCant = new int [tam];
        auxCT = new double *[tam];
        
        for(int i=0;i<nd;i++){
            auxC[i] = citaPaciente[i];
            auxCant[i] = citaCantidad[i];
            auxCT[i] = citaTiempoYPago[i];
        }
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        citaPaciente = auxC;
        citaCantidad = auxCant;
        citaTiempoYPago = auxCT;
    }
}

int buscarPaciente(char *dni,char ***&citaPaciente,int nd){
    if(citaPaciente == nullptr){
        return -1;
    }
    
    for(int i=0; citaPaciente[i]; i++){
        if(strcmp(citaPaciente[i][0], dni) == 0){
            return i;
        }
    }
    return -1;
}

void hallarMonto(int h1,int m1,int s1,int h2,int m2,int s2,
        double tarifa,double &tar,double &tiempo){
    double horaInicio = h1*3600 + m1*60 + s1;
    double horaFin = h2*3600 + m2*60 + s2;
    
    tiempo = horaFin-horaInicio;
    tiempo = tiempo/3600;
    tar = (double)(tiempo*tarifa);
}

int buscar(char *codMedico,char ***medicoDatos,int numProd){
    if(medicoDatos == nullptr){
        return -1;
    }
    
    for(int i=0; medicoDatos[i]; i++){
        if(strcmp(medicoDatos[i][0], codMedico) == 0){
            return i;
        }
    }
    return -1;
}

void aumentarEspacios1(char ***&medicoDatos,double *&medicoTarifaHora,
                int &numProd,int &cap){
    char ***auxM;
    double *auxT;
    // tamProd es CAP
    cap += INCREMENTO;
    if(medicoDatos==nullptr){
        medicoDatos = new char **[cap];
        medicoTarifaHora = new double [cap];
        
        medicoDatos[0] = nullptr;
        medicoTarifaHora[0] = 0;
        
        numProd=1;
    }else{
        auxM = new char **[cap];
        auxT = new double [cap];
        
        for(int i=0;i<numProd;i++){
            auxM[i] = medicoDatos[i];
            auxT[i] = medicoTarifaHora[i];
        }
        delete medicoDatos;
        delete medicoTarifaHora;
        
        medicoDatos = auxM;
        medicoTarifaHora = auxT;
    }
}

char *asignar(char *cadena){
    char *ptAux;
    ptAux = new char[strlen(cadena)+1];
    strcpy(ptAux,cadena);
    return ptAux;
}

void pruebaDeCargaDeCitas(const char *nombArch, char ***medicoDatos, double *medicoTarifaHora,
            char ****citaPaciente, int **citaCantidad, double ***citaTiempoYPago){
    
}
void ReporteDeCitasPorMedico(const char *nombArch, char ***medicoDatos, double *medicoTarifaHora,
            char ****citaPaciente, int **citaCantidad, double ***citaTiempoYPago){
    ofstream arch;
    AbrirArchivoE(arch,nombArch);
    arch<<setw(57)<<"CLINICA PSICOLOGICA LP1"<<endl;
    elaborarLinea(arch,CANT,'=');
    arch<<"RELACION DE CITAS POR MEDICO"<<endl;
    int cant,cantT;
    double tiemT,pagoT,tiempoTOTAL=0,pagoTOTAL=0;
    arch.precision(2);
    arch<<fixed;
    for(int i=0;medicoDatos[i];i++){
        elaborarLinea(arch,CANT,'=');
        arch<<"CODIGO"<<setw(16)<<"Nombre"<<setw(60)<<"TARIFA POR HORA DE CONSULTA:"<<setw(7)<<
                medicoTarifaHora[i]<<endl;
        arch<<medicoDatos[i][0]<<setw(10)<<" "<<medicoDatos[i][1]<<endl;
        elaborarLinea(arch,CANT,'-');
        arch<<"RELACION DE PACIENTES ATENDIDOS:"<<endl;
        elaborarLinea(arch,CANT,'-');
        arch<<setw(10)<<"DNI"<<setw(14)<<"Nombre"<<setw(41)<<"Cantidad de citas"<<
                setw(22)<<"Tiempo total (hrs)"<<setw(12)<<"Pago total"<<endl;
        elaborarLinea(arch,CANT,'-');
        cant=0;
        cantT=0;
        tiemT=0;
        pagoT=0;
        for(int j=0;citaPaciente[i][j];j++){
            cant++;
            arch<<setw(4)<<cant<<setw(10)<<citaPaciente[i][j][0]<<"    "<<left<<setw(30)<<
                    citaPaciente[i][j][1]<<right<<setw(10)<<citaCantidad[i][j]<<
                    setw(21)<<citaTiempoYPago[i][j][0]<<setw(18)<<citaTiempoYPago[i][j][1]<<endl;
            cantT += citaCantidad[i][j];
            tiemT += citaTiempoYPago[i][j][0];
            pagoT += citaTiempoYPago[i][j][1];
        }
        tiempoTOTAL += tiemT;
        pagoTOTAL += pagoT;
        elaborarLinea(arch,CANT,'-');
        arch<<setw(35)<<"TOTAL:"<<setw(23)<<cantT<<setw(21)<<tiemT<<setw(18)<<pagoT<<endl;
    }
    elaborarLinea(arch,CANT,'=');
    arch<<setw(58)<<"TOTAL:"<<setw(20)<<tiempoTOTAL<<setw(19)<<pagoTOTAL<<endl;
}

void elaborarLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++){
        arch.put(c);
    }
    arch.put('\n');
}