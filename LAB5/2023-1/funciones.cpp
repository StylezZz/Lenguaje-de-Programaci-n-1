/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "funciones.h"
#define INCREMENTO 5
using namespace std;

void lecturaAlumnos(const char *nombreArch,int *&alumno_Codigo,
        char **&alumno_Nombre,char *&alumno_Modalidad,int *&alumno_Porcentaje
            ,int *&alumno_Escala,char ***&alumno_cursos){
    
    
    ifstream arch(nombreArch,ios::in);
    if(not arch.is_open()){
        cout<<"no se pudo abrir el archivo de alumnos";
        exit(1);
              
    }
    int cap=0,numDat=0;
    alumno_Codigo = nullptr;
    alumno_Nombre = nullptr;
    alumno_Modalidad = nullptr;
    alumno_Porcentaje = nullptr;
    alumno_Escala = nullptr;
    alumno_cursos = nullptr;
    int codAlu,escala,porcentaje;
    char *nomb,modalidad;
    while(true){
        arch>>codAlu;
        if(arch.eof())break;
        arch.get();
        nomb=leerCadena(arch);
        arch>>escala;
        if(arch.fail()){
            arch.clear();
            arch>>modalidad;
            if(modalidad=='S'){
                arch.get();
                arch>>porcentaje;
            }else{
                porcentaje=100;
            }
            
                  
            arch.get();
            arch>>escala;
        }else{
            modalidad='P';
            porcentaje=100;
        }
        
        if(numDat==cap){
            aumentarEspacios(alumno_Codigo,alumno_Nombre,alumno_Modalidad,
                    alumno_Porcentaje,alumno_Escala,alumno_cursos,numDat,cap);
        }
        guardarAlu(alumno_Codigo,alumno_Nombre,alumno_Modalidad,
                    alumno_Porcentaje,alumno_Escala,alumno_cursos,numDat,codAlu,
                nomb,modalidad,porcentaje,escala);

        
        //cout<<codAlu<<" "<<nomb<<" "<<modalidad<<" "<<porcentaje<<" "<<escala<<endl;
    }
     
    
}
void aumentarEspacios(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                   int *&alumno_Porcentaje,int *&alumno_Escala,
        char ***&alumno_cursos,int &numDat,int &cap){
    int *auxCod,*auxPorc,*auxEsc;
    char **auxNomb,*auxModal, ***auxAluCursos = nullptr;
    
   
    cap += INCREMENTO;
    if(alumno_Codigo==nullptr){
        InicializarIncre(alumno_Codigo,alumno_Nombre,alumno_Modalidad,
                    alumno_Porcentaje,alumno_Escala,alumno_cursos,cap);
        numDat=1;
    }else{
        auxCod = new int[cap]{};
        auxNomb = new char*[cap]{};
        auxModal = new char[cap]{};
        auxPorc = new int[cap]{};
        auxEsc = new int [cap]{};
        auxAluCursos = new char **[cap]{};
        
        for(int i=0;i<numDat;i++){
            auxCod[i] = alumno_Codigo[i];
            auxNomb[i] = alumno_Nombre[i];
            auxModal[i] = alumno_Modalidad[i];
            auxPorc[i] = alumno_Porcentaje[i];
            auxEsc[i] = alumno_Escala[i];
            auxAluCursos[i] = alumno_cursos[i];
        }
        delete alumno_Codigo;
        delete alumno_Nombre;
        delete alumno_Modalidad;
        delete alumno_Porcentaje;
        delete alumno_Escala;
        delete alumno_cursos;
        
        alumno_Codigo = auxCod;
        alumno_Nombre = auxNomb;
        alumno_Modalidad = auxModal;
        alumno_Porcentaje = auxPorc;
        alumno_Escala = auxEsc;
        alumno_cursos = auxAluCursos;
    }
}
void InicializarIncre(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                   int *&alumno_Porcentaje,int *&alumno_Escala,char ***&alumno_cursos,int cap){
    
    alumno_Codigo = new int[cap]{};
    alumno_Nombre = new char*[cap]{};
    alumno_Modalidad = new char[cap]{};
    alumno_Porcentaje = new int[cap]{};
    alumno_Escala = new int [cap]{};
    alumno_cursos = new char**[cap]{};
            
            
    alumno_Codigo[0]=0;
    alumno_Nombre[0]=nullptr;
    alumno_Modalidad[0]='0';
    alumno_Porcentaje[0]=0;
    alumno_Escala[0]=0;
    alumno_cursos[0]= nullptr;
}

