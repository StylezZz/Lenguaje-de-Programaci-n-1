/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "funciones.h"
#define MAXLINEAS 150
using namespace std;

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++){
        arch<<c;
    }
    arch<<endl;
}

void hallarEspecialidad(char *nombreMedico,char *especialidad){
    int flag=0,j=0;
    for(int i=0;nombreMedico[i];i++){
        if(nombreMedico[i]=='_' and nombreMedico[i+2]>='a' and nombreMedico[i+2]<='z'){
            nombreMedico[i]='\0';
            flag=1;
        }
        if(flag){
            especialidad[j]=nombreMedico[i+1];
            j++;
            if(nombreMedico[i+1]=='\0')break;
        }
    }
}

bool buscarPaciente(int dni){
    int dniArch;
    double gasto;
    bool resultado=false;
    char nombrePaciente[150];
    ifstream archBusquedaBin("Pacientes.bin",ios::in|ios::binary);
    if(not archBusquedaBin.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Pacientes.bin"<<endl;
        exit(1);
    }
    while(1){
        archBusquedaBin.read(reinterpret_cast<char*>(&dniArch),sizeof(int));
        if(archBusquedaBin.eof())break;
        archBusquedaBin.read(reinterpret_cast<char*>(nombrePaciente),sizeof(char)*150);
        archBusquedaBin.read(reinterpret_cast<char*>(&gasto),sizeof(double));
        if(dni==dniArch){
            resultado=true;
            return resultado;
        }
    }
    
}

void cargarPacientes(ofstream &archPacientesBin,char *nombrePaciente,int dni){
   double montoGastado=0;
   //Se debe verficar que no se tengan pacientes repetidos
   bool repetido;
   repetido = buscarPaciente(dni);
   if(not repetido){
       //Si es que no se encuentra entonces se escribe en el archivo
       archPacientesBin.write(reinterpret_cast<const char*>(&dni),sizeof(int));
       archPacientesBin.write(reinterpret_cast<const char*>(nombrePaciente),sizeof(char)*150);
       archPacientesBin.write(reinterpret_cast<const char*>(&montoGastado),sizeof(double));
   }
}

bool buscarMedicina(int cod){
    int codigoBus;
    char descripcion[120];
    bool flag=false;
    double precio;
    ifstream arch("Medicinas.bin",ios::in|ios::binary);
    if(not arch.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Medicinas.bin"<<endl;
        exit(1);
    }
    while(1){
        arch.read(reinterpret_cast<char*>(&codigoBus),sizeof(int));
        if(arch.eof())break;
        arch.read(reinterpret_cast<char*>(descripcion),sizeof(char)*120);
        arch.read(reinterpret_cast<char*>(&precio),sizeof(double));
        if(cod==codigoBus){
            flag=true;
            return flag;
        }
    }
}

void cargarMedicinas(ofstream &archMedicinas,int codMedicamento,char *descripcion,
                double precioMedicina){
    bool repetido;
    repetido = buscarMedicina(codMedicamento);
    if(not repetido){
        archMedicinas.write(reinterpret_cast<const char*>(&codMedicamento),sizeof(int));
        archMedicinas.write(reinterpret_cast<const char*>(descripcion),sizeof(char)*120);
        archMedicinas.write(reinterpret_cast<const char*>(&precioMedicina),sizeof(double));
    }
}

void borrarCaracteres(char *nombre){
    for(int i=0;nombre[i];i++){
        if(nombre[i]=='_' or nombre[i]=='-'){
            nombre[i]=' ';
        }
    }
}

void convertirMayuscula(char *especialidad){
    for(int i=0;especialidad[i];i++){
        if(especialidad[i]>='a' and especialidad[i]<='z'){
            especialidad[i] = especialidad[i]- 'a' + 'A'; 
        }
    }
}

void cargarMedico(ofstream &archMedicos,char *codigoMedico,char *nombreMedico){
    char especialidad[60];
    hallarEspecialidad(nombreMedico,especialidad);
    convertirMayuscula(especialidad);
    archMedicos<<setw(10)<<codigoMedico<<setw(10)<<" "<<left<<setw(45)<<
            nombreMedico<<setw(10)<<" "<<especialidad<<endl;
}

//void generarConsultasBin(){
//    //Creamos el Consultas.bin
//    ofstream ()
//}

void ingresarConsultaParte2(ofstream &archConsultas,int id,int tope,int codMedicamento){
    if(tope==id){
        archConsultas<<setw(10)<<codMedicamento<<endl;
    }else{
        archConsultas<<setw(10)<<codMedicamento<<setw(10);
    }
}

