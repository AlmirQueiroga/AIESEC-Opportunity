#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.h"

class Apartamento :public Imovel {
public:
	Apartamento();
	~Apartamento();
	std::string getPosicao();
	double getValorDoCondominio();
	int getNumeroDeVagasNaGaragam();
	void setPosicao();
	void setValorDoCondominio();
	void setNumeroDeVagasNaGaragem();
private:
	std::string posicao;
	double valorDoCondominio;
	int numeroDeVagasNaGaragem;
}


#endif