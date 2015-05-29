#ifndef DRZEWOAVL_HH
#define DRZEWOAVL_HH

/*!
 * \brief Definicja drzewa AVL
 *
 * Pik zawiera definicję drzewa AVL.
 */

#include "IDrzew.hh"
#include "WezelAVL.hh"

/*!
 * \brief The DrzewoAVL class
 *
 * Klasa modeluje poęcie dzewa AVL.
 */
template < class typ >
class DrzewoAVL : public IDrzew<typ>{

    /*!
     * \brief Korzeń drzewa
     *
     * Wskaźnik na węzeł będący korzeniem drzewa binarnego.
     */
    WezelAVL<typ> *Korzen;

    /*!
     * \brief Liczba Węzłów
     *
     * Ilość węzłów w drzewie.
     */
    int LiczbaWezlow;

    /*!
     * \brief FindMin
     *
     * Szuka węzła o nejmniejeszej wartości, począwszy od
     * węzła podanego w arunemcie.
     *
     * \param[in] poszukiwacz - węzeł startowy poszukwiań
     * \retval - wskaźnik na węzeł przechowujący najmniejszą wartość
     */
    WezelAVL<typ>* FindMin(WezelAVL<typ> *poszukiwacz) {
        while(poszukiwacz -> Lewy != NULL)
            poszukiwacz = poszukiwacz -> Lewy;
        return poszukiwacz;
    }

    /*!
     * \brief FindSuccessor
     *
     * Szuka poprzednika węzła podanego w artumencje wywołania.
     * \param[in] poszukiwacz - węzeł którego poprzednik ma zostać znaleziony
     *
     * \retval wskaźnik na węzeł będący poprzednikiem
     */
    WezelAVL<typ>* FindSuccessor(WezelAVL<typ> *poszukiwacz) {
        if(poszukiwacz -> Prawy != NULL)
            return FindMin(poszukiwacz -> Prawy);

        WezelAVL<typ> *tymczasowyWezel = poszukiwacz -> Rodzic;
        while((tymczasowyWezel != NULL) && (tymczasowyWezel -> Lewy != poszukiwacz)) {
            poszukiwacz = tymczasowyWezel;
            tymczasowyWezel = tymczasowyWezel -> Rodzic;
        }
        return tymczasowyWezel;
    }

    /*!
     * \brief Rotacja RR
     *
     * Metoda wykonuje rotację prawą, gdzie A jest węzłem głównym
     * rotacji.
     * \param[in] A - wskaźnik do węzła głównego rotacji
     */
    void RR(WezelAVL<typ> *A) {
        WezelAVL<typ> *B = A->Prawy, *pom = A->Rodzic;

        A->Prawy = B->Lewy;
        if(A->Prawy)
            A->Prawy->Rodzic = A;

        B->Lewy = A;
        B->Rodzic = pom;
        A->Rodzic = B;

        if(pom) {
            if(pom->Lewy == A)
                pom->Lewy = B;
            else
                pom->Prawy = B;
        }
        else Korzen = B;

        if(B->WspRownowagi == -1)
            A->WspRownowagi = B->WspRownowagi = 0;
        else {
            A->WspRownowagi = -1;
            B->WspRownowagi = 1;
        }
    }

    /*!
     * \brief Rotacja LL
     *
     * Metoda wykonuje rotację lewą, gdzie A jest węzłem głównym
     * rotacji.
     * \param[in] A - wskaźnik do węzła głównego rotacji
     */
    void LL(WezelAVL<typ> * A) {
      WezelAVL<typ> * B = A->Lewy, * pom = A->Rodzic;

      A->Lewy = B->Prawy;
      if(A->Lewy) A->Lewy->Rodzic = A;

      B->Prawy = A;
      B->Rodzic = pom;
      A->Rodzic = B;

      if(pom) {
        if(pom->Lewy == A)
            pom->Lewy = B;
        else
            pom->Prawy = B;
      }
      else Korzen = B;

      if(B->WspRownowagi == 1)
          A->WspRownowagi = B->WspRownowagi = 0;
      else {
        A->WspRownowagi = 1; B->WspRownowagi = -1;
      }
    }

    /*!
     * \brief Rotacja RL
     *
     * Metoda wykonuje rotację prawą i lewą, gdzie A jest węzłem głównym
     * rotacji.
     * \param[in] A - wskaźnik do węzła głównego rotacji
     */
    void RL(WezelAVL<typ> * A) {
      WezelAVL<typ> * B = A->Prawy, * C = B->Lewy, * pom  = A->Rodzic;

      B->Lewy = C->Prawy;
      if(B->Lewy)
          B->Lewy->Rodzic = B;

      A->Prawy = C->Lewy;
      if(A->Prawy)
          A->Prawy->Rodzic = A;

      C->Lewy = A;
      C->Prawy = B;
      A->Rodzic = B->Rodzic = C;
      C->Rodzic = pom;

      if(pom) {
        if(pom->Lewy == A)
            pom->Lewy = C;
        else
            pom->Prawy = C;
      }
      else Korzen = C;

      if(C->WspRownowagi == -1)
          A->WspRownowagi =  1;
      else A->WspRownowagi = 0;
      if(C->WspRownowagi ==  1)
          B->WspRownowagi = -1;
      else B->WspRownowagi = 0;

      C->WspRownowagi = 0;
    }


