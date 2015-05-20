#ifndef IDRZEW_HH
#define IDRZEW_HH

/*!
 * \brief Definicja IDrzew
 *
 * Plik zawiera definicję interfejsu IDrzew
 */
#include "Wezel.hh"

/*!
 * \brief The IDrzewclass
 *
 * Klasa czysto abstrancyjna modelująca interfejs użytkownika dla drzew.
 */
template < class typ >
class IDrzew {

public:

    /*!
     * \brief Insert
     *
     * Dodaje nową daną (węzeł) do struktury drzewa.
     *
     * \param[in] wartosc - dana do dodania
     */
    virtual void Insert(typ wartosc) = 0;

    /*!
     * \brief Remove
     *
     * Usuwa węzeł przechowujący daną wartość.
     *
     * \param[in] wartosc - przechowywana wartość do usunuęcia z drzewa
     */
    virtual void Remove(typ wartosc) = 0;

    /*!
     * \brief Search
     *
     * Wyszukuje i zwraca daną wartość z drzewa.
     * W przypadku braku jej w drzewie wyświetla stosowny błąd
     * i zwraca NULL / 0.
     *
     * \param[in] wartosc - wartość do znalezienia w drzewie
     *
     * \retval - odnaleziona wartość
     */
    //virtual Wezel<typ>* Search(typ wartosc) = 0;

};

#endif
