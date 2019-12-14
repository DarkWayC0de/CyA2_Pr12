//
// Created by darkwayc0de on 11/12/19.
//

#include "UnidadMonetaria.h"
const std::pair<int, std::string> &UnidadMonetaria::getUnidad() const {
  return Unidad;
}
void UnidadMonetaria::setUnidad(const std::pair<int, std::string> &unidad) {
  Unidad = unidad;
}
UnidadMonetaria::UnidadMonetaria(int valor, const char simbolo[]) {
  std::pair<int,std::string> unidad(valor,simbolo);
  this->Unidad = unidad;
}
