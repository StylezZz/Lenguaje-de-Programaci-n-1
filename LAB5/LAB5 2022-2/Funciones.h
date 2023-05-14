/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Author: Lenovo
 *
 * Created on 8 de mayo de 2023, 10:52 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void AbrirArchivoL(ifstream &arch, const char *nombArch);
void AbrirArchivoE(ofstream &arch, const char *nombArch);
void cargarCitas(const char *nombArch, char ***&medicoDatos, double *&medicoTarifaHora,
            char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago);
void agregarPacientes(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempoYPago,
                            char *codPaciente,char *nombrePaciente,double tiempo,double montoPagar,
                            int &nd,int &tam);
int buscarPaciente(char *dni,char ***&citaPaciente,int nd);
void hallarMonto(int h1,int m1,int s1,int h2,int m2,int s2,double tarifa,double &tar,double &tiempo);
int buscar(char *codMedico,char ***medicoDatos,int numProd);
void agregarMedicos(char ***&medicoDatos,double *&medicoTarifaHora,
                    char *codMedico,char *nombreMedico,double tarifa,
                    int &numProd,int &tamProd);
void aumentarEspacios1(char ***&medicoDatos,double *&medicoTarifaHora,
                int &numProd,int &cap);
char *asignar(char *cadena);
void pruebaDeCargaDeCitas(const char *nombArch, char ***medicoDatos, double *medicoTarifaHora,
            char ****citaPaciente, int **citaCantidad, double ***citaTiempoYPago);
void ReporteDeCitasPorMedico(const char *nombArch, char ***medicoDatos, double *medicoTarifaHora,
            char ****citaPaciente, int **citaCantidad, double ***citaTiempoYPago);
void incrementarEspacios2(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempoYPago,
                    int &nd,int &tam);
void inicializarPtr(char ****&citaPaciente, int **&citaCantidad, double ***&citaTiempoYPago);
void elaborarLinea(ofstream &arch,int cant,char c);
void incremento(char ***&medicoDatos,double *&medicoTarifaHora, char ****&citaPaciente, 
                int **&citaCantidad,double ***&citaTiempoYPago,
                    int &num,int &tam);
#endif /* FUNCIONES_H */

