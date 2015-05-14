#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "InterfejsADT.hh"
#include <ctime>
#include "Statystyka.hh"
#include "IObserwowany.hh"
#include <list>
#include "../inc/ISort.hh"

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
class Benchmark : public IObserwowany {

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

/*!
   * \brief Lista Obserwatorow
   *
   * Lista aktywnych obserwatorów danego objektu
   */
  std::list<IObserwator*> ListaObserwatorow;

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
}

/*!
 * \brief
 * Testowanie algorytmu
 *
 * Metoda testuje algorytm w okreslonej liczbie serii i powtórzeniach
 * pomiary zapisuje do pliku podanego pez użytkownika
 *
 * \param[in] I - objekt klasy implementującej InterfesjADT na której zostanie przeprowadzony test
 * \param[in] nazwaPliku - nazwa pliku z danymi do wczytania
 * \param[in] sort - referencja do objektu sortującego
 * \param[in] IT - referencja do obiektu implementującego Iterable
 */
void Test(InterfejsADT<typ> &I, std::string const nazwaPliku, ISort<typ> &sort, Iterable<typ> &IT) {

  for(size_t j = 0; j < IleProb; ++j) {
    for(size_t k = 0; k < IlePowtorzen; ++k) {

      I.WczytajDane(nazwaPliku.c_str(), IleDanych[j]);
      this -> PowiadomObserwatorow();
      sort.Sort(0, IleDanych[j]-1, IT);
      this -> PowiadomObserwatorow();
      I.Zwolnij();
    }
  }
 }

/*!
   * \brief Dodaje Obserwatora
   *
   * Dodaje obserwatora do listy obserwatorów danego objektu
   *
   * \param[in] nowyObserwator - wskaźnik na objekt będący obserwatorem
   */
  void DodajObserwatora(IObserwator *nowyObserwator) {
    ListaObserwatorow.push_back(nowyObserwator);
  }

  /*!
   * \brief Usuwa Obserwatora
   *
   * Usuwa danego obserwatora z listy obserwatorów
   *
   * \param[in] obserwator - wskaźnik na obserwatora który ma zostać usunięty
   */
  void UsunObserwatora(IObserwator *obserwator) {
    ListaObserwatorow.remove(obserwator);
  }

  /*!
   * \brief Powiadamia Obserwatorów
   *
   * Wywołuje u wszystkich aktywnych obserwatorów metodę Aktualizuj.
   */
  void PowiadomObserwatorow() {
    std::list<IObserwator*>::iterator it = ListaObserwatorow.begin();
    for(; it != ListaObserwatorow.end(); ++it)
      (*it) -> Aktualizuj();
  }

};

#endif
