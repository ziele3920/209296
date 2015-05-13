#ifndef HYBRIDSORT_HH
#define HYBRIDSORT_HH

/*!
 * \brief
 * Definicja klasy HybridSort
 *
 * Plik zawiera definicję klasy HybridSort
 */

#include "QuickSortOpt.hh"
#include "InsertSort.hh"

/*!
 * \brief The HybridSort class
 *
 * Klasa modeluje objekt potrafiący sortować kontener typu Iterable,
 * algorytm wykorzystuje zotymalizowany (mediana z trzech algorytm sortowania
 * szybkiego oraz algirytm sortowania przez wstawianie
 */
template < class typ >
class HybridSort : public ISort<typ> {

public:

      /*!
       * \brief
       * Sortowanie hybrydowe
       *
       * Metoda realizuje algorytm sortowania hybrydowego bazujący na
       * zoptymalizowanym ze względu na wybór pivota (mediana z trzech)
       * algorytmowi Sortowania Szybkiego oraz jako algorytm pomocniczy
       * wykorzystane zostało sortowanie przez wstawianie.
       *
       * \param[in] lewy - indeks pierwszego elementu z listy do posortowania
       * \param[in] prawy - indeks ostatniego elementu z listy do posortowania
       * \param[in] tab - referencja do sortowanego kontenera
       */
      void Sort(const int lewy, const int prawy, Iterable<typ> &tab) {
        InsertSort<typ> inSort;
        QuickSortOpt<typ> qSort;
        int nowy = 0;
        int prog = 32;

        if(lewy < prawy) {
        nowy = qSort.Partition(lewy, prawy, tab);

            if(nowy - lewy > prog)
                Sort(lewy, nowy, tab);
            else
                inSort.Sort(lewy, nowy, tab);
            if(prawy - nowy > prog)
                 Sort(nowy+1, prawy, tab);
            else
                 Sort(nowy+1, prawy, tab);
          }
      }

};


#endif
