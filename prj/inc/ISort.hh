#ifndef ISORT_HH
#define ISORT_HH

/*!
 * \brief
 * Interfejs ISort
 *
 * Plik zawiera defincję interfejsu ISortable
 */

#include "ListArr2x.hh"

/*!
 * \brief
 * Interfejs ISort
 *
 * Klasa modeluje pojęcie interfejsu ISort, który tworzy interfejs
 * użytkownika dla algorytmów sortujących.
 */
template < class typ >
class ISort {
public:
    /*!
   * \brief Sort
   *
   * Metoda wykonująca agorytm sortowania na kontenerze podanym w argumencie.
   *
   * \param[in] tab - referencja do sortowanego kontenera
   * \param[in] lewy - początkowy indeks sortowania
   * \param[in] prawy - końcowy indeks sortowania
   */
  virtual void Sort(const int lewy, const int prawy, Iterable<typ> &tab) = 0;
};

#endif