char *leerCadena(ifstream &arch){
    char buff[200],*cad;
    arch.getline(buff,200,',');
    
    cad = new char[strlen(buff)+1];
    strcpy(cad,buff);
    return cad;
}

void guardarAlu(int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                   int *&alumno_Porcentaje,int *&alumno_Escala,char ***&alumno_cursos,int &numDat,
                int codAlu,char *nomb,char modalidad,int porcentaje,int escala){
    
    alumno_Codigo[numDat]=0;
    alumno_Codigo[numDat-1]=codAlu;
    alumno_Nombre[numDat]=nullptr;
    alumno_Nombre[numDat-1]=nomb;
        
        
    alumno_Modalidad[numDat]='0';
    alumno_Modalidad[numDat-1]=modalidad;
    alumno_Porcentaje[numDat]=0;
    alumno_Porcentaje[numDat-1]=porcentaje;
    alumno_Escala[numDat]=0;
    alumno_Escala[numDat-1]=escala;
    alumno_cursos[numDat]=nullptr;
    //alumno_cursos[numDat-1]=nullptr;
    numDat++;
}

void pruebaLecturaAlumnos(const char *nombreArch,int *alumno_Codigo,
        char **alumno_Nombre,char *alumno_Modalidad,int *alumno_Porcentaje
            ,int *alumno_Escala,char ***alumno_cursos){
    ofstream arch(nombreArch,ios::out);
    if(not arch.is_open()){
        cout<<"no se pudo abrir el archivo de Repalumnos";
        exit(1);
              
    }
    
    for(int i=0;alumno_Codigo[i];i++){
       
        arch<<left<<setw(10)<<alumno_Codigo[i]<<setw(35)<<alumno_Nombre[i]<<
                setw(10)<<alumno_Modalidad[i]<<setw(5)<<alumno_Porcentaje[i]<<
                setw(10)<<alumno_Escala[i]<<endl;
        
        if(alumno_cursos[i]==nullptr){
            arch<<"NO TIENE CURSOS DE MOMENTO"<<endl<<endl;
        }else{
            for(int j=0;alumno_cursos[i][j]!=nullptr;j++){
            
            
            }
        }
        
    }
    
    
}


