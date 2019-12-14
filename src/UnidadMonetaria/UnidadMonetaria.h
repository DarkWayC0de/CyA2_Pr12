//
// Created by darkwayc0de on 11/12/19.
//

#ifndef PR12_SRC_UNIDADMONETARIA_UNIDADMONETARIA_H_
#define PR12_SRC_UNIDADMONETARIA_UNIDADMONETARIA_H_

#include <string>
#include <utility>
class UnidadMonetaria {
 public:
  UnidadMonetaria() = default;
  ~UnidadMonetaria()= default;
  const std::pair<int, std::string> &getUnidad() const;
  void setUnidad(const std::pair<int, std::string> &unidad);
  UnidadMonetaria(int valor, const char simbolo[]);
 private:
  std::pair<int,std::string> Unidad;
};

#endif //PR12_SRC_UNIDADMONETARIA_UNIDADMONETARIA_H_
