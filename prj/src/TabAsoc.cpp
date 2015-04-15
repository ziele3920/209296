/*!
 * \brief
 * Definicje metod TabAsoc
 *
 * Plik zawiera fedinicje metod Tablicy Asocjacyjnej
 */

#include "../inc/TabAsoc.hh"

  int TabAsoc::operator[] (const std::string klucz) const {
  return Pobierz(klucz);
}

int &TabAsoc::operator[] (const std::string klucz) {
  std::cout << "tadam" << std::endl;
  return Dodaj(klucz);
}
