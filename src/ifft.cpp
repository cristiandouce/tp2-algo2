#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

#include "./ifft.h"

using namespace std;

ifft::ifft() {
    assign_streams(&cin, &cout);
}

ifft::ifft(istream *is) {
    assign_streams(is, &cout);
}

ifft::ifft(ostream *os) {
    assign_streams(&cin, os);
}

ifft::ifft(istream *is, ostream *os) {
    assign_streams(is, os);
}	

bool
ifft::inverse() {
    return true;
}

void
ifft::run_algorithm() {
    fft::run_algorithm();
}