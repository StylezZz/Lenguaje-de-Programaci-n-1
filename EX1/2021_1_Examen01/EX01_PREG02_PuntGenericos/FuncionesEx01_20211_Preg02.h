/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesEx01_20211_Preg02.h
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 25 de mayo de 2021, 09:43 AM
 */

#ifndef FUNCIONESEX01_20211_PREG02_H
#define FUNCIONESEX01_20211_PREG02_H
#include <fstream>
using namespace std;

void cargadatos(void *&conductor,void *&falta);
void leerConductores(void *&conductor);
void* leeConductor(ifstream &archConductores);
char * leerCadena(ifstream &archConductores,char car);
void imprimeConductor(void *conductor);
void leerFaltas(void *&falta);
void imprimefalta(void *falta);
void registrafaltas(void *&consolidado,void *conductor,void *falta);
void imprime(void *consolidado);
void imprimirConductor(void *conductorReg,ofstream &archMuestraConductores);
void* leeInfraccion(ifstream &archInfracciones);
void imprimefaltareg(ofstream &arch,void *registro);
void asignarConductoresConsolidado(void **consolidadoBuff,void *conductor,void *falta,int licenciaArch,
        int mmArch,int aaArch,int codInfraccionArch,int numConsolidados);
int buscarConductorConsolidado(void **consolidadoBuff,int licenciaArch,int mmArch,int aaArch);
char * asignarNombre(void *conductor,int licenciaArch);
int buscarFalta(int codInfraccionArch,void *falta);
void imprimirLinea(char car,int cant,ofstream &arch);
void ordenarConsolidado(void *consolidado);
void qsortConductores(void *consolidado,int izq,int der);
void cambiar(void *&i, void *&k);
int comparar(void *registroI,void *registroK);
void imprimirCadaConsolidado(void *consolidadoReg,ofstream &archReporte);


#endif /* FUNCIONESEX01_20211_PREG02_H */

