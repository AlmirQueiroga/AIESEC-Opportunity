#ifndef IMOVEL_H
#define IMOVEL_H

#include <iostream>
#include <string>
#include "Endereco.h"
class Imovel{
public:
	Imovel();
	~Imovel();
	virtual std::string getDescricao()=0;
	Endereco getEndereco(){return endereco}
private:
	Endereco endereco;


}
#endif