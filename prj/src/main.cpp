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
#define ILOSC_PROB 3

int main(int argc, char *argv[]) {

  TabAsoc TS;
  /*
  int *i;
  int k = 7;
  int *z = &k;
  i = z;
  *i = 4;
  std::cout << k << std::endl; */
 
  TS["kupa"]=5;
  std::cout << TS.operator[]("kupa") << std::endl;
  int *i;
  int *l; 
  Lista<int> L;
  L.push(7, 0);
  i = &L.RefBegin();
  l = &L.RefBegin();
  *i = 5;
  std::cout << *i << " " << *l<< std::endl; 
  /*
  unsigned int iloscDanych[ILOSC_PROB] = {10, 25000, 75000};
  std::string nazwaPlikuStat[3] = {"LinkLista.dat", "ListArr2x.dat", "ListArr1.dat"};
  Framework *I;
  Lista<int> *LL = new Lista<int>;
  ListArr1<int> *LA1 = new ListArr1<int>;
  ListArr2x<int> *LA2 = new ListArr2x<int>;
  Benchmark<int> *B = new Benchmark<int>(ILOSC_PROB, iloscDanych, ILOSC_POWTORZEN);

  for(int j=0; j<2; j++) { 
    switch(j) {
    case 0: I = LL; break;
    case 1: I = LA2; break;
    case 2: I = LA1; break;
    default: std::cerr << "Brak przypisania wkaznika" << std::endl;
    }
    B -> Test(I, nazwaPlikuStat[j]);
    } */
return 0;
}
