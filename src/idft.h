#ifndef _IDFT_H_INCLUDED_
#define _IDFT_H_INCLUDED_

#include "./dft.h"

class idft : public dft {
	// private members

	// protected members
	protected:
		virtual bool inverse();

		virtual void run_algorithm();

	// public members
	public:
		idft();

		idft(istream *is);

		idft(ostream *os);

		idft(istream *is, ostream *os) ;

		~idft(){};
};

#endif