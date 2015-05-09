/*!
 * \brief Klasa Stoper
 *
 * Plik zawiera definicję klasy Stoper.
 * */

#ifndef STOPER_HH
#define STOPER_HH

#include <iostream>
#include <ctime>

/*!
 * \brief The Stoper class
 *
 * Klasa modeluje stoper niezbędny do odliczania czasu.
 */
class Stoper {

    /*!
   * \brief Czas Początkowy
   *
   * Czas w którym stoper zaczął odliczać.
   */
  double CzasPoczatkowy;

  /*!
   * \brief Czas Końcowy
   *
   * Czas w którym odliczanie czasu zostało zatrzymane.
   */
  double CzasKoncowy;

  /*!
   * \brief Czy Liczy
   *
   * Zmienna przechowuje wartośc true gdy stoper aktualnie odlicza czas,
   * lub false gdy jest zatrzymany.
   */
  bool CzyLiczy;

public:

  /*!
   * \brief Stoper
   *
   * Kontruktor bezarumentowy zeruje czasy i ustawia wartość pola CzyLiczy na false.
   */
  Stoper();

  /*!
   * \brief Start
   *
   * Uruchamia odliczanie czasu.
   */
  void Start();

  /*!
   * \brief Stop
   *
   * Zatrzymuje odliczanie czasu.
   */
  void Stop();

  /*!
   * \brief Reset
   *
   * Resetuje stoper.
   */
  void Reset();

  /*!
   * \brief Pomiar
   *
   * Wyłuskuje czas pomiaru w ms.
   * \retval zwrca czas pomiaru wyrażon w ms
   */
  double DajPomiar() const;

  /*!
   * \brief Czy Odmierza
   *
   * Informuje czy stoper aktualinie liczy czy nie.
   * \retval true - gdy odlicza
   * \retval false - gdy nie odlicza
   */
  bool CzyOdmierza() const;

};
#endif
