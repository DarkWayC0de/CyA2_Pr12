//
// Created by darkwayc0de on 11/12/19.
//

#ifndef PR12_SRC_MONEDERO_MONEDERO_H_
#define PR12_SRC_MONEDERO_MONEDERO_H_

#include <vector>
#include <list>
#include "../UnidadMonetaria/UnidadMonetaria.h"

class Monedero {
 public:
  Monedero();
  ~Monedero() = default;
  std::list<std::pair<int,UnidadMonetaria>> SuplirCantidad(double cantidad);
  void mostrarmonedas(std::list<std::pair<int,UnidadMonetaria>> listaMoenedas);
 private:
  std::vector<UnidadMonetaria> unidesMonetarias;
  std::vector<std::pair<int,UnidadMonetaria>> monedero;
  int eurosacentimos(double euros);
};

#endif //PR12_SRC_MONEDERO_MONEDERO_H_
