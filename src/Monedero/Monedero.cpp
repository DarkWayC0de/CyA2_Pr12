//
// Created by darkwayc0de on 11/12/19.
//

#include <iostream>
#include <fstream>
#include "Monedero.h"



Monedero::Monedero(){
 const char NOMBRE_ARCHIVO[30] = "../data/euro.data";
 std::ifstream readfile(NOMBRE_ARCHIVO);
 if (readfile.is_open()) {
   char cantidad[5];
   char unidad[50];
   while (!readfile.eof()) {
     readfile >> cantidad >> unidad;
     UnidadMonetaria moneda(std::stod(cantidad), unidad);
     this->unidesMonetarias.push_back(moneda);
   }
   readfile.close();
 } else {
   std::cout<<"Error en la carga de monedas\n";
   exit(1);
 }
}
std::list<std::pair<double, UnidadMonetaria>> Monedero::SuplirCantidad(double cantidad) {
  const char UNIDAD[30] = "euro";
  cantidad = unidadasubunidad(cantidad);
  double cantidad2 = cantidad - (int)cantidad;
  if(cantidad2 >= 0.5){
   cantidad =cantidad+1 -cantidad2;
  }
  std::list<std::pair<double,UnidadMonetaria>> solucion;
  for (int i = this ->unidesMonetarias.size()-1 ; i >= 0 && cantidad > 0; --i) {
    double moneda = this->unidesMonetarias[i].getUnidad().first;
    if(this -> unidesMonetarias[i].getUnidad().second.find(UNIDAD)!=std::string::npos){
      moneda = unidadasubunidad(moneda);
    }
    if (cantidad / moneda >= 1){
      std::pair<int,UnidadMonetaria> pareja;
      pareja.first = (int)(cantidad / moneda);
      pareja.second = this-> unidesMonetarias[i];
      cantidad -= pareja.first * moneda;
      solucion.push_back(pareja);
    }
  }
  return solucion;
}
double Monedero::unidadasubunidad(double unidades){
  return (double)(unidades*100);
}
void Monedero::mostrarmonedas(std::list<std::pair<double, UnidadMonetaria>> listaMoenedas) {
  for(auto i = listaMoenedas.begin(); i!= listaMoenedas.end(); ++i){
    std::cout<< i->first <<" de "<<i->second.getUnidad().first<<" "<<i->second.getUnidad().second<<" ";
  }
}
