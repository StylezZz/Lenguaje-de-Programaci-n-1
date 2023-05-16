/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BibCargaFaltas.h
 * Author: Alonso Oswaldo Acosta Gonzales
 * Codigo del Alumno: 20170809
 * Created on 25 de mayo de 2021, 08:13 AM
 */

#ifndef BIBCARGAFALTAS_H
#define BIBCARGAFALTAS_H
#include <fstream>
using namespace std;

void cargarFaltas(int *licencia,char ***placa,int ***&falta,int ***&fecha);
void reporteFaltas(int *licencia,char **conductor,char ***placa,int ***falta,int ***fecha);
int buscarConductor(int *licencia,int licenciaArch);
void asignarFaltas(int **&falta,int **&fecha,char **placa,char *placaArch,int fechaArch,int codInfraccionArch);
double obtenerMontoMulta(int codInfraccionArch);
int buscarPlaca(char *placaArch,char **placa);
double obtenerMontoTotal(int *falta,int *fecha,int &fecha1,int &fechaN);
double obtenerMontoMulta(int codInfraccionArch);
void imprimirLinea(char car,int cant,ofstream &arch);
void achicarMemoria(int ***falta,int ***fecha,char ***placa,int numConductores);
void achicarMemoriaConductor(int **&falta,int **&fecha,char **placa);
void achicarMemoriaInfraccciones(int *&falta,int *&fecha);

#endif /* BIBCARGAFALTAS_H */

