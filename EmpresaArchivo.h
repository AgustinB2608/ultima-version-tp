#pragma once
#include "Empresa.h"
#include <string>

class EmpresaArchivo{
private:
    bool abrirA(std::string modo = "rb");
    void cerrarA();
    FILE *_p;
    std::string _Filename;
public:
    EmpresaArchivo();
    EmpresaArchivo(std::string Filename);
    bool guardar(Empresa x);
    int buscar(int numE);
    Empresa leer(int pos);
    int getCantidadRegistros();
    bool Modificar(Empresa x,int pos);
    bool realizarCopia(std::string filename = "Empresa.bak");
    bool restaurarCopia(std::string filename = "Empresa.bak");
};
