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
  const std::pair<double, std::string> &getUnidad() const;
  void setUnidad(const std::pair<double, std::string> &unidad);
  UnidadMonetaria(double valor, const char simbolo[]);
 private:
  std::pair<double,std::string> Unidad;
};

#endif //PR12_SRC_UNIDADMONETARIA_UNIDADMONETARIA_H_
