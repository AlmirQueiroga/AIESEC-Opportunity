#ifndef TERRENO_H
#define TERRENO_H

#include "Imovel.h"

class Terreno : public Imovel{
public:
	Terreno();
	~Terreno();
	double getArea();
	void setArea();
private:
	double area;
}

#endif