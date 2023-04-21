/* 
 * File:   Funciones.h
 * Author: Jhoyfer Melendez Torres (20203823)
 *
 * Created on 18 de abril de 2023, 07:12 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>

void leerArchivo();
void insertaMedico(ofstream &archMedicos, char *codigo, char *medico);
void divideCadenas(char *medico, char *especialidad);
void insertaPaciente(ofstream &archPacientes,int dni, char *nombrePaciente);
int verifica(int dni);
void crearReportesSimples();
void verificaPaciente(ifstream &paciente, ofstream &reporte);
void verificaMedicina();
void verificacionBinario( ifstream & nombreArch, const char * nombre);
void verificacionReporte( ofstream & nombreArch, const char * nombre);

#endif /* FUNCIONES_H */
