#include <iomanip>
#include <iostream>


#include "./utils.h"

using namespace std;

unsigned int
next_power2 (unsigned int const &l) {
  /*
  Si l es potencia de 2, (l-1) tendra solo 1s en los bits menos
   significativos, entonces "l & (l-1)" siempre sera 0.
  Se chequea aparte el caso l=0 dado que la expresion previa no aplica en
   dicho caso
  */
  bool isPowerOf2 = !(l == 0) && !(l & (l - 1));
  if (isPowerOf2) {
    return l;
  }

  unsigned int p = l;

  /*
    Ya sabemos que l no es potencia de 2, entonces la proxima potencia de 2 sera el numero que
    tenga en '1' el bit "a la izquierda" del bit en '1' mas significativo del numero original, y
    los menos significativos en '0'. Por ej:
      0010 0110 -> Numero original NO potencia de 2
      0100 0000 -> Proxima potencia de 2 de dicho numero

    Para obtener dicho resultado, se completa con 1s a partir del bit mas significativo hacia
    el menos significativo, y luego se suma 1; con lo cual se propagara un bit de carry hasta
    setear en 1 el proximo bit del 1 que era mas significativo y dejando el resto en 0s.
    Por ej:
      0010 0110 -> Numero original NO potencia de 2
      0011 1111 -> Numero completado con 1s
      0100 0000 -> Numero previo al que se le suma 1 obteniendo resultado final

    Para realizar el proceso de rellenado con 1s, solo hace falta realizar ceil(log2(n)= operaciones de
    shift y OR, siendo "n" la cantidad de bits del numero.
    En nuestro caso consideramos n=32, entonces tenemos ceil(log2(32))=5
  */

  p |= p >> 1;
  p |= p >> 2;
  p |= p >> 4;
  p |= p >> 8;
  p |= p >> 16;
  p++;

  return p;
}

void
right_pad_input(lista<complejo> &vector) {
  // Si la cantidad de elementos del vector no es potencia de 2,
  // agregamos 0s hasta completar tamaño con proxima potencia de 2
  unsigned int tam = vector.tamano();
  unsigned int v = next_power2(tam);
  unsigned int zeros = v - tam;
  zero_pad(vector, zeros);
}


void zero_pad(lista<complejo> &vector, unsigned int const &zeros) {
  // NOTE: retorno si no debo agregar nada
  if (zeros == 0) {
    return;
  }

  for(int i = 0; i < zeros; i++){
    complejo aux (0.0, 0.0);
    vector.insertar_despues(aux, vector.ultimo());
  }
}
