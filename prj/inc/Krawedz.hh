#ifndef KRAWEDZ_HH
#define KRAWEDZ_HH

#include "Wierzcholek.hh"


template < class typ >
struct Krawedz {

  int waga;
  Wierzcholek<typ> *WierzcholekLewy;
  Wierzcholek<typ> *WierzcholekPrawy;
  Krawedz<typ> **PozNaLiscieKrawedzi;
  Lista< Krawedz<typ>* > *PozNaLiscieSasiedztwa;


};


#endif
