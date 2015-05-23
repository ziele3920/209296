#ifndef KRAWEDZ_HH
#define KRAWEDZ_HH

#include "Wierzcholek.hh"


template < class typ >
struct Krawedz {

  Wierzcholek<typ> *WierzcholekLewy;
  Wierzcholek<typ> *WierzcholekPrawy;
  status Label;

Krawedz() {
    WierzcholekLewy = NULL;
    WierzcholekPrawy = NULL;
}


};


#endif
