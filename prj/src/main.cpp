/*! 
 * \file
 * \brief
 * Moduł główny programu
 *
 *
 * Program wkonuje serię 50 pomiarów czasu wykonania metody start
 * dla różncyh wielkości problemu obliczeniowego.
 * OBSŁUGA PROGRAMU:
 * Aby wywołać program należy w lini poleceń wywołać jego nazę
 *  np: "./a.out"
 */

#include "../inc/ListArr2x.hh"
#include "../inc/Statystyka.hh"
#include "../inc/Benchmark.hh"
#include "../inc/Pliki.hh"
//#include "../inc/QuickSortOpt.hh"
#include "../inc/InsertSort.hh"
#include "../inc/HeapSort.hh"
#include "../inc/HybridSort.hh"

/*!
 * \brief
 * Ilośc powtórzeń danej próby
 *
 * Ilośc powtórzeń danej próby
 */
const int ILOSC_POWTORZEN = 50;

/*!
 * \brief
 * Ilość prób
 * 
 * Ilość prób = ilość rozmiarów prób
 */
const int ILOSC_PROB = 9;

const std::string NAZWA_PLIKU_Z_DANYMI = "dane.dat";

int main(int argc, char *argv[]) {

 ListArr2x<int> L;
 HybridSort<int> QS;
 L.WczytajDane(NAZWA_PLIKU_Z_DANYMI.c_str(), 10);
 L.Pokaz();
 QS.Sort(0, L.size()-1, L);
 L.Pokaz();
 /*unsigned int iloscDanych[ILOSC_PROB] = {10,10, 100, 400, 1000, 4000, 10000, 40000, 100000};
  std::string nazwaPlikuStat[3] = {"statystyka.dat"};
  ListArr2x<int> *L = new ListArr2x<int>;

  Statystyka *stat = new Statystyka(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);
  Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);

  B -> DodajObserwatora(stat);
  //LosujIntDoPliku(10000000, 100);

   B -> Test(L, NAZWA_PLIKU_Z_DANYMI);
   stat -> ZapiszStaty(nazwaPlikuStat[0]);
   B -> UsunObserwatora(stat);
*/
return 0;
}
