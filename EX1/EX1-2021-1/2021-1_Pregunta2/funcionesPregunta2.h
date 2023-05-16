/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPregunta2.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 20:06
 */

#ifndef FUNCIONESPREGUNTA2_H
#define FUNCIONESPREGUNTA2_H
#include <fstream>
using namespace std;

void imprime(void *consolidado);
void registraFaltas(void *&consolidado,void *conductor,void *falta);
char *leerCadenaFin(ifstream &arch);
void *obtenerConductor(ifstream &arch);
void leerConductores(void *&conductores,ifstream &arch);
void cargarDatos(void *&conductor,void *&falta);
void imprimeconductor(void *conductor);
void imprimirUnConductor(void *conductor,ofstream &arch);
void imprimirLineas(ofstream &arch,char c);
void leerFaltas(void *&falta,ifstream &arch);
void *obtenerFalta(ifstream &arch);
char *leerCadena(ifstream &arch);
void imprimefalta(void *falta);
void muestraFalta(void *falta,ofstream &arch);
void asignarDatosFalta(void **buffConsolidados,void *conductor,
        void *falta,int auxLicencia,int mm,int aa,int codInfraccion,int numConsolidados);
int buscarConductorEnConsolidado(void **buffConsolidados,int auxLicencia,int mm,int aa);
char *retornarNombre(void *conductor,int licenciaAux);
int buscarFalta(int cod,void *falta);



#endif /* FUNCIONESPREGUNTA2_H */

