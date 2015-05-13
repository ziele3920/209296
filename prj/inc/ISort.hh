/*!
 * \brief
 * Interfejs ISort
 *
 * Plik zawiera defincję interfejsu ISortable
 */

#include <iostream>
#include "Iterable.hh"

/*!
 * \brief
 * Interfejs ISort
 *
 * Klasa modeluje pojęcie interfejsu ISort, który tworzy interfejs
 * użytkownika dla algorytmów sortujących.
 */
class ISort {
public:
    /*!
   * \brief Sort
   *
   * Metoda wykonująca agorytm sortowania na kontenerze podanym w argumencie.
   *
   * \param[in] kontener - wskaźnik na kontener do posrowania.
   */
  virtual void Sort(Iterable *kontener) = 0;
};
