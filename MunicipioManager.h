#pragma once
#include "Municipio.h"
#include "MunicipioArchivo.h"

class MunicipioManager{
private:
    MunicipioArchivo MunArchivo;
    void CargarMunicipio();
    void listarMunicipios();
    void bajaLogicaMunicipio();
    void modificarMunicipio();

public:

    void copiaSeguridad();
    void restaurarCopiaSeguridad();

    void Menu();
    void buscarMunicipio();
    void Mostrar(Municipio x);
    Municipio CrearMunicipio();

    void Municipios3em();

};
