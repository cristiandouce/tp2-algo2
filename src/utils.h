#ifndef _UTILS_H_INCLUDED_
#define _UTILS_H_INCLUDED_

#include "../vendor/complejo.h"
#include "../vendor/lista.h"

/**
 * @brief Retorna un numero mayor al entero provisto
 *        que sea potencia de 2
 *
 * @param l
 * @return unsigned int
 */
unsigned int next_power2 (unsigned int const &l);
void right_pad_input(lista<complejo> &vector);

#endif