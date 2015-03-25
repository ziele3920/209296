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
#include <ctime>

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
#define ILOSC_PROB 5

int main(int argc, char *argv[]) {
  unsigned int iloscDanych[ILOSC_PROB] = {1, 10, 1000, 1000000, 100000000};
  //unsigned int maxDanych = iloscDanych[ILOSC_PROB-1];
  std::string nazwaPlikuStat[3] = {"Lista.dat" , "Stos.dat", "Kolejka.dat"};
  std::clock_t poczatek, koniec;
  double suma;
  Statystyka stat(ILOSC_PROB, iloscDanych);
  InterfejsADT<int> *I;
  Lista<int> *L = new Lista<int>;
  Stos<int> *S = new Stos<int>;
  Kolejka<int> *K = new Kolejka<int>;

  /*if(argc == 3)
    LosujIntDoPliku(maxDanych, 10); */

  for(int j=0; j<3; j++) { //dla kazdego typu danych
    switch(j) {
    case 0: I = L; break;
    case 1: I = S; break;
    case 2: I = K; break;
    default: std::cerr << "Brak przypisania wkaznika" << std::endl;
    }
    for(int i=0; i<ILOSC_PROB; i++) {
      suma = 0;
      for (int k=0; k<ILOSC_POWTORZEN; k++) {
	poczatek = std::clock();
	I -> Start(iloscDanych[i]);
	koniec = std::clock();
	suma = suma + (koniec - poczatek);
	I -> Zwolnij();
      }
      stat[i] = (suma/10)/(double)(CLOCKS_PER_SEC / 1000);
    }
    stat.ZapiszStaty(nazwaPlikuStat[j]);
  }

  

return 0;
}
