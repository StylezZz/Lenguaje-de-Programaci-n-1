/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAplicacion.h
 * Author: chris
 *
 * Created on 26 de abril de 2023, 15:00
 */

#ifndef FUNCIONESAPLICACION_H
#define FUNCIONESAPLICACION_H


bool buscarCodigo(int codigo,struct StPaciente *arrPacientes,int numPac,int &pos);
void completarPacientes(int dniBusqueda,struct StPaciente *arrPacientes,int numCitas
                        ,int numPac,struct StCita *arrCitas);

void leerMedicos(struct StMedico *arrMedicos,int &numMedicos);
//Parte B
void leerPacientes(struct StPaciente *arrPacientes,int &numPacientes);

//Parte C
void leerCitas(struct StCita *arrCitas,int &numCitas,struct StPaciente *arrPacientes,
        int numPacientes);
//Función de impresión de caracteres
void imprimirLineas(ofstream &arch,char c);

void emitirReporte(struct StPaciente *arrPacientes,struct StCita *arrCitas,
                   struct StMedico *arrMedicos,int numPacientes,int &numCitas,
                   int numMedicos);
#endif /* FUNCIONESAPLICACION_H */

