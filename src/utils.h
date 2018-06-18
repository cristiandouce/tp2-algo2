#ifndef _UTILS_H_INCLUDED_
#define _UTILS_H_INCLUDED_

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>

#include "../vendor/complejo.h"
#include "../vendor/lista.h"

using namespace std;

/**
 * @brief Retorna un numero mayor al entero provisto
 *        que sea potencia de 2. La complejidad temporal
 *        de las operaciones de bitwise ordenadas es de
 *        O(log [n]).
 *
 */
unsigned int next_power2 (unsigned int const &);
/**
 * @brief Toma una lista de <complejo> y completa con
 *        ceros a la derecha segun la cantidad provista
 *        como segundo parametro.
 *
 */
void zero_pad(lista<complejo> &, unsigned int const &);
/**
 * @brief Combina tanto next_power2 como zero_pad para
 *        dada una entrada de tipo lista<complejo>, com-
 *        pletar la misma con ceros hasta la proxima po-
 *        tencia de 2 la
 *
 */
void right_pad_input(lista<complejo> &);
/**
 * @brief Dado un input stream y una lista<complejo>,
 *        lee hasta encontrar newline y almacena todo en
 *        la lista mencionada
 *
 */
void read_input_stream_line(istream *, lista<complejo> &);
/**
 * @brief Dado un output stream y una lista<complejo>,
 *        escribe todos los elementos de la lista al stream
 *        concatenando un newline al terminar.
 *
 */
void write_output_stream_line(ostream *, lista<complejo> &);

#endif