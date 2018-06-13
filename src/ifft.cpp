#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include "./ifft.h"

using namespace std;

ifft::ifft(): fft::fft() { }

ifft::ifft(istream *is): fft::fft(is) { }

ifft::ifft(ostream *os): fft::fft(os) { }

ifft::ifft(istream *is, ostream *os): fft::fft(is, os) { }

bool
ifft::inverse() {
    return true;
}

void
ifft::run_algorithm() {
    fft::run_algorithm();
}