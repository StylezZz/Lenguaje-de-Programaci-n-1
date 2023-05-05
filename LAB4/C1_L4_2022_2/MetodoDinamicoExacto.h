/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: AndreeEstudio
 *
 * Created on 30 de abril de 2023, 07:31
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
#include <iomanip>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "MetodoDinamicoExacto.h"
#define MAXLIN 100
using namespace std;


void implin(ofstream &arch,char car,int c);
void lee_cadenas(char *&cad,char *&esp,char *nomxesp);
void lecturaDeMedicos(const char *nom
        ,int *&med_Codigo,char **&med_Nombre,char **&med_Especialidad
        ,double *&med_Tarifa);
void lee_data(ifstream &arch,char *&xxnom);
void pruebaDeLecturaDeMedicos(const char *nom
        ,int *med_Codigo,char **med_Nombre,char **med_Especialidad
        ,double *med_Tarifa);
int busca_dat(int ffdni[],int xdni,int cant);
void lecturaDeCitas(const char *nom,int *&pac_Dni,char **&pac_Nombre
                ,int **&pac_Citas);
void asigna_citas(int *&pac_Citas,int *&ffCita,int num);
void copiar_arr_dinamicos(int *&pac_Dni,char **&pac_Nombre
                            ,int **&pac_Citas
                        ,int *ffdni,char **ffnom,int **ffcita
                        ,int *num_cit,int cant);
void agraga_cod_med_fecha(int *&ffcita,int xcita,int xcitafecha,int num_cit);
void pruebaDeLecturaDeCitas(const char *nom,int *pac_Dni,char **pac_Nombre
                ,int **pac_Citas);
int busca(int **pac_Citas,int cod);
int busca_med(int *med_Codigo,int cod);
void saca_resto(int *pac_Citas,
        int *med_Codigo,double *med_Tarifa
    ,int *num_citas,double *tot_gastos);
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nom
            ,int *med_Codigo,char **med_Nombre
            ,char **med_Especialidad,double *med_Tarifa,int *pac_Dni
            ,char **pac_Nombre,int  **pac_Citas);
#endif /* METODODINAMICOEXACTO_H */
