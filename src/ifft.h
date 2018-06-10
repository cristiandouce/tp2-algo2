#ifndef _IFFT_H_INCLUDED_
#define _IFFT_H_INCLUDED_

#include <fstream>
#include <sstream>

#include "./fft.h"

using namespace std;

class ifft : public fft {
	// private members

	// protected members
	protected:
		virtual bool inverse();

		virtual void run_algorithm();

	// public members
	public:
		ifft();

		ifft(istream *is);

		ifft(ostream *os);

		ifft(istream *is, ostream *os);

		~ifft(){};
};

#endif