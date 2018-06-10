#include <iomanip>
#include <iostream>

#include "./fft.h"

using namespace std;

fft::fft() {
    assign_streams(&cin, &cout);
}

fft::fft(istream *is) {
    assign_streams(is, &cout);
}

fft::fft(ostream *os) {
    assign_streams(&cin, os);
}

fft::fft(istream *is, ostream *os) {
    assign_streams(is, os);
}

bool
fft::inverse() {
    return false;
}

void
fft::right_pad_input() {
    // Si la cantidad de elementos del vector no es potencia de 2,
    // agregamos 0s hasta completar tamaño con proxima potencia de 2
    unsigned int tam = input_.tamano();
    unsigned int v = next_power2(tam);

    if (tam < v) {
        lista<complejo>::iterador it = input_.ultimo();

        for(int i=0; i < (v-tam); i++){
            complejo aux (0.0, 0.0);
            input_.insertar_despues(aux, it);
            it = input_.ultimo();
        }
    }
}

void
fft::run_algorithm() {
    right_pad_input();
    lista<complejo> X = recursive_algorithm(input_);
    lista<complejo>::iterador it = X.primero();

    double norm = get_norm();

    while(!it.extremo()){
        *os_ << it.dato() * norm << " ";
        it.avanzar();
    }

    *os_ << endl;
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
    size_t i = 0;
    lista<complejo>::iterador it = v.primero();
    lista<complejo>::iterador itOdd;
    lista<complejo>::iterador itEven;

    do {
        if (i % 2) {
            itOdd = odd.ultimo();
            odd.insertar_despues(it.dato(), itOdd);
        } else {
            itEven = even.ultimo();
            even.insertar_despues(it.dato(), itEven);
        }

        i++;
        it.avanzar();
    } while (!it.extremo());
}

lista<complejo>
fft::recompone(lista<complejo> &G, lista<complejo> &H, int const &N) {
    lista<complejo> X;

    lista<complejo>::iterador it_G = G.primero();
    lista<complejo>::iterador it_H = H.primero();
    lista<complejo>::iterador it_X = X.ultimo();

    double arg;
    complejo j = get_exp_complejo();
    complejo w;

    // combine
    // Para X[k] con 0 < k < N/2
    for (int k = 0; k < N/2; ++k) {
        arg = 2 * M_PI * k  / N;
        w = (cos(arg) + j.conjugado() * sin(arg));

        complejo t = w * it_H.dato();
        X.insertar_despues(it_G.dato()+t,it_X);
        if(!it_G.extremo()) it_G.avanzar();
        if(!it_H.extremo()) it_H.avanzar();
        it_X = X.ultimo();
    }

    it_G = G.primero();
    it_H = H.primero();

    //Para X[k] con N/2 < k < N
    for (int k = 0; k < N/2; ++k) {
        arg = 2 * M_PI * k  / N;
        w = (cos(arg) + j.conjugado() * sin(arg));

        complejo t = w * it_H.dato();
        X.insertar_despues(it_G.dato()-t,it_X);
        if(!it_G.extremo()) it_G.avanzar();
        if(!it_H.extremo()) it_H.avanzar();
        it_X = X.ultimo();
    }

    return X;
}