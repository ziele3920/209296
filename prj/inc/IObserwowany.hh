/*!
 * \brief Interfejs obserwowanego
 *
 * W pliku zawarta jest definicja interfejsu obserwowanego
 */

#ifndef IOBSERwOWANY_HH
#define IOBSERWOWANY_HH

#include "IObserwator.hh"

/*!
 * \brief The IObserwowany class
 *
 * Klasa czysto wirtualna modelująca interfejs objektu obserwowanego.
 */
class IObserwowany {

public:

   /*!
   * \brief Dodaje Obserwatora
   *
   * Dodaje nowego obserwatora do listy oserwatorów danego objektu.
   *
   * \param[in] nowyObserwator - wkaźnik na dodawanego obserwatora
   */
  virtual void DodajObserwatora(IObserwator *nowyObserwator) = 0;

    /*!
   * \brief Usuwa Obserwatora
   *
   * Usuwa danego obserwatora z listy obserwatorów danego objektu.
   *
   * \param[in] obserwator - obserwator do usunięcia z listy
   */
  virtual void UsunObserwatora(IObserwator *obserwator) = 0;

    /*!
   * \brief Powiadamia Obserwatorów
   *
   * Powiadamia obseratorów o wydarzeniu.
   */
  virtual void PowiadomObserwatorow() = 0;

};

#endif
