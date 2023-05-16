/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPreg2.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 15:52
 */

#ifndef FUNCIONESPREG2_H
#define FUNCIONESPREG2_H
#include <fstream>
using namespace std;

void leerDatos(char **&clientes,int ***&intProductos,char ***&strProductos);

void agregarProducto(int **intProd,char **strProd,int cod,char *nombre,int cant,int &num);

int buscarProducto(int **intProducto,int cod,int num);
void incrementarEspacios2(int **&intProd, char **&strProd,int &numDat,int &cap);

void incrementarEspacios(char **&clientes,int ***&intProductos,char ***&strProducto,int &numDatos,int &cap);
char* leerCadena(ifstream &arch);

void imprimirDatos(char **clientes,int ***intProductos,char ***strProductos);
void imprimirLineas(ofstream &arch,char c);
void cambiarSTR (char **str, int i, int k);
void cambiarINT (int **num, int i, int k) ;
void ordenar (int **intProductos, char **strProductos, int izq, int der);
void ordenarPedidos (char **clientes, int ***intProductos, char ***strProductos) ;

#endif /* FUNCIONESPREG2_H */

