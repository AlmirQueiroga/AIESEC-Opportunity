#include "Comissionado.h"
#define S_MINIMO 937

Comissionado::Comissionado(double v,double p,std::string n,int m):Funcionario(n,m){
	setVendasSemanais(v);
	setPercentualComissao(p);
}

double Comissionado::calcularSalario(){
	return getVendasSemanais()*getPercentualComissao()+S_MINIMO;
}

double Comissionado::getVendasSemanais(){
	return vendasSemanais;
}

double Comissionado::getPercentualComissao(){
	return percentualComissao;
}

void Comissionado::setVendasSemanais(double v){
	vendasSemanais=v;
}

void Comissionado::setPercentualComissao(double p){
	percentualComissao=p;
}


