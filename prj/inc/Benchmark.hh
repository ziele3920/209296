#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "Framework.hh"
#include <ctime>
#include "Statystyka.hh"
#include "Pliki.hh"

/*!
 * \file
 * \brief
 * Definicja klasy Benchmark
 *
 * Plik zawiera definicję klasy Benchmark wraz z definicją jej metod.
 */

/*!
 * \brief
 * Modeluje pojęcie Benchmarku
 *
 * Modeluje pojęcie Benchmarku czyli objektu mierzącego czas wykonywania
 * algoytmu
 */
template < class typ> 
class Benchmark {
/*!
 * \brief
 * Statystyki testu
 *
 * Pole przechowuje wyniki testów
 */
Statystyka *stat;

/*!
 * \brief
 * Ilość prób
 *
 * Ilość powtórzeń każdej seriii
 */
unsigned int IleProb;

/*!
 * \brief
 * Tablica liczności serii
 *
 * Tablica z licznościami elementów dla kojenych serii
 */
unsigned int *IleDanych;

/*!
 * \brief
 * Ilość powtórzeń
 *
 * Ilość powtórzeń każdej serii
 */
unsigned int IlePowtorzen;

public:

/*!
 * \brief
 * Konstruktor 2 argumentowy
 *
 * Tworzy objekt klasy Benchmark i inicjuje nową statystykę dla objektu
 *
 * \param[in] ileProb - ilość prób, które zostaną wykonane
 * \param[in] ileDanych - wkaźnik na tablice z licznościami kolejnych serii
 * \param[in] ilePowtorzen - ilość powtórzeń każdej serii
 */
 Benchmark(const unsigned int ileProb, unsigned int* const ileDanych, const unsigned int ilePowtorzen) {
  IleProb = ileProb;
  IleDanych = ileDanych;
  IlePowtorzen = ilePowtorzen; 
  stat = new Statystyka(IleProb, IleDanych);
}

/*!
 * \brief
 * Testowanie algorytmu
 *
 * Metoda testuje algorytm w okreslonej liczbie serii i powtórzeniach
 * pomiary zapisuje do pliku podanego pez użytkownika
 *
 * \param[in] I - objekt klasy na której zostanie przeprowadzony test
 * \param[in] nazwaPlikuStat - nazwa pliku do którego zostaną zapisane statystyki
 * param[in] nazwaPlikuDane - nazwa pliku z danymi neizbędnymi do przeprowadzenia testu
 */
  void Test(Framework *I, const char* const nazwaPlikuDane, std::string const nazwaPlikuStat) const {
  std::clock_t poczatek, koniec;
  double suma;
  std::fstream plikIn;

  for(size_t j = 0; j < IleProb; ++j) {
  suma = 0;
    for(size_t k = 0; k < IlePowtorzen; ++k) {
      poczatek = std::clock();
      I -> WczytajDane(nazwaPlikuDane, IleDanych[j]);
      OtworzPlikIn(nazwaPlikuDane, plikIn); 
      I -> Start(plikIn, IleDanych[j]);
      koniec = std::clock();
      suma = suma + (koniec - poczatek);
      I -> Zwolnij();
      plikIn.close();
    }
   (*stat)[j] = (suma/IlePowtorzen)/(double)(CLOCKS_PER_SEC/1000);
  }
 stat -> ZapiszStaty(nazwaPlikuStat);
 }
};

#endif
