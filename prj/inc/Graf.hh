#ifndef GRAF_HH
#define GRAF_HH

/*!
 * \brief Graf
 *
 * Plik zawira definicję klasy graf
 */
#include "Krawedz.hh"


/*!
 * \brief The Graf class
 *
 * Klasa modeluje poęcie Grafu.
 */
template < class typ >
class Graf {

    /*!
   * \brief ListaWierzcholkow
   *
   * Pole przechowuje listę wskaźników na wierzchołki grafu.
   */
  Lista< Wierzcholek<typ>* > ListaWierzcholkow;

  /*!
   * \brief ListaKrawedzi
   *
   * Pole przechowuje listę wsaźników na krawędzi grafu.
   */
  Lista< Krawedz<typ>* > ListaKrawedzi;

  bool znaleziono = false;


  /*!
   * \brief PrzeciwnyW
   *
   * Metoda zwraca przeciwny Wierzcholek do wierzchołka w
   * względem krawędzi k.
   *
   * \param w - wskaźnik na wierzchołek do którego szukany
   *            jest przeciwny
   * \param k - wskaźnik na krawędź która łączy wierzchołki
   * \retval - zwraca wskaźnik na przeciwległy wierzchołek
   */
  Wierzcholek<typ>* PrzeciwnyW(Wierzcholek<typ> *w, Krawedz<typ> *k) {
      if(k->WierzcholekLewy != w)
          return k->WierzcholekLewy;
      return k->WierzcholekPrawy;
  }

  void SetLabelW(Wierzcholek<typ> *w, status stat) {
      w->Label = stat;
  }

  void SetLabelE(Krawedz<typ> *e, status stat) {
      e->Label = stat;
  }

  status GetLabelW(Wierzcholek<typ> *w) {
      return w->Label;
  }

  status GetLabelE(Krawedz<typ> *e) {
      return e->Label;
  }

public:

  /*!
   * \brief DajWierzcholek
   *
   * Szuka wierzchołka przechowującego daną wartość i
   * zwraca wskaźnik na niego.
   *
   * \param wartosc - wartośc przechowywana przez
   *                  szukany wierzcholek
   * \retval - wskaźnik na wierzchołek lub null w przypakdu nie znalezienia
   */
  Wierzcholek<typ>* DajWierzcholek(const typ wartosc) const {
      Wierzcholek<typ> *wierzcholek;
      for(size_t i = 0; i < (ListaWierzcholkow.size()); ++i) {
          wierzcholek = ListaWierzcholkow[i];
          if(wierzcholek -> Dana == wartosc)
              return wierzcholek;
      }
      std::cerr << "Blad! Nie znaleziono wierzcholka o wartosci " << wartosc << std::endl;
      return NULL;
  }

  /*!
   * \brief DodajWierzcholek
   *
   * Dodaje wierzchołek przechowujący daną wartośc do grafu
   *
   * \param wartosc - wartośc jaka przechowuje nowy wierzchołek
   */
  void DodajWierzcholek(const typ wartosc) {
    Wierzcholek<typ> *nowy = new Wierzcholek<typ>;
    nowy -> Dana = wartosc;
    ListaWierzcholkow.push(nowy, ListaWierzcholkow.size());
  }

  void DodajKrawedz(const typ v, const typ w) {
    Wierzcholek<typ> *w1, *w2;
    w1 = DajWierzcholek(v);
    w2 = DajWierzcholek(w);
    if(w1 == NULL || w2 == NULL) {
        std::cerr << "Blad dodawnia krawedzi, nie znaleziono wierzcholka" << std::endl;
    }
    Krawedz<typ> *nowa = new Krawedz<typ>;
    nowa -> WierzcholekLewy = w1;
    nowa -> WierzcholekPrawy = w2;
    w1 -> ListaKrawedziV.push(nowa, w1->ListaKrawedziV.size());
    w2 -> ListaKrawedziV.push(nowa, w2->ListaKrawedziV.size());
    ListaKrawedzi.push(nowa, ListaKrawedzi.size());
  }


