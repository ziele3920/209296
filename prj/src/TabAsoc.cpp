/*!
 * \brief
 * Definicje metod TabAsoc
 *
 * Plik zawiera fedinicje metod Tablicy Asocjacyjnej
 */

#include "../inc/TabAsoc.hh"

const int TabAsoc::operator() (const std::string klucz) const {
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
  std::string wart;
  OtworzPlikIn(nazwaPliku, plik);

  for(size_t i  = 0; i<n; ++i) {
    getline(plik, nowy);
    getline(plik, wart);
    operator[](nowy)=atoi(wart.c_str());
  }   
  plik.close();
  }
/*
void TabAsoc::Start(std::fstream &plik, const unsigned int k) {
  std::string nowy, wart;
  for(size_t i  = 0; i<k; ++i) {
    getline(plik, nowy);
    getline(plik, nowy);
    getline(plik, wart);
    operator[](nowy)=atoi(wart.c_str());
  }   	 
  }*/

void TabAsoc::Start(std::fstream &plik, const unsigned int k) {
  std::string klucz;
  for(size_t i = 0; i<k; ++i) {
    getline(plik, klucz);
    operator()(klucz);
    getline(plik, klucz);
  }
}





