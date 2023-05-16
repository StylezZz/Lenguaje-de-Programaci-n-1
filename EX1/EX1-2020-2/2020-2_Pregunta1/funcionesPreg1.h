/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesPreg1.h
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 12:29
 */

#ifndef FUNCIONESPREG1_H
#define FUNCIONESPREG1_H
#include <fstream>
using namespace std;

void leerDatos(void *&pedidos,void *&stock);
void atiende(void *pedidos,void *stock);
void imprimirDatos(void *pedidos,void *stock);
void* leerDato(ifstream &arch);
void leerStock(void *&stock,ifstream &arch);
void mostrarStock(void *stock,ofstream &arch);
void imprimirStock(void *stock,ofstream &arch);
void imprimirLineas(ofstream &arch,char c);
void imprimirPedido(void *ped,ofstream &arch);
void imprimirPedidos(void *pedidos,ofstream &arch);
void *devolverPedido(int codRuc,int dd,int mm,int aa,int codProd,char *nomProd,int cantPedida,
        int cantSolicitada);
void leerPedidos(void *&pedidos,ifstream &arch);
char *leerCadena(ifstream &arch);
void ordenarPedidos(void *pedidos,int opc);
void qsortPedidos(void **pedidos,int izq,int der,int opc);
void cambiar(void *&pedido1,void *&pedido2);
int comparar(void *p1,void *p2,int opc);
//void atiende(void *pedidos,void *stock)
void atenderPedido(void *ped,void *stock);
int actualizarStock(int codigo,int cantSol, void *stock);
void imprimePedidoF (int ruc, int fecha, int codP, char *nombP, int cantS, int cantA,
        ofstream &arch);
void imprimirDatos(void *pedidos,void *stock);


#endif /* FUNCIONESPREG1_H */

