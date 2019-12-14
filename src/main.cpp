#include <iostream>
#include "Monedero/Monedero.h"

int main() {
  Monedero cartera;
  auto dinero = cartera.SuplirCantidad(3.23);
  cartera.mostrarmonedas(dinero);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
