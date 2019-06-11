#ifndef ORCAMENTOESTOURADOEXCEPTION_H
#define ORCAMENTOESTOURADOEXCEPTION_H
#include <exception>

class OrcamentoEstouradoException : public std::exception{

public:

	OrcamentoEstouradoException(){}

	const char * what();
};

#endif