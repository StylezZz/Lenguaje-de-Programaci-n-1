/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 14 de mayo de 2023, 0:51
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funcionesPreg1.h"
#include "funcionesPreg2.h"
using namespace std;

int main(int argc, char** argv) {
    void *sesiones;
    leerSesiones(sesiones);
    imprimirSesiones(sesiones);
    return 0;
}