  void UsunWierzcholek(typ wartosc) {
      Wierzcholek<typ> *w = DajWierzcholek(wartosc);
      if(w == NULL) {
          std::cerr << "Blad usuniecia wierzcholka - brak szukanego wierzcholka" << std::endl;
          return;
      }
      for(size_t i = 0; i<w->ListaKrawedziV.size(); ++i)
          ListaKrawedzi.Remove(w->ListaKrawedziV[i]);
      ListaWierzcholkow.Remove(w);
      delete w;
  }


  void ResetLabels() {
      for(size_t  i = 0; i < ListaWierzcholkow.size(); ++i)
          SetLabelW(ListaWierzcholkow[i], nieodwiedzony);
      for(size_t j = 0; j < ListaKrawedzi.size(); ++j)
          SetLabelE(ListaKrawedzi[j], nieodwiedzony);
  }

  void SciezkaDFS(Lista<typ> *sciezka, Wierzcholek<typ> *poczatkowyW, const typ koncowyW) {
      if(znaleziono) return;
      Wierzcholek<typ> *aktualnyW = poczatkowyW;
      Wierzcholek<typ> *pomocniczyW;
      Krawedz<typ> *aktualnaK;

      SetLabelW(aktualnyW, odwiedzony);
      sciezka -> push(aktualnyW->Dana, sciezka -> size());
      if(poczatkowyW->Dana == koncowyW) {
          znaleziono = true;
          return;
      }

      for(size_t i = 0; i < aktualnyW ->ListaKrawedziV.size(); ++i) {
          aktualnaK = aktualnyW ->ListaKrawedziV[i];
          if (GetLabelE(aktualnaK) == nieodwiedzony) {
              pomocniczyW = PrzeciwnyW(aktualnyW, aktualnaK);
              if(GetLabelW(pomocniczyW) == nieodwiedzony) {
                  SetLabelE(aktualnaK, odwiedzony);
                  SciezkaDFS(sciezka, pomocniczyW, koncowyW);
              }
              else
                  SetLabelE(aktualnaK, powrotny);
          }
      }
      if(!znaleziono)
        sciezka->Remove(aktualnyW->Dana);

  }


  void SciezkaBFS(Lista<typ> *sciezka, Wierzcholek<typ> *poczatkowyW, const typ koncowyW) {
      Krawedz<typ> *aktualnaK;
      Wierzcholek<typ> *aktualnyW, *pomocniczyW;
      int i = 0;
      Lista< Wierzcholek<typ>* > *L = new Lista< Wierzcholek<typ> *>[ListaWierzcholkow.size()];
      int *poprzednik = new int[100];

      bool odnaleziona = false;

      if(poczatkowyW->Dana == koncowyW) {
          sciezka->push(poczatkowyW->Dana, 0);
          return;
      }

      aktualnyW = poczatkowyW;
      poprzednik[aktualnyW->Dana] = -1;
      L[i].push(aktualnyW, L[i].size());
      SetLabelW(aktualnyW, odwiedzony);

      while(L[i].size() != 0) {
          for(size_t j = 0; j < L[i].size(); ++j) {
              aktualnyW = L[i][j];
              for(size_t k = 0; k < aktualnyW->ListaKrawedziV.size(); ++k) {
                  aktualnaK = aktualnyW->ListaKrawedziV[k];
                  if(GetLabelE(aktualnaK) == nieodwiedzony)
                      pomocniczyW = PrzeciwnyW(aktualnyW, aktualnaK);
                  if(GetLabelW(pomocniczyW) == nieodwiedzony) {
                      poprzednik[pomocniczyW->Dana] = aktualnyW->Dana;
                      SetLabelE(aktualnaK, odwiedzony);
                      SetLabelW(pomocniczyW, odwiedzony);
                      L[i+1].push(pomocniczyW, L[i+1].size());
                      if(pomocniczyW->Dana == koncowyW) {
                          k = aktualnyW->ListaKrawedziV.size();
                          j = L[i].size();
                          odnaleziona = true;
                      }
                  }
                  else
                      SetLabelE(aktualnaK, poprzeczny);
              }
          }
          if(odnaleziona) break;
          ++i;
      }
      int z = pomocniczyW -> Dana;
      while (z != -1) {
          sciezka->push(z, 0);
          z = poprzednik[z];

      }
  }

};


#endif
