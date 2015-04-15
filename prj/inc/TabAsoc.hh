#ifndef TABASOC_HH
#define TABASOC_HH

/*!
 * \brief
 * Definicja klasy TabAsoc
 *
 * Plik zawiera definicję klasy TabAsoc
 */

#include "TabHash.hh"

/*!
 * \brief
 * Modeluje Tablice Asocjacyjną
 *
 * Klasa TabAsoc modeluje pojęcie Tablicy Asocjacyjnej zaimplementowanej
 * jako Tablica Haszująca
 */
class TabAsoc : TabHash {

public:

/*!
 * \brief
 * Przeciążenie operatora[]
 *
 * Przeciążenie operatora[] w celu umożliwiena odczytu wartości
 * z tablicy za pomocą klucza
 *
 * \param[in] klucz - klucz pod jakim chcemy znaleźć wartość
 *
 * \retval - zwraca wartość znajdującą sie pod danym kluczem, lub -1 
 * w przypadku gdy nie znaleziono pasującego klucza w tablicy
 */
  int operator[] (const std::string klucz) const;

/*!
 * \brief
 * Przeciążenie operatora[]
 *
 * Przeciążenie operatora[] w celi umożliwienia zapisania nowej wartości
 * do tablicy pod wskazanym kluczem
 *
 * \param[in] klucz - klucz pod którym chcemy zapisać daną
 *
 * \retval - zwraca referencje do miejsca przechowywanai danej
 */
  int &operator[] (const std::string klucz);

};

#endif
