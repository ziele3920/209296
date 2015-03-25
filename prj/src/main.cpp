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

#include "../src/Lista.cpp"
#include "../src/Stos.cpp"
#include "../src/Kolejka.cpp"
#include "../inc/Statystyka.hh"
#include "../src/ListaArr1.cpp"
#include "../src/ListaArr2x.cpp"
#include <ctime>

/*!
 * \brief
 * Ilośc powtórzeń danej próby
 *
 * Ilośc powtórzeń danej próby
 */
#define ILOSC_POWTORZEN 1

/*!
 * \brief
 * Ilość prób
 * 
 * Ilość prób = ilość rozmiarów prób
 */
#define ILOSC_PROB 6

int main(int argc, char *argv[]) {
  unsigned int iloscDanych[ILOSC_PROB] = {1, 10, 1000, 50000, 100000, 1000000};
  //unsigned int maxDanych = iloscDanych[ILOSC_PROB-1];
  std::string nazwaPlikuStat[3] = {"LinkLista.dat" , "ListArr1.dat", "ListArr2x.dat"};
  std::clock_t poczatek, koniec;
  double suma;
  Statystyka stat(ILOSC_PROB, iloscDanych);
  InterfejsADT<int> *I;
  Lista<int> *LL = new Lista<int>;
  ListArr1<int> *LA1 = new ListArr1<int>;
  ListArr2x<int> *LA2 = new ListArr2x<int>;

  /*if(argc == 3)
    LosujIntDoPliku(maxDanych, 10); */

  for(int j=0; j<3; j++) { 
    switch(j) {
    case 0: I = LL; break;
    case 1: I = LA1; break;
    case 2: I = LA2; break;
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
      stat[i] = (suma/ILOSC_POWTORZEN)/(double)(CLOCKS_PER_SEC / 1000);
    }
    stat.ZapiszStaty(nazwaPlikuStat[j]);
  }

  

return 0;
}
