#include <iostream>
#include "EmpresaManager.h"
#include <string>
#include <cstring>
#include "Municipio.h"
#include "MunicipioArchivo.h"
using namespace std;

Empresa EmpresaManager::CrearEmpresa(){
    int NumeroEmpresa,NumeroMunicipio,Categoria,NumeroEmpleados ;
    bool Estado;
    Fecha fecha;
    float facturacionA;
    Municipio municipio;
    MunicipioArchivo muniarch;
    string Nombre;
   // do{
    cout << "Numero de empresa:" << endl;
    cin >> NumeroEmpresa;
    Empresa em = empArchivo.leer(empArchivo.buscar(NumeroEmpresa));
  //  if (empArchivo.buscar(NumeroEmpresa)!=-1 && em.getEstado()){
   //     cout<<"Numero de empresa ya existente"<<endl;
   // }

   // if(empArchivo.buscar(NumeroEmpresa)!=-1 && em.getEstado()==false){
     //   cout<<"La empresa ya existe y esta borrada con baja logica"<<endl;
   // }
   // } while(empArchivo.buscar(NumeroEmpresa)!=-1);

    cout << "Nombre de empresa: " << endl;
    cin.ignore();
    getline(cin,Nombre);
    do{
    cout << "Cantidad de empleados: " << endl;
    cin >> NumeroEmpleados;
    if (NumeroEmpleados<0){
        cout<<"Cantidad de empleados no valida"<<endl;
    }
    }while(NumeroEmpleados<0);
    do{
    cout << "Categoria: " << endl;
    cin >> Categoria;
    if (Categoria>81||Categoria<0){
        cout<<"Numero de categoria no valido"<<endl;
    }
    } while(Categoria>81||Categoria<0);
    do{
    cout << "Numero de municipio: " << endl;
    cin >> NumeroMunicipio;
    if (NumeroMunicipio>136||NumeroMunicipio<0){
        cout<<"Numero de municipio no valido"<<endl;
    }

    else if(muniarch.buscar(NumeroMunicipio)==-1){
        cout<<"No existe archivo de ese numero de municipio"<<endl;
    }
    } while(NumeroMunicipio>136||NumeroMunicipio<0||muniarch.buscar(NumeroMunicipio)==-1);
    cout<<"Fecha de creación"<<endl;
    fecha.CargarFecha();
    cout<<"Facturación anual: "<<endl;
    cin>>facturacionA;

    Estado = true;
    Empresa emp(NumeroEmpresa, Nombre, NumeroEmpleados, Categoria, NumeroMunicipio, fecha, facturacionA, Estado);
    return emp;
 }
void EmpresaManager::Mostrar(Empresa x){
  if ((x.getEstado())==true){
        Fecha fecha;
    cout << "Numero de empresa: " << x.getNumeroDeEmpresa() << endl;
    cout << "Nombre de empresa: " << x.getNombreDeEmpresa() << endl;
    cout << "Cantidad de empleados: " << x.getCantidadEmpleados() << endl;
    cout << "Categoria: " << x.getCategoria() << endl;
    cout << "Numero de municipio: " << x.getNumeroMunicipio() << endl;
    fecha = x.getFechaCreacion();
    cout << "Fecha de creacion: " <<endl;
    fecha.MostrarFecha();
    cout << "Facturacion anual: " <<x.getFacturacionAnual()<<endl;
    cout << "Disponibilidad: " << (x.getEstado() ? "Disponible":"No disponible") << endl;

    }


}

void EmpresaManager::CargarEmpresa(){
    Empresa x;
    x = CrearEmpresa();

    if(empArchivo.guardar(x)){
        cout<<"Empresa guardada con exito :D"<<endl;
    }
    else{cout<<"No pudo guardarse la empresa D:"<<endl;}
}

void EmpresaManager::buscarEmpresa(){
    int posiA,numE;
    Empresa x;
    cout<<"Ingrese el número de empresa a buscar: "<<endl;
    cin>>numE;
    posiA = empArchivo.buscar(numE);
    if(posiA>=0){
            x=empArchivo.leer(posiA);
            if (x.getEstado()==true){
            Mostrar(x);
        }
        else{ cout<<"La empresa está dada de baja"<<endl;} ;
    }
    else{ cout<<"La empresa no se encuentra"<<endl;}

}

void EmpresaManager::listarEmpresas(){
    Empresa x;
    int cantreg = empArchivo.getCantidadRegistros();

    for(int i=0;i<cantreg;i++){
        x = empArchivo.leer(i);
        cout<<"--------------------------------------------------"<<endl;
        Mostrar(x);
    }

}

