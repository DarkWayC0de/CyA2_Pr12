//
// Created by darkwayc0de on 11/12/19.
//

#include <iostream>
#include "Monedero.h"

Monedero::Monedero(): monedero(){
  UnidadMonetaria Uncentimo(1,"cent");
  this -> unidesMonetarias.push_back(Uncentimo);
  UnidadMonetaria Doscentimo(2,"cents");
  this -> unidesMonetarias.push_back(Doscentimo);
  UnidadMonetaria cincocentimo(5,"cents");
  this -> unidesMonetarias.push_back(cincocentimo);
  UnidadMonetaria diescentimo(10,"cents");
  this -> unidesMonetarias.push_back(diescentimo);
  UnidadMonetaria veintecentimo(20,"cents");
  this -> unidesMonetarias.push_back(veintecentimo);
  UnidadMonetaria Cincuentacentimo(50,"cents");
  this -> unidesMonetarias.push_back(Cincuentacentimo);
  UnidadMonetaria Uneuro(1,"euro");
  this -> unidesMonetarias.push_back(Uneuro);
  UnidadMonetaria Doseuros(2,"euros");
  this -> unidesMonetarias.push_back(Doseuros);
  UnidadMonetaria Cincoeuros(5,"euros");
  this -> unidesMonetarias.push_back(Doseuros);
  UnidadMonetaria Dieseuros(10,"euros");
  this -> unidesMonetarias.push_back(Doseuros);
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
