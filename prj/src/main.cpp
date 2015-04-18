/*! 
 * \file
 * \brief
 * Moduł główny programu
 *
 *
 * Program wkonuje serię 10 pomiarów czasu wykonania metody start
 * (badanie czasu zapisu i odczytu do/z Tablicy Asocjacyjnej
 * dla różncyh wielkości problemu obliczeniowego.
 * Jako plik wynikowy otrzymujemy plik z czasami poświęconymi
 * przez program na zapis/odczyt n danych z tablicy.
 *
 * WYMAGANIA:
 * Plik z danymi musi być w formacie takim, że każda linia to kolejno 
 * "klucz
 *  wartość"
 * 
 * Klucze muszą być sześcioznakowymi ciągami stringów składających 
 * się wyłącznie z małych liter.
 *
 * Wartości mogą być dowolnym intem
 *
 * OBSŁUGA PROGRAMU:
 * Aby wywołać program należy w lini poleceń wywołać jego nazę
 *  np: "./a.out"
 */

#include "../inc/TabAsoc.hh"
#include "../inc/Statystyka.hh"
#include "../inc/Benchmark.hh"


/*!
 * \brief
 * Ilośc powtórzeń danej próby
 *
 * Ilośc powtórzeń danej próby
 */
#define ILOSC_POWTORZEN 10

/*!
 * \brief
 * Ilość prób
 * 
 * Ilość prób = ilość rozmiarów prób
 */
#define ILOSC_PROB 7

int main(int argc, char *argv[]) {
  unsigned int iloscDanych[ILOSC_PROB] = {40, 100, 400, 1000, 4000, 10000, 40000};
  std::string nazwaPlikuStat[1] = {"TabHash.dat"};
  char dane[] = "rand_dane_z_kluczem.dat";
  
  Framework *I = new TabAsoc;

  Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);

  B -> Test(I, dane,  nazwaPlikuStat[0]);

return 0;
}