    /*!
     * \brief Rotacja LR
     *
     * Metoda wykonuje rotację lewą i prawą, gdzie A jest węzłem głównym
     * rotacji.
     * \param[in] A - wskaźnik do węzła głównego rotacji
     */
    void LR(WezelAVL<typ> * A) {
      WezelAVL<typ> * B = A->Lewy, * C = B->Prawy, * pom = A->Rodzic;

      B->Prawy = C->Lewy;
      if(B->Prawy)
          B->Prawy->Rodzic = B;

      A->Lewy = C->Prawy;
      if(A->Lewy)
          A->Lewy->Rodzic = A;

      C->Prawy = A;
      C->Lewy = B;
      A->Rodzic = B->Rodzic = C;
      C->Rodzic = pom;

      if(pom) {
        if(pom->Lewy == A)
            pom->Lewy = C;
        else
            pom->Prawy = C;
      }
      else Korzen = C;

      if(C->WspRownowagi ==  1)
          A->WspRownowagi = -1;
      else A->WspRownowagi = 0;
      if(C->WspRownowagi == -1)
          B->WspRownowagi =  1;
      else B->WspRownowagi = 0;

      C->WspRownowagi = 0;
    }

    /*!
     * \brief Czyści drzewo
     *
     * Usuwa wszystkie węzły i zwalnia po nich pamięć leżące
     * poniżej węzła podanego w argumecie (z nim włącznie)
     *
     * \param wezel - węzeł od którego zaczyna się czyszczenie
     */
    void Czysc(WezelAVL<typ> *wezel) {
        if(wezel != NULL) {
          Czysc(wezel ->Lewy);
          Czysc(wezel ->Prawy);
          delete wezel;
        }
    }

public:

    /*!
     * \brief Konstruktor bezarumentowy
     *
     * Konstrunkto bezargumentowy zeruje liczbę węzłów i ustawia
     * Korzen na NULL.
     */
    DrzewoAVL() {
      Korzen = NULL;
      LiczbaWezlow = 0;
    }

    /*!
     * \brief
     * Destruktor
     *
     * Destruktor zwalnia pamięć usuwając wszystkie węzły drzewa.
     */
    ~DrzewoAVL() {
       Czysc(Korzen);
    }

    /*!
     * \brief Insert
     *
     * Dodaje nową daną (węzeł) do struktury drzewa.
     *
     * \param[in] wartosc - dana do dodania
     */
    void Insert(typ wartosc) {

        WezelAVL<typ> *nowyWezel = new WezelAVL<typ>;
        nowyWezel-> Dana = wartosc;
        WezelAVL<typ> *rodzicNowego = NULL;
        WezelAVL<typ> *poszukiwacz = Korzen;

        while (poszukiwacz != NULL) {
          rodzicNowego = poszukiwacz;
          if (poszukiwacz -> Dana > wartosc)
              poszukiwacz = poszukiwacz -> Lewy;
          else if(poszukiwacz -> Dana < wartosc)
              poszukiwacz = poszukiwacz -> Prawy;
          else
              return;
        }

        nowyWezel -> Rodzic = rodzicNowego;

        if (rodzicNowego == NULL)
            Korzen = nowyWezel;
        else if(nowyWezel-> Dana < rodzicNowego -> Dana)
            rodzicNowego -> Lewy = nowyWezel;
        else
            rodzicNowego -> Prawy = nowyWezel;

        ++LiczbaWezlow;

        if(LiczbaWezlow == 1) return;

         WezelAVL<typ> *r;
         bool t;

        if(rodzicNowego->WspRownowagi != 0)
            rodzicNowego->WspRownowagi = 0;
        else {
          if(rodzicNowego->Lewy == nowyWezel)
            rodzicNowego->WspRownowagi = 1;
          else
            rodzicNowego->WspRownowagi = -1;
          r = rodzicNowego->Rodzic;
          t = false;

          while(r) {
            if(r->WspRownowagi) {
              t = true;
              break;
            };

            if(r->Lewy == rodzicNowego) r->WspRownowagi =  1;
            else
                r->WspRownowagi = -1;
            rodzicNowego = r;
            r = r->Rodzic;
          }

          if(t != 0) {
            if(r->WspRownowagi == 1) {
              if(r->Prawy == rodzicNowego) r->WspRownowagi = 0;
              else if(rodzicNowego->WspRownowagi == -1) LR(r);
              else LL(r);
            }
            else {              // r.WspRownowagi = -1
              if(r->Lewy == rodzicNowego) r->WspRownowagi = 0;
              else if(rodzicNowego->WspRownowagi == 1) RL(r);
              else RR(r);
            }
          }
        }
    }

