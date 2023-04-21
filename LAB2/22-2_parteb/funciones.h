/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.h
 * Author: MAURICIO
 *
 * Created on 18 de abril de 2023, 12:59 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void actualizarGastosPac(const char *nombArchPacientesB,const char *nombArchMedicinasB,
        const char *nombArchConsultasT);
void actualizarPaciente(int dniBuscado,fstream &arch,int cantReg,double precioMed,int);
double buscarPrecioMed(int codBuscado,ifstream &arch,int cantReg);
void generarReporteMed(const char *nombArchReporte,const char *nombArchMed);
void generarReportePac(const char *nombArchReporte,const char *nombArchPac);
void generarReporteMedicinas(const char *nombArchReporte,const char *nombArchMedi);
void generarReporteConsultas(const char *nombArchReporte, const char *nombArchConsultas);
void imprimeLinea(ofstream &arch,char c,int n);
void descomponerFecha(int fecha,int &dia,int &mes,int &anio);
void separadoresEspacios(char *cadena);

#endif /* FUNCIONES_H */

