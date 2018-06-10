#include <iomanip>
#include <iostream>

#include "./idft.h"

using namespace std;

idft::idft() {
    assign_streams(&cin, &cout);
}

idft::idft(istream *is) {
    assign_streams(is, &cout);
}

idft::idft(ostream *os) {
    assign_streams(&cin, os);
}

idft::idft(istream *is, ostream *os) {
    assign_streams(is, os);
}

bool
idft::inverse() {
    return true;
}

void
idft::run_algorithm() {
    dft::run_algorithm();
}