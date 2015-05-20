#ifndef DRZEWOBINARNETEST_HH
#define DRZEWOBINARNETEST_HH

/*!
 * \brief Drzewo binarne testowalne
 *
 * Plik zawiera implemementację testowalnego drzewa binarnego.
 */

#include "DrzewoBinarne.hh"
#include "Pliki.hh"

/*!
 * \brief The DrzewoBinaneTest class
 *
 * Drzewo binarne z zaimplemetowanym interfejejsem do testów.
 */
template < class typ >
class DrzewoBinarneTest : public DrzewoBinarne<typ>, public ITestable {
public:


    /*!
     * \brief
     * Wczytanie danych z pliku
     *
     * Wczytuje zadaną ilość danych do przetworzenia z
     * pliku o zadanej nazwie.
     *
     * \param[in] nazwaPliku - nazwa pliku z danymi
     * \param[in] n - ilość danych do wczytania
     */
    void WczytajDane(std::string const nazwaPliku, unsigned int n) {
        std::fstream plik;
        typ tmp;
        OtworzPlikIn(nazwaPliku.c_str(), plik);
        for(size_t i = 0; i<n; ++i) {
            plik >> tmp;
            this -> Insert(tmp);
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
     * \param[in] k - ilość elementów dla których mają zostać wykonane obliczenia.
     * \param[in] nazwaPliku - nazwa pliku z danymi
     */
    void Start(const unsigned int k, std::string const nazwaPliku ) {
          //WczytajDane(nazwaPliku, k);
        std::fstream plik;
        typ tmp;
        OtworzPlikIn(nazwaPliku.c_str(), plik);
        for(size_t i = 0; i<k; ++i) {
            plik >> tmp;
            this -> Search(tmp);
        }
        plik.close();
    }

    /*!
     * \brief
     * Zwalnia pamięć po teście
     *
     * Zwalnia pamięć zajmowaną przez objekty wykorzytsane do testów
     */
    void Zwolnij() {
        DrzewoBinarne<typ> *db;
        db = this;
        db ->CzyscDrzewo();
    }
};

#endif
