#ifndef ITESTABLE_HH
#define ITESTABLE_HH

#include <iostream>

/*!
 * \file
 * \brief 
 * Definicja klasy ITestable
 *
 * Plik zawiera definicję abstrakcyjnej klasy ITestable,
 * która tworzy interfejs dla programów implementowanych
 * podczas zajęć laboratoryjnych z PAMSI.
 */


/*!
 * \brief
 * Modeluje interfejs programu
 *
 * Modeluje interfejs do programów wykonywanch 
 * w ramach kursu.
 */
class ITestable{

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
  virtual void WczytajDane(std::string const nazwaPliku, unsigned int n) = 0;

  /*!
   * \brief 
   * Wykonanie części obliczeniowej programu
   *
   * Metoda w której implementowana jest część obliczeniowa
   * programu, której czas wykonania zostanie zmierzony.
   *
   * \param[in] k - ilość elementów dla których mają zostać wykonane obliczenia.
   */
  virtual void Start(const unsigned int k, std::string const nazwaPliku ) = 0;

  /*!
   * \brief
   * Zwalnia pamięć po teście
   *
   * Zwalnia pamięć zajmowaną przez objekty wykorzytsane do testów
   */
  virtual void Zwolnij() = 0;

};

#endif
