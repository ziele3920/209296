/*! 
 * \file
 * \brief
 * Moduł główny programu
 *
 *
 * Program wkonuje serię 10 pomiarów czasu wykonania metody start
 * dla różncyh wielkości problemu obliczeniowego, dla każdego
 * zaimplemetowanego typu danych - Lista, Stos, Kolejka. 
 * Procedura obliczeniowa polega na utworzeniu 'objektu'
 * przechoującego n danych (stałych liczb).
 * statystykę pomiarów 
 * zapisuje do pliku o nazwie "TypDaych.dat".
 * gdzie "TypDanych" to odpowiednio Lista, Kolejka lub Stos
 *
 * OBSŁUGA PROGRAMU:
 * Aby wywołać program należy w lini poleceń wywołać jego nazę
 *  np: "./a.out"
 */

#include "../inc/Lista.hh"
#include "../inc/Kolejka.hh"
#include "../inc/Stos.hh"
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
#define ILOSC_PROB 3

int main(int argc, char *argv[]) {
  unsigned int iloscDanych[ILOSC_PROB] = {1, 10, 1000};
  std::string nazwaPlikuStat[3] = {"Lista.dat" , "Stos.dat", "Kolejka.dat"};
  Framework *I;
  Lista<int> *L = new Lista<int>;
  Stos<int> *S = new Stos<int>;
  Kolejka<int> *K = new Kolejka<int>;
  Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);

  for(int j=0; j<3; j++) { //dla kazdego typu danych
    switch(j) {
    case 0: I = L; break;
    case 1: I = S; break;
    case 2: I = K; break;
    default: std::cerr << "Brak przypisania wkaznika" << std::endl;
    }
    B -> Test(I, nazwaPlikuStat[j]);
  }
 
return 0;
}
