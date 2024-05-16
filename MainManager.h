#pragma once
#include "EmpresaManager.h"
#include "MunicipioManager.h"
#include "ConfiguracionManager.h"

class MainManager{
private:
    EmpresaManager empresaMan;
    MunicipioManager muniMan;
    ConfiguracionManager confMan;
    void GenerarReporte();
    void MostrarReporte();
public:
    void menu();

};
