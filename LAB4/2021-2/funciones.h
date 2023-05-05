/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 4 de mayo de 2023, 8:31
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
char *leerCadena(ifstream &in);
void estructurasParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,
                                           int *&cantEnBibl,double *&precio);
void estructurasParaLosLibros_Reporte(char **codigo,char **titulo,int *cantEnBibl,
                                      double *precio);
void usuariosDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre);
char *leerCadenaFinal(ifstream &in);
void usuariosDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre);
void librosYUsuariosInhabilitados_Reporte(char **&codigo,char **&titulo,int *&cantEnBibl,
                                          double *&precio,int *&carne,char *&tipo,
                                          char **&nombre);
void abrirArchivo(char car,char **codigo,char **titulo,int *&cantEnBibl,
                  double *precio,int *carne,char *tipo,char **nombre,
                  double *&deudaPrecio,ofstream &reporte);
void imprimirReporte(char car,int *carneDeuda,int *cantDeuda,char **nombreDeuda,
                     double *montoDeuda,ofstream &arch);
void imprimirLibros(char **codigo,char **titulo,int *cantEnBibl,
                    double *precio,double *deudaXLibro,ofstream &arch);
#endif /* FUNCIONES_H */