void lecturaCursos(const char *nombreArch,int *alumno_Codigo,int *alumno_Escala,
        char **&curso_Nombre,double *&curso_Creditos,int ***&curso_Alumnos,char ***&alumno_cursos){
    
    ifstream arch(nombreArch,ios::in);
    if(not arch.is_open()){
        cout<<"no se pudo abrir el archivo de Cursos-alumnos";
        exit(1);
              
    }
    int cod,escalaAlu,posAlu,posCurso;
    char *nomb;
    double cred;
   
    curso_Nombre =  nullptr;
    curso_Creditos =  nullptr;
    curso_Alumnos =  nullptr;
    int cap=0,numDatCur=0,capAlu=0, *arrCantAlu,*arrCapAlu,curRepFlag,*Alumno;
    int *capCursoXalumno, *numCursosXAlumno,cantAlu;
    arrCapAlu = nullptr;
    arrCantAlu = nullptr;
    capCursoXalumno = nullptr;
    numCursosXAlumno = nullptr;
    cantAlu = obtenerCantAlumnos(alumno_Codigo);
    
    capCursoXalumno = new int[cantAlu]{};
    numCursosXAlumno = new int[cantAlu]{};
    cout<<cantAlu<<endl;
    int num=1,aux=1;
    while(1){
        
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        nomb = leerCadena(arch);
        arch>>cred;
//        cout<<"Antes de numDatCur==cap"<<endl;
        if(numDatCur==cap){
            cout<<"Aumentar: "<<num<<endl;
            aumentarEspaciosCursos(curso_Nombre,curso_Creditos
                    ,curso_Alumnos,arrCantAlu,arrCapAlu,numDatCur,cap);      
            num++;
        }
        curRepFlag = verificarCursoRepetido(curso_Nombre,nomb,numDatCur);
        posAlu = buscarAlumno(alumno_Codigo,cod);
        escalaAlu = alumno_Escala[posAlu];
        Alumno = new int[2]{};
        Alumno[0] = cod;
        Alumno[1] = escalaAlu;
        
        if(curRepFlag == -1){
            curso_Nombre[numDatCur]=nullptr;
            curso_Nombre[numDatCur-1]=nomb;
            curso_Creditos[numDatCur]=0;
            curso_Creditos[numDatCur-1]=cred;
            numDatCur++;
        }
        posCurso = buscarCurso(curso_Nombre,nomb,numDatCur);
        llenarCursoAlumno(curso_Alumnos[posCurso],arrCantAlu[posCurso],arrCapAlu[posCurso],Alumno,posCurso);
        if(capCursoXalumno[posAlu] == numCursosXAlumno[posAlu]){
            cout<<"Aux: "<<aux<<endl;
            aumentarEspaciosALUMNOXCURSO(alumno_cursos[posAlu],
                    capCursoXalumno[posAlu],numCursosXAlumno[posAlu]);
            aux++;
        }
        alumno_cursos[posAlu][numCursosXAlumno[posAlu]]=nullptr;
        alumno_cursos[posAlu][numCursosXAlumno[posAlu]-1]=nomb;
        
        numCursosXAlumno[posAlu]++;
        
        //llenarALUMNOCURSOS(alumno_cursos[posAlu],nomb,capCursoXalumno[posAlu],numCursosXAlumno[posAlu]);
    }

//    
    for(int i=0;curso_Nombre[i]!=nullptr;i++){
        cout<<curso_Nombre[i]<<" "<<curso_Creditos[i]<<endl;
        for(int j=0;j<arrCantAlu[i]-1;j++){
            cout<<curso_Alumnos[i][j][0]<<" "<<curso_Alumnos[i][j][1]<<endl;
        }
    }
    for(int i=0;alumno_Codigo[i];i++){
       
        cout<<left<<setw(10)<<alumno_Codigo[i]<<endl;
        if(alumno_cursos[i]!= nullptr){
            for(int j=0;alumno_cursos[i][j]!= nullptr;j++){
                cout<<alumno_cursos[i][j]<<"/";
            }
            cout<<endl; 
        }

//        if(alumno_cursos[i]==nullptr){
//            arch<<"NO TIENE CURSOS DE MOMENTO"<<endl<<endl;
//        }else{
//            for(int j=0;alumno_cursos[i][j]!=nullptr;j++){
//            
//            
//            }
//        }
        
    }
}

int obtenerCantAlumnos(int *alumno_Codigo){
    int cont=0;
    for(int i=0;alumno_Codigo[i];i++){
        cont++;
    }
    return cont;
}

int verificarCursoRepetido(char **curso_Nombre,char *nomb,int numDat){
    
    for(int i=0;i<numDat-1;i++){
        if(strcmp(curso_Nombre[i],nomb)==0)return 0;
        
        
    }
    return -1;
}

int buscarCurso(char **curso_Nombre,char *nomb,int numDat){
    
    for(int i=0;i<numDat-1;i++){
        if(strcmp(curso_Nombre[i],nomb)==0)return i;
        
        
    }
    return -1;
}


