/*! 
 * \file
 * \brief
 * Moduł główny programu
 *
 *
 * Program wkonuje serię 10 pomiarów czasu wykonania metody start
 * dla różncyh wielkości problemu obliczeniowego, dla każdego
 * zaimplemetowanego typu danych - LinkLista, ListaArr1, ListaArr2x. 
 * Procedura obliczeniowa polega na utworzeniu 'objektu'
 * przechoującego n danych (stałych liczb).
 * statystykę pomiarów 
 * zapisuje do pliku o nazwie "TypDaych.dat".
 * gdzie "TypDanych" to odpowiednio Lista, ListaArr1 i ListaArr2x
 *
 * OBSŁUGA PROGRAMU:
 * Aby wywołać program należy w lini poleceń wywołać jego nazę
 *  np: "./a.out"
 */

#include "../inc/ListArr2x.hh"
#include "../inc/Statystyka.hh"
#include "../inc/Benchmark.hh"
#include "../inc/Pliki.hh"

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
const int ILOSC_PROB = 8;

const std::string NAZWA_PLIKU_Z_DANYMI = "dane.dat";

int main(int argc, char *argv[]) {
  unsigned int iloscDanych[ILOSC_PROB] = {10,10, 100, 400, 1000, 4000, 10000, 40000};
  std::string nazwaPlikuStat[3] = {"statystyka.dat"};
  ListArr2x<int> *L = new ListArr2x<int>;

  Statystyka *stat = new Statystyka(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);
  Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);

  B -> DodajObserwatora(stat);
  //LosujIntDoPliku(10000000, 100);

   B -> Test(L, NAZWA_PLIKU_Z_DANYMI);
   stat -> ZapiszStaty(nazwaPlikuStat[0]);
   B -> UsunObserwatora(stat);
   
return 0;
}
