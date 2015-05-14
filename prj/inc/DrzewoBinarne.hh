#ifndef DRZEWOBINARNE_HH
#define DRZEWOBINARNE_HH

/*!
 * \brief DrzewoBinarne
 *
 * Plik zawiera definicje klasy DrzewoBinarne.
 */

#include <Wezel.hh>

/*!
 * \brief Klasa DrzewoBinarne
 *
 * Klasa modeluje Drzewo Binarne.
 */

template < class typ >
class DrzewoBinarne {

  /*!
   * \brief Korzeń drzewa
   *
   * Wskaźnik na węzeł będący korzeniem drzewa binarnego.
   */
  Wezel *Korzen;

  /*!
   * \brief Liczba Węzłów
   *
   * Ilość węzłów w drzewie.
   */
  int LiczbaWezlow;

public:

  /*!
   * \brief Konstruktor bezarumentowy
   * 
   * Konstrunkto bezargumentowy zeruje liczbę węzłów i ustawia
   * Korzen na NULL.
   */
  DrzewoBinarne() {
    Korzen = NULL;
    LiczbaWezlow = 0;
  }

  /*!
   * \brief Konstruktor przyjmujący daną
   *
   * Kontruktor tworzy nowy węzeł będący korzeniem drzewa,
   * i umieszcza w nim przekazaną wartość.
   *
   * \param[in] dana - wartosc do umieszczenia w korzeniu
   */
  DrzewoBinarne(typ dana) {
    Korzen = new Wezel<typ>():
    Korzen -> wartosc = dana;
    LiczbaWezlow = 1;
  }

  /*!
   * \brief Dodaje element
   * 
   * Dodaje element do drzewa binarnego
   *
   * \param[in] dana - wartość do umieszczenia w drzewie.
   */
  void Dodaj(const typ dana){}

};

#endif
