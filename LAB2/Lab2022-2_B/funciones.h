/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 20 de abril de 2023, 10:55
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
void mostrarReporte();
void verificarMedicinasBin();
void borrarCaracteres(char *nombre);
void convertirMayuscula(char *especialidad);
void ingresarConsultaParte2(ofstream &archConsultas,int id,int tope,char *codMedicamento);
void ingresarConsultaParte1(ofstream &archConsultas,int dni,char *codigoMedico,
        int fecha,int cantMedicamentos);
void sacarFecha(int fecha, int& dd, int& mm, int& aa);
void hallarEspecialidad(char *nombreMedico,char *especialidad);
bool buscarPaciente(int dni);
void cargarPacientes(ofstream &archPacientesBin,char *nombrePaciente,int dni);
bool buscarMedicina(int cod);
void cargarMedicinas(ofstream &archMedicinas,int codMedicamento,char *descripcion,
                double precioMedicina);
void cargarMedico(ofstream &archMedicos,char *codigoMedico,char *nombreMedico);
void leerArchivo();
void verficarPacientesBin();
#endif /* FUNCIONES_H */