    /*!
     * \brief Remove
     *
     * Usuwa węzeł przechowujący daną wartość.
     *
     * \param[in] wartosc - przechowywana wartość do usunuęcia z drzewa
     */
    void Remove(typ wartosc) {
        WezelAVL<typ>  *x, *y, *poprzednik;
        WezelAVL<typ> *usuwany = Search(wartosc);

        bool zagniezdzenie;

        if(usuwany->Lewy && usuwany->Prawy) {
          poprzednik = FindSuccessor(usuwany);
          zagniezdzenie = false;
        }
        else {
          if(usuwany->Lewy) {
            poprzednik = usuwany->Lewy;
            usuwany->Lewy = NULL;
          }
          else {
            poprzednik = usuwany->Prawy;
            usuwany->Prawy = NULL;
          }
          usuwany->WspRownowagi = 0;
          zagniezdzenie  = true;
        }

        if(poprzednik) {
          poprzednik->Rodzic = usuwany->Rodzic;
          poprzednik->Lewy = usuwany->Lewy;
          if(poprzednik->Lewy)
              poprzednik->Lewy->Rodzic  = poprzednik;
          poprzednik->Prawy = usuwany->Prawy;
          if(poprzednik->Prawy)
              poprzednik->Prawy->Rodzic = poprzednik;
          poprzednik->WspRownowagi = usuwany->WspRownowagi;
        }

        if(usuwany->Rodzic) {
          if(usuwany->Rodzic->Lewy == usuwany)
              usuwany->Rodzic->Lewy = poprzednik;
          else
              usuwany->Rodzic->Prawy = poprzednik;
        }
        else Korzen = poprzednik;

        if(zagniezdzenie) {
          y = poprzednik;
          poprzednik = usuwany->Rodzic;
          while(poprzednik) {
            if(!poprzednik->WspRownowagi) {
              if(poprzednik->Lewy == y)
                  poprzednik->WspRownowagi = -1;
              else
                  poprzednik->WspRownowagi = 1;
              break;
            }
            else {
              if(((poprzednik->WspRownowagi == 1) && (poprzednik->Lewy == y)) || ((poprzednik->WspRownowagi == -1) && (poprzednik->Prawy == y))) {
                poprzednik->WspRownowagi = 0;
                y = poprzednik; poprzednik = poprzednik->Rodzic;
              }
              else {
                if(poprzednik->Lewy == y)
                    x = poprzednik->Prawy;
                else x = poprzednik->Lewy;
                if(!x->WspRownowagi) {
                  if(poprzednik->WspRownowagi == 1)
                      LL(poprzednik);
                  else RR(poprzednik);
                  break;
                }
                else if(poprzednik->WspRownowagi == x->WspRownowagi) {
                  if(poprzednik->WspRownowagi == 1) LL(poprzednik); else RR(poprzednik);
                  y = x; poprzednik = x->Rodzic;
                }
                else {
                  if(poprzednik->WspRownowagi == 1) LR(poprzednik); else RL(poprzednik);
                  y = poprzednik->Rodzic; poprzednik = y->Rodzic;
                }
              }
            }
          }
        }
    }


    /*!
     * \brief Search
     *
     * Wyszukuje i zwraca daną wartość z drzewa.
     * W przypadku braku jej w drzewie
     * i zwraca NULL
     *
     * \param[in] wartosc - wartość do znalezienia w drzewie
     *
     * \retval - odnaleziona wartość / NULL gdy brak wartości
     */
    WezelAVL<typ>* Search(typ wartosc) {
        WezelAVL<typ> *poszukiwacz = Korzen;

        while((poszukiwacz != NULL) && (poszukiwacz -> Dana != wartosc)) {
            if(wartosc < poszukiwacz -> Dana)
                poszukiwacz = poszukiwacz -> Lewy;
            else
                poszukiwacz = poszukiwacz -> Prawy;
        }
        return poszukiwacz;
    }

    /*!
     * \brief CzyscDrzewo
     *
     * Usuwa wszystkie węzły drzewa, walnia po nich pamięć,
     * następnie ustawia korzeń na NULL i Liczbę węzłów na 0.
     */
    void CzyscDrzewo() {
        Czysc(Korzen);
        Korzen = NULL;
        LiczbaWezlow = 0;
    }
};

#endif
