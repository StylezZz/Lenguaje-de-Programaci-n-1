/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: chris
 *
 * Created on 22 de abril de 2023, 16:38
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void operator *(struct Persona &per, double porc);
//double operator +(const struct Persona &per1,
//                          const struct Persona &per2);
struct Persona operator +(const struct Persona &per1,
                          const struct Persona &per2);

#endif /* FUNCIONES_H */

