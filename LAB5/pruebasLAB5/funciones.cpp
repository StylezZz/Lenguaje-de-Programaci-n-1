/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
enum Registro{DNI,NOMBRE,SUELDO};

void leeRegistro(void *&persona){
    int *dni,d;
    char *nombre,buff[100];
    double *sueldo; 
    void **registro;
    
    cin>>d;
    if(cin.eof()){
        persona = nullptr;
        return;
    }
    dni = new int;
    *dni = d;
    cin.get();
    cin.getline(buff,100,',');
    nombre = new char[strlen(buff)+1];
    strcpy(nombre,buff);
    sueldo = new double;
    cin.get();
    cin>>*sueldo;
    
    registro = new void*[3];
    registro[DNI]=dni;
    registro[NOMBRE]=nombre;
    registro[SUELDO]=sueldo;
    
    persona = registro;
}

void imprimeRegistro(void *persona){
    int *dni;
    char *nombre;
    double *sueldo;
    void **registro= (void **)persona;
    
    dni = (int*)(registro[DNI]);
    nombre = (char*)(registro[NOMBRE]);
    sueldo = (double*)(registro[SUELDO]);
    
    cout.precision(2);
    cout<<fixed;
    cout<<left<<setw(10)<<*dni<<setw(40)<<nombre<<
            right<<setw(12)<<*sueldo<<endl;
    
}

void liberarEspacios(void *persona){
    int *dni;
    char *nombre;
    double *sueldo;
    void **registro= (void **)persona;
    
    dni = (int*)(registro[DNI]);
    nombre = (char*)(registro[NOMBRE]);
    sueldo = (double*)(registro[SUELDO]);
    
    delete dni;
    delete nombre;
    delete sueldo;
    delete registro;
}