void sacarFecha(int fecha, int& dd, int& mm, int& aa) {
    aa = fecha / 10000; 
    fecha = fecha % 10000; 
    mm = fecha / 100; 
    dd = fecha % 100; 
}

void ingresarConsultaParte1(ofstream &archConsultas,int dni,char *codigoMedico,
        int fecha,int cantMedicamentos){
    int dd,mm,aa;
    sacarFecha(fecha,dd,mm,aa);
    archConsultas<<dni<<setw(10)<<codigoMedico<<setw(50)<<dd<<"/"<<mm<<"/"<<aa<<setw(10);
    archConsultas<<cantMedicamentos;
}

void imprimirEncabezado(ofstream &archVerificacion){
    archVerificacion<<"CODMED"<<setw(10)<<"MEDICO"<<setw(50)<<"ESPECIALIDAD";
    archVerificacion<<setw(30)<<"DNI"<<setw(10)<<"PACIENTE"<<setw(50)<<"GASTO";
    archVerificacion<<"CODMEDICINA"<<setw(10)<<"DESCRIPCION"<<setw(50)<<"PRECIO";
}

void verificarMedicinasBin(){
    ifstream archMedicinasBin("Medicinas.bin",ios::in|ios::binary);
    if(not archMedicinasBin.is_open()){
        cout<<"ERROR no se puede abrir el archivo Medicinas.bin"<<endl;
        exit(1);
    }
    ofstream archReporte("ReporteMedicinas.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR no se puede abrir el archivo ReporteMedicinas.txt"<<endl;
        exit(1);
    }
    int cantMedicinas;
    char descripcion[120];
    double precio;
    archReporte<<"Reporte-Medicinas"<<endl;
    imprimirLineas(archReporte,'=');
    while(1){
        archMedicinasBin.read(reinterpret_cast<char*>(&cantMedicinas),sizeof(int));
        if(archMedicinasBin.eof())break;
        archMedicinasBin.read(reinterpret_cast<char*>(descripcion),sizeof(char)*120);
        archMedicinasBin.read(reinterpret_cast<char*>(&precio),sizeof(double));
        archReporte<<cantMedicinas<<"     "<<setw(70)<<left<<descripcion<<setw(20)<<right<<precio<<endl;
    }
    archMedicinasBin.close();
    archReporte.close();
}

void verficarPacientesBin(){
    //Como si se puede leer el Medicos.txt y Consultas.txt
    //Solo me queda leer bien el Pacientes.bin y el Medicinas.bin
    ifstream archPacientesBin("Pacientes.bin",ios::in|ios::binary);
    if(not archPacientesBin.is_open()){
        cout<<"ERROR no se pudo abrir Pacientes.bin"<<endl;
        exit(1);
    }
    
    ofstream archReporte("ReportePacientes.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR no se pudo abrir ReportePacientes.txt"<<endl;
        exit(1);
    }
   
    int dni;
    char nombre[150];
    double gastos;
    
    archReporte<<"Reporte-Pacientes:"<<endl;
    imprimirLineas(archReporte,'=');
    while(1){
        archPacientesBin.read(reinterpret_cast<char*>(&dni),sizeof(int));
        if(archPacientesBin.eof())break;
        archPacientesBin.read(reinterpret_cast<char*>(nombre),sizeof(char)*150);
        archPacientesBin.read(reinterpret_cast<char*>(&gastos),sizeof(double));
        archReporte<<dni<<"       "<<setw(30)<<left<<nombre<<setw(40)<<gastos<<endl;
    }
    archPacientesBin.close();
    archReporte.close();
}

void imprimirMedicos(ofstream &arch){
    ifstream archMedicos("Medicos.txt",ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Medicos.txt"<<endl;
        exit(1);
    }
    arch<<setw(50)<<"STAFF DE MEDICOS"<<endl;
    arch<<setw(20)<<"CODIGO"<<setw(10)<<"NOMBRE"<<setw(70)<<"ESPECIALIDAD"<<endl;
    int pos=1;
    char nombreMedico[150],especialidad[40],codMedico[15];
    while(1){
        archMedicos>>codMedico;
        if(archMedicos.eof())break;
        archMedicos>>nombreMedico>>especialidad;
        borrarCaracteres(nombreMedico);
        arch<<pos<<")"<<setw(20)<<codMedico<<setw(50)<<left<<nombreMedico<<setw(50)<<left<<especialidad<<endl;
        pos++;
    }
    archMedicos.close();
}

