//
// Created by darkwayc0de on 11/12/19.
//

#include <iostream>
#include <fstream>
#include "Monedero.h"

Monedero::Monedero(): monedero(){
 std::ifstream readfile("../data/euros.data");
 if (readfile.is_open()) {
   char cantidad[5];
   char unidad[50];
   while (!readfile.eof()) {
     readfile >> cantidad >> unidad;
     UnidadMonetaria moneda(std::stoi(cantidad), unidad);
     this->unidesMonetarias.push_back(moneda);
   }
   readfile.close();
 } else {
   std::cout<<"Error en la carga de monedas\n";
   exit(1);
 }
}
std::list<std::pair<int, UnidadMonetaria>> Monedero::SuplirCantidad(double cantidad) {
  cantidad = eurosacentimos(cantidad);
  std::list<std::pair<int,UnidadMonetaria>> solucion;
  for (int i = this ->unidesMonetarias.size()-1 ; i >= 0 && cantidad > 0; --i) {
    int moneda = this->unidesMonetarias[i].getUnidad().first;
    if(this -> unidesMonetarias[i].getUnidad().second.find("euro")!=std::string::npos){
      moneda = eurosacentimos(moneda);
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
int Monedero::eurosacentimos(double euros){
  return (int)(euros*100);
}
void Monedero::mostrarmonedas(std::list<std::pair<int, UnidadMonetaria>> listaMoenedas) {
  for(auto i = listaMoenedas.begin(); i!= listaMoenedas.end(); ++i){
    std::cout<< i->first <<" euros de "<<i->second.getUnidad().first<<" "<<i->second.getUnidad().second<<" ";
  }
}
