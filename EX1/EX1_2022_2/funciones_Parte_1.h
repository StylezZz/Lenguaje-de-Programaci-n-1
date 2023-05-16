/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_Parte_1.h
 * Author: jean-
 *
 * Created on 15 de mayo de 2023, 01:24 AM
 */

#ifndef FUNCIONES_PARTE_1_H
#define FUNCIONES_PARTE_1_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

char *leerCadenaBuff(char *cad);
char *leerCadenaArch(ifstream &arch,char c);
//60509,AMPICILINA 125MG SUSP 90ML,58.65
void CargarMedicamentos(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,
        const char *name);
void leerMedicina(ifstream &arch,char *&descMedicina,double &precioMedicina);
void agregarMedicina(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,
        int &numDat,int &tamanio,int codMedicina,char *descMedicina,double precioMedicina);
void aumentarEspacios(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,
       int &numDat,int &tamanio);
void PruebaDeCargaDeMedicamentos(int *med_Codigo,char **med_Descripcion,
        double *med_Precio,const char *name);



void CargarConsultas(int ***&consultas_int,char ***&consultas_char,const char *name);
void pasarAMemoriaExacta(int ***&consultas_int,char ***&consultas_char,int numDat,
        int *buffDni,int *buffFecha,int **buffMedicamentos,int *cantMedicamento,
        char ***buffMedicos,int *cantMedicos,char **buffNombre);
void cargarPaciente(int **&consultas_int,char **&consultas_char,int buffDni,int buffFecha,
        int *buffMedicamentos,int cantMedicamento,char **buffMedicos,int cantMedicos,
        char *buffNombre);
void cargarPaqueteMedicina(int *&consultas_int,int buffMedicina,int buffcantidad);
void actualizarPaciente(ifstream &arch,int &buffFecha,
        int *&buffMedicamentos,int &cantMedicamento,
        char **&buffMedicos,int &cantMedicos,
        int fecha,char *codMedico);
int buscarMedico(char *codMedico,char **buffMedicos);
int buscarMedicamento(int codMedicamento,int *buffMedicamentos);
void agregarPaciente(ifstream &arch,int &buffDni,int &buffFecha,
        int *&buffMedicamentos,int &cantMedicamento,
        char **&buffMedicos,int &cantMedicos,
        char *&buffNombre,int dniPac,int fecha,char *nombPac,char *codMedico);
int buscarPaciente(int dniPac,int *buffDni);
void leerCabeza(ifstream &arch,int dd,int &fecha,int &dniPac,char *&nombPac,
        char *&codMedico);
void PruebaDeCargaDeConsultas(int ***consultas_int,char ***consultas_char,const char *name);

#endif /* FUNCIONES_PARTE_1_H */
