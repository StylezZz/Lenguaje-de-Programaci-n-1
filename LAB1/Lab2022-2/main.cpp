/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on 11 de abril de 2023, 11:11
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    char codigoMedico[20],pediatria[50],ginecologia[50];
    char nombreCompleto[150];
    int fecha,dniPaciente;
    char nombrePaciente[150];
    int cantMedicamentos,codMedicina,fechaRetiro;
    leerPrimeraLinea(pediatria,ginecologia,fecha);
    char especialidad[20],nombreMedicina[100];
    while(true){
        cin>>codigoMedico>>nombreCompleto;
        formatearEspecialidad(nombreCompleto,especialidad);
        if(cin.eof()){
            break;
        }
        if(cin.fail()){
            //pacientes
            cin>>dniPaciente>>nombrePaciente>>cantMedicamentos;
            if(validarEspecialidad(especialidad,pediatria,ginecologia)){
                //Validar que es solo pediatria o ginecologia
                int pos=0,bandera=0;
                int dd,mm,aa;
                char c;
                imprimirPaciente(pos,dniPaciente,nombrePaciente,cantMedicamentos);
                for(int i=0;i<cantMedicamentos;i++){
                    cin>>codMedicina>>nombreMedicina>>dd>>c>>mm>>c>>aa;
                    imprimirMedicamento(codMedicina,nombreCompleto,dd,mm,aa,bandera);
                }
            }
        }else{
            //ya leiste doctor
            imprimirDoctor(nombreCompleto,codigoMedico,especialidad);
            
        }
    }
    return 0;
}

