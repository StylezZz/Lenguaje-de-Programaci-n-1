/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <ratio>
#include "funciones.h"
#include "FuncionesFecha.h"
#define MAXLINEAS 100
using namespace std;

char *leerCadenaFinal(ifstream &in){
    char buff[250],*cad;
    in.getline(buff,250,'\n');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

char *leerCadena(ifstream &in){
    char buff[250],*cad;
    in.getline(buff,250,',');
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void estructurasParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,
                                           int *&cantEnBibl,double *&precio){
    ifstream arch("Libros.csv",ios::in);
    if(!arch){
        cout<<"ERROR no se pudo abrir el archivo Libros.csv"<<endl;
        exit(1);
    }
    char *buffCodigos[200],*buffTitulos[200],*cod,*nombreTitulo,*persona;
    int buffCantEnBibl[200],numDatos=0,aa,cant;
    double buffPrecio[200],auxPrecio;
    char c;
    
    while(1){
        cod = leerCadena(arch);
        if(arch.eof())break;
        nombreTitulo = leerCadena(arch);
        persona = leerCadena(arch);
        arch>>aa>>c>>cant>>c>>auxPrecio;
//        cout<<cod<<" "<<nombreTitulo<<" "<<cant<<" "<<auxPrecio<<endl;
        buffCodigos[numDatos]=cod;
        buffTitulos[numDatos]=nombreTitulo;
        buffPrecio[numDatos]=auxPrecio;
        buffCantEnBibl[numDatos]=cant;
        numDatos++;
    }
    
    codigo = new char*[numDatos+1];
    titulo = new char*[numDatos+1];
    cantEnBibl = new int[numDatos+1];
    precio = new double[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        codigo[i]=buffCodigos[i];
        titulo[i]=buffTitulos[i];
        cantEnBibl[i]=buffCantEnBibl[i];
        precio[i]=buffPrecio[i];
    }
    codigo[numDatos]=nullptr;
    titulo[numDatos]=nullptr;
    cantEnBibl[numDatos]=0;
    precio[numDatos]=0;
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<MAXLINEAS;i++)arch<<c;
    arch<<endl;
}


void estructurasParaLosLibros_Reporte(char **codigo,char **titulo,int *cantEnBibl,
                                      double *precio){
    ofstream arch("ReporteParaLibros.txt",ios::out);
    if(!arch){
        cout<<"Error no se ha abierto el archivo ReporteParaLibros.txt"<<endl;
        exit(1);
    }
    arch<<"Reporte para libros"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(10)<<left<<"CODIGO"<<setw(40)<<right<<"TITULO"<<setw(20)<<right<<"STOCK"<<
           setw(20)<<"PRECIO"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;codigo[i]!=nullptr;i++){
        arch<<setw(20)<<left<<codigo[i]<<setw(40)<<right<<titulo[i]<<setw(10)<<right<<
                cantEnBibl[i]<<setw(20)<<precio[i]<<endl;
    }
}

void encontrarTipo(char *carneTipo,char &tipo){
    
}

//char *tipo,**nombre;
//int *carne;
void usuariosDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre){
    ifstream arch("Usuarios.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Usuarios.csv"<<endl;
        exit(1);
    }
    int buffCarne[200],numDatos=0,carneAux;
    char buffTipo[200],*buffNombre[200],*nombreUsuario,tipoAux,c;
    while(1){
        arch>>carneAux>>tipoAux>>c;
        if(arch.eof())break;
        nombreUsuario = leerCadenaFinal(arch);
//        cout<<carneAux<<" "<<tipoAux<<" "<<nombreUsuario<<endl;
        buffCarne[numDatos]=carneAux;
        buffTipo[numDatos]=tipoAux;
        buffNombre[numDatos]=nombreUsuario;
        numDatos++;
    }
    carne = new int[numDatos+1];
    tipo = new char[numDatos+1];
    nombre= new char*[numDatos+1];
    
    
    
    for(int i=0;i<numDatos;i++){
        carne[i]=buffCarne[i];
        tipo[i]=buffTipo[i];
        nombre[i]=buffNombre[i];
    }
    
    
    cout<<numDatos<<endl;
    
    carne[numDatos]=0;
    tipo[numDatos]=0;
    nombre[numDatos]=nullptr;
    
//    for(int i=0;carne[i];i++){
//        cout<<carne[i]<<" "<<tipo[i]<<" "<<nombre[i]<<endl;
//    }
}

void usuariosDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre){
    ofstream arch("ReporteDeUsuarios.txt",ios::out);
    if(!arch){
        cout<<"Error no se puede abrir el archivo ReporteDeUsuarios.txt"<<endl;
        exit(1);
    }
    arch<<"Reporte de Usuarios"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(15)<<left<<"CARNE"<<setw(20)<<right<<"TIPO"<<setw(40)<<right<<"NOMBRE"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;carne[i];i++){
        arch<<setw(15)<<left<<carne[i]<<setw(20)<<right<<tipo[i]<<setw(40)<<right<<
                nombre[i]<<endl;
    }
}

int diasNoPermitidos(int datoFecha,int fecha,char tip,double &penalidad){
    if(tip=='A'){
        if(numeroDeDias(datoFecha,fecha)>3){
            penalidad=1.5;
            return 1;
        }
        else return 0;
    }
    if(tip=='D'){
        if(numeroDeDias(datoFecha,fecha)>15){
            penalidad=2.25;
            return 1;
        }
        else return 0;
    }
    if(tip=='E'){
        if(numeroDeDias(datoFecha,fecha)>7){
            penalidad=1;
            return 1;
        }
        else return 0;
    }
    cout<<"ERROR";
    exit(1);
}

int buscarCarne(int num,int *arreglo,int numDatos){
    for(int i=0;i<numDatos;i++){
        if(num==arreglo[i])return i;
    }
    return -1;
}

int buscarLibro(char *codigoBus,char **arreglo){
    for(int i=0;arreglo[i];i++){
        if(strcmp(codigoBus,arreglo[i])==0){
            return i;
        }
    }
    return -1;
}

//char **codigo,**titulo,*tipo,**nombre;
//    int *carne,*cantEnBibl;
//    double *precio;

int buscarCarne(int num,int *arreglo){
    for(int i=0;arreglo[i];i++){
        if(num==arreglo[i]){
            return i;
        }
    }
    return -1;
}



void imprimirReporte(char car,int *carneDeuda,int *cantDeuda,char **nombreDeuda,
                     double *montoDeuda,ofstream &arch){
    imprimirLineas(arch,'=');
    if(car=='E'){
        arch<<setw(50)<<right<<"ESTUDIANTES DEUDORES"<<endl;
    }else if(car=='D'){
        arch<<setw(50)<<right<<"DOCENTES DEUDORES"<<endl;
    }else{
        arch<<setw(50)<<right<<"ADMINISTRATIVOS DEUDORES"<<endl;
    }
    imprimirLineas(arch,'-');
    arch<<"No.    " <<setw(9)<<left<<"CARNE"<<setw(9)<<right<<"NOMBRE"
            <<setw(65)<<right<<"CANT. DE LIB. ADEUDADOS"<<setw(23)<<right<<
            "MONTO ADEUDADO"<<endl;
    for(int i=0;carneDeuda[i];i++){
        arch<<setw(2)<<right<<i+1<<")    "<<setw(12)<<left<<carneDeuda[i]<<
                setw(60)<<left<<nombreDeuda[i]<<setw(12)<<left<<cantDeuda[i]
                <<setw(18)<<right<<setprecision(2)<<fixed<<montoDeuda[i]<<endl;
    }
    
}

