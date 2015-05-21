#ifndef GRAF_HH
#define GRAF_HH

#include "Krawedz.hh"

template < class typ >
class Graf {

  Lista< Wierzcholek<typ>* > ListaWierzcholkow;
  Lista< Krawedz<typ>* > ListaKrawedzi;
  Lista< Lista< Krawedz<typ>* > > ListaListSasiedztwa;

public:

  void DodajWierzcholek(typ wartosc) {
    Wierzcholek<typ> *nowy = new Wierzcholek<typ>;
    nowy -> dana = wartosc;
    ListaWierzcholkow.push(nowy, ListaWierzcholkow.size());
    // Przypisanie PozNaLiscieWierzcholkow;

  }

  void DodajKrawedz(Wierzcholek<typ> *v, Wierzcholek<typ> *w, int wartosc) {
    Krawedz<typ> *nowa = new Krawedz<typ>;
    nowa -> WierzcholekLewy = v;
    nowa -> WierzcholekPrawy = w;
    nowa -> waga = wartosc;
    // TO DO!!!!
  }
};


#endif
