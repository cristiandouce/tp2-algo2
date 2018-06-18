#include <iomanip>
#include <iostream>

#include "./src/utils.h"
#include "./fft.h"

using namespace std;

fft::fft(): ft::ft() { }

fft::fft(istream *is): ft::ft(is) { }

fft::fft(ostream *os): ft::ft(os) { }

fft::fft(istream *is, ostream *os): ft::ft(is, os) { }

bool
fft::inverse() {
    return false;
}

void
fft::run_algorithm() {
    // NOTE: retorno rapido si no hay nada que procesar
    //       en el arreglo de input_.
    if (input_.tamano() == 0) { return; }

    // llevo tamano de entrada a una potencia de 2
    // agregando 0s al final del arreglo
    right_pad_input(input_);

    // corro el algoritmo recursivo implementado
    // desde el vector entrada al vector salidas
    output_ = recursive_algorithm(input_);
}

lista<complejo>
fft::recursive_algorithm(lista<complejo> &v) {
    int N = v.tamano();

    if (N <= 1) {
        return v;
    }

    lista<complejo> v_even_parts;
    lista<complejo> v_odd_parts;
    particion(v, v_even_parts, v_odd_parts);

    lista<complejo> G = recursive_algorithm(v_even_parts);
    lista<complejo> H = recursive_algorithm(v_odd_parts);

    return recompone(G, H, N);
}

void
fft::particion(lista<complejo> &v, lista<complejo> &even, lista<complejo> &odd) {
    std::size_t i = 0;
    lista<complejo>::iterador it = v.primero();

    do {
        if (i % 2) {
            odd.insertar_despues(it.dato(), odd.ultimo());
        } else {
            even.insertar_despues(it.dato(), even.ultimo());
        }

        i++;
        it.avanzar();
    } while (!it.extremo());
}

lista<complejo>
fft::recompone(lista<complejo> &G, lista<complejo> &H, double const &N) {
    lista<complejo> X;

    lista<complejo>::iterador it_G = G.primero();
    lista<complejo>::iterador it_H = H.primero();

    double arg;
    complejo j = get_exp_complejo();
    double norm = N == input_.tamano() ? get_norm() : 1; // solo en la ultima iteracion
    complejo w;

    // combine
    // Para X[k] con 0 < k < N/2
    for (int k = 0; k < N/2; ++k) {
        arg = 2 * M_PI * k  / N;
        w = (cos(arg) + j.conjugado() * sin(arg));

        complejo t = w * it_H.dato();
        X.insertar_despues((it_G.dato() + t) * norm, X.ultimo());
        if(!it_G.extremo()) it_G.avanzar();
        if(!it_H.extremo()) it_H.avanzar();
    }

    it_G = G.primero();
    it_H = H.primero();

    //Para X[k] con N/2 < k < N
    for (int k = 0; k < N/2; ++k) {
        arg = 2 * M_PI * k  / N;
        w = (cos(arg) + j.conjugado() * sin(arg));

        complejo t = w * it_H.dato();
        X.insertar_despues((it_G.dato() - t) * norm, X.ultimo());
        if(!it_G.extremo()) it_G.avanzar();
        if(!it_H.extremo()) it_H.avanzar();
    }

    return X;
}