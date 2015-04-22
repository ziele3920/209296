/*!
 * \file
 * \brief
 * Definicja klasy ListArr1
 *
 * Plik zawiera definicję klasy ListaArr2x ujętej w szablon typu
 * wraz z jej składowymi metofdami.
 */

#include "InterfejsADT.hh"
#include "Pliki.hh"

/*!
 * \brief
 * Modeluje pojęcie Listy (array) 
 *
 * Modeluje pojęcie Listy opartej na dynamicznej tablicy.
 * Dodając elementy zwiększa tablicę dwukrotnie, jeżeli brakuje miejsca.
a */
template < class typ>
class ListArr2x : public InterfejsADT<typ> {

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
   * \brief
   * Zamienia elmenty pablicy
   *
   * Zamienia dwa elementy tablicy o polach podanych w wywołaniu
   * \param[in] a - indeks pierwszego elementu do zamiany
   * \param[in] b - indeks drugiego elementu do zamiany
   */
  /*  void Zamien(int a, int b) {
    int pom;
    pom = tab[a];
    tab[a] = tab[b];
    tab[b] = pom;
    }*/

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
     * \param[in] rozmairKopca - rozmiar kopca który sortujemy
     */
   void Kopcuj(const int Rozmiar, const int i) {
    int najwiekszy;
    int lewy = 2*i+1, prawy = (2*i)+2;

    if(lewy <= Rozmiar && tab[lewy] > tab[i])
      najwiekszy = lewy;
    else najwiekszy = i;

    if(prawy <= Rozmiar && tab[prawy] > tab[najwiekszy])
      najwiekszy = prawy;

    if(najwiekszy!= i) {
	Zamien(tab[najwiekszy],tab[i]);
	Kopcuj(Rozmiar,najwiekszy);
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
  /* void BudujKopiec(const int rozmiar) {
    for(int i = rozmiar/2-1; i >= 0; --i)
      Kopcuj(rozmiar, i);
      }*/
  void BudujKopiec(const int rozmiar) {
    for(int i = rozmiar/2 -1; i >= 0; --i)
      Kopcuj(rozmiar, i);
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
   * Dodaje element do ListyArr1
   *
   * Dodaje nowy element do ListyArr1
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
      typ *tymczasowy = new typ[RozmiarT];
      for (unsigned int i = 0; i < pole; ++i)
	tymczasowy[i] = tab[i];
      tymczasowy[pole] = dana;
      for (unsigned int i = (pole+1); i < RozmiarL; ++i)
	tymczasowy[i] = tab[i-1];
      delete[] tab;
      tab = tymczasowy;
    }
    else {
      if(pole == RozmiarL) {
	tab[RozmiarL] = dana;
	++RozmiarL;
      }
      else {
	++RozmiarL;
	typ *tymczasowy = new typ[RozmiarT];
	for(size_t i = 0; i < pole; ++i)
	  tymczasowy[i] = tab[i];
	tymczasowy[pole] = tab[pole];
	for(size_t i = (pole+1); i < RozmiarL; ++i)
	  tymczasowy[i] = tab[i-1];
	delete[] tab;
	tab = tymczasowy;
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
   * retval - zwraca wartosc pobranej danej lub '-1' w przyadku bledu
   */
  typ pop(const unsigned int pole) {
    if(RozmiarL == 0) {
      std::cerr << "Blad! Nie mozna pobrac elementu z pustej listy!" << std::endl;
      return -1;
    }
    else if(pole < 0 || pole > (RozmiarL-1)) {
      std::cerr << "Blad pobrania elementu. Blednny nr pola. zakres popranwych wartosci pola: 0 - " << RozmiarL-1 << std::endl;
      return -1;
    }
    else if(4*RozmiarL >= RozmiarT ) {
      if(pole == (RozmiarL-1)) {
	--RozmiarL;
	return tab[RozmiarL];
      }
      else {
	--RozmiarL;
	typ *tymczasowy = new typ[RozmiarT];
	typ wartosc = tab[pole];
	for(size_t i = 0; i < pole; ++i)
	  tymczasowy[i] = tab[i];
	for(size_t i = (pole+1); i < RozmiarL; ++i)
	  tymczasowy[i-1] = tab[i];
	delete[] tab;
	tab = tymczasowy;
	return wartosc;
      }
    }
    else {           // stosunek < 1:4
      --RozmiarL;
      RozmiarT = RozmiarT/2;
      typ *tymczasowy = new typ[RozmiarT];
      typ wartosc = tab[pole];
      for(size_t i = 0; i < pole; ++i)
	tymczasowy[i] = tab[i];
      for(size_t i = pole; i < RozmiarL; ++i)
	tymczasowy[i] = tab[i+1];
      return wartosc;
    }
    std::cout << "Blad usuniecia z listy" << std::endl;
    return -1;
  }

  /*!
   * \brief
   * Wielkość listy
   *
   * Informuje o ilości elementów znajdujących się na LiścieArr1
   * 
   * \retval - zwraca liczbę elementów ListyArr1
   */
  unsigned int size() const { return RozmiarL; } 

  /*!
   * \brief
   * Metoda testująca czas
   *
   * Metoda testująca czas wczytania n elementów na ListęArr1
   *
   * \param[in] k - ilość elementów do wczytania
   */
  void Start(const unsigned int k) {
    HeapSort(size()-1);
}

  /*!
   * \brief
   * Wczytuje dane z pliku
   * 
   * Wczytuje dane z pliku do ListArr1
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
   * Zwalnia pamięć zaalokowaną przez ListArr1
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

};

