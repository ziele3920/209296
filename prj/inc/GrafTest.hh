#ifndef GRAFTEST_HH
#define GRAFTEST_HH

/*!
 * \brief GrafTest
 *
 * Plik zawiera definicję klasy GrafTest
 */

#include "Graf.hh"
#include "Iterable.hh"

/*!
 * \brief GrafTest
 *
 * Klasa modelująca pojecie grafu z zaimplementowanymi metodami niezbędnymi
 * do przeprowadzneia testów.
 */
template < class typ >
class GrafTest : public Graf<typ>, public ITestable {

public:

  /*!
   * \brief
   * Wczytanie danych z pliku
   *
   * Wczytuje zadaną ilość danych do przetworzenia z
   * pliku o zadanej nazwie.
   * Plik musi wyglądać następująco:
   * - pierwsza dana to pierwszy wierzchołek,
   * - n-1 trójek "nowy_wierzcholek wierzcholek_krawedzi wierzcholek_krawedzi"
   * - reszta pliku to pary istniejących wierzchołków tworzących krawędzie
   *
   * \param[in] nazwaPliku - nazwa pliku z danymi
   * \param[in] n - ilość wierzchołków do wczytania
   */
  void WczytajDane(std::string const nazwaPliku, const unsigned int n) {
      std::fstream plik;
      typ wartosc, wierzcholek1, wierzcholek2;
      OtworzPlikIn(nazwaPliku.c_str(), plik);

      plik >> wartosc;
      this -> DodajWierzcholek(wartosc);

      for(size_t i = 0; i<n-1; ++i) {
          plik >> wartosc;
          this -> DodajWierzcholek(wartosc);
          plik >> wierzcholek1;
          plik >> wierzcholek2;
          this -> DodajKrawedz(wierzcholek1, wierzcholek2);
      }
      while(!plik.eof()) {
          plik >> wierzcholek1;
          plik >> wierzcholek2;
          this ->DodajKrawedz(wierzcholek1, wierzcholek2);
      }
      plik.close();
  }

  /*!
   * \brief
   * Wykonanie części obliczeniowej programu
   *
   * Metoda w której implementowana jest część obliczeniowa
   * programu, której czas wykonania zostanie zmierzony.
   *
   * \param[in] w1 - wartość początkowego wierzchołka
   * \param[in] w2 - wartość końcowego wierzchołka
   */
  void Start(const unsigned int w1, const unsigned int w2) {
      Lista<typ> sciezka;
      this->SciezkaBFS(&sciezka, this->DajWierzcholek(w1), w2);
      //this->SciezkaDFS(&sciezka, this->DajWierzcholek(w1), w2);
//      for(size_t i = 0; i < sciezka.size(); ++i)
//          std::cout << sciezka[i] << ", ";
//      std::cout << std::endl;
  }

  /*!
   * \brief Reset
   *
   * Resetuje flagi.
   */
  void Reset() {
      this ->ResetLabels();
  }

  /*!
   * \brief
   * Zwalnia pamięć po teście
   *
   * Zwalnia pamięć zajmowaną przez objekty wykorzytsane do testów
   *
   * param[in] nazwaPliku - plik z danymi
   * param[in] n - ilosc danych
   */
  void Zwolnij(std::string const nazwaPliku, const unsigned int n) {
      std::fstream plik;
      typ wartosc;

      OtworzPlikIn(nazwaPliku.c_str(), plik);
      plik >> wartosc;
      this -> UsunWierzcholek(wartosc);

      for(size_t i = 0; i<3*(n-1); ++i) {
          plik >> wartosc;
            if(i%3 == 0) {
                this -> UsunWierzcholek(wartosc);
            }

      }
      plik.close();
      //this ->zw();
  }
};

#endif
