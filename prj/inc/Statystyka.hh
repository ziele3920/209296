#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>
#include "IObserwator.hh"
#include "Stoper.hh"
#include <fstream>
#include <cstdlib>
#include <string>

/*!
 * \file
 * \brief
 * Zawiera definicję klasy Statystyka
 *
 * Zawiera definicję klasy Statystyka
 */

/*!
 * \brief
 * Modeluje pojęcie statystyki
 * 
 * Modeluje pojęcie statystyki, czyli średnich czasów wykonania
 * metody dla różnyuch wielkości prób.
 */

class Statystyka : public IObserwator {

  /*!
   * \brief
   * Ilość prób
   *
   * Ilość prób do utworzenia statystyki
   */
  unsigned int IleProb;

  /*!
   * \brief
   * Tablica z rozmiarami prób
   * 
   * Wskaźnik na tablicę zawierającą wielkości danych prób.
   */
  unsigned int *Proba;

  /*!
   * \brief
   * Średni czas wykonania danej próby
   *
   * wskaźnik na tablica ze średnimi czasami wykonania kolejnych prób.
   */
  double *Czas;

  /*!
   * \brief Suma Czasu Proby
   *
   * Przechowuje sumę czasów pojedyńczych powtórzeń z danej próby.
   */
  double SumaCzasuProby;

  /*!
   * \brief Ilość Powtórzeń
   *
   * Przechowuje ilość wykonywanych powtórzeń pojedyńczego testu.
   */
  unsigned int IloscPowtorzen;

  /*!
   * \brief Licznik Powtórzeń
   *
   * Zlicza ilosć wykonanych powtórzeń w danej próbie.
   */
  unsigned int LicznikPowtorzen;

  /*!
   * \brief Licznik Prób
   *
   * Zlicza ilosć prób wykonanych prób.
   */
  unsigned int LicznikProb;

  /*!
   * \brief Stoper
   *
   * Stoper wykorzystywany do pomiaru czasu.
   */
  Stoper *MojStoper;

public:

  /*!
   * \brief
   * Konstruktor z dwoma pramametrami
   *
   * Konstruktor z dwoma paramatremi tworzy dynamiczne tablice
   * przechowujące statystykę oraz wypełnia rozmiary prób.
   *
   * \param[in] iloscProb - liczbosc prob w ksperymencie
   * \param[in] proby - tablica z licznościami prób.
   */
  Statystyka(const unsigned int iloscProb, unsigned int *proby, const unsigned int ilePowtorzen);

  /*!
   * \brief
   * Destruktor - zwaknia pamięć
   *
   * Zwalnia pamięć zaalokowaną na dynamiczne tablicy przechowujące statystykę.
   */
  ~Statystyka() {delete[] Czas; delete[] Proba; delete MojStoper;}

  /*!
   * \brief
   * Zapisuje statysykę do pliku
   *
   * Zapisuje statystystykę do pliku o nazwie podanej w argumencie.
   * Plik zapisany zostaje w sposób, gdzie każda nowa linia wygląda następująco:
   * RozmiarPróby,ŚredniCzas
   * czas wyrażony jest w ms.
   *
   * \param[in] nazwaPliku - nazwa pliku do którego ma zostać zapisanaza statystyka
   */
  void ZapiszStaty(std::string nazwaPliku) const;

  /*!
   * \brief Aktualizuj
   *
   * Aktualizuje pozyskiwane dane dotyczące wyników testu:
   * Jeżeli stoper nie odlicza to uruchamia odliczanie,
   * Jeżeli stper odlicza to go zatrzymuje i sumuje czasy powtórzeń.
   * Gdy nasąpi wykonanie wszystkich pomiarów w próbie to uzupełnia
   * talicę przechowywujacą średnie czasy każdej próby.
   */
  void Aktualizuj();

};

#endif
