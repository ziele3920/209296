#ifndef STATUS_HH
#define STATUS_HH

/*!
 * \brief The status enum
 *
 * Definicja typu wyliczeniowego status, który jest wykorzystywany
 * przez algorytmy przejćia grafu jako flagi ustawiane na wierzchołkach
 * i krawędziach.
 */
enum status {nieodwiedzony, odwiedzony, powrotny, poprzeczny };

#endif
