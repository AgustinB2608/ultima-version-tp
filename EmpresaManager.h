#pragma once
#include "Empresa.h"
#include "EmpresaArchivo.h"
#include "Fecha.h"

class EmpresaManager{
private:
    void CargarEmpresa();
    EmpresaArchivo empArchivo;
    void buscarEmpresa();
    void listarEmpresas();
    void modificarEmpresa();
    void bajalogicaEmpresa();


public:

    void copiaSeguridad();
    void restaurarCopiaSeguridad();

    Empresa CrearEmpresa();
    void Mostrar(Empresa x);
    void Menu();
};
