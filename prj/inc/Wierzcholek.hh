#ifndef WIERZCHOLEK_HH
#define WIERZCHOLEK_HH

#include "Lista.hh"

enum status {nieodwiedzony, odwiedzony, powrotny, poprzeczny };

template < class typ >
struct Krawedz;

template < class typ >
struct Wierzcholek {

  typ Dana;
  Lista< Krawedz<typ>* > ListaKrawedziV;
  status Label;

  ~Wierzcholek() {
      for(size_t i = 0; i < ListaKrawedziV.size(); ++i)
          delete ListaKrawedziV[i];
    ListaKrawedziV.Zwolnij();
  }

};


#endif
