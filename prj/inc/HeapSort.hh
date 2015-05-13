#ifndef HEAPSORT_HH
#define HEAPSORT_HH

/*!
 * \brief Heap Sort
 *
 * Plik zawiera definicję klasy HeapSort
 */

#include "ISort.hh"

/*!
 * \brief HeapSort
 *
 * Klasa modelująca objekt potrafiący wykonać sortowanie przez
 * kopcowanie na kontenerze Iterable.
 */
template < class typ >
class HeapSort : public ISort<typ> {

    /*!
     * \brief
     * Porównuje el. kopca
     *
     * Porównuje i ustawia elementy kopca w odpowiedniej kolejności
     *
     * \param[in] rozmiarKopca - rozmiar kopca który sortujemy
     * \param[in] i - numer gałęzi kopca
     * \param[in] tab - referencja do sortowanego kontenera
     */
   void Kopcuj(const int rozmiarKopca, const int i, Iterable<typ> &tab) {
    int najwiekszy;
    int lewy = 2*i+1, prawy = (2*i)+2;

    if(lewy <= rozmiarKopca && tab[lewy] > tab[i])
      najwiekszy = lewy;
    else najwiekszy = i;

    if(prawy <= rozmiarKopca && tab[prawy] > tab[najwiekszy])
      najwiekszy = prawy;

    if(najwiekszy!= i) {
    tab.Zamien(najwiekszy, i);
    Kopcuj(rozmiarKopca, najwiekszy, tab);
      }
  }

   /*!
    * \brief
    * Tworzy kopiec
    *
    * Tworzy kopiec z tablicy o podanym rozmiarze
    *
    * \param[in] rozmiar - rozmiar tablicy
    * \param[in] tab - referencja do sortowanego kontenera
    */
   void BudujKopiec(const int rozmiar, Iterable<typ> &tab) {
     for(int i = rozmiar/2 -1; i >= 0; --i)
       Kopcuj(rozmiar, i, tab);
   }

public:

   /*!
    * \brief
    * Sortowanie przez kopcowanie
    *
    * Realizuje algorytm sortowania przez kopcowanie
    * Alotytm sortuje tablicę od początku - pierwszy argument jest
    * ignorowany.
    *
     * \param[in] lewy - indekst pierwszego elementu do posortowania
     * \param[in] prawy - indeks ostatniego elementu do posortowania
     * \param[in] tab - referencja do kontenera
     */
   void  Sort(const int lewy, const int prawy, Iterable<typ> &tab) {
     int rozmiar = prawy;
     BudujKopiec(rozmiar, tab);
     for(size_t i = rozmiar; i > 0; --i) {
       tab.Zamien(i, 0);
        --rozmiar;
        Kopcuj(rozmiar, 0, tab);
     }
   }
};
#endif
