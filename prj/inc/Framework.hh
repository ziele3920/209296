#ifndef FRAMEWORK_HH
#define FRAMEWORK_HH

#include <iostream>

/*!
 * \file
 * \brief 
 * Definicja klasy Framework
 *
 * Plik zawiera definicję abstrakcyjnej klasy Framework,
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
class Framework {

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
  virtual void WczytajDane(const char *nazwaPliku, unsigned int n) = 0;

  /*!
   * \brief 
   * Wykonanie części obliczeniowej programu
   *
   * Metoda w której implementowana jest część obliczeniowa
   * programu, której czas wykonania zostanie zmierzony.
   *
   * \param[in] k - ilość elementów dla których mają zostać wykonane obliczenia.
   */
  virtual void Start(const unsigned int k) = 0;

};

#endif
