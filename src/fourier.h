#ifndef _FOURIER_H_INCLUDED_
#define _FOURIER_H_INCLUDED_

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>

#include "../vendor/lista.h"
#include "../vendor/complejo.h"

#include "./program.h"
#include "./utils.h"

using namespace std;

class ft : public program {
	
	protected:
		lista<complejo> input_;
		istream *is_;
		ostream *os_;

		void assign_streams(istream *is, ostream *os);

		void read_input_line();

		double get_norm ();

		complejo get_exp_complejo();

		virtual bool inverse() = 0;

		virtual void run_algorithm() = 0;

	public:
		ft();

		ft(istream *is);

		ft(ostream *os);

		ft(istream *is, ostream *os);

		virtual ~ft(){};

		void compute();
};

#endif