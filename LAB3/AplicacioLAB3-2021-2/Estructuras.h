/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estructuras.h
 * Author: alulab14
 *
 * Created on 27 de abril de 2023, 10:09 AM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct St_LibroPrestado{
    char codigoLib[20];
    int fechaRetiro;
    bool deuda;
};

struct St_Usuario{
    int carne;
    char tipo[20];
    char nombre[150];
    struct St_LibroPrestado libPrest[20];
    int numLibPrest;
    char condicion[20];
};


struct St_UsuarioPrestamo{
    int carne;
    char tipo;
    int fechaRetiro;
    bool deuda;
};



struct St_Libro{
    char codigo[20];
    char titulo[200];
    int stock;
    double precio;
    int prestados;
    struct St_UsuarioPrestamo estudiantes[100];
    struct St_UsuarioPrestamo docentes[100];
    struct St_UsuarioPrestamo administrativos[100];
    int cantEst;
    int cantDoc;
    int cantAdm;
};




#endif /* ESTRUCTURAS_H */

