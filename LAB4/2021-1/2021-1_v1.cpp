#include <iomanip>
#include <fstream>
#include <cstring>
#define MAXLINEAS 100
#include <iostream>
using namespace std;


char* leerCadenaSaltoLinea(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,'\n');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void cargarConductores(int *&licencia,char **&conductor){
    ifstream arch("Conductores.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo hallar el archivo Conductores.csv"<<endl;
        exit(1);
    }
    
    int buffLicencia[200],numDatos=0,numLicencia;
    char *bufferConductor[200],*nombre;
    
    while(1){
        arch>>numLicencia;
        if(arch.eof())break;
        arch.get();
        nombre = leerCadenaSaltoLinea(arch);
        buffLicencia[numDatos]=numLicencia;
        bufferConductor[numDatos]=nombre;
        numDatos++;
    }
    licencia = new int[numDatos+1];
    conductor = new char*[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        licencia[i]=buffLicencia[i];
        conductor[i]=bufferConductor[i];
    }
    licencia[numDatos]=0;
    conductor[numDatos]=NULL;
}

void imprimirLineas(ofstream &out,char c){
    for(int i=0;i<MAXLINEAS;i++){
        out<<c;
    }
    out<<endl;
}

void reporteConductores(int *licencia,char **conductor){
    ofstream arch("ReporteConductores.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el ReporteConductores.txt"<<endl;
        exit(1);
    }
    arch<<setw(40)<<"REPORTE DE CONDUCTORES"<<endl;
    imprimirLineas(arch,'=');
    arch<<setw(10)<<left<<"LICENCIA"<<setw(40)<<right<<"NOMBRE"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;licencia[i];i++){
        arch<<setw(10)<<left<<licencia[i]<<setw(40)<<right<<conductor[i]<<endl;
    }
}

int main(int argc, char** argv) {
    char **conductor,*gravedad;
    int *licencia, *infraccion;
    double *multa;
    cargarConductores(licencia, conductor);
    reporteConductores(licencia, conductor);
//    cargarInfracciones(infraccion, gravedad, multa);
//    reporteInfracciones(infraccion, gravedad, multa);
//    reporteDeFaltas(licencia, conductor, infraccion, gravedad, multa);
    return 0;
}