double preciomed(int codmedicamento){
    char medicamento[120];
    double precio;
    int codmedic;
    
    ifstream medbin("Medicinas.bin",ios::in|ios::binary);
    if(!medbin){
        cout << "No se puede abrir el archivo Medicinas";
        exit(1);
    }
    while(1){
        medbin.read(reinterpret_cast< char*>(&codmedic),sizeof(int));
        if(medbin.eof()) break;
        medbin.read(reinterpret_cast< char*>(medicamento),sizeof(char)*120);       
        medbin.read(reinterpret_cast< char*>(&precio),sizeof(double));          
        if(codmedic==codmedicamento) return precio;
    }
    return 0;
}

void actualiza_pac(int dni,double precio){
    char nombre[150];
    double gasto;
    int dni2;
    
    fstream pacbin("Pacientes.bin",ios::in|ios::out|ios::binary);
    if(!pacbin){
        cout << "No se puede abrir el archivo Pacientes";
        exit(1);
    }   
    while(1){
        pacbin.read(reinterpret_cast<char*>(&dni2),sizeof(int));
        if(pacbin.eof()) break;
        pacbin.read(reinterpret_cast<char*>(nombre),sizeof(char)*150);       
        pacbin.read(reinterpret_cast<char*>(&gasto),sizeof(double));     
        if(dni==dni2){
           int mov=-1*sizeof(double);
           pacbin.seekg(mov,ios::cur);
            gasto+=precio;
            pacbin.write(reinterpret_cast<const char*>(&gasto),sizeof(double));
            pacbin.flush();
            break;
        }
    }
}


void actualizarDatos(){
    int dni,dd,mm,aa,cantmed,codmedicamento;
    char nombre[100],medico[100],codmed[10],c,medicamento[100];
    double precio;
    
    ifstream cons("Consultas.txt",ios::in);
    if(!cons){
        cout << "No se puede abrir el archivo Consultas";
        exit(1);
    }    
    while(1){
        cons >> dni;
        if(cons.eof()) break;
        cons >> codmed >> dd >> c >> mm >> c >> aa >> cantmed;
        precio=0;
        for(int i=0;i<cantmed;i++){
            cons >> codmedicamento;
            precio += preciomed(codmedicamento);
        } 
        actualiza_pac(dni,precio);
    }
}

void imprimirPacientes(ofstream &arch){
    ifstream archPacientes("Pacientes.bin",ios::in|ios::binary);
    if(not archPacientes.is_open()){
        cout<<"ERROR no se pudo abrir Pacientes.bin"<<endl;
        exit(1);
    }
    int dni,pos=1;
    char nombre[150];
    double monto;
    arch<<setw(50)<<"PACIENTES REGISTRADOS"<<endl;
    arch<<setw(20)<<"DNI"<<setw(20)<<"NOMBRE"<<setw(50)<<"GASTOS POR MEDICINAS"<<endl;
    while(1){
        archPacientes.read(reinterpret_cast<char*>(&dni),sizeof(int));
        if(archPacientes.eof())break;
        archPacientes.read(reinterpret_cast<char*>(nombre),sizeof(char)*150);
        archPacientes.read(reinterpret_cast<char*>(&monto),sizeof(double));
        arch<<pos<<")"<<setw(15)<<dni<<setw(20)<<nombre<<setw(50)<<left<<monto<<endl;
        pos++;
    }
    archPacientes.close();
}

void imprimirMedicinas(ofstream &arch){
    ifstream archMedicinas("Medicinas.bin",ios::in|ios::binary);
    if(not archMedicinas.is_open()){
        cout<<"ERROR no se pudo abrir Medicinas.bin"<<endl;
        exit(1);
    }
    int codMedicina,pos=1;
    char descripcion[120];
    double precio;
    arch<<setw(50)<<"PACIENTES REGISTRADOS"<<endl;
    arch<<setprecision(2)<<fixed;
    arch<<setw(10)<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(70)<<"PRECIO"<<endl;
    while(1){
        archMedicinas.read(reinterpret_cast<char*>(&codMedicina),sizeof(int));
        if(archMedicinas.eof())break;
        archMedicinas.read(reinterpret_cast<char*>(descripcion),sizeof(char)*120);
        archMedicinas.read(reinterpret_cast<char*>(&precio),sizeof(double));
        arch<<pos<<")"<<setw(10)<<codMedicina<<setw(20)<<left<<descripcion;
        arch<<setw(70)<<left<<precio<<endl;
    }
    archMedicinas.close();
}

