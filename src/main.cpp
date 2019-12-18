#include <iostream>
#include "Monedero/Monedero.h"

int main() {
  Monedero cartera;
  double  cantidad;
  std::cout<<"Introduce la cantidad a calcular: ";
  std::cin>>cantidad;
  std::cout<<"Para "<<cantidad<<" se puede obtener con ";
  auto dinero = cartera.SuplirCantidad(cantidad);
  cartera.mostrarmonedas(dinero);
  std::cout << std::endl;
  return 0;
}
