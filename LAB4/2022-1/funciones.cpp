/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "funciones.h"
using namespace std;

char *leerCadena(ifstream &arch){
    char buffer[200],*cad;
    arch.getline(buffer,200,',');
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}

void formatearCategoria(char *nombre,char &categoria){
    int len = strlen(nombre);
    if(nombre[len-2]==' '){
        categoria = nombre[len-1];
        nombre[len-2]=0;
    }else{
        categoria ='-';
    }
}


void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    ifstream arch("Clientes.csv",ios::in);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo Clientes.csv"<<endl;
        exit(1);
    }
    int buffDNI[200],numDatos=0,telefono;
    char *buffNombre[200],buffCategoria[200],*nombre,categoria;
    int dni;
    while(1){
        arch>>dni;
        if(arch.eof())break;
        arch.get();
        nombre= leerCadena(arch);
        formatearCategoria(nombre,categoria);
        arch>>telefono;
        cout<<dni<<" "<<nombre<<" "<<categoria<<telefono<<endl;
        buffDNI[numDatos]=dni;
        buffNombre[numDatos]=nombre;
        buffCategoria[numDatos]=categoria;
        numDatos++;
    }
    cli_DNI = new int[numDatos+1];
    cli_Nombre = new char*[numDatos+1];
    cli_Categoria = new char[numDatos+1];
    
    for(int i=0;i<numDatos;i++){
        cli_DNI[i]=buffDNI[i];
        cli_Nombre[i]=buffNombre[i];
        cli_Categoria[i]=buffCategoria[i];
    }
    
    cli_DNI[numDatos]=0;
}

void imprimirLineas(ofstream &arch,char c){
    for(int i=0;i<100;i++)arch<<c;
    arch<<endl;
}

void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria){
    ofstream arch("ReporteDeClientes.txt",ios::out);
    if(!arch){
        cout<<"Error no se pudo abrir el archivo ReporteDeClientes.txt"<<endl;
        exit(1);
    }
    arch<<"Reporte de Clientes"<<endl;
    imprimirLineas(arch,'=');
    for(int i=0;cli_DNI[i];i++){
        arch<<setw(10)<<left<<cli_DNI[i]<<setw(50)<<right<<cli_Nombre[i]<<setw(20)<<right<<cli_Categoria[i]<<endl;
    }
}


int buscarCliente(int codigo,int *arreglo){
    for(int i=0;arreglo[i];i++){
        if(codigo==arreglo[i])return i;
    }
    return -1;
}

void leeValores(char *&cad,double &desc,double &cant,double &prec,int &DNI,
        int &fecha,ifstream &arch){
    int aa,dd,mm;
    char c;
    double aux;
    arch.get();
    cad=leerCadena(arch);
    arch>>cant;
    if(arch.fail()){
        arch.clear();
        arch.get();
        arch>>desc>>c>>cant;
    }
    arch>>c>>prec>>c>>DNI>>c>>dd>>c>>mm>>c>>aa;
    fecha=dd+mm*100+aa*10000;
}

int buscarDato(int *arr,int dato){
    for(int i=0;arr[i];i++)if(arr[i]==dato)return i;
    cout<<"Error, no se encontro el dato: "<<dato;
    exit(1);
}

int buscarDato(int *arr,int dato,int numDat){
    for(int i=0;i<numDat;i++)if(arr[i]==dato)return i;
    return -1;
}

void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
        char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
        int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido){
    ifstream arch("Pedidos.csv",ios::in);
    if(!arch){
        cout<<"ERROR EN PEDIDOS.CSV"<<endl;
        exit(1);
    }
    int buff_proCod[200],*buffCodProFecha[200],numDat=0,cod,DNI,fecha,pos1,pos2;
    double descuento[200],precio[200],*cantPed[200],desc,cant,prec;
    char *descripcion[200],*cad;
    int numPedidos[200]={},i;
    for(i=0;cli_DNI[i];i++){
        buffCodProFecha[i] =  new int [50];
        cantPed[i] = new double [25];
   }
    while(1){
        arch>>cod;
        if(arch.eof())break;
        leeValores(cad,desc,cant,prec,DNI,fecha,arch);
        pos1=buscarDato(cli_DNI,DNI);
        //agregar datos al cliente
        agregarDatosCliente(buffCodProFecha[pos1],cod,fecha,
                cantPed[pos1],cant,numPedidos[pos1]);
        pos2=buscarDato(buff_proCod,cod,numDat);
        if(pos2==-1){
            agregarProducto(buff_proCod[numDat],cod,descripcion[numDat],cad
                ,descuento[numDat],desc,precio[numDat],prec,numDat);
        }
    }
    copiarArreglosDinamicos(pro_Codigo,pro_Descripcion,pro_Descuento,pro_Precio,
        cli_CodigoProFechaPedido,cli_CantidadPedido,numDat,buff_proCod,
        descripcion,descuento,precio,cli_DNI,i,cantPed,buffCodProFecha,numPedidos);
    for(i=0;cli_DNI[i];i++){
        delete buffCodProFecha[i];
        delete cantPed[i];
   }
}


