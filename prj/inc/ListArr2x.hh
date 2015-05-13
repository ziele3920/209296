/*!
 * \file
 * \brief
 * Definicja klasy ListArr2x
 *
 * Plik zawiera definicję klasy ListaArr2x ujętej w szablon typu
 * wraz z jej składowymi metofdami.
 */

#include "InterfejsADT.hh"
#include "Iterable.hh"
#include "Pliki.hh"

/*!
 * \brief
 * Modeluje pojęcie Listy (array) 
 *
 * Modeluje pojęcie Listy opartej na dynamicznej tablicy.
 * Dodając elementy zwiększa tablicę dwukrotnie, jeżeli brakuje miejsca.
a */
template < class typ>
class ListArr2x : public InterfejsADT<typ>, Iterable<typ> {

  /*!
   * \brief
   * Wkaźnik na dynamiczną tablicę
   *
   * Wskaźnik na dynamiczną tablicę tworzącą ListęArr2x
   */
  typ *tab;

  /*!
   * \brief
   * Rozmiar tablicy
   *
   * Aktualny rozmiar tablicy.
   */
  unsigned int RozmiarT;

  /*!
   * \brief
   * Rozmiar Listy
   *
   * Aktualny rozmiar ListyArr2x
   */
  unsigned int RozmiarL;
  

  /*!
    * \brief UsunZListy
    *
    * Usuwa z listy element o podanym indeksie
    *
    * \param[in] pole - indeks elementu do usunięcia.
    */
   void UsunZListy(const unsigned int pole) {
       typ *tymczasowy = new typ[RozmiarT];
       for(size_t i = 0; i < pole; ++i)
           tymczasowy[i] = tab[i];
       for(size_t i = (pole+1); i < RozmiarL; ++i)
           tymczasowy[i-1] = tab[i];
       delete[] tab;
       tab = tymczasowy;
   }

   /*!
    * \brief DodajDoListy
    *
    * Dodaje daną do listy na określony indeks
    *
    * \param dana - wartość która ma zostać umieszczona na liście
    * \param pole - indeks pola na którym ma zostać umieszczona wartość
    */
   void DodajDoListy(const typ dana, const unsigned int pole) {
       typ *tymczasowy = new typ[RozmiarT];
       for (size_t i = 0; i < pole; ++i)
     tymczasowy[i] = tab[i];
       tymczasowy[pole] = dana;
       for (size_t i = (pole+1); i < RozmiarL; ++i)
     tymczasowy[i] = tab[i-1];
       delete[] tab;
       tab = tymczasowy;
   }

  /*!
   * \brief
   * Zamienia elmenty listy
   *
   * Zamienia dwa elementy listy o polach podanych w wywołaniu
   * \param[in] a - indeks pierwszego elementu do zamiany
   * \param[in] b - indeks drugiego elementu do zamiany
   */
void Zamien(typ &a,typ &b) {
    typ temp = a;
    a = b;
    b = temp;
  }

    /*!
     * \brief
     * Porównuje el. kopca
     *
     * Porównuje i ustawia elementy kopca w odpowiedniej kolejności
     *
     * \param[in] rozmiarKopca - rozmiar kopca który sortujemy
     * \param[in] i - numer gałęzi kopca
     */
   void Kopcuj(const int rozmiarKopca, const int i) {
    int najwiekszy;
    int lewy = 2*i+1, prawy = (2*i)+2;

    if(lewy <= rozmiarKopca && tab[lewy] > tab[i])
      najwiekszy = lewy;
    else najwiekszy = i;

    if(prawy <= rozmiarKopca && tab[prawy] > tab[najwiekszy])
      najwiekszy = prawy;

    if(najwiekszy!= i) {
	Zamien(tab[najwiekszy],tab[i]);
	Kopcuj(rozmiarKopca,najwiekszy);
      }
  }


  /*!
   * \brief
   * Tworzy kopiec
   *
   * Tworzy kopiec z tablicy o podanym rozmiarze
   *
   * \param[in] rozmiar - rozmiar tablicy 
   */
  void BudujKopiec(const int rozmiar) {
    for(int i = rozmiar/2 -1; i >= 0; --i)
      Kopcuj(rozmiar, i);
  }

  /*!
   * \brief
   * Znajduje mediane
   *
   * Znajduje mediane wartości z trzech podanych elementów Listy
   *
   * \param[in] a - indeks pierwszego elementu do liczenia mediany
   * \param[in] b - indeks drugiego elementu do liczenia mediany
   * \param[in] c - indeks trzeciego elementu do liczenia mediany
   *
   * \retval - zwraca indeks elementu będącego medianą z trzech wartości podanych elementów
   */
int MedianaTrzech(const int a, const int b, const int c) const {
  if((tab[a] <= tab[b]) && (tab[a] <= tab[c])) {
    if(tab[b] <= tab[c])  return b; 
    else return c;
  }

  if((tab[b] <= tab[a]) && (tab[b] <= tab[c])) {
    if(tab[a] <= tab[c])  return a;
    else return c;
  }
  return b;
}

