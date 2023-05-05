/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: alulab14
 * Codigo: 20203371
 *  Nombre: Gabriel Omar Duran Ruiz
 * Created on 23 de septiembre de 2022, 08:05 AM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H
#include <fstream>
using namespace std;

void AbrirArchivoLectura(ifstream &arch,const char *nombArch);
void AbrirArchivoEscritura(ofstream &arch,const char *nombArch);
void lecturaDeMedicos(const char *nombArch,int *&med_Codigo,char **&med_Nombre,
        char **&med_Especialidad,double *&med_Tarifa);
void leeNombEsp(char *&nomb,char *&esp,ifstream &arch);
void copiarArreglosCrearDinamicosMed(int *&med_Codigo,char **&med_Nombre,
        char **&med_Especialidad,double *&med_Tarifa,int *buffCodigo,char **buffNomb,
        char **buffEspecialidad,double *buffTarifa,int numDat);
void pruebaDeLecturaMedicos(const char *nombArch,int *med_Codigo,char **med_Nombre,
        char **med_Especialidad,double *med_Tarifa);
void lecturaDeCitas(const char *nombArch,int *&pac_Dni,char **&pac_Nombre,int **&pac_Citas);
void agregarCitaAPaciente(int &codPac,char *nombPac,int *&citasPac,int &numCit,
        int codMed,int fecha,char *&nomb);
void copiarArreglosCrearDinamicosCitas(int *&pac_Dni,char **&pac_Nombre,
        int **&pac_Citas,int *buffCodPac,char **buffNombPac,int **buffPacCitas,
        int *cantCit,int numDat);
void llenarPacCitas(int *pacCitas,int *buffPacCitas,int cantCit);
void registrarNuevoPaciente(int *buffCodPac,char **buffNombPac,int **buffPacCitas,
                    int codPac,char *nomb,int codMed,int fecha,int &numDat,int *cantCit);
void leerFecha(ifstream &arch,int &fecha);
int buscarPaciente(int codPac,int *buffCodPac,int numDat);
char *leeCadena(ifstream &arch,int c);
void pruebaDeLecturaDeCitas(const char *nombArch,int *pac_Dni,char **pac_Nombre,int **pac_Citas);
void imprimeCitasPaciente(int *pac_Citas,ofstream &arch);
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nombArch,
            int *med_Codigo,char **med_Nombre,char **med_Especialidad,
        double *med_Tarifa,int *pac_Dni,char **pac_Nombre,int **pac_Citas);
void imprimeCabeceraIngresos(ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);
void imprimeCabeceraMedicos(ofstream &arch);
void imprimeCabeceraPacientes(ofstream &arch);
#endif /* METODODINAMICOEXACTO_H */

