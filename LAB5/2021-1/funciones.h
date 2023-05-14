/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 7 de mayo de 2023, 0:14
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
char* leerCadena(ifstream &arch);
void reporteConductores(int *licencia,char **conductor);
void incrementarEspacios(int *&licencia,char **&conductor,int &numDatos,int &cap);
void cargarConductores(int *&licencia,char **&conductor);
void imprimirLineas(ofstream &arch,char c);
char* leerCadenaSaltoLinea(ifstream &arch);
void reporteFaltas(int *licencia,char **conductor,char ***placa,int **falta);
int buscarLicencia(int dato,int *licencias);
void incrementarEspacios(char **&placa,int *&falta,int &numDatos,int &cap);
void agregarFalta(char **&placa,int *&falta,int &numDatos,int &cap,char *auxPlaca,
                  int auxFalta);
void cargarFaltas(int *licencia, char ***&placa,int **&falta);
void incrementarEspacios(char **&placa,int *&falta,int &numDatos,int &cap);
void imprimirFaltas(char **placa,int *falta,ofstream &arch);
void imprimeMultas(double *multa,ofstream &arch);
void reporteMultas(int *licencia,char **conductor,double **multa);
double buscarFalta(int num,ifstream &arch,int &pos);
void cargarMultas(int *&falta,double *&multa,ifstream &arch);
void resumenMultas(int *licencia,int **falta,double **&multa);
#endif /* FUNCIONES_H */

