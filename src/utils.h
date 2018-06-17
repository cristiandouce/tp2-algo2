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
 *        que sea potencia de 2
 *
 * @param l
 * @return unsigned int
 */
unsigned int next_power2 (unsigned int const &);
void zero_pad(lista<complejo> &, unsigned int const &);
void right_pad_input(lista<complejo> &);
void read_input_stream_line(istream *, lista<complejo> &);

#endif