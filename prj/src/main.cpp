/*! 
 * \file
 * \brief
 * Moduł główny programu
 *
 *
 * Program wkonuje serię 10 pomiarów czasu wykonania metody start
 * dla różncyh wielkości problemu obliczeniowego.
 * Dane do obliczeń wczytuje z pliku o nazwie podanej w pierwszym
 * argumencie wywołania programu, a statystykę pomiarów 
 * zapisuje do pliku o nazwie "statystyka.dat".
 *
 * OBSŁUGA PROGRAMU:
 * Aby wywołać program należy w lini poleceń wywołać jego nazę
 *  i jako pierwszy argument podać nazwę pliku
 * z miliardem danych w formacie int np: "./a.out dane.dat"
 * Jeżeli nie posiadamy takiego pliku to podczas wywoływania programu 
 * należe podać jako pierwszy argument nazwę pliku "dane.dat"
 * i dodatkowo jakikolwiek drugui argument, spowoduje to utworzenie 
 * pliku z danymi o nazwie "dane.dat" przed częścią obliczeniową programu.
 * Przykład wywoałania z tworzeniem pliku z danymi: "./a.out dane.dat l"
 */

#include "../src/Lista.cpp"
#include "../inc/Statystyka.hh"
#include <ctime>
#include "../inc/InterfejsADT.hh"
#include "../inc/Framework.hh"

#define ILOSC_POWTORZEN 10
#define ILOSC_PROB 5

int main(int argc, char *argv[]) {
  unsigned int iloscDanych[ILOSC_PROB] = {1, 10, 1000, 1000000, 100000000};
  //unsigned int maxDanych = iloscDanych[ILOSC_PROB-1];
  std::clock_t poczatek, koniec;
  double suma;
  InterfejsADT<int> *I;
  Statystyka stat(ILOSC_PROB, iloscDanych);
  Lista<int> *L = new Lista<int>;


  /*if(argc == 3)
    LosujIntDoPliku(maxDanych, 10);*/
  /*
  for(int i=0; i<ILOSC_PROB; i++) {
    suma = 0;
    for (int k=0; k<ILOSC_POWTORZEN; k++) {
      Lista<int> *L = new Lista<int>;
      I = L;
      poczatek = std::clock();
      I -> Start(iloscDanych[i]);
      koniec = std::clock();
      suma = suma + (koniec - poczatek);
      delete L;
    }
    stat[i] = (suma/10)/(double)(CLOCKS_PER_SEC / 1000);
  }

stat.ZapiszStaty();
  */

return 0;
}
