/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcione.h
 * Author: chris
 *
 * Created on 3 de mayo de 2023, 22:27
 */

#ifndef FUNCIONE_H
#define FUNCIONE_H
#include <fstream>
using namespace std;

char* leerCadenaSaltoLinea(ifstream &);
void cargarConductores(int *&,char **&);
void imprimirLineas(ofstream &,char );
void reporteConductores(int *,char **);
void cargarInfracciones(int *&,char *&,double *&);
void reporteInfracciones(int *,char *,double *);
void reporteDeFaltas(int *,char **,int *,char *,double *);
void limpiarArchivos(int *&,int *&,char **&,double *&);
void mostrarReporte(ofstream &,int *,char **,int *,double *,char);
void abrirArchivo(int *&,char **&,int *&,double *&,int *,char **,int *,char *,double *,char);
int buscarPlaca(char **,char *,int);
int esTipoFalta(char ,int *,char *);
#endif /* FUNCIONE_H */