void abrirArchivo(char car,char **codigo,char **titulo,int *&cantEnBibl,
                  double *precio,int *carne,char *tipo,char **nombre,
                  double *&deudaPrecio,ofstream &reporte){
    ifstream arch("RegistroDePrestamos.csv",ios::in);
    if(!arch){
        cout<<"Error no se encontro el archivo RegistroDePrestamos.csv"<<endl;
        exit(1);
    }
    
    int *carneDeuda,auxCarne,dd,mm,aa,fechaFija=20210924,fechaVar;
    char **nombreDeuda,tipoAux,c,*codLibro;
    int *cantDeuda;
    double *montoDeuda,penalidad;
    char *bufferNombreDeuda[200]{};
    int buffCarneDeuda[200]{0},buffCantDeuda[200]{0},numDatos=0;
    double buffDeuda[200]{0};
    while(1){
        arch>>auxCarne>>tipoAux>>c;
        if(arch.eof())break;
        codLibro = leerCadena(arch);
        arch>>dd>>c>>mm>>c>>aa;
        fechaVar = dd + mm*100+ aa*10000;
        if(tipoAux==car){
            if(diasNoPermitidos(fechaFija,fechaVar,car,penalidad)){
                int posDeudor = buscarCarne(auxCarne,carne,numDatos);
                int posLibro = buscarLibro(codLibro,codigo);
                if(posDeudor!=-1){
                    buffCantDeuda[posDeudor]++;
                    buffDeuda[posDeudor]+=precio[posLibro]*penalidad/100;
                }else{
                    posDeudor = buscarCarne(auxCarne,carne);
                    buffCarneDeuda[numDatos]=auxCarne;
                    bufferNombreDeuda[numDatos]=nombre[posDeudor];
                    buffCantDeuda[numDatos]=1;
                    buffDeuda[numDatos]+=(precio[posLibro]*penalidad/100);
                    numDatos++;
                }
                deudaPrecio[posLibro]+=precio[posLibro]*penalidad/100;
                cantEnBibl[posLibro]--;
            }
        }
    }
    arch.clear();
    arch.close();
    carneDeuda = new int[numDatos+1];
    cantDeuda = new int[numDatos+1];
    nombreDeuda= new char*[numDatos+1];
    montoDeuda = new double[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        carneDeuda[i]=buffCarneDeuda[i];
        cantDeuda[i]=buffCantDeuda[i];
        nombreDeuda[i]=bufferNombreDeuda[i];
        montoDeuda[i]=buffDeuda[i];
    }
    carneDeuda[numDatos]=0;
    imprimirReporte(car,carneDeuda,cantDeuda,nombreDeuda,montoDeuda,reporte);
    delete carneDeuda;
    delete cantDeuda;
    delete nombreDeuda;
    delete montoDeuda;
}

void imprimirLibros(char **codigo,char **titulo,int *cantEnBibl,
                    double *precio,double *deudaXLibro,ofstream &arch){
    imprimirLineas(arch,'=');
    arch<<setw(50)<<right<<"STOCK DE LIBROS DE LA BIBLIOTECA"<<endl;
    imprimirLineas(arch,'-');
    arch.precision(2);
    arch<<fixed;
    for(int i=0;codigo[i];i++){
        arch<<i+1<<")     "<<setw(15)<<left<<codigo[i]<<
                setw(50)<<left<<titulo[i]<<setw(5)<<right<<cantEnBibl[i]<<
                setw(20)<<right<<setprecision(2)<<fixed<<precio[i]<<setw(18)
                <<right<<deudaXLibro[i]<<endl;
    }
}


void librosYUsuariosInhabilitados_Reporte(char **&codigo,char **&titulo,int *&cantEnBibl,
                                          double *&precio,int *&carne,char *&tipo,
                                          char **&nombre){
    int i;
    double *deudaXLibro;
    char car;
    for(i=0;codigo[i];i++);
    deudaXLibro = new double[i+1]{};
    i=0;
    ofstream reporte("ReporteFinal.txt",ios::out);
    while(1){
        if(i==0)car='E';
        else if(i==1)car='D';
        else if(i==2)car='A';
        else break;
        abrirArchivo(car,codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,deudaXLibro,
                reporte);
        i++;
    }
    
    imprimirLibros(codigo,titulo,cantEnBibl,precio,deudaXLibro,reporte);
    
}
