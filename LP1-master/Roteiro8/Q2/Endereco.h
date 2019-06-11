#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <string>

class Endereco{
public:
	Endereco();
	~Endereco();
	std::string getLogradouro();
	std::string getBairro();
	int getNumero();
	std::string getCidade();
	std::string getCep();
	void setLogradouro();
	void setBairro();
	void setNumero();
	void setCidade();
	void setCep();

private:
	std::string logradouro;
	std::string bairro;
	int numero;
	std::string cidade;
	std::string cep;
}




#endif