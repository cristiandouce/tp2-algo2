#include <iomanip>
#include <iostream>

#include "./dft.h"

using namespace std;

dft::dft(){
    assign_streams(&cin, &cout);
}

dft::dft(istream *is) {
    assign_streams(is, &cout);
}

dft::dft(ostream *os) {
    assign_streams(&cin, os);
}

dft::dft(istream *is, ostream *os) {
    assign_streams(is, os);
}

bool
dft::inverse() {
    return false;
}

void
dft::run_algorithm() {
    // NOTE: retorno rapido si no hay nada que procesar
    //       en el arreglo de input_.
    if (input_.tamano() == 0) { return; }

    double k, n, N = input_.tamano();
    double arg, norm = get_norm();
    complejo acum, j = get_exp_complejo();
    lista<complejo>::iterador x;

    for (k = 0 ; k < N; ++k) {
        // arranco en el primer elemento
        x = input_.primero();
        acum = 0;
        n = 0;

        // repito hasta el ultimo elemento de entrada
        // la sumatoria de los x[n] * W(kn, N)
        do {
            arg = 2 * M_PI * k * n / N;
            acum += (x.dato()) * (cos(arg) + j.conjugado() * sin(arg));
            n += 1;
            x.avanzar();
        } while( !x.extremo() );

        // multiplicamos por el normalizador que
        // corresponda segun el modo
        acum *= norm;

        // escribo el acumulado a la salida una vez
        // terminado de procesar el k-esimo elemento
        // de la DFT/IDFT
        *os_ << acum << " ";
    }

    // termino de escribir al stream de salida
    *os_ << endl;
}