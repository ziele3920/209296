#ifndef FRAMEWORK_HH
#define FRAMEWORK_HH

#include <iostream>
#include "Pliki.hh"

/*!
 * \file
 * \brief 
 * Definicja klasy ITestable
 *
 * Plik zawiera definicję abstrakcyjnej klasy ITestable,
 * która tworzy interfejs testowy dla programów implementowanych
 * podczas zajęć laboratoryjnych z PAMSI.
 */


/*!
 * \brief
 * Modeluje interfejs tetsowy programu
 *
 * Modeluje interfejs testowy do programów wykonywanch
 * w ramach kursu.
 */
class ITestable {

public:

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
  virtual void WczytajDane(std::string const nazwaPliku, const unsigned int n) = 0;

  /*!
   * \brief 
   * Wykonanie części obliczeniowej programu
   *
   * Metoda w której implementowana jest część obliczeniowa
   * programu, której czas wykonania zostanie zmierzony.
   *
   * \param[in] w1 - pierwsza wartość
   * \param[in] w2 -  druga wartość
   */
  virtual void Start(const unsigned int w1, const unsigned int w2) = 0;

    /*!
   * \brief Reset
   *
   * Resetuje flagi.
   */
  virtual void Reset() = 0;

  /*!
   * \brief
   * Zwalnia pamięć po teście
   *
   * Zwalnia pamięć zajmowaną przez objekty wykorzytsane do testów
   *
   * param[in] nazwaPliku - plik z danymi
   * param[in] n - ilosc danych
   */
  virtual void Zwolnij(std::string const nazwaPliku, const unsigned int n) = 0;

};

#endif
