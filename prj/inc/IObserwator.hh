/*!
 * \brief Klasa IObserwator
 *
 * Plik zawira definicję klasy IObsereator.
 */

#ifndef IOBSERWATOR_HH
#define IOBSERWATOR_HH

/*!
 * \brief The IObserwator class
 *
 * Klasa modeluje interfejs objektu będącego obserwatorem.
 */
class IObserwator {

public:

    /*!
   * \brief Aktualizuj
   *
   * Aktualizuje dane na podstawie wydarzenie w objekcie obserowanym.
   */
  virtual void Aktualizuj() = 0;

};
#endif
