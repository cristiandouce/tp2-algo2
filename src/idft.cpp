#include <iomanip>
#include <iostream>

#include "./idft.h"

using namespace std;

idft::idft(): dft::dft() { }

idft::idft(istream *is): dft::dft(is) { }

idft::idft(ostream *os): dft::dft(os) { }

idft::idft(istream *is, ostream *os): dft::dft(is, os) { }

bool
idft::inverse() {
    return true;
}

void
idft::run_algorithm() {
    dft::run_algorithm();
}