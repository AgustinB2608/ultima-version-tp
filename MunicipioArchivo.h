#pragma once
#include "Municipio.h"

class MunicipioArchivo{
private:
    bool abrirA(std::string modo = "rb");
    void cerrarA();
    FILE *_p;
    std::string _Filename;
public:
    MunicipioArchivo();
    MunicipioArchivo(std::string Filename);
    bool guardar(Municipio x);
    int buscar(int numE);
    Municipio leer(int pos);
    int getCantidadRegistros();
    bool Modificar(Municipio x,int pos);

    bool realizarCopia(std::string filename = "Municipio.bak");
    bool restaurarCopia(std::string filename = "Municipio.bak");

};
