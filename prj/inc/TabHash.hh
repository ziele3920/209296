#ifndef TABHASH_HH
#define TABHASH_HH

/*!
 * \brief
 * Definicja Tablicy Haszującej
 *
 * Plik zawiera  definicję  Tablicy Haszującej
 */

#include <iostream>
#include "ListArr2x.hh"

//#define ROZMIAR 1000033
#define ROZMIAR 1
/*!
 * \brief
 * Tablica Haszująca
 *
 * Klasa modeluje pojęcie Tablicy Haszującej
 */
class TabHash{

/*!
 * \brief
 * Para wartości klucz - wartość
 *
 * Struktura modeluje nierozłączny element Tablicy Haszującej
 * czyli parę klucz - wartość
 */
  struct Para {

/*!
 * \brief
 * Klucz
 *
 * Klucz pod którym przechowywana jest wartość
 */
    std::string Klucz;

/*!
 * \brief
 * Wartość
 *
 * Wartość przechowywana w Tablicy Haszującej pod kluczem
 */
    int Wartosc;

/*!
 * \brief
 * Konstruktor 2 argumentowy 
 *
 * Dwuarumentowy onstruktor nierozłącznej Pary (Klucz i Wartosc)
 * Tworzy nowy objekt inicjując go podanymi wartościami
 *
 * \param[in] wart - wartość, którą inicjujemy objekt
 * \param[in[ key - klucz, którym inicjujemy objekt
 */  
    Para(const int wart, const std::string key);

/*!
 * \brief
 * Konstruktor 1 argumentowy
 *
 * Jednoargumentowy konstruktor nierozłącznej pary (Warotsc i Klucz)
 * Tworzy nowy objekt inicjując go kluczem: "" i wartością i
 *
 * \param[in] i - wartosc którą zostanie zainicjowany objekt
 */
    Para(const int i);

/*!
 * \brief
 * Konstruktor bezarumentowy
 *
 * Bezargumentowy konstruktor nierozłącznej pary (Klucz i Wartość)
 * Tworzy nowy objekt inicjując go kluczem: "" i wartością -1
 */
    Para();

/*!
 * \brief
 * Operator przypisania
 *
 * Przeciążenie opratora przypisania - kopiuje i przypisuje wartości pól
 *
 * \param[in] p - objekt który chcemy skopiować
 */
    void operator= (const Para p);
  };

/*!
 * \brief
 * Lista Par
 *
 * Lista przechowująca pary: wartość - klucz o takim samym hashu
 */
    ListArr2x<Para> *_Tab[ROZMIAR];

/*!
 * \brief
 * Szuka wartości pod kluczemklucz
 * 
 * Przeszukuje Listę znajdującą się na podanej pozycji Tablicy Haszującej
 * w celu znalezienia pasującego klucza
 *
 * \param[in] pozycja - pozycja Tablicy Haszującej na której znajduje się Lista do pzeszukania
 * \param[in] szukanyKlucz - klucz który ma zostać znaleziony
 *
 * \retval - zwraca wartość przechowywaną pod danym kluczem
 */
  const int DajZListy(const unsigned int pozycja, const std::string szukanyKlucz) const;

/*!
 * \brief
 * Funkcja haszująca
 *
 * Funkcja sumuje wartości liczbowe kodu ASCII liter klucza i na ich podstawie
 * generuje numer indeksu
 *
 * \param[in] klucz - klucz do haszowania
 *
 * \retval - zwraca numer indeksu Tablicy Haszującej
 */
  unsigned int H(const std::string klucz) const;

protected:

/*!
 * \brief
 * Pobiera wartość z Tablicy
 *
 * Pobiera wartość przechowywaną pod zadanycm kluczem z Tablicy Haszuącej
 *
 * \param[in] szukanyKlucz - klucz pod którym szukamy wartości
 *
 * \retval - zwraca wartość przechowywaną pod kluczem
 */
  const int Pobierz(const std::string szukanyKlucz) const; 

/*!
 * \brief
 * Dodaje elemet do tablicy
 *
 * Dodaje element (daną oraz jej klucz) do Tablicy Haszującej
 *
 * \param[in] - nowaDana - wartość którą dodajemy
 * \param[in] - nowyKlucz - klucz pod którym przechowujemy daną
 */
  int &Dodaj(const std::string nowyKlucz);

  TabHash();
  ~TabHash();

};


#endif
