#pragma once
#include <string>
class Municipio{
private:
    int _Numero;
    char _Nombre[30];
    int _Seccion;
    int _CantidadHabitantes;
    bool _Estado;
public:
    Municipio();
    Municipio(int Numero, std::string Nombre, int Seccion, int CantidadHabitantes, bool Estado);
    //setters
    void setNumero(int Numero);
    void setNombre(std::string Nombre);
    void setSeccion(int Seccion);
    void setCantidadHabitantes(int CantidadHabitantes);
    void setEstado(bool Estado);
    //getters
    int getNumero();
    std::string getNombre();
    int getSeccion();
    int getCantidadHabitantes();
    bool getEstado();
};

// Municipios.dat
// Número (1 a 135)
// Nombre
// Sección a la que pertenece (1 a 9)
// Cantidad de habitantes
// Estado (bool)