  /*!
   * Partycjonowanie listy
   *
   * Metoda będąca częścią algorytmu Sortowania Szybkiego.
   * Dzieli przekazany fragment listy na dwie części - 
   * lewy z elementami mniejszymi od wybranego pivota
   * i prawa z elementami większymi od wybranego pivota.
   * Pivot jest dobierany za pomocą liczenia mediany z trzech elementów:
   * pierwszego, środkowego i ostatniego.
   *
   * \param[in] lewy - indeks pierwszego elementu z listy do posortowania
   * \param[in] prawy - indekst ostatniego elmentu z listy do posortowania
   */
  int Partition(int lewy, int prawy) {
    typ Pivot = tab[MedianaTrzech(lewy, (lewy+prawy)/2, prawy-1)];
    
    while(1) {
      while(tab[prawy] > Pivot) --prawy;
      while(tab[lewy] < Pivot) ++lewy;
      if( lewy < prawy ) {
	Zamien(tab[lewy], tab[prawy]);
	++lewy; --prawy;
      }
      else return prawy;
    }
  }
  
public:

  /*!
   * \brief
   * Konstruktor bezarumentowy
   *
   * Kontruktor alokujący tablicę jednoelementową z której będzie
   * tworzona lista
   */
  ListArr2x() {
    RozmiarT = 1;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
  }

  /*!
   * \brief
   * Dodaje element do ListyArr2x
   *
   * Dodaje nowy element do ListyArr2x
   *
   * \param[in] dana - element który chcemy umieścić na liście
   * \param[in] pole - nr pola na którym chcemy umieścić element
   *                   jeżeli chcesz umieścić na początku listy podaj
   *                   wartość 0, na końcu warość size()
   */
  void push (const typ dana, const unsigned int pole) {
    if(pole < 0 || pole > RozmiarL) {
      std::cerr << "Blad dodania elementu na ListArr2x. Bledny nr pola. Zakres poprawnych wartosci pola: 0 - " << RozmiarL << std::endl;
    }
    else if(RozmiarL == 0) {
      tab[0] = dana;
      ++RozmiarL;
    }
    else if(RozmiarL == RozmiarT) {
      ++RozmiarL; 
      RozmiarT = 2*RozmiarT;
      DodajDoListy(dana, pole);
    }
    else {
      if(pole == RozmiarL) {
        tab[RozmiarL] = dana;
        ++RozmiarL;
      }
      else {
        ++RozmiarL;
        DodajDoListy(dana, pole);
      }
    }
  }

  /*!
   * \brief
   * Pobiera element z ListyArr2x
   *
   * Pobiera element z ListyArr2x usuwając go z niej i zmniejszając rozmiar
   * o połowę w przypadku przekroczenia stosunku 1:4 (RozmiarL:RozmiarT)
   *
   * param[in] - pole - nr pola z którgo chcemy pobrać element (indeksowane od 0)
   *
   */
  void pop(const unsigned int pole) {
    if(RozmiarL == 0) {
      std::cerr << "Blad! Nie mozna usunac elementu z pustej listy!" << std::endl;
      return;
    }
    else if(pole < 0 || pole > (RozmiarL-1)) {
      std::cerr << "Blad usuwania elementu. Blednny nr pola. zakres popranwych wartosci pola: 0 - " << RozmiarL-1 << std::endl;
      return;
    }

    else { // poprawny indeks pola do usunięcia
        if(pole == (RozmiarL-1) && (4*RozmiarL >= RozmiarT)) {  // usuwa z końca
            --RozmiarL;
            return;
        }
        else {
            --RozmiarL;
            if(4*RozmiarL < RozmiarT) RozmiarT = RozmiarT/2; // stosunek < 1:4
            UsunZListy(pole);
            return;
        }
    }
    std::cout << "Blad usuniecia z listy" << std::endl;
    return;
  }

  /*!
   * \brief
   * Wielkość listy
   *
   * Informuje o ilości elementów znajdujących się na LiścieArr2x
   * 
   * \retval - zwraca liczbę elementów ListyArr2x
   */
  unsigned int size() const { return RozmiarL; } 

