#include <iostream>
#include <string>
#include <cstring>
#include "Empresa.h"
using namespace std;
   Empresa::Empresa() : _FechaCreacion(1, 1, 1900) {
    _NumeroEmpresa = 0;
    strcpy(_NombreEmpresa, "");
    _CantidadEmpleados = 0;
    _Categoria = 0;
    _NumeroMunicipio = 0;
    _Estado = false;
    _FacturacionAnual = 0;
}

Empresa::Empresa(int NumeroEmpresa, string NombreEmpresa, int CantidadEmpleados, int Categoria, int NumeroMunicipio,Fecha fecha, float facturacion, bool Estado) {
    setNumeroDeEmpresa(NumeroEmpresa);
    setNombreEmpresa(NombreEmpresa);
    setCantidadEmpleados(CantidadEmpleados);
    setCategoria(Categoria);
    setFacturacionAnual(facturacion);
    setNumeroMunicipio(NumeroMunicipio);
    setEstado(Estado);
    _FechaCreacion = fecha;
}

    int Empresa::getNumeroDeEmpresa() { return _NumeroEmpresa; }
    int Empresa::getCantidadEmpleados(){return _CantidadEmpleados;}
    int Empresa::getCategoria(){return _Categoria;}
    int Empresa::getNumeroMunicipio(){return _NumeroMunicipio;}
    string Empresa::getNombreDeEmpresa(){return _NombreEmpresa;}
    bool Empresa::getEstado(){return _Estado; }
    void Empresa::setFechaCreacion(Fecha fecha){
    _FechaCreacion = fecha;
    }
    float Empresa::getFacturacionAnual(){return _FacturacionAnual;}
    Fecha Empresa::getFechaCreacion(){return _FechaCreacion;}

    void Empresa::setNumeroDeEmpresa(int NumeroEmpresa){if(NumeroEmpresa>-1){_NumeroEmpresa = NumeroEmpresa;} }
    void Empresa::setNombreEmpresa(string NombreEmpresa) {
        if(NombreEmpresa.size()<=29 ){
        strcpy(_NombreEmpresa, NombreEmpresa.c_str()); }
    else{ cout<<"NOMBRE NO VALIDO"<<endl;}
    }
    void Empresa::setCantidadEmpleados(int CantidadEmpleados) { _CantidadEmpleados = CantidadEmpleados; }
    void Empresa::setCategoria(int Categoria) { if (Categoria>0&&Categoria<81)_Categoria = Categoria; }
    void Empresa::setNumeroMunicipio(int NumeroMunicipio) {if(NumeroMunicipio>0&&NumeroMunicipio<136){ _NumeroMunicipio = NumeroMunicipio;}
    else{_NumeroEmpresa = -1; } }
    void Empresa::setEstado(bool Estado) { _Estado = Estado; }
    void Empresa::setFacturacionAnual(float facturacion){_FacturacionAnual=facturacion;}

