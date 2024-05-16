#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ConfiguracionManager.h"


using namespace std;
void ConfiguracionManager::copiaEmpresas(){
    EmpresaManager empM;
    empM.copiaSeguridad();
}

void ConfiguracionManager::copiaMunicipios(){
    MunicipioManager munM;
    munM.copiaSeguridad();
}

void ConfiguracionManager::restaurarEmpresas(){
    EmpresaManager empM;
    empM.restaurarCopiaSeguridad();
}

void ConfiguracionManager::restaurarMunicipios(){
    MunicipioManager munM;
    munM.restaurarCopiaSeguridad();
}

void ConfiguracionManager::establecerDatos(){
    bool restcopia;
    MunicipioArchivo MunArchivo;
    EmpresaArchivo EmpArchivo;
    cout<<"¿Realmente quiere restaurar la copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>restcopia;
    if(restcopia){
        if(MunArchivo.restaurarCopia("Municipio.inic")){
            cout<<"La copia de seguridad se ha restaurado con exito"<<endl;
        }
        else cout<<"No se pudo restaurar la copia de seguridad"<<endl;
        if(EmpArchivo.restaurarCopia("Empresas.inic")){
            cout<<"La copia de seguridad se ha restaurado con exito"<<endl;
        }
        else cout<<"No se pudo restaurar la copia de seguridad"<<endl;
    }

    }




void ConfiguracionManager::Menu(){

    int op;
    bool t=true;
    while(t){
            system ("cls");
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"----------------- MENU CONFIGURACION ----------------"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"(1) - COPIA DE SEGURIDAD DEL ARCHIVO DE EMPRESAS "<<endl;
            cout<<"(2) - COPIA DE SEGURIDAD DEL ARCHIVO DE MUNICIPIOS "<<endl;
            cout<<"(3) - RESTAURAR EL ARCHIVO DE EMPRESAS"<<endl;
            cout<<"(4) - RESTAURAR EL ARCHIVO DE MUNICIPIOS"<<endl;
            cout<<"(5) - ESTABLECER DATOS DE INICIO"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"(0) - VOLVER AL MENU PRINCIPAL "<<endl;
            cout<<"-----------------------------------------------------"<<endl;

            cin>>op;

            system("cls");
            switch(op){

        case 1:
            copiaEmpresas();
            break;

        case 2:
            copiaMunicipios();
            break;

        case 3:
            restaurarEmpresas();
            break;

        case 4:
            restaurarMunicipios();
            break;

        case 5:
            establecerDatos();
            break;

        case 0:
            t=false;
            break;

        default:
            cout<<"Opcion elegida no valida."<<endl;
            break;

            }
            system("pause");
    }
}
