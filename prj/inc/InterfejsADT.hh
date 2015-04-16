#ifndef INTERFEJSADT_HH
#define INTERFEJSADT_HH

#include "Framework.hh"

/*!
 *\ brief
 * Definiuje interfejs użytkownika 
 *
 * Definiuje interfejs użytkownika dla listy, stosu i kolejki.
 */
template < class typ >
class InterfejsADT : public Framework {

public:

  // virtual ~InterfejsADT() = 0;

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
  virtual typ pop(const unsigned int pole) = 0;

  /*!
   * \brief
   * Liczność elemetów
   * 
   * Informuje o licznośći elementów obecnie przechowywanych
   *
   * \retval zwraca ilość przechowywanych elementów
   */
  virtual unsigned int size() const = 0;

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
  void WczytajDane(const char *nazwaPliku, const unsigned int n) = 0;

  /*!
   * \brief 
   * Wykonanie części obliczeniowej programu
   *
   * Metoda w której implementowana jest część obliczeniowa
   * programu, której czas wykonania zostanie zmierzony.
   *
   * \param[in] k - ilość elementów dla których mają zostać wykonane obliczenia.
   * param[in] plik - plik z którego wczytujemy dane
   */
  void Start(std::fstream &plik, const unsigned int k) = 0;

  /*!
   * \brief
   * Zwalnia pamięć
   *
   * Zwalnia pamięć zajmowaną przez daną strukturę
   */
  virtual void Zwolnij () = 0;



};

#endif
