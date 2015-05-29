/*!
 * \file
 * \brief
 * Funkcje obslugi plikow
 *
 * Plik zawiera deklaracje funkcji zwiazanych z obsuga plikow
 */
#ifndef PLIKI_HH
#define PLIKI_HH
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Lista.hh"

/*!
 * \brief
 * Otwiera plik do odczytu
 *
 * Otwiera plik i sprawdza czy otwarcie sie powiodlo
 * jezeli nie to koczy program
 *
 * \param[in] nazwaPliku - nazwa pliku ktory chcemy otworzyc
 * \param[in] plik - strumien powiazany z plikiem
 */
void OtworzPlikIn(const char *nazwaPliku, std::fstream &plik);

/*!
 * \brief
 * Otwiera plik do zapisu czysząc jego zawartość
 *
 * Otwiera plik i sprawdza czy otwarcie sie powiodlo
 * jezeli nie to koczy program
 *
 * \param[in] nazwaPliku - nazwa pliku ktory chcemy otworzyc
 * \param[in] plik - strumien powiazany z plikiem
 */
void OtworzPlikOut(const char *nazwaPliku, std::fstream &plik);

/*!
 * \brief
 * Zapisuje n losowych liczb(int) do pliku
 *
 * Losuje n liczb z zakresu od 1 do podonago przez użytwkonika
 * następnie zapisuje wylosowane dane do pliku o nazwe "dane.dat"
 *
 * \param[in] n - ilość liczb do zapisania
 * \param[in] zakres - górny zakres wartości liczb
 */
void LosujIntDoPliku(const unsigned int n, const unsigned int zakres);

/*!
 * \brief LosujGrafIntDoPliku
 *
 * Generuje plik zawierający losowo wygenerowane, niepowtarzające się
 * wierzchołki i krawędzie(mogące się powtarzać) tworzące spójny graf.
 * Wierzchołki są reprezentowane przez liczby typu całkowitoliczbowego.
 *
 * Schemat pliku:
 *
 * "pierwszy_wierzchołek nowy_wierzchołek nowy_wierzchołekTK wierzcholekTK"
 *
 * gdzie trójki (nie licząc pierwszego_wierzchołka) powtarzają się tyle razy ile
 * ma być wierzchołków pomniejszonych o 1. , gdzie zaimek TK oznacza
 * wierzchołek z grupy wcześniej wygenerowanych wierzchołków do którego zaczepiony
 * zostaje koniec krawędzi między (nowy_wierzcholekTK i wierzcholekTK).
 * Reszte pliku stanowią pary wierzchołków tworzące nowe krawędzie.
 *
 *  Ilość krawędzi musi być większa lub równa ilości wierzchołków.
 *
 * \param w - zadana ilość wierzchołków grafu
 * \param e - zadana ilość grawędzi
 * \param zakres - zakres liczb wartości wierzchołków
 */
void LosujGrafIntDoPliku(const unsigned int w, const unsigned int e, const unsigned int zakres);

#endif
