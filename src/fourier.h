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
#include "./src/utils.h"

using namespace std;

class ft : public program {

	protected:
		lista<complejo> input_;
		lista<complejo> output_;
		istream *is_;
		ostream *os_;
		istream *rs_;

		/**
		 * @brief lee una linea del stream de entrada
		 * 				y la guarda en input_ para ser procesada
		 * 				al llamar run_algoritm()
		 */
		void read_input_line();

		double get_norm();

		complejo get_exp_complejo();

		/**
		 * @brief corre el algoritmo de regression
		 * 				para una linea del vector de entrada.
		 *
		 */
		// void run_regression();

		virtual bool inverse() = 0;

		virtual void run_algorithm() = 0;

	public:
		ft();

		ft(istream *is);

		ft(ostream *os);

		ft(istream *is, ostream *os);

		virtual ~ft(){};


		/**
		 * @brief Flaggea el la instancia para correr
		 * 				la regression como salida del compute()
		 */
		// void regression(istream *rs, double &);

		/**
		 * @brief Inicializa el procesamiento del algoritmo
		 * 				seleccionado.
		 *
		 */
		void compute();
};

#endif