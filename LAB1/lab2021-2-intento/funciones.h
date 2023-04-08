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


void imprimirResumen(int cantLibros,double sumaDeudas);
void imprimirCurso(char *codLibro,int fechaRetiro,double deudaxLibro,int primero);
void mostrarSubtitulos();
void imprimirSegundoEncabezado(int numCarnet,char tipo,char *nombre);
void calcularDeuda(int fechaAdm,int fechaDoc,int fechaEst,int fechaRetiro,
                    char tipo,double &deuda,double precioLibro);
void leeCurso(char *codLibro,int &fechaRetiro,double &precioLibro,
        double &deudaxLibro,char tipo,int fechaAdm,int fechaDoc,int fechaEst);
void imprimirCabeceraYFechas(int fechaDoc,int fechaEst,int fechaAdm);
void imprimirLineas(char c);
void sacarFecha(int &dd,int &mm,int &aa,int fecha);
void imprimirFechas(int fechaAdm,int fechaDoc,int fechaEst);
void imprimirPrimerEncabezado(int fechaAdm,int fechaDoc,int fechaEst);
void leerUnaFecha(int &fecha);
void leerFechas(int &fechaAdm,int &fechaDoc,int &fechaEst);

#endif /* FUNCIONES_H */

