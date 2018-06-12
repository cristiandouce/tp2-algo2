#ifndef _FFT_H_INCLUDED_
#define _FFT_H_INCLUDED_

#include "./fourier.h"

class fft : public ft {
	// private members

	// protected members
	protected:
		virtual bool inverse();

		virtual void run_algorithm();

		lista<complejo> recursive_algorithm(lista<complejo> &v);

		void particion(lista<complejo> &v, lista<complejo> &even, lista<complejo> &odd);

		lista<complejo> recompone(lista<complejo> &G, lista<complejo> &H, double const &N);

	// public members
	public:
		fft();

		fft(istream *is);

		fft(ostream *os);

		fft(istream *is, ostream *os);

		~fft(){};
};

#endif