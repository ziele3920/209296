/*!
* \file
* \brief
* Definicja klasy ListArr1
*
* Plik zawiera definicję klasy ListaArr2x ujętej w szablon typu
* wraz z jej składowymi metofdami.
*/
#include "InterfejsADT.hh"
/*!
* \brief
* Modeluje pojęcie Listy (array)
*
* Modeluje pojęcie Listy opartej na dynamicznej tablicy.
* Dodając elementy zwiększa tablicę dwukrotnie, jeżeli brakuje miejsca.
a */
template < class typ>
class ListArr2x : public InterfejsADT<typ>, public Iterable<typ> {
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


public:
/*!
* \brief
* Konstruktor bezarumentowy
*
* Kontruktor alokujący tablicę jednoelementową z której będzie
* tworzona lista
*/
  ListArr2x() {
    RozmiarT = 20;
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
* Informuje o ilości elementów znajdujących się na LiścieArr1
*
* \retval - zwraca liczbę elementów ListyArr1
*/
  unsigned int size() const { return RozmiarL; }

/*!
* \brief
* Zwalnia pamięć
*
* Zwalnia pamięć zaalokowaną przez ListArr2x
*/
  void Zwolnij() {
    delete[] tab;
    RozmiarT=20;
    tab = new typ[RozmiarT];
    RozmiarL = 0;
  }
  /*!
   * \brief operator []
   *
   * Przeciążenie operatora [] w celu umożliwienia przeglądania listy
   * \param[in] i - indeks elementu
   * \retval - zwraca wartośc znajdującą się na danym indeksie
   */
  typ operator[] (unsigned int i) {
    return tab[i];
  }



};
