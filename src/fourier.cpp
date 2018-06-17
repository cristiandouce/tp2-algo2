#include <iomanip>
#include <iostream>
#include <cmath>

#include "./fourier.h"
#include "./utils.h"

using namespace std;

ft::ft(): is_(&cin), os_(&cout), rs_(0), rerr_(0), regrN_(1) { }

ft::ft(istream *is): is_(is), os_(&cout), rs_(0), rerr_(0), regrN_(1) { }

ft::ft(ostream *os): is_(&cin), os_(&cout), rs_(0), rerr_(0), regrN_(1) { }

ft::ft(istream *is, ostream *os): is_(is), os_(os), rs_(0), rerr_(0), regrN_(1) { }

void ft::read_input_line() {
	// nos aseguramos que el input_ lista
	// este siempre vacío antes de empezar.
	input_.clear();

	read_input_stream_line(is_, input_);
}

void ft::write_output_line() {
	// NOTE: no escribo desde output_ cuando
	//			 estoy en modo regression
	if (rs_ != 0) {
		return;
	}

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
ft::regression(istream *rs, double const &rerr) {
	rs_ = rs;
	rerr_ = rerr;
}

void ft::run_regression() {
	// salgo de la ejecucion si la regresion
	// no fue inicializada correctamente
	if (rs_ == 0) {
		return;
	}

	// copio y libero el arreglo de salida
	lista<complejo> &Xk = output_;

	// retorno rapido si Xk esta vacio
	if (Xk.tamano() == 0) {
		cout << endl;
		return;
	}

	// leo la primer linea desde el stream de regresiones
	lista<complejo> Rk;
	read_input_stream_line(rs_, Rk);

	// retorno rapido si Rk esta vacio
	if (Rk.tamano() == 0) {
		cout << endl;
		return;
	}

	// completo los arreglos con 0s para poder calcular la regresion
	int maxSize = max(Rk.tamano(), Xk.tamano());
	unsigned int zerosToRk = maxSize - Rk.tamano();
	unsigned int zerosToXk = maxSize - Xk.tamano();

	zero_pad(Rk, zerosToRk);
	zero_pad(Xk, zerosToXk);

	// proceso la regresion y escribo a os_ directo.
	// el write_output_line tiene una regla de escape
	// para el escenario de regression
	calculate_regression(Rk, Xk);

	// Me aseguro de limpiar las variables al terminar de
	// procesar la linea
	Rk.clear();
	Xk.clear();
}

void
ft::calculate_regression(lista<complejo> &X, lista<complejo> &R) {
	if (X.tamano() != R.tamano()) {
		cout << "Error interno" << endl;
		exit(-1);
	}

	// En
	if (X.tamano() == 0) {
		*os_ << endl;
		return;
	}

	lista<complejo>::iterador Xit = X.primero();
	lista<complejo>::iterador Rit = R.primero();

	double num;
	double den;

	while (!Xit.extremo()) {
		complejo aux = Xit.dato() - Rit.dato();

		// sumo en el numerador producto(aux, aux*)
		num += aux.abs2();

		// sumo en el denominador
		// producto(R[k], R[k]*) = abs(R[x])^2
		den += Rit.dato().abs2();

		// avanzo ambos iteradores para el siguiente k
		Xit.avanzar();
		Rit.avanzar();
	}

	// calculo finalmente el error
	double Ex = sqrt(num / den);

	// evaluo si esta ok?
	bool ok = Ex < rerr_;

	// escribo a la saliida del programa
	*os_ << "test " << regrN_ << ":"
			 << (ok ? " ok " : " error ")
			 << X.tamano() << " "
			 << Ex
			 << endl;

	// incremento el flag de cuantos tests se corrieron
	regrN_++;

	// marco el programa con error solo si
	if (!ok) {
		code(-1);
	}
}

void
ft::compute() {
	while(!is_->eof()) {
		read_input_line();
		run_algorithm();
		run_regression();
		write_output_line();
	}
}