void copiarArreglosDinamicos(int *&pro_Codigo,char **&pro_Descripcion,
        double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido,
        double **&cli_CantidadPedido,int numDat,int *buff_proCod,char **descripcion,
        double *descuento,double *precio,int *cli_DNI,int i,double **cantPed,
        int **buffCodProFecha,int *numPedidos){
    
    pro_Codigo = new int [numDat+1];
    pro_Descripcion = new char *[numDat+1];
    pro_Descuento = new double [numDat+1];
    pro_Precio = new double [numDat+1];
    cli_CodigoProFechaPedido = new int *[i+1];
    cli_CantidadPedido = new double *[i+1];
    for(i=0;i<numDat;i++){
        pro_Codigo[i]=buff_proCod[i];
        pro_Descripcion[i]=descripcion[i];        
        pro_Descuento[i]=descuento[i];
        pro_Precio[i]=precio[i];
    }
    for(i=0;cli_DNI[i];i++){
        asignarValoresCliente(cli_CodigoProFechaPedido[i],buffCodProFecha[i],
                cli_CantidadPedido[i],cantPed[i],numPedidos[i]);
    }
    pro_Codigo[numDat]=0;
    pro_Descripcion[numDat]= nullptr;
    pro_Descuento[numDat]= 0;
    pro_Precio[numDat]= 0;
}

void asignarValoresCliente(int *&codProFecha,int *&buffCodProFecha,
            double *&cantPed, double  *&buffCantPed,int num){
    codProFecha = new int [2*num+2];
    cantPed = new double [num+1];
    for(int i=0;i<num;i++){
        codProFecha[2*i]=buffCodProFecha[2*i];
        codProFecha[(2*i)+1]=buffCodProFecha[(2*i)+1];
        cantPed[i]=buffCantPed[i];
    }
    codProFecha[2*num]=0;
    codProFecha[2*num+1]=0;
    cantPed[num]=0;

}

void agregarProducto(int &bufferCodigo,int auxCodigoProducto,char *&bufferDescripcion,
                     char *auxDescripcion,double &descuento,double desc,double &Precio,
                     double &pre,int &numDatos){
    bufferCodigo = auxCodigoProducto;
    bufferDescripcion= auxDescripcion;
    descuento = desc;
    Precio = pre;
    numDatos++;
}

int buscarDatos(int *arreglo,int num,int numDatos){
    for(int i=0;i<numDatos;i++){
        if(arreglo[i]==num){
            return i;
        }
    }
    return -1;
}

void agregarDatosCliente(int *&codProFecha,int codigo,int fecha,double *&cantidadPed,
                         double cant,int &numDatos){
    codProFecha[numDatos*2]=codigo;
    codProFecha[(numDatos*2)+1]=fecha;
    cantidadPed[numDatos]=cant;
    numDatos++;
}

void imprimePedidos(int *codFecha,double *cant,ofstream &archRep2){
    for(int i=0;codFecha[2*i];i++){
        archRep2<<setw(10)<<left<<codFecha[2*i]<<setw(10)<<left<<codFecha[2*i+1]
                <<setw(10)<<right<<setprecision(2)<<fixed<<cant[i]<<endl;
    }
}

void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,
        char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
        int **cli_CodigoProFechaPedido,double **cli_CantidadPedido){
    ofstream archRep1("ReporteProductos.txt",ios::out);
    ofstream archRep2("ReportePedidos.txt",ios::out);
    for(int i=0;pro_Codigo[i];i++){
        archRep1<<setw(10)<<left<<pro_Codigo[i]<<setw(40)<<left
                <<pro_Descripcion[i]<<setw(12)<<right<<setprecision(2)<<fixed
                <<pro_Descuento[i]<<setw(12)<<right<<pro_Precio[i]<<endl;
    }
    
    for(int i=0;cli_DNI[i];i++){
        archRep2<<setw(10)<<left<<cli_DNI[i]<<endl;
        imprimePedidos(cli_CodigoProFechaPedido[i],cli_CantidadPedido[i],archRep2);
    }
}