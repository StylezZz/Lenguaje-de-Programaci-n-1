/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "funcionesBiblioteca.h"
using namespace std;

//Función adicional
void formatearNombre(char *nombreEsp,char *esp){
    int i,j,k,m;
    for(i=0;nombreEsp[i];i++){
        if(nombreEsp[i]=='_')nombreEsp[i]=' ';
    }
    for(j=i-1;j>=0;j--){
        if(nombreEsp[j]==' ')break;
    }
    
    for(k=j+1,m=0;nombreEsp[k];k++,m++){
        esp[m]=nombreEsp[k];
    }
    esp[m]=0;
    nombreEsp[j]=0;
    
}

//Lectura 1
bool operator >>(ifstream &in,struct StMedico &med){
    int codigo;
    char nombreCompleto[150],especialidad[30],nombre[120];
    double tarifa;
    in>>codigo;
    if(in.eof())return false;
    in>>nombreCompleto;
    formatearNombre(nombreCompleto,especialidad);
    in>>tarifa;
    med.codigo = codigo;
    med.tarifaPoxConsulta = tarifa;
    strcpy(med.especialidad,especialidad);
    strcpy(med.nombre,nombreCompleto);
    return true;
}

//Lectura 2
bool operator >>(ifstream &in,struct StPaciente &pac){
    int dni,telefono;
    char nombre[150];
    in>>dni;
    if(in.eof())return false;
    in>>nombre;
    in>>telefono;
    pac.numeroDeCitas =0;
    pac.totalGastado = 0;
    pac.dni = dni;
    pac.telefono = telefono;
    strcpy(pac.nombre,nombre);
    return true;
}

//Lectura 3
int operator >>(ifstream &in,struct StCita &cita){
    int dniPaciente,dd,mm,aa,fecha,codMedico;
    char c;
    in>>dniPaciente;
    if(in.eof())return -1;
    in>>codMedico>>dd>>c>>mm>>c>>aa;
    fecha = dd + mm*100 + aa*10000;
    cita.codigoDelMedico = codMedico;
    cita.fecha = fecha;
    cita.tarifaPorConsulta = 0;
    return dniPaciente;
}

//Busqueda
bool operator <=(struct StCita &cita, struct StMedico *arrMedicos){
    for(int i=0;arrMedicos[i].codigo;i++){
        if(arrMedicos[i].codigo == cita.codigoDelMedico){
            strcpy(cita.especialidad,arrMedicos[i].especialidad);
            cita.tarifaPorConsulta = arrMedicos[i].tarifaPoxConsulta;
            return true;
        }
    }
    return false;
}

//Agregación
void operator +=(struct StPaciente &pac,struct StCita cita){
    int i=pac.numeroDeCitas;
    pac.citas[i].codigoDelMedico = cita.codigoDelMedico;
    strcpy(pac.citas[i].especialidad,cita.especialidad);
    pac.citas[i].fecha = cita.fecha;
    pac.citas[i].tarifaPorConsulta = cita.tarifaPorConsulta;
    pac.numeroDeCitas++;
}

//Gastos
void operator ++(struct StPaciente &pac){
    double suma=0;
    for(int i=0;i<pac.numeroDeCitas;i++){
        suma += pac.citas[i].tarifaPorConsulta;
    }
    pac.totalGastado = suma;
}

//Función de impresión de fechas
void imprimeFecha(ofstream &arch,int fecha){
    int dd,mm,aa;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"
            <<setw(4)<<right<<aa<<setfill(' ');
}

//Impresión
void operator <<(ofstream &out,struct StPaciente pac){
    out<<"  DNI"<<setw(20)<<right<<"NOMBRE"<<right<<setw(20)<<"TELEFONO"<<endl;
    out<<setw(20)<<left<<pac.dni<<setw(30)<<left<<pac.nombre<<left<<
            pac.telefono<<endl;
    out<<"RELACION DE CITAS"<<endl;
    out<<"No.     FECHA"<<setw(20)<<right<<"CODIGO DEL MEDICO"<<setw(20)<<right<<
               "ESPECIALIDAD"<<setw(10)<<right<<"TARIFA"<<endl;
    for(int i=0;i<pac.numeroDeCitas;i++){
        out<<setw(2)<<right<<i+1<<")   ";
        imprimeFecha(out,pac.citas[i].fecha);
        out<<setw(15)<<right<<pac.citas[i].codigoDelMedico<<setw(8)<<" "<<
                setw(20)<<left<<pac.citas[i].especialidad<<setw(10)<<right
                <<setprecision(2)<<fixed<<pac.citas[i].tarifaPorConsulta<<endl;
    }
    out<<"MONTO TOTAL GASTADO:  "<<pac.totalGastado<<endl;
}







