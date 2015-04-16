/*!
 * \brief
 * Definicja metod Tablicy Haszującej
 *
 * Plik zawiera definicję metod klasy TabHash
 */

#include "../inc/TabHash.hh"


TabHash::Para::Para(const int wart, const std::string key) {
  Klucz = key;
  Wartosc = wart;
}


TabHash::Para::Para(const int i) {
  Wartosc = i; Klucz = "";
}


TabHash::Para::Para() {
  Wartosc = -1; Klucz = "";
}


void TabHash::Para::operator= (const Para p) {
  Wartosc = p.Wartosc;
  Klucz = p.Klucz;
}


const int TabHash::DajZListy(const unsigned int pozycja, const std::string szukanyKlucz) const {
  unsigned int i = 0;
  while((i <= _Tab[pozycja] -> size()) && (szukanyKlucz != _Tab[pozycja] -> operator[](i).Klucz))
    ++i;

  if(szukanyKlucz == _Tab[pozycja] -> operator[](i).Klucz)
    return _Tab[pozycja] -> operator[](i).Wartosc;

  std::cerr << "Brak szukanego klucza w Tablicy" << std::endl;
  return -1;
}


unsigned int TabHash::H(const std::string klucz) const {

    unsigned int suma = 1;
    for(size_t i = 0; i < klucz.size(); ++i)
      suma *= (klucz.at(i)-(unsigned int)(96*0.4));
    return suma % ROZMIAR;
}


const int TabHash::Pobierz(const std::string szukanyKlucz) const {
  return DajZListy(H(szukanyKlucz), szukanyKlucz);
}


int &TabHash::Dodaj(const std::string nowyKlucz) {
  unsigned int pozycja = H(nowyKlucz);
  Para p(-1, nowyKlucz);
  _Tab[pozycja] -> push(p, _Tab[pozycja] -> size());
  return _Tab[pozycja] -> RefEnd().Wartosc;
}

TabHash::TabHash(){
  for(size_t i = 0; i<ROZMIAR; ++i)
    _Tab[i] = new ListArr2x<Para>;
}

TabHash::~TabHash() {
  for(size_t i = 0; i<ROZMIAR; ++i) 
    _Tab[i] -> Zwolnij();

}


