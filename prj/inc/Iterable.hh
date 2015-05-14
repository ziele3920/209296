#ifndef ITERABLE_HH
#define ITERABLE_HH

/*!
 * \brief
 * Definicja Iterable
 *
 * Plik zawiera definicje interfejsu Iterable
 */

#include <iostream>

/*!
 * \brief The Iterable class
 *
 * Klasa modeluje interfejs umożliwiajacy przeglądanie kontenera
 * oraz uzystkiwanie referencji do jego ostatniego pola co jest
 * wymagane w obecnej implementacji tablicy asocjacyjnej
 */
template < class typ >
class Iterable {

public:


/*!
 * \brief operator []
 *
 * Przeciążenie operatora [] w celu umożliwienia przeglądania kontenera
 * \param[in] i - indeks elementu
 * \retval - zwraca wartośc znajdującą się na danym indeksie
 */
virtual typ operator[] (unsigned int i) = 0;

/*!
 * \brief RefEnd
 *
 * Zwraca referencję do ostatniego elementu kontenera umożliwiając przypisanie
 * tam nowego elementu.
 *
 * \retval - referencja do ostatniego pola listy
 */
virtual typ &RefEnd() = 0;
};

#endif
