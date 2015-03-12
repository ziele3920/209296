/*!
 * \file
 * \brief
 * Definicje metod klasy Tablica
 *
 * PLik zawiera definicje metod klasy Tablica
 */

#include "../inc/Tablica.hh"

void Tablica::WczytajDane(const char *nazwaPliku, const unsigned int n) {

  std::fstream plik;
  int wartosc;
  unsigned int i=0;

  OtworzPlikIn(nazwaPliku, plik);
  while (!plik.eof() && i!=(n-1)) {
    plik >> wartosc;
    if (plik.fail()) {
      std::cerr << "Blad, nieoczekiwana wartosc w pliku" << std::endl;
      exit(-3); 
    }
    WskT[i] = wartosc;
    i++;
  }
  plik.close();
  if(i < n) {
    std::cerr << "Blad, plik zawiera " << i << "wartosci a chcesz wczytac ich" << n << std::endl;
    exit(-4);
  }
}

void Tablica::Start(const unsigned int k) {
  for(unsigned int i=1; i<k; i++)
    WskT[i] = 2*WskT[i];
}

