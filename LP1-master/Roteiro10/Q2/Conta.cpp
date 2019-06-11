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

void Conta::sacar(double valor){
	std::exception erro;
	try{
		if(valor>getLimite()){
			throw ValorAcimaDoLimiteException();
		}
		double resto;
		resto=getSaldo()-valor;
		if(resto<0){
			throw SaldoNaoDisponivelException();
		}
		setSaldo(resto);
		std::cout<<"Transacao Concluida"<<std::endl;
		}
	catch(ValorAcimaDoLimiteException erro){
		erro.Mensagem();
	}
	catch(SaldoNaoDisponivelException erro){
		erro.Mensagem();
	};
}

void Conta::depositar(double valor){
	double total;
	total=getSaldo()+valor;
	setSaldo(total);
}