  /*!
   * \brief
   * Metoda do testów
   *
   * Metoda, której czas wykonanai ma zostać zmierzony
   *
   * \param[in] k - ilość elementów do wczytania
   */
  void Start(const unsigned int k) {
    //QSortOpt(0, size()-1);
    //InsertSort(0, size()-1);
    HybridSort(0, size()-1);
    //HeapSort(size()-1);
}

  /*!
   * \brief
   * Wczytuje dane z pliku
   * 
   * Wczytuje dane z pliku do ListArr2x
   *
   * param[in] nazwaPliku - nazwa pliku z danymi
   * param[in] n - ilość danych do wczytania, 0 oznacza wszystkie dane z pliku
   */
  void WczytajDane(const char *nazwaPliku, unsigned int n) {
    std::fstream plik;
    int pom;
    OtworzPlikIn(nazwaPliku, plik);
    for(int i = 0; i < (int)n; ++i) { 
      plik >> pom;
      push(pom, RozmiarL);
    }
    plik.close();
  }

  /*!
   * \brief
   * Zwalnia pamięć
   * 
   * Zwalnia pamięć zaalokowaną przez ListArr2x
   */
  void Zwolnij() { 
    delete[] tab;
    RozmiarT=1;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
  }

  /*!
   * \brief
   * Sortowanie przez kopcowanie
   *
   * Realizuje algorytm sortowania przez kopcowanie
   * 
   * \param[in] rozmiar - rozmiar tablicy do posortowania
   */
  void HeapSort(int rozmiar) {
    BudujKopiec(rozmiar);
    for(size_t i = rozmiar; i > 0; --i) {
      Zamien(tab[i], tab[0]);
	--rozmiar;
	Kopcuj(rozmiar, 0);
      }
  }
  /*!
   * \brief
   * Wyświetla elementy Listy
   * 
   * Metoda wypsuje na terminal elementy znajdujące się na liście
   */
  void Pokaz() {
    for (size_t i = 0; i < RozmiarL; ++i)
      std::cout << tab[i] << " " ;
    std::cout << std::endl;
  } 
  /*!
   * \brief
   * Zoptymalizowane Szybkie Sortowanie
   *
   * Realizuje zoptymalizowany ze względu na wybór pivota algorytm
   * szybkiego sortowania elementów Listy
   *
   * \param[in] lewy - indeks pierwszego elementu tworzącego Listę do posotrowania
   * \param[in] prawy - indeks ostatniego elementu tworzącego Listę do posotrowania
   */
void QSortOpt(const int lewy, const int prawy) {
  int nowy;
  if(lewy < prawy) {

    nowy = Partition(lewy, prawy);
    QSortOpt(lewy, nowy);
    QSortOpt(nowy+1, prawy);
  }
}


  /*!
   * \brief
   * Sortowanie przez wstawianie
   *
   * Metoda realizuje algorytm sortowania przez wstawianie.
   *
   * \param[in] pierwszyElement - indekst pierwszego elementu do posortowania
   * \param[in] ostatniElement - indeks ostatniego elementu do posortowania
   */
  void InsertSort(int pierwszyElement, int ostatniElement) {
    
    int pom, j;
    for(int i = pierwszyElement; i<=ostatniElement; ++i){
      pom = tab[i];
      for(j = i -1; j >= 0 && tab[j] > pom; --j)
	tab[j+1] = tab[j];
      tab[j+1] = pom;
    }
  }

  /*!
   * \brief
   * Sortowanie hybrydowe
   *
   * Metoda realizuje algorytm sortowania hybrydowego bazujący na 
   * zoptymalizowanym ze względu na wybór pivota (mediana z trzech)
   * algorytmowi Sortowania Szybkiego oraz jako algorytm pomocniczy
   * wykorzystane zostało sortowanie przez wstawianie.
   *
   * \param[in] lewy - indeks pierwszego elementu z listy do posortowania
   * \param[in] prawy - indeks ostatniego elementu z listy do posortowania
   */
  void HybridSort(int lewy, int prawy){
    int nowy;
    int prog = 32;
    if(lewy < prawy) {
	nowy = Partition(lewy, prawy);
	if(nowy - lewy > prog)
	  HybridSort(lewy, nowy);
	else
	  InsertSort(lewy, nowy);
	if(prawy - nowy > prog)
	  HybridSort(nowy+1, prawy);
	else
	  HybridSort(nowy+1, prawy);
      }
  }
  
  /*!
   * \brief operator []
   *
   * Przeciążenie opratora[] w celu umożliwienia przeglądania
   * zawrtości listy. Indeksujemy od 0.
   *
   * \param[in] indeks - indeks elementu, którego wartość ma zostać odczytana
   * \retval zwraca wartość znajdującą się na danym indeksie listy
   */
  typ operator[] (unsigned int indeks) {
      return tab[indeks];
  }

};

