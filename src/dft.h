#ifndef _DFT_H_INCLUDED_
#define _DFT_H_INCLUDED_

#include "./fourier.h"

class dft : public ft {
	// private members

	// protected members
	protected:
		virtual bool inverse();

		virtual void run_algorithm();

	// public members
	public:
		dft();

		dft(istream *is);

		dft(ostream *os);

		dft(istream *is, ostream *os);

		~dft(){};
};

#endif