/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 30 de marzo de 2023, 19:34
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void imprimirLineas(char c);
void sacarFecha(int &dd,int &mm,int &aa,int fecha);
void imprimirFechas(int fechaAdm,int fechaDoc,int fechaEst);
void imprimirPrimerEncabezado(int fechaAdm,int fechaDoc,int fechaEst);
void leerFecha(int &fecha);
void leerFechas(int &fechaAdm,int &fechaDoc,int &fechaEst);

#endif /* FUNCIONES_H */

