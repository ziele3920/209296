#ifndef WIERZCHOLEK_HH
#define WIERZCHOLEK_HH

#include "Lista.hh"
#include "Krawedz.hh"

template < class typ >
struct Wierzcholek {

  typ Dana;
  Wierzcholek<typ> **PozNaLiscieWierzcholkow;
  // Lista< Krawedz<typ>* > ListaSasiedztwa;
  // NIE BANGLA!!!!!
  
};


#endif
