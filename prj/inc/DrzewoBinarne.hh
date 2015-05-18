#ifndef DRZEWOBINARNE_HH
#define DRZEWOBINARNE_HH

/*!
 * \brief DrzewoBinarne
 *
 * Plik zawiera definicje klasy DrzewoBinarne.
 */

#include "IDrzew.hh"
#include "Wezel.hh"

/*!
 * \brief Klasa DrzewoBinarne
 *
 * Klasa modeluje Drzewo Binarne.
 */

template < class typ >
class DrzewoBinarne : public IDrzew<typ>{

  /*!
   * \brief Korzeń drzewa
   *
   * Wskaźnik na węzeł będący korzeniem drzewa binarnego.
   */
  Wezel<typ> *Korzen;

  /*!
   * \brief Liczba Węzłów
   *
   * Ilość węzłów w drzewie.
   */
  int LiczbaWezlow;

  /*!
   * \brief FindMin
   *
   * Szuka węzła o nejmniejeszej wartości, począwszy od
   * węzła podanego w arunemcie.
   *
   * \param[in] poszukiwacz - węzeł startowy poszukwiań
   * \retval - wskaźnik na węzeł przechowujący najmniejszą wartość
   */
  Wezel<typ> FindMin(Wezel<typ> *poszukiwacz) {
      while(poszukiwacz -> Lewy != NULL)
          poszukiwacz = poszukiwacz -> Lewy;
      return poszukiwacz;
  }

  /*!
   * \brief FindSuccessor
   *
   * Szuka poprzednika węzła podanego w artumencje wywołania.
   * \param[in] poszukiwacz - węzeł którego poprzednik ma zostać znaleziony
   *
   * \retval wskaźnik na węzeł będący poprzednikiem
   */
  Wezel<typ> FindSuccessor(Wezel<typ> *poszukiwacz) {
      if(poszukiwacz -> Prawy != NULL)
          return FindMin(poszukiwacz -> Prawy);

      Wezel<typ> *tymczasowyWezel = poszukiwacz -> Rodzic;
      while((tymczasowyWezel != NULL) && (tymczasowyWezel -> Lewy != poszukiwacz)) {
          poszukiwacz = tymczasowyWezel;
          tymczasowyWezel = tymczasowyWezel -> Rodzic;
      }
      return tymczasowyWezel;
  }

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
   * \brief Dodaje element
   * 
   * Dodaje element do drzewa binarnego
   *
   * \param[in] wartosc - wartość do umieszczenia w drzewie.
   */
  void Insert(const typ wartosc){

      Wezel<typ> *nowyWezel = new Wezel<typ>;
      nowyWezel-> Dana = wartosc;
      Wezel<typ> *rodzicNowego = NULL;
      Wezel<typ> *poszukiwacz = Korzen;

      while (poszukiwacz != NULL) {
        rodzicNowego = poszukiwacz;
        if (poszukiwacz -> Dana > wartosc)
            poszukiwacz = poszukiwacz -> Lewy;
        else if(poszukiwacz -> Dana < wartosc)
            poszukiwacz = poszukiwacz -> Prawy;
        else
            return;
      }

      nowyWezel -> Rodzic = rodzicNowego;

      if (rodzicNowego == NULL)
          Korzen = nowyWezel;
      else if(nowyWezel-> Dana < rodzicNowego -> Dana)
          rodzicNowego -> Lewy = nowyWezel;
      else
          rodzicNowego -> Prawy = nowyWezel;

      ++LiczbaWezlow;
  }


  /*!
   * \brief Remove
   *
   * Usuwa węzeł przechowujący daną wartość.
   *
   * \param[in] wartosc - przechowywana wartość do usunuęcia z drzewa
   */
  void Remove(typ wartosc) {
      Wezel<typ> *usuwany = Search(wartosc);
      Wezel<typ> *nastepnik, *pomocniczy;

      if((usuwany -> Lewy == NULL) || (usuwany -> Prawy == NULL))
          nastepnik = usuwany;
      else
          nastepnik = FindSuccessor(usuwany);
      if(nastepnik -> Lewy != NULL)
          pomocniczy = nastepnik -> Lewy;
      else
          pomocniczy = nastepnik -> Prawy;
      if(pomocniczy != NULL)
          pomocniczy -> Rodzic = nastepnik -> Rodzic;
      if(nastepnik -> Rodzic == NULL)
          Korzen = pomocniczy;
      else {
          if(nastepnik == nastepnik -> Rodzic -> Lewy)
              nastepnik -> Rodzic -> Lewy = pomocniczy;
          else
              nastepnik -> Rodzic -> Prawy = pomocniczy;
      }
      if(nastepnik != usuwany)
          usuwany -> Dana = nastepnik -> Dana;
      return nastepnik;
  }

  /*!
   * \brief Search
   *
   * Wyszukuje i zwraca daną wartość z drzewa.
   * W przypadku braku jej w drzewie wyświetla stosowny błąd
   * i zwraca NULL / 0
   *
   * \param[in] wartosc - wartość do znalezienia w drzewie
   *
   * \retval - odnaleziona wartość
   */
  typ Search(typ wartosc) {
      Wezel<typ> *poszukiwacz = Korzen;

      while((poszukiwacz != NULL) && (poszukiwacz -> Dana != wartosc)) {
          if(wartosc < poszukiwacz -> Dana)
              poszukiwacz = poszukiwacz -> Lewy;
          else
              poszukiwacz = poszukiwacz -> Prawy;
      }
      return poszukiwacz -> Dana;
  }
};

#endif
