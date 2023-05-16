/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibCargaFaltas.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 18:57
 */

#ifndef BIBCARGAFALTAS_H
#define BIBCARGAFALTAS_H
#include <fstream>
using namespace std;

void cargarFaltas(int *licencia,char ***placa,int ***&falta,int ***&fecha);
void reducirMemoria(int **&falta,int **&fecha,char **placa);
void reducir(int *&falta,int *&fecha);
void agregarDatos(int **&falta,int **&fecha,char **placa,
        char *placaAux,int auxFecha,int auxLicencia,int numFalta);
int buscarPlaca(char *cad,char **placas);
int buscarLicencia(int cod,int *arreglo);
char *leerCadena(ifstream &arch);
void imprimirLineas(ofstream &arch,char c);
void reporteFaltas(int *licencia,char **conductor,char ***placa,int ***falta,
        int ***fecha);
double obtenerMontoTotal(int *falta,int *fecha,int &fecha1,int &fechaN);
double obtenerMontoMulta(int codInfraccionArch);


#endif /* BIBCARGAFALTAS_H */

