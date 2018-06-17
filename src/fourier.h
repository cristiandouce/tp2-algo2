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

		// para la regresion
		istream *rs_;
		double rerr_;
		int regrN_;

		/**
		 * @brief lee una linea del stream de entrada
		 * 				y la guarda en input_ para ser procesada
		 * 				al llamar run_algoritm()
		 */
		void read_input_line();
		// void read_input_stream_line(istream *, lista<complejo> &);

		/**
		 * @brief Escribe una linea en el stream de output
		 * 				lo almacenado en el arreglo output_
		 */
		void write_output_line();

		double get_norm();
		double get_norm(double const &);

		complejo get_exp_complejo();

		/**
		 * @brief Invoca el algoritmo de regression
		 * 				para una linea del vector de entrada.
		 *
		 */
		void run_regression();

		/**
		 * @brief Calcula laa regresion entre 2 listas de complejos
		 * 				escribiendo su resultado a os_, y afectando el
		 * 				codigo del programa para ser retornado
		 *
		 */
		void calculate_regression(lista<complejo> &, lista<complejo> &);

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
		void regression(istream *rs, double const &);

		/**
		 * @brief Inicializa el procesamiento del algoritmo
		 * 				seleccionado.
		 *
		 */
		void compute();
};

#endif