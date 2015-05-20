#ifndef WEZELAVL_HH
#define WEZELAVL_HH

/*!
 * \brief Węzeł drzewa AVL
 *
 * Plik zawiera definicję węzła wykorzytywanego w drzewie AVL.
 */


/*!
 * \brief Węzeł drzewa AVL
 *
 * Struktura nędąca reprezentacją pojednyńczego węzła w drzewie AVL.
 */
template < class typ >
struct WezelAVL {

    /*!
     * \brief Przechowywana wartość
     *
     * Pole przechowuje wartość elementu znajdującego się w danym węźle.
     */
    typ Dana;

    /*!
     * \brief Rodzic danego węzła.
     *
     * Wskaźnik na rodzica danego węzła.
     */
    WezelAVL *Rodzic;

    /*!
     * \brief Lewy potomek
     *
     * Wskaźnik na lewego potomka danego węzła.
     */
    WezelAVL *Lewy;

    /*!
     * \brief Prawy potomek
     *
     * Wskaźnik na prawego potomnka danego węzła.
     */
    WezelAVL *Prawy;

    int WspRownowagi;

    WezelAVL() {
        Rodzic = NULL;
        Lewy = NULL;
        Prawy = NULL;
        WspRownowagi = 0;
    }

    ~WezelAVL() {
        Rodzic = NULL;
        Lewy = NULL;
        Prawy = NULL;
    }

};

#endif
