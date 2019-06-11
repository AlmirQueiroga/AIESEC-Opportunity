#include "Assalariado.h"

Assalariado::Assalariado(double s,std::string n,int m):Funcionario(n,m){
    setSalario(s);
}

void Assalariado::setSalario(double s){
	salario=s;
}

double Assalariado::getSalario(){
	return salario;
}

double Assalariado::calcularSalario(){
	return salario;
}