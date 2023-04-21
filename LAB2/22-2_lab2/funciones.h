/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: MAURICIO
 *
 * Created on 11 de abril de 2023, 09:10 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void crearBinarios(const char *nombArchPac,const char *nombArchMed);
void separarArchivo(const char *nombArchDatosT,const char *nombArchMedicosT,
        const char *nombArchPacientesB,const char *nombArchMedicinasB,
        const char *nombArchConsultasT);
void separarNombreEspecialidad(char *nombreMed,char *especialidad);
void separadoresEspacios(char *cadena);
void pasarAMayusculas(char *cadena);
int buscarPaciente(int dniBuscado,fstream &arch,int cantReg);
void cargarPaciente(fstream &arch,int dni,char *nombrePac,double gastoMedPac);
int buscarMedicina(int codBuscado,fstream &arch,int cantReg);
void cargarMedicina(fstream &arch,int cod,char *descripcionMed,double precio);
void generarReporteMed(const char *nombArchReporte,const char *nombArchMed);
void generarReportePac(const char *nombArchReporte,const char *nombArchPac);
void generarReporteMedicinas(const char *nombArchReporte,const char *nombArchMedi);
void generarReporteConsultas(const char *nombArchReporte, const char *nombArchConsultas);
void imprimeLinea(ofstream &arch,char c,int n);
void descomponerFecha(int fecha,int &dia,int &mes,int &anio);


#endif /* FUNCIONES_H */

