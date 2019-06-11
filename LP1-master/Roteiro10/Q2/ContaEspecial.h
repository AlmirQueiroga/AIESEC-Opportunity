#ifndef CONTAESPECIAL_H
#define CONTAESPECIAL_H
#include "Conta.h"

class ContaEspecial : public Conta {
	public:
		ContaEspecial(std::string nc,float sl,unsigned int id,double sa);
		~ContaEspecial();
		void definirLimite();
};

#endif