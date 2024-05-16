#include <iostream>
#include "MainManager.h"
#include <string>
#include <cstring>
using namespace std;

/*

class Reporte1{
private:
    int _NumeroMunicipio;
    char _NombreMunicipio[30];
    int _CantidadEmpleados;
public:
    Reporte1(int NumeroMunicipio, std::string NombreMunicipio, int CantidadEmpleados);
    void Mostrar();///despues hacerlo donde corresponde, en el manager de reporte

};

Reporte1::Reporte1(int NumeroMunicipio =0, std::string NombreMunicipio ="", int CantidadEmpleados =0){
    _NumeroMunicipio = NumeroMunicipio;
    strcpy(_NombreMunicipio,NombreMunicipio.c_str());
    _CantidadEmpleados = CantidadEmpleados;
}

void Reporte1::Mostrar(){
    cout<<"Numero de municipio: "<<_NumeroMunicipio<<endl;
    cout<<"Nombre de municipio: "<<_NombreMunicipio<<endl;
    cout<<"Cantidad de empleados: "<<_CantidadEmpleados<<endl;
}



void MainManager::GenerarReporte(){  ///faltan validaciones
    MunicipioArchivo MunArchivo;
    Municipio municipio;
    int numMuni;

    EmpresaArchivo empArch;

    cout<<"Ingrese numero de municipio:"<<endl;
    cin>>numMuni;
    int pos = MunArchivo.buscar(numMuni); //va a devolcer la posicon en el archivo de ese numero de municipio
    municipio = MunArchivo.leer(pos); //va a devolver un municipio enviando su posicion en el archivo
    // muniMan.Mostrar(municipio); ///pa chequear que ande bien nomas
    // ahora necesito saber la cantidad de empleados que tiene ese municipio
    int CantidadEmpleados = 0;
    int CantidadEmpresas = empArch.getCantidadRegistros();

    for(int i=0;i<CantidadEmpresas;i++){
        Empresa emp = empArch.leer(i);
        if (emp.getNumeroMunicipio() == numMuni && emp.getEstado()==true){ //importante esa segunda validacion
            CantidadEmpleados = CantidadEmpleados + emp.getCantidadEmpleados(); ///IMPORTANTE, es += porque pueden haber varias empresas en ese municipio, entonces necesito acumular todos los empleados de todas las empresas del municipio
     }
    }
    ///generar el archivo numero de municipio, nombre de municipio y cantidad de empleados
    Reporte1 repo(numMuni,municipio.getNombre(),CantidadEmpleados);  ///lo que viene a continuacion se puede hacer de otra forma, no necesariamente asì

    FILE *p;
    p = fopen("Reporte1.dat","wb"); eberia actualizar, igualno entiendo porque si ahora quiero ingresar el reporte de el municipìo 2, el de municipio 1 se borrarà
    if(p==nullptr){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }
    fwrite(&repo,sizeof(Reporte1),1,p);
    fclose(p);
    cout<<"Reporte generado con éxito"<<endl;
}

void MainManager::MostrarReporte(){
    Reporte1 repo;
    FILE *p;
    p = fopen("Reporte1.dat","rb");
    if(p==nullptr){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }
    fread(&repo,sizeof(Reporte1),1,p);
    repo.Mostrar();
    fclose(p);


}

 */

void MainManager::menu(){

    int op;
    bool t=true;
    while(t){
            system ("cls");
            cout<<"--------- MENU PRINCIPAL --------"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"(1) - EMPRESAS "<<endl;
            cout<<"(2) - MUNICIPIOS"<<endl;
            cout<<"(3) - CONFIGURACION"<<endl;
            cout<<"(4) - REPORTES"<<endl;
          //  cout<<"5 - GENERAR ARCHIVO REPORTE #1"<<endl;
          //  cout<<"6 - MOSTRAR ARCHIVO REPORTE #1"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"(0) - SALIR "<<endl;
            cout<<"---------------------------------"<<endl;
            cin>>op;

            system("cls");
            switch(op){
            case 1:
                empresaMan.Menu();
                break;
            case 2:
                muniMan.Menu();
                break;
            case 3:
                confMan.Menu();
                break;
            case 6:
               // MostrarReporte();

                break;
            case 0:
                t=false;
                break;

            default:
                cout<<"Opción elegida no valida"<<endl;
                break;

            }
            system("pause");
    }

}
