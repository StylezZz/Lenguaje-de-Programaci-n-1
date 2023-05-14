/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 8 de mayo de 2023, 10:20
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *persona;
    
    leeRegistro(persona);
    imprimeRegistro(persona);
    return 0;
}

