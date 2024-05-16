#pragma once
#include <string>
#include "Fecha.h"
class Empresa
{
   private:
    int _NumeroEmpresa;
    char _NombreEmpresa[30];
    int _CantidadEmpleados;
    int _Categoria;
    int _NumeroMunicipio;
    Fecha _FechaCreacion;
    float _FacturacionAnual;
    bool _Estado;
   public:
    Empresa();
    Empresa(int NumeroEmpresa, std::string NombreEmpresa, int CantidadEmpleados, int Categoria, int NumeroMunicipio, Fecha fecha, float facturacion, bool Estado);
    ///setters
    void setNumeroDeEmpresa(int NumeroEmpresa);
    void setNombreEmpresa(std::string NombreEmpresa);
    void setCantidadEmpleados(int CantidadEmpleados);
    void setCategoria(int Categoria);
    void setNumeroMunicipio(int NumeroMunicipio);
    void setFechaCreacion(Fecha fecha);
    void setEstado(bool Estado);
    void setFacturacionAnual(float facturacion);
    ///getters
    int getNumeroDeEmpresa();
    std::string getNombreDeEmpresa();
    int getCantidadEmpleados();
    int getCategoria();
    int getNumeroMunicipio();
    float getFacturacionAnual();
    Fecha getFechaCreacion();
    bool getEstado();

};
