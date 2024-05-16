#include <iostream>
#include "MunicipioManager.h"
using namespace std;

Municipio MunicipioManager::CrearMunicipio(){
    int Numero,seccion,cantidadhabitantes;
    bool Estado;
    string Nombre;
    do{
    cout << "Numero de Municipio:" << endl;
    cin >> Numero;
    Municipio mu = MunArchivo.leer(MunArchivo.buscar(Numero));
    if (MunArchivo.buscar(Numero)!=-1 && mu.getEstado()==true){
        cout<<"Numero de empresa ya existente"<<endl;
    }
    if(MunArchivo.buscar(Numero)!=-1 && mu.getEstado()==false){
         cout<<"El municipio ya existe y esta borrada con baja logica"<<endl;
    }
    } while(MunArchivo.buscar(Numero)!=-1);
    cout << "Nombre del municipio: " << endl;
    cin.ignore();
    getline(cin,Nombre);
    do{
    cout << "Cantidad de habitantes: " << endl;
    cin >> cantidadhabitantes;
    if (cantidadhabitantes<0){
        cout<<"Cantidad de habitantes no valida"<<endl;
    }
    }while(cantidadhabitantes<0);
    do{
    cout << "Seccion: " << endl;
    cin >> seccion;
    if (seccion>81||seccion<0){
        cout<<"Numero de seccion no valido"<<endl;
    }
    } while(seccion>81||seccion<0);
    Estado = true;
    Municipio mun(Numero, Nombre, seccion, cantidadhabitantes, Estado);
    return mun;
}
void MunicipioManager::Mostrar(Municipio x){
  if ((x.getEstado())==true){
    cout << "Numero del municipio: " << x.getNumero() << endl;
    cout << "Nombre de empresa: " << x.getNombre() << endl;
    cout << "Cantidad de habitantes: " << x.getCantidadHabitantes() << endl;
    cout << "Seccion: " << x.getSeccion() << endl;
    cout << "Disponibilidad: " << (x.getEstado() ? "Disponible":"No disponible") << endl;

    }


}
void MunicipioManager::CargarMunicipio(){
    Municipio x;
    x = CrearMunicipio();

    if(MunArchivo.guardar(x)){
        cout<<"Muncipio guardado con exito :D"<<endl;
    }
    else{cout<<"No pudo guardarse el municipio D:"<<endl;}
}


void MunicipioManager::buscarMunicipio(){   ///mensaje no se encuentra cuando esta dada de baja
    int posiA,numE;
    Municipio x;
    cout<<"Ingrese el numero de municipio a buscar: "<<endl;
    cin>>numE;
    posiA = MunArchivo.buscar(numE);
    if(posiA>=0){
        x=MunArchivo.leer(posiA);
        if (x.getEstado()){
        Mostrar(x);
        }
        else{ cout<<"El municipio está dado de baja"<<endl;}

    }
    else{ cout<<"El municipio no se encuentra"<<endl;}

}

void MunicipioManager::listarMunicipios(){
    Municipio x;
    int cantreg = MunArchivo.getCantidadRegistros();
    //empArchivo.getCantidadRegistros();

    for(int i=0;i<cantreg;i++){
        x = MunArchivo.leer(i);
        cout<<"--------------------------------------------------"<<endl;
        Mostrar(x);
    }
}

void MunicipioManager::modificarMunicipio(){
    Municipio x;
    int numero, pos,cantH;
    cout<<"Ingrese numero de municipio a modificar: "<<endl;
    cin>>numero;

    pos = MunArchivo.buscar(numero);

    if (pos >= 0) {
        Municipio x = MunArchivo.leer(pos);

    cout<<"Ingrese la nueva cantidad de habitantes: "<<endl;
    cin>>cantH;
    x.setCantidadHabitantes(cantH);
    if(MunArchivo.Modificar(x,pos)){
            cout<<"Se ha modificado correctamente"<<endl;
        }
        else  cout<<"No se puedo modificar la empresa"<<endl;
    }
    else{cout<<"No se pudo modificar, la empresa no existe"<<endl;}

}

void MunicipioManager::bajaLogicaMunicipio(){
    Municipio x;
    int numero, pos;
    cout<<"Ingrese numero de municipio a eliminar: "<<endl;
    cin>>numero;

    pos = MunArchivo.buscar(numero);

    if (pos >= 0) {
        Municipio x = MunArchivo.leer(pos);
        x.setEstado(false);
        if(MunArchivo.Modificar(x,pos)){
            cout<<"Elimando correctamente."<<endl;
        }
        else  cout<<"No se ha eliminado el municipio."<<endl;
    }
    else{cout<<"No se pudo eliminar. El municipio no existe."<<endl;}

}

void MunicipioManager::copiaSeguridad(){
    bool hacercopia;
    cout<<"¿Realmente quiere realizar una copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>hacercopia;
    if(hacercopia){
        if(MunArchivo.realizarCopia()){ //cambiar
            cout<<"La copia de seguridad se ha realizado con exito"<<endl;
        }
        else cout<<"No se pudo realizar la copia de seguridad"<<endl;
    }
    else cout<<"No se ha realizado la copia"<<endl;
}

void MunicipioManager::restaurarCopiaSeguridad(){
    bool restcopia;
    cout<<"¿Realmente quiere restaurar la copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>restcopia;
    if(restcopia){
        if(MunArchivo.restaurarCopia("Municipio.bak")){
            cout<<"La copia de seguridad se ha restaurado con exito"<<endl;
        }
        else cout<<"No se pudo restaurar la copia de seguridad"<<endl;
    }
    else cout<<"No se ha restaurado la copia"<<endl;

}

void MunicipioManager::Menu(){

    int op;
    bool t=true;
    while(t){
            system ("cls");
            cout<<"---------------------------------------"<<endl;
            cout<<"------------ MENU MUNICIPIO -----------"<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"(1) - CARGAR MUNICIPIO "<<endl;
            cout<<"(2) - BUSCAR MUNICIPIO POR NUMERO"<<endl;
            cout<<"(3) - LISTAR MUNICIPIOS"<<endl;
            cout<<"(4) - MODIFICAR CANTIDAD DE HABITANTES"<<endl;
            cout<<"(5) - DAR DE BAJA MUNICIPIO"<<endl;
            cout<<"(6) - REALIZAR COPIA DE SEGURIDAD"<<endl;
            cout<<"(7) - RESTAURAR COPIA DE SEGURIDAD"<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<"(0) - SALIR "<<endl;
            cout<<"---------------------------------------"<<endl;

            cin>>op;

            system("cls");
            switch(op){

        case 1:
            CargarMunicipio();
            break;

        case 2:
            buscarMunicipio();
            break;

        case 3:
            listarMunicipios();
            break;

        case 4:
            modificarMunicipio();
            break;

        case 5:
            bajaLogicaMunicipio();
            break;

        case 6:
            copiaSeguridad();
            break;

        case 7:
            restaurarCopiaSeguridad();
            break;

        case 0:
            t=false;
            break;

        default:
            cout<<"Opcion elegida no valida"<<endl;
            break;

            }
            system("pause");
    }
}
