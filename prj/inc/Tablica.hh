#ifndef TABLICA_HH
#define TABLICA_HH

#include "Framework.hh"
#include "Pliki.hh"

/*!
 * \file
 * \brief
 * Definicja klasy Tablica
 *
 * Plik zawiera definicję klasy Tablica.
 */

/*!
 * \brief
 * Modeluje pojęcie tablicy
 *
 * Modeluje pojęcie tablicy jendowymiarowej 
 * o zadanym rozmiarze, alokowanej dynamicznie.
 */

class Tablica : public Framework {

  /*!
   * \brief
   * Rozmiar tablicy
   *
   * Rozmiar tablicy.
   */
  unsigned int Rozmiar;

  /*!
   * \brief
   * Wslaźnik do tablicy
   *
   * Wslaźnik do dynamicznie zaalokowanej tablicy.
   */
  int *WskT;

public:

  /*!
   * \brief
   * Konstruktor z zadanym rozmiarem tablicy
   *
   * Konstruktor jednoargumentowy z zadanym rozmairem tablicy.
   *
   * \param[in] rzm - rozmiar nowej tablicy
   */
  Tablica (const unsigned int rzm) { Rozmiar = rzm; WskT = new int[Rozmiar]; }

  /*!
   * \brief
   * Destruntor tablicy
   *
   * Zwalnia pamięć zaalokowaną na daną tablicę
   */
  ~Tablica () { delete [] WskT; }

  /*!
   * \brief
   * Wczytanie danych z pliku
   *
   * Wczytuje zadaną ilość danych do przetworzenia z 
   * pliku o zadanej nazwie.
   *
   * \param[in] nazwaPliku - nazwa pliku z danymi
   * \param[in] n - ilość danych do wczytania
   */
  void WczytajDane(const char *nazwaPliku, const unsigned int n);

  /*!
   * \brief
   * Przemnaża n elementów tablicy przez 2
   *
   * Przemnaża zadaną ilość elementów tablicy przez 2.
   * Uwaga! Możliwośc przekroczenia zakresu tablicy!
   *
   * \param[in] k - ilość elementów tablicy który zostaną
   * przemnożone przez 2.
   */
  void Start(const unsigned int k);
};


#endif
