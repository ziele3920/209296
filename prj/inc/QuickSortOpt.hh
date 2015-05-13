#ifndef QUICKSORTOPT_HH
#define QUICKSORTOPT_HH

/*!
 * \brief
 * Definicja klasy QuickSortOpt
 *
 * Plik zawiera definicję klasy QuickSortOpt
 */

#include "ISort.hh"
#include "HybridSort.hh"

/*!
 * \brief The QuickSortOpt class
 *
 * Klasa modeluje objekt potrafiący sortować kontener typu Iterable,
 * algorymem szybkiego syrtowania zoptymalizowanym o wybór pivota
 * na podstawie mediany z trzech.
 */
template < class typ >
class QuickSortOpt : public ISort<typ> {

    /*!
     * Partycjonowanie kontenera
     *
     * Metoda będąca częścią algorytmu Sortowania Szybkiego.
     * Dzieli przekazany fragment kontenera na dwie części -
     * lewy z elementami mniejszymi od wybranego pivota
     * i prawa z elementami większymi od wybranego pivota.
     * Pivot jest dobierany za pomocą liczenia mediany z trzech elementów:
     * pierwszego, środkowego i ostatniego.
     *
     * \param[in] lewy - indeks pierwszego elementu z kontenera do posortowania
     * \param[in] prawy - indekst ostatniego elmentu z kontenera do posortowania
     * \param[in] tab - referencja do sortowanego kontenera
     */
    int Partition(int lewy, int prawy, Iterable<typ> &tab) {
      typ Pivot = tab[MedianaTrzech(lewy, (lewy+prawy)/2, prawy-1, tab)];

      while(1) {
        while(tab[prawy] > Pivot) --prawy;
        while(tab[lewy] < Pivot) ++lewy;
        if( lewy < prawy ) {
          tab.Zamien(lewy, prawy);
          ++lewy; --prawy;
        }
        else return prawy;
      }
    }

    /*!
     * \brief
     * Znajduje mediane
     *
     * Znajduje mediane wartości z trzech podanych elementów kontenera
     *
     * \param[in] a - indeks pierwszego elementu do liczenia mediany
     * \param[in] b - indeks drugiego elementu do liczenia mediany
     * \param[in] c - indeks trzeciego elementu do liczenia mediany
     * \param[in] tab - referencja do sortowanego kontenera
     *
     * \retval - zwraca indeks elementu będącego medianą z trzech wartości podanych elementów
     */
  int MedianaTrzech(const int a, const int b, const int c, Iterable<typ> &tab) const {
    if((tab[a] <= tab[b]) && (tab[a] <= tab[c])) {
      if(tab[b] <= tab[c])  return b;
      else return c;
    }

    if((tab[b] <= tab[a]) && (tab[b] <= tab[c])) {
      if(tab[a] <= tab[c])  return a;
      else return c;
    }
    return b;
  }

  template <class U> friend class HybridSort;

public:

  /*!
   * \brief
   * Zoptymalizowane Szybkie Sortowanie
   *
   * Realizuje zoptymalizowany ze względu na wybór pivota algorytm
   * szybkiego sortowania elementów konteneru
   *
   * \param[in] lewy - indeks pierwszego elementu tworzącego kontener do posotrowania
   * \param[in] prawy - indeks ostatniego elementu tworzącego kontener do posotrowania
   * \param[in] tab - referencja do sortowanego kontenera
   */

void Sort(const int lewy, const int prawy, Iterable<typ> &tab) {
  int nowy;
  if(lewy < prawy) {

    nowy = Partition(lewy, prawy, tab);
    Sort(lewy, nowy, tab);
    Sort(nowy+1, prawy, tab);
  }
}

};

#endif
