#ifndef ITERABLE_HH
#define ITREABLE_HH

/*!
 * \brief
 * Interfejs Iterable
 *
 * Plik zawiera defincję interfejsu Iterable
 */

#include <iostream>

/*!
 * \brief
 * Interfejs Iterable
 *
 * Klasa modeluje pojęcie interfejsu Iterable, który umożliwia wgląd w kontener,
 * oraz udostępnia interferjsowi ISortable metodę umożliwiającą kolejkowanie
 * elementów.
 */
template < class typ>
class Iterable {
public:
    /*!
     * \brief operator []
     *
     * Przeciążenie opratora[] w celu umożliwienia przeglądania
     * zawrtości kontenera. Indeksujemy od 0.
     *
     * \param[in] indeks - indeks elementu, którego wartość ma zostać odczytana
     * \retval zwraca wartość znajdującą się na danym indeksie kontenera
     */
    virtual typ operator[] (unsigned int indeks) const  = 0;

    virtual void Zamien(int a, int b) = 0;

};

#endif

