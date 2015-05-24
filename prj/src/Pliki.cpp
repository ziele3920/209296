/*!
 * \file
 * \brief
 * Definicje funkcji obslugi plikow
 *
 * Plik zawiera definicje funkcji zwiazanych z obsluga plikow.
 */

#include "../inc/Pliki.hh"

void OtworzPlikIn(const char *nazwaPliku, std::fstream &plik) {
  plik.open(nazwaPliku, std::ios::in);
  if (!plik.good()) {
    std::cerr << "Blad otwarcia pliku: " << nazwaPliku << std::endl;
    exit (-1);
  }
}

void OtworzPlikOut(const char *nazwaPliku, std::fstream &plik) {
  plik.open(nazwaPliku, std::ios::out|std::ios::trunc);
  if(!plik.good()) {
    std::cerr << "Blad utworzenia pliku: " << nazwaPliku << std::endl;
    exit(-1);
  }
}

void LosujIntDoPliku(const unsigned int n, const unsigned int zakres) {

  std::fstream plik;
  srand(time(NULL));

  plik.open("dane.dat", std::ios::out|std::ios::trunc);
  if (plik.good()) {
    for(unsigned int i=0; i<n; i++)
      plik << rand()%zakres+1 << " ";
    plik.close();
  }
  else {
    std::cerr << "Blad utworzenia pliku!" << std::endl;
    exit (-5);
  }
}

//void LosujGrafIntDoPliku(const unsigned int w, const unsigned int e, const unsigned int zakres) {
//    std::fstream plik;
//    srand(time(NULL));
//    bool *czyWierzcholek = new bool[zakres];
//    int wierzcholek, w1, w2;

//    for(size_t k = 0; k < zakres; ++k)
//        czyWierzcholek[k] = false;

//    OtworzPlikOut("graf.dat", plik);
//    for(size_t i = 0; i < w; ++i) {
//        wierzcholek = rand()%zakres;
//        plik << wierzcholek << " ";
//        czyWierzcholek[wierzcholek] = true;
//    }
//    for(size_t j = 0; j < e; ++j) {
//        do {
//            w1 = rand()%zakres;
//        } while(czyWierzcholek[w1] == false);

//        do {
//            w2 = rand()%zakres;
//        } while(czyWierzcholek[w2] == false || w1 == w2);
//        plik << w1 << " " << w2 << " ";
//    }
//    plik.close();
//}

void LosujGrafIntDoPliku(const unsigned int w, const unsigned int e, const unsigned int zakres) {
    std::fstream plik;
    srand(time(NULL));
    bool *czyWierzcholek = new bool[zakres];
    Lista<int> wierzcholki;
    int wierzcholek, w1, w2;

    for(size_t k = 0; k < zakres; ++k)
        czyWierzcholek[k] = false;

    OtworzPlikOut("graf.dat", plik);

    wierzcholek = rand()%zakres;
    plik << wierzcholek << " ";
    czyWierzcholek[wierzcholek] = true;
    wierzcholki.push(wierzcholek, 0);

    for(size_t i = 0; i < w-1; ++i) {
        do {
            wierzcholek = rand()%zakres;
        }while (czyWierzcholek[wierzcholek] == true);
        plik << wierzcholek << " ";
        czyWierzcholek[wierzcholek] = true;
        plik << wierzcholek << " " << wierzcholki[rand()%wierzcholki.size()] << " ";
        wierzcholki.push(wierzcholek, 0);
    }

    for(size_t j = 0; j < e-w; ++j) {
        do {
            w1 = rand()%zakres;
        } while(czyWierzcholek[w1] == false);

        do {
            w2 = rand()%zakres;
         } while(czyWierzcholek[w2] == false || w1 == w2);
         plik << w1 << " " << w2 << " ";
    }
    plik.close();

}
      

