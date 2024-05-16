#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include "MunicipioArchivo.h"
MunicipioArchivo::MunicipioArchivo(){
    _Filename = "Municipio.dat";
}

MunicipioArchivo::MunicipioArchivo(string Filename){
     _Filename=Filename;
}


bool MunicipioArchivo::abrirA(string modo){
    _p = fopen(_Filename.c_str(), modo.c_str());
    if(_p==nullptr){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    else{return true;}
}
void MunicipioArchivo::cerrarA(){
    fclose(_p);

}

bool MunicipioArchivo::guardar(Municipio x){
    if(abrirA("ab")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return false;
    }
    bool grabo = fwrite(&x,sizeof(Municipio),1,_p);
    cerrarA();
    return grabo;
}

int MunicipioArchivo::buscar(int numE){
    Municipio x;
    int pos=0;
     if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        return -1;
    }
    while(fread(&x,sizeof(Municipio),1,_p)){
        if(x.getNumero()==numE){
            break;
        }
        pos++;
    }
    cerrarA();
    if(x.getNumero() == numE){
        return pos;
    }
    else{return -1;}

}
Municipio MunicipioArchivo::leer(int pos){
    Municipio x;
    if(abrirA("rb")==false){
        cout<<"No se pudo abrir el archivo correctamente"<<endl;
        x.setNumero(-1);
        return x;
    }
    fseek(_p,sizeof (Municipio)*pos,0); /// SEEK_SET
    fread(&x,sizeof(Municipio),1,_p);
    cerrarA();
    return x;
}
int MunicipioArchivo::getCantidadRegistros(){
    if (abrirA("rb")==false){
            cout<<"No se pudo abrir el archivo correctamente"<<endl;
            return 0;
    }
    fseek(_p,0,2);
    int cantbyte = ftell(_p);
    int cantreg = cantbyte/sizeof(Municipio);  // 100bytes/10bytes

    cerrarA();
    return cantreg;

}

bool MunicipioArchivo::Modificar(Municipio x,int pos){
   bool guardado;
   if (abrirA("rb+")==false){
    cout<<"No se encontró el archivo."<<endl;
    return false;
   }
   fseek(_p,sizeof(Municipio)*pos,0);
   guardado = fwrite (&x,sizeof(Municipio),1,_p);
   cerrarA();
   return guardado;
 }

bool MunicipioArchivo::realizarCopia(string filename){
    FILE *pBak;
    Municipio x;

    pBak=fopen(filename.c_str(),"wb");
    if(pBak==nullptr){
        return false;
    }

    int cantreg = getCantidadRegistros();
    for(int i=0;i<cantreg;i++){
        x = leer(i);
        fwrite(&x,sizeof(Municipio),1,pBak);
    }
    fclose(pBak);
    return true;
}

bool MunicipioArchivo::restaurarCopia(string filename){
    Municipio x;
    MunicipioArchivo archibak(filename.c_str());

    if(!abrirA("wb")){
        return false;
    }

    int cantreg = archibak.getCantidadRegistros();


    for(int i=0;i<cantreg;i++){
        x = archibak.leer(i);
        fwrite(&x,sizeof(Municipio),1,_p);
    }
    cerrarA();
    return true;
}


