#ifndef INSERTSORT_HH
#define INSERTSORT_HH

/*!
 * \brief Insert Sort
 *
 * Plik zawiera definicję klasy InsertSort
 */

#include "ISort.hh"

/*!
 * \brief InsertSort
 *
 * Klasa modelująca objekt potrafiący wykonać sortowanie przez
 * wstawianie na kontenerze Iterable.
 */
template < class typ >
class InsertSort : public ISort<typ> {

public:

    /*!
     * \brief
     * Sortowanie przez wstawianie
     *
     * Metoda realizuje algorytm sortowania przez wstawianie.
     *
     * \param[in] lewy - indekst pierwszego elementu do posortowania
     * \param[in] prawy - indeks ostatniego elementu do posortowania
     * \param[in] tab - referencja do kontenera
     */
    void  Sort(const int lewy, const int prawy, Iterable<typ> &tab) {

        int j;
        typ pom;
        for(int i = lewy; i<=prawy; ++i) {
          pom = tab[i];
          for(j = i -1; j >= 0 && tab[j] > pom; --j)
            tab.Zamien(j+1, j);
        }
    }

};



#endif