void EmpresaManager::modificarEmpresa(){
    Empresa x;
    int ne, pos;
    Fecha fecha;
    cout<<"Ingrese un numero de empresa para modificar"<<endl;
    cin>>ne;

    pos = empArchivo.buscar(ne);
    if (pos >= 0) {
        Empresa x = empArchivo.leer(pos);
        if(x.getEstado()){
            cout<<"Ingrese la nueva fecha de creacion"<<endl;
            fecha.CargarFecha();
            x.setFechaCreacion(fecha);
            if(empArchivo.Modificar(x,pos)){
            cout<<"Se ha modificado correctamente"<<endl;
    }
            else  cout<<"No se puedo modificar la empresa"<<endl;
        }

        else  cout<<"La empresa esta dada de baja"<<endl;
    }
    else{cout<<"No se pudo modificar, la empresa no existe"<<endl;}

}

void EmpresaManager::bajalogicaEmpresa(){
    Empresa x;
    int ne, pos;
    cout<<"Ingrese numero de empresa a eliminar: "<<endl;
    cin>>ne;

    pos = empArchivo.buscar(ne);
    if (pos >= 0) {
        Empresa x = empArchivo.leer(pos);
        x.setEstado(false);
        if(empArchivo.Modificar(x,pos)){
            cout<<"Elimando correctamente."<<endl;
        }
        else  cout<<"No se ha eliminado la emmpresa."<<endl;
    }
    else{cout<<"No se pudo eliminar. La empresa no existe."<<endl;}

}
///La baja logica la hice sola como está arriba,pero despues vi como lo hizo brian y puse aca abajo como lo hizo el, si lo prefieren borren lo mio y dejen lo del profe

/*void EmpresaManager::eliminarEmpresas(){
    int numeroEmpresa, indice;

    cout << "Ingrese numero de empresa que quiere eliminar: ";
    cin >> numeroEmpresa;

    indice = empresaArchivo.buscar(numeroEmpresa);

    if(indice != -1){
        Empresa empresa = empresaArchivo.leer(indice);
        bool eliminar;

        mostrar(empresa);

        cout << "Esta seguro que quiere eliminar la empresa? 1-SI 0-NO: ";
        cin >> eliminar;

        if(eliminar){
            if(empresaArchivo.eliminar(numeroEmpresa)){
                cout << "La empresa se elimino correctamente!"<<endl;
            }
            else{
                cout << "La empresa no se pudo eliminar..." << endl;
            }
        }
        else{
            cout << "La empresa no se elimino. " << endl;
        }


    }
    else{
        cout << "La empresa no existe..." << endl;
    }

}
*/
void EmpresaManager::copiaSeguridad(){
    bool hacercopia;
    cout<<"¿Realmente quiere realizar una copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>hacercopia;
    if(hacercopia){
        if(empArchivo.realizarCopia()){
            cout<<"La copia de seguridad se ha realizado con exito"<<endl;
        }
        else cout<<"No se pudo realizar la copia de seguridad"<<endl;
    }
    else cout<<"No se ha realizado la copia"<<endl;
}

void EmpresaManager::restaurarCopiaSeguridad(){
    bool restcopia;
    cout<<"¿Realmente quiere restaurar la copia de seguridad? 1 - SI / 0 - NO"<<endl;
    cin>>restcopia;
    if(restcopia){
        if(empArchivo.restaurarCopia("Empresa.bak")){
            cout<<"La copia de seguridad se ha restaurado con exito"<<endl;
        }
        else cout<<"No se pudo restaurar la copia de seguridad"<<endl;
    }
    else cout<<"No se ha restaurado la copia"<<endl;

}

void EmpresaManager::Menu(){

    int op;
    bool t=true;
    while(t){
            system ("cls");
            cout<<"--------------------------------------------------"<<endl;
            cout<<"------------------- MENU EMPRESAS ----------------"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"(1) - CARGAR EMPRESA "<<endl;
            cout<<"(2) - LISTAR EMPRESA POR NUMERO"<<endl;
            cout<<"(3) - LISTAR TODAS LAS EMPRESAS"<<endl;
            cout<<"(4) - MODIFICAR FECHA DE CREACION"<<endl;
            cout<<"(5) - DAR DE BAJA EMPRESA"<<endl;
            cout<<"(6) - REALIZAR COPIA DE SEGURIDAD"<<endl;
            cout<<"(7) - RESTAURAR COPIA DE SEGURIDAD"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"(0) - SALIR "<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cin>>op;

            system("cls");
            switch(op){

        case 1:
            CargarEmpresa();
            break;

        case 2:
            buscarEmpresa();
            break;

        case 3:
            listarEmpresas();
            break;

        case 4:
            modificarEmpresa();
            break;

        case 5:
            bajalogicaEmpresa();
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
