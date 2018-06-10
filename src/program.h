#ifndef _PROGRAM_H_INCLUDED_
#define _PROGRAM_H_INCLUDED_

class program {
  // public members go here
	public:
    // constructor y destructor
		program();
		virtual ~program();

    // devuelve el valor de codigo
    // de la ejecucion del programa
    int code();

    // ejecuta el programa
		virtual void compute() = 0;

	// protected members go here
	protected:
    // almacena el valor del codigo
    // de la ejecucion
    int code_;

    // settea el valor del codigo de la ejecucion
		void code(const int &);

  // private members go here
};

#endif