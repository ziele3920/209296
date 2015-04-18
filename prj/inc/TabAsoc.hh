#ifndef TABASOC_HH
#define TABASOC_HH

/*!
 * \brief
 * Definicja klasy TabAsoc
 *
 * Plik zawiera definicję klasy TabAsoc
 */

#include "TabHash.hh"
#include "Framework.hh"

/*!
 * \brief
 * Modeluje Tablice Asocjacyjną
 *
 * Klasa TabAsoc modeluje pojęcie Tablicy Asocjacyjnej zaimplementowanej
 * jako Tablica Haszująca
 */
class TabAsoc : TabHash, public Framework {

public:

/*!
 * \brief
 * Przeciążenie operatora()
 *
 * Przeciążenie operatora() w celu umożliwiena odczytu wartości
 * z tablicy za pomocą klucza
 *
 * \param[in] klucz - klucz pod jakim chcemy znaleźć wartość
 *
 * \retval - zwraca wartość znajdującą sie pod danym kluczem, lub -1 
 * w przypadku gdy nie znaleziono pasującego klucza w tablicy
 */
  const int operator() (const std::string klucz) const;

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

/*!
 * \brief
 * Wczytuje dane
 *
 * Wcztuje dane do Tablicy Haszującej z pliku, w kótym linijka
 * po linijce są podane kolejne wartości klucz, wartość.
 *
 * \para[in] nazwaPliku - nazwa pliku z danymi
 * \param[in] n - ilość danych do wczytania
 */
  void WczytajDane(const char *nazwaPliku, const unsigned int n);

/*!
 * \brief
 * Obliczenia do pomiarów
 *
 * Metoda niezbędna do wykonania Benchmarka w celu zmierzenia czasu zapisu
 * i odczytu z tablicy dancyh
 *
 * \param[in] plik - referencja do owtartego pliku z danymi
 * \param[in] k - ilość elementów na których zostanie przeprowadzony test
 */
  void Start(std::fstream &plik, const unsigned int k);

/*!
 * \brief
 * Zwalnia pamięć
 * 
 * Zwalnia pamięć pomiędzy kolejnymi seriami testów - czyści tylko
 * przechowywane wartości
 */
  void Zwolnij();


};

#endif
