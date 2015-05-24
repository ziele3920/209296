#ifndef KRAWEDZ_HH
#define KRAWEDZ_HH

/*!
 * \brief Krawedz
 *
 * Plik zawiera definicję struktury Krawedz
 */

#include "Wierzcholek.hh"

/*!
 * \brief Krawedz
 *
 * Struktura modeluje pojęcie krawędzi wierzchołka.
 */
template < class typ >
struct Krawedz {

    /*!
   * \brief WierzcholekLewy
   *
   * Wskaźnik na jeden z wierzchołków przyległych do krawędzi.
   */
  Wierzcholek<typ> *WierzcholekLewy;

  /*!
   * \brief WierzcholekPrawy
   *
   * Wskaźnik na drugi z wierzchołków przyległych do krawędzi.
   */
  Wierzcholek<typ> *WierzcholekPrawy;

  /*!
   * \brief Label
   *
   * Flaga krawędzi niezbędna dla algorytmów przechodzenia przez graf.
   */
  status Label;

  /*!
 * \brief Krawedz
 *
 * Konstruktor ustwiający wskaźniki na wierzchołki na wartość NULL.
 */
Krawedz() {
    WierzcholekLewy = NULL;
    WierzcholekPrawy = NULL;
}


};


#endif
