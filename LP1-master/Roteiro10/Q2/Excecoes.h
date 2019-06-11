#ifndef EXCECOES_H
#define EXCECOES_H
#include <iostream>
#include <string>
#include <exception>

class SaldoNaoDisponivelException : public std::exception {
	public:
		SaldoNaoDisponivelException(){};
		void Mensagem();
};

class ValorAcimaDoLimiteException : public std::exception{
	public:
		ValorAcimaDoLimiteException(){};
		void Mensagem();
} ;

#endif // EXCECOES_H