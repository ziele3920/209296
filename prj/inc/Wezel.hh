#ifndef WEZEL_HH
#define WEZEL_HH

/*!
 * \brief
 * Klasa węzeł
 *
 * Plik zawiera definicję strukntury Węzeł.
 */

#include <iostream>


/*!
 * \brief
 * Struktura Węzeł
 *
 * Struktura modeluje pojęcie węzła - elementu drzewa, na który składa się
 * wartość, rodzic, lewy potomek i prawy potomek.
 */
template < class typ<>
struct Wezel {
  /*!
   * \brief Przechowywana wartość
   *
   * Pole przechowuje wartość elementu znajdującego się w danym węźle.
   */
  typ Wartosc;

  /*!
   * \brief Rodzic danego węzła.
   * 
   * Wskaźnik na rodzica danego węzła.
   */
  Wezel *Rodzic;

  /*!
   * \brief Lewy potomek
   * 
   * Wskaźnik na lewego potomka danego węzła.
   */
  Wezel *Lewy;

  /*!
   * \brief Prawy potomek
   * 
   * Wskaźnik na prawego potomnka danego węzła.
   */
  Wezel *Prawy;

 public:

  Wezel() {
    Rodzic = NULL;
    Lewy = NULL;
    Prawy = NULL;
  }

};
#endif 
