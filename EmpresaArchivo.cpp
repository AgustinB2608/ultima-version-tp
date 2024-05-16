#include <iostream>
#include "EmpresaArchivo.h"
using namespace std;
#include<cstring>

EmpresaArchivo::EmpresaArchivo(){
    _Filename = "Empresas.dat";
}

EmpresaArchivo::EmpresaArchivo(string Filename){
     _Filename=Filename;
}


bool EmpresaArchivo::abrirA(string modo){
    _p = fopen(_Filename.c_str(), modo.c_str());
    if(_p==nullptr){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    else{return true;}
}
void EmpresaArchivo::cerrarA(){
    fclose(_p);

}

bool EmpresaArchivo::guardar(Empresa x){
    if(abrirA("ab")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    bool grabo = fwrite(&x,sizeof(Empresa),1,_p);
    cerrarA();
    return grabo;
}

int EmpresaArchivo::buscar(int numE){
    Empresa x;
    int pos=0;
     if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return -1;
    }
    while(fread(&x,sizeof(Empresa),1,_p)){
        if(x.getNumeroDeEmpresa()==numE){
            break;
        }
        pos++;
    }
    cerrarA();
    if(x.getNumeroDeEmpresa() == numE){
        return pos;
    }
    else{return -1;}

}
Empresa EmpresaArchivo::leer(int pos){
    Empresa x;
    if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        x.setNumeroDeEmpresa(-1);
        return x;
    }
    fseek(_p,sizeof (Empresa)*pos,0); /// SEEK_SET
    fread(&x,sizeof(Empresa),1,_p);
    cerrarA();
    return x;
}
int EmpresaArchivo::getCantidadRegistros(){
    if (abrirA("rb")==false){
            cout<<"No se pudo abrir el archivo correctamente"<<endl;
            return 0;
    }
    fseek(_p,0,2);
    int cantbyte = ftell(_p);
    int cantreg = cantbyte/sizeof(Empresa);

    cerrarA();
    return cantreg;

}

bool EmpresaArchivo::Modificar(Empresa x,int pos){
   bool guardo;
   if (abrirA("rb+")==false){
    cout<<"No se encontró el archivo"<<endl;
    return false;
   }
   fseek(_p,sizeof(Empresa)*pos,0);
   guardo = fwrite (&x,sizeof(Empresa),1,_p);
   cerrarA();
   return guardo;
 }
 /*bool EmpresaArchivo::eliminar(int numeroEmpresa){
    int indice;
    Empresa empresa;

    indice = buscar(numeroEmpresa);
    empresa = leer(indice);
    empresa.setEstado(0);

    return guardar(indice, empresa);       guardar es literalmente el modificar
}*/
 /*bool EmpresaArchivo::guardar(Empresa empresa){     ///otra version de modificar

    int grabo;

    if(abrir("ab") == false){
        return false;
    }

    grabo = fwrite(&empresa, sizeof (Empresa), 1, _pFile);

    cerrar();

    return grabo;
}*/


bool EmpresaArchivo::realizarCopia(string filename){
    FILE *pBak;
    Empresa x;

    pBak=fopen(filename.c_str(),"wb");
    if(pBak==nullptr){
        return false;
    }

    int cantreg = getCantidadRegistros();
    for(int i=0;i<cantreg;i++){
        x = leer(i);
        fwrite(&x,sizeof(Empresa),1,pBak);
    }
    fclose(pBak);
    return true;
}



bool EmpresaArchivo::restaurarCopia(string filename){
    Empresa x;
    EmpresaArchivo archibak(filename.c_str());

    if(!abrirA("wb")){
        return false;
    }

    int cantreg = archibak.getCantidadRegistros();


    for(int i=0;i<cantreg;i++){
        x = archibak.leer(i);
        fwrite(&x,sizeof(Empresa),1,_p);
    }
    cerrarA();
    return true;
}


