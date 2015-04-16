/*!
 * \brief
 * Definicje metod TabAsoc
 *
 * Plik zawiera fedinicje metod Tablicy Asocjacyjnej
 */

#include "../inc/TabAsoc.hh"

  const int TabAsoc::operator[] (const std::string klucz) const {
  return Pobierz(klucz);
}

const int TabAsoc::Daj (const std::string klucz) const {
  return Pobierz(klucz);
}

int &TabAsoc::operator[] (const std::string klucz) {
  return Dodaj(klucz);
}

void TabAsoc::Zwolnij() { 
  this -> ~TabHash();
}

void TabAsoc::WczytajDane(const char *nazwaPliku, const unsigned int n) {
  std::string nowy;
  std::fstream plik;
  OtworzPlikIn(nazwaPliku, plik);
  for(size_t i  = 0; i<n; ++i) {
    getline(plik, nowy);
    plik >> operator[](nowy);
  }   
}

void TabAsoc::Start(std::fstream &plik, const unsigned int k) {
  std::string nowy;
  for(size_t i  = 0; i<k; ++i) {
    getline(plik, nowy);
    plik >> operator[](nowy);
  }   	 
}
/*
void TabAsoc::Start(std::fstream &plik, const unsigned int k) {
  std::string klucz;
  for(size_t i = 0; i<k; i +=2 ) {


*/

