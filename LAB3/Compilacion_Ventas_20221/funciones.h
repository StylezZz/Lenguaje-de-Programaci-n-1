/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 25 de abril de 2023, 12:07
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

ifstream &operator >>(ifstream &in,struct Estructura_ClienteRegistrado &cliente);
void operator +=(struct Estructura_ClienteRegistrado *cli,
                 struct Estructura_ClienteRegistrado cliVar);
void operator +=(struct Estructura_ClienteRegistrado &cli,
                 struct Estructura_PedidoRealizado ped);
void operator +=(struct Estructura_ProductosEnAlmacen *arrPro,
                 struct Estructura_ProductosEnAlmacen pro);
void imprimirFecha(ofstream &out,int fecha);
ofstream &operator <<(ofstream &out,
                      struct Estructura_ClienteRegistrado c);
ofstream &operator <<(ofstream &out,
                      struct Estructura_ProductosEnAlmacen *arr);

#endif /* FUNCIONES_H */

