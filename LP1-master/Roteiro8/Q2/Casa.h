#ifndef CASA_H
#define CASA_H

#include "Imovel.h"

class Casa :public Imovel{
public:
	Casa();
	~Casa();
	int getNumeroDePavimentos();
	int getQuantidadeDeQuartos();
	double getAreaDoTerreno();
	double getAreaConstruida();
	void setNumeroDePavimentos();
	void setQuantidadeDeQuartos();
	void setAreaDoTerreno();
	void setAreaConstruida();
private:
	int numeroDePavimentos;
	int quantidadeDeQuartos;
	double areaDoTerreno;
	double areaConstruida;
}



#endif