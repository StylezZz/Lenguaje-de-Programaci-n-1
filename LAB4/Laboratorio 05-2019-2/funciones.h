/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 29 de abril de 2023, 18:36
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
char *asignarCadena(char *cadena);
void incrementarEspacios(char **&productos,int &numProd,int &cap);

char **leerAlmacen(ifstream &arch);

void leerPalets(char ***&almacenes);
void imprimirPalets(char ***almacenes);

char  *leerCadena(ifstream &in,char ='\n');

void leerProductos(char **&codigoProd,char **&nombreProd);

void imprimirProductos(char **codigoProd,char **nombreProd);

void ordenarProductos(char **codigoProd,char **nombreProd);
void cuentaProductos(char ***almacenes,char **codigoProd,char **nombreProd);
void ordenarProductos(char **codigoProd,char **nombreProd);
void ordenar(char **codigoProd,char **nombreProd,int izq,int der);
void cambiar(char **st,int i,int k);
void cuentaProductos(char ***almacenes,char **codigoProd,char **nombreProd);

int contar(char *codigoProd,char ***almacenes);
#endif /* FUNCIONES_H */