void aumentarEspaciosCursos(char **&curso_Nombre,double *&curso_Creditos
                    ,int ***&curso_Alumnos,int *&arrCantAlu,int *&arrCapAlu,int &numDat,int &cap){
    
    cap += INCREMENTO;
    char **auxCuNomb;
    double *auxcursoCred;
    int ***auxcursoAlu,*auxCantAlu,*auxcapAlu;
    if(curso_Nombre==nullptr){
        curso_Nombre = new char *[cap]{};
        curso_Creditos = new double[cap]{};
        curso_Alumnos = new int**[cap]{};
        arrCantAlu = new int[cap]{};
        arrCapAlu = new int[cap]{};
        
        curso_Nombre[0]=nullptr;
        curso_Creditos[0]=0;
        curso_Alumnos[0]=nullptr;
        arrCantAlu[0]=0;
        arrCapAlu[0]=0;
        numDat=1;
    }else{
        
        auxCuNomb = new char*[cap]{};
        auxcursoCred = new double[cap]{};
        auxcursoAlu = new int**[cap]{};
        auxCantAlu = new int[cap]{};
        auxcapAlu = new int[cap]{};
        for(int i=0;i<numDat;i++){
            auxCuNomb[i] = curso_Nombre[i];
            auxcursoCred[i] = curso_Creditos[i];
            auxcursoAlu[i] = curso_Alumnos[i];
            auxCantAlu[i] = arrCantAlu[i];
            auxcapAlu[i] = arrCapAlu[i];
        }
        delete curso_Nombre;
        delete curso_Creditos;
        delete curso_Alumnos;
        delete arrCantAlu;
        delete arrCapAlu;
        curso_Nombre = auxCuNomb;
        curso_Creditos = auxcursoCred;
        curso_Alumnos = auxcursoAlu;
        arrCantAlu = auxCantAlu;
        arrCapAlu = auxcapAlu;
    }
    
    
    
}

int buscarAlumno(int *alumno_Codigo,int cod){
    for(int i=0;alumno_Codigo[i]!=0;i++){
        if(alumno_Codigo[i]==cod)return i;
    }
    return -1;
}


void llenarCursoAlumno(int **&CursoAlu,int &cantAlu,int &capAlu,int *Alumno,int posCurso){
    
    if(cantAlu == capAlu){
        aumentarEspaciosCursosAlumno(CursoAlu,cantAlu,capAlu);
                    
        
    }
    CursoAlu[cantAlu]=nullptr;
    CursoAlu[cantAlu-1]=Alumno;
    cantAlu++;
         
}



void aumentarEspaciosCursosAlumno(int **&CursoAlu,int &cantAlu,int &capAlu){
    
    capAlu += INCREMENTO;
    int **auxAlumnos;
    if(CursoAlu==nullptr){
        CursoAlu = new int *[capAlu]{};

        
        CursoAlu[0]=nullptr;

    }else{
        auxAlumnos = new int *[capAlu]{};
        for(int i=0;i<cantAlu;i++){
            auxAlumnos[i] = CursoAlu[i];
        }
        delete CursoAlu;
        CursoAlu = auxAlumnos;

    }
    
}

void aumentarEspaciosALUMNOXCURSO(char **&aluCurso,
                   int &cap,int &cantidad){
    
    cap += INCREMENTO;

    char **auxAlumnoCurso;
    if(aluCurso==nullptr){
        aluCurso = new char *[cap]{};

        
        aluCurso[0]=nullptr;
        cantidad=1;
    }else{
        auxAlumnoCurso = new char *[cap]{};
        for(int i=0;i<cantidad;i++){
            auxAlumnoCurso[i] = aluCurso[i];
        }
        delete aluCurso;
        aluCurso = auxAlumnoCurso;

    }
    
}

void llenarALUMNOCURSOS(char **&alumnoCurso,char *nomb,int &capaluCurso,int &numCursoAlu){
    
    alumnoCurso[numCursoAlu]=nullptr;
    alumnoCurso[numCursoAlu-1]=nomb;
    numCursoAlu++;
    
}

