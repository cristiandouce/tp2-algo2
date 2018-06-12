#include <iomanip>
#include <iostream>

#include "./fourier.h"

using namespace std;

ft::ft(): is_(&cin), os_(&cout) { }

ft::ft(istream *is): is_(is), os_(&cout) { }

ft::ft(ostream *os): is_(&cin), os_(&cout) { }

ft::ft(istream *is, ostream *os): is_(is), os_(os) { }

void ft::read_input_line() {
	complejo aux;
	string line;

	getline(*is_, line);

	stringstream linestream(line);

	// nos aseguramos que el input_ lista
	// este siempre vacío antes de empezar.
	input_.clear();

	lista<complejo>::iterador it;
	it = input_.ultimo();

	// leemos cada valor
	while(linestream >> aux) {
		input_.insertar_despues(aux, it);
		it = input_.ultimo();
	}

	// Error de formato en input stream.
	// Detenemos la ejecución del programa.
	if (linestream.bad()) {
		cerr << "cannot read from input stream." << endl;
		exit(1);
	}
}

void ft::write_output_line() {
	lista<complejo>::iterador out = output_.primero();

	while(!out.extremo()) {
		*os_ << out.dato() << " ";
		out.avanzar();
	}

	*os_ << endl;

	// nos aseguramos que el vector de salida
	// este siempre vacio al terminar
	output_.clear();
}

double
ft::get_norm () {
	double N = input_.tamano();
	return get_norm(N);
}

double
ft::get_norm(double const &N) {
	return inverse() && (N > 0) ? 1/N : 1;
}

complejo
ft::get_exp_complejo() {
	return inverse() ? complejo(0, -1) : complejo(0, 1);
}

void
ft::compute() {
	while(!is_->eof()) {
		read_input_line();
		run_algorithm();
		// if (isRegression) {
		// 	run_regression();
		// }

		write_output_line();
	}
}