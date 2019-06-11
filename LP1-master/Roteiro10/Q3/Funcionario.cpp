#include "Funcionario.h"

Funcionario::Funcionario(std::string n,int m)
{
    setNome(n);
    setMatricula(m);
}

std::string Funcionario::getNome(){
	return nome;
}

int Funcionario::getMatricula(){
	return matricula;
}

void Funcionario::setNome(std::string n){
	nome=n;
}

void Funcionario::setMatricula(int m){
	matricula=m;
}