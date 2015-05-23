#ifndef INTERFEJSADT_HH
#define INTERFEJSADT_HH


/*!
 *\ brief
 * Definiuje interfejs użytkownika 
 *
 * Definiuje interfejs użytkownika dla listy, stosu i kolejki.
 */
template < class typ >
class InterfejsADT {

public:


  /*!
   * \brief
   * Dodaje kolejny element
   *
   * Dodaje kolejny element do typu danych
   *
   * \param[in] dana - element który chcemy dorzucić do naszego typu
   * \param[in] pole - !!!DOSTEPNE TYLKO DLA LISTY!!! nr pola na które
   *                   chcemy dodać element
   */
  virtual void push(const typ dana, const unsigned int pole) = 0;

  /*!
   * \brief
   * Pobiera element
   *
   * Pobiera element z typu danych
   *
   * \param[in] pole - !!!DOSTEPNE TYLKO DLA LISTY!!! nr pola z ktore 
   *                   pobiera element
   *
   * \retval zwraca wartość danego elementu
   */
  virtual void pop(const unsigned int pole) = 0;

  /*!
   * \brief
   * Liczność elemetów
   * 
   * Informuje o licznośći elementów obecnie przechowywanych
   *
   * \retval zwraca ilość przechowywanych elementów
   */
  virtual unsigned int size() const = 0;





};

#endif
