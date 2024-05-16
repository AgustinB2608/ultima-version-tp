#include <iostream>
#include <cstring>
#include "Municipio.h"
Municipio::Municipio(){
_Numero = 0;
strcpy(_Nombre,"");
_Seccion = 0;
_CantidadHabitantes = 0;
_Estado = false;}
Municipio::Municipio(int Numero, std::string Nombre, int Seccion, int CantidadHabitantes, bool Estado){
_Numero = Numero;
strcpy(_Nombre, Nombre.c_str());
_Seccion = Seccion;
_CantidadHabitantes = CantidadHabitantes;
_Estado = Estado;
}
///setters
void Municipio::setNumero(int Numero){
if(Numero>0&&Numero<136){_Numero = Numero;}
}
void Municipio::setNombre(std::string Nombre){
if(Nombre.size()<30){strcpy(_Nombre, Nombre.c_str());}
}
void Municipio::setSeccion(int Seccion){
if(Seccion>0&&Seccion<10){_Seccion = Seccion;}
}
void Municipio::setCantidadHabitantes(int CantidadHabitantes){
if(CantidadHabitantes>-1){_CantidadHabitantes = CantidadHabitantes;}
}
void Municipio::setEstado(bool Estado){_Estado = Estado;}
///getters
int Municipio::getNumero(){return _Numero;}
std::string Municipio::getNombre(){return _Nombre;}
int Municipio::getSeccion(){return _Seccion;}
int Municipio::getCantidadHabitantes(){return _CantidadHabitantes;}
bool Municipio::getEstado(){return _Estado;}