void imprimirConsultas(ofstream &arch){
    arch<<setw(50)<<"RELACION DE CONSULTAS"<<endl;
    arch<<setw(10)<<"PACIENTE"<<setw(10)<<"MEDICO"<<setw(20)<<"FECHA"<<setw(20)<<
            "CANTIDAD DE MEDICINAS"<<setw(20)<<"CODIGOS DE MEDICAMENTOS"<<endl;
    ifstream archConsultas("Consultas.txt",ios::in);
    if(not archConsultas.is_open()){
        cout<<"ERROR no se puede abrir Consultas.txt"<<endl;
        exit(1);
    }
    int dniPac,dd,mm,aa,cantidad,pos=1,codMedicina;
    char codMedico[40],c;
    while(1){
        archConsultas>>dniPac;
        if(archConsultas.eof())break;
        archConsultas>>codMedico>>dd>>c>>mm>>c>>aa>>cantidad;
        arch<<pos<<")"<<setw(10)<<dniPac<<setw(10)<<codMedico<<"   "<<dd;
        arch<<"/"<<mm<<"/"<<aa<<"   "<<cantidad<<setw(20);
        for(int i=0;i<cantidad;i++){
            archConsultas>>codMedicina;
            arch<<codMedicina<<"    ";
        }
        arch<<endl;
        pos++;
    }
    archConsultas.close();
}

void mostrarReporte(){
    //Primero se hará la creación del archivo ReporteFinal.txt
    ofstream arch("ReporteFinal.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR no se puede abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    arch<<setw(50)<<"EMPRESA PRESTADORA DE SALUD EPS-LP1"<<endl;
    imprimirLineas(arch,'=');
    imprimirMedicos(arch);
    imprimirLineas(arch,'=');
    actualizarDatos();
    imprimirPacientes(arch);
    imprimirLineas(arch,'=');
    imprimirMedicinas(arch);
    imprimirLineas(arch,'=');
    imprimirConsultas(arch);
    arch.close();
}



void leerArchivo(){
    //Abrimos los archivos
    ifstream arch("Medico-Paciente-Medicinas.txt",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Medicos-Paciente-Medicinas.txt"<<endl;
        exit(1);
    }
    ofstream archMedicos("Medicos.txt",ios::out);
    if(not archMedicos.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Medicos.txt"<<endl;
        exit(1);
    }
    ofstream archPacientesBin("Pacientes.bin",ios::out|ios::binary);
    if(not archPacientesBin.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Pacientes.bin"<<endl;
        exit(1);
    }
    ofstream archMedicinasBin("Medicinas.bin",ios::out|ios::binary);
    if(not archMedicinasBin.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Medicinas.bin"<<endl;
        exit(1);
    }
    
    ofstream archConsultas("Consultas.txt",ios::out);
    if(not archConsultas.is_open()){
        cout<<"ERROR no se pudo abrir el archivo Consultas.txt"<<endl;
        exit(1);
    }
    
    char codigoMedico[20],nombreMedico[150],nombrePaciente[150],codigoAtencion[20];
    char nombreMedicoCopy[150];
    char descripcion[120],c;
    double precioMedicina;
    int dni,fecha,dd,mm,aa,cantMedicamentos,codMedicamento;
    
    while(true){
        arch>>dni;
        if(arch.eof())break;
        if(arch.fail()){
            //Limpiamos
            arch.clear();
            arch>>codigoMedico>>nombreMedico;
            strcpy(nombreMedicoCopy,nombreMedico);
            //Luego de leer lo que se nos pide para el archivo medicos 
            //Se ingresa a dicho medico al archivo de Medicos.txt
            cargarMedico(archMedicos,codigoMedico,nombreMedico);
            
        }else{
            arch>>nombrePaciente>>codigoAtencion;
            arch>>dd>>c>>mm>>c>>c>>aa>>cantMedicamentos;
            fecha = dd + mm*100 + aa*10000;
            //Luego de tener los datos necesario para el paciente se les ingresa
            cargarPacientes(archPacientesBin,nombrePaciente,dni);
            ingresarConsultaParte1(archConsultas,dni,codigoAtencion,fecha,cantMedicamentos);
            for(int i=0;i<cantMedicamentos;i++){
                arch>>codMedicamento>>descripcion>>precioMedicina;
                cargarMedicinas(archMedicinasBin,codMedicamento,descripcion,precioMedicina);
                ingresarConsultaParte2(archConsultas,i+1,cantMedicamentos,codMedicamento);
            }
        }
    }
    arch.close();
    archMedicinasBin.close();
    archMedicos.close();
    archPacientesBin.close();
    archConsultas.close();
}