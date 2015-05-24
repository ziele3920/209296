#ifndef WIERZCHOLEK_HH
#define WIERZCHOLEK_HH

/*!
 * \brief Definicja wierzcholka
 *
 * Plik zawiera definicję struktury Wierzchołek
 */

#include "Lista.hh"
#include "status.hh"


template < class typ >
struct Krawedz;

/*!
 * \brief Wierzcholek
 *
 * Struktura modeluje pojęcie wierzchołka grafu.
 */
template < class typ >
struct Wierzcholek {

    /*!
   * \brief Dana
   *
   * Wartość przechowywana przez wierzchołek.
   */
  typ Dana;

  /*!
   * \brief ListaKrawedziV
   *
   * Lista wskaźników na krawędzi odchodzące od wierzchołka.
   */
  Lista< Krawedz<typ>* > ListaKrawedziV;

  /*!
   * \brief Label
   *
   * Flaga wierzchołka niezbędna dla algorytmów przechodzenia przez graf.
   */
  status Label;

  /*!
   * \brief Destruktor
   *
   * Destrunktor wierzchołka usuwający krawędzie przyległe.
   */
  ~Wierzcholek() {
      for(size_t i = 0; i < ListaKrawedziV.size(); ++i)
          delete ListaKrawedziV[i];
    //ListaKrawedziV.Zwolnij();
  }

};


#endif
