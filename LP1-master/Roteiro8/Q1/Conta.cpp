#include "Conta.h"

Conta::Conta(std::string nc,float sl,unsigned int id,double sa)
{
	setNomeCliente(nc);
	setSalarioMensal(sl);
	setNumeroConta(id);
	setSaldo(sa);
	definirLimite();    
}

Conta::~Conta()
{
    //dtor
}

std::string Conta::getNomeCliente(){
	return nomeCliente;
}

float Conta::getSalarioMensal(){
	return salarioMensal;
}

unsigned int Conta::getNumeroConta(){
	return numeroConta;
}

double Conta::getSaldo(){
	return saldo;
}

float Conta::getLimite(){
	return limite;
}

void Conta::setNomeCliente(std::string nc){
	nomeCliente=nc;
}

void Conta::setSalarioMensal(float sl){
	salarioMensal=sl;
}

void Conta::setNumeroConta(unsigned int id){
	numeroConta=id;
}

void Conta::setSaldo(double sa){
	saldo=sa;
}

void Conta::setLimite(float li){
	limite=li;
}

void Conta::definirLimite(){
	limite=2*getSalarioMensal();
}

int Conta::sacar(double valor){
	if(valor<=getLimite()){
		double resto;
		resto=getSaldo()-valor;
		setSaldo(resto);
		return 1;
	}
	else{
		return 0;
	}
}

void Conta::depositar(double valor){
	double total;
	total=getSaldo()+valor;
	setSaldo(total);
}