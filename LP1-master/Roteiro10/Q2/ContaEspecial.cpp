#include "ContaEspecial.h"

ContaEspecial::ContaEspecial(std::string nc,float sl,unsigned int id,double sa):Conta(nc,sl,id,sa){
	definirLimite();
}

ContaEspecial::~ContaEspecial(){

}

void ContaEspecial::definirLimite(){
	float aux;
	aux=3*getSalarioMensal();
	setLimite(aux);
}