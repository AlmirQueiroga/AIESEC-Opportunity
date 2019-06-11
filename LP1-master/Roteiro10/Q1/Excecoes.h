#ifndef EXCECOES_H
#define EXCECOES_H
#include <iostream>
#include <string>
#include <exception>

class ValorAbaixoException : public std::exception{
	public:
		ValorAbaixoException();
		void descrever();
};

class ValorAcimaException : public std::exception{
	public:
		ValorAcimaException();
		void descrever();
};

class ValorMuitoAcimaException :public std::exception{
	public:
		ValorMuitoAcimaException();
		void descrever();
};

#endif // EXCECOES_H
