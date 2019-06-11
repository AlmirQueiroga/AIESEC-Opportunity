#include "Excecoes.h"

void SaldoNaoDisponivelException::Mensagem(){
	std::cout<<"Saldo insuficiente para completar a transacao"<<std::endl;
}

void ValorAcimaDoLimiteException::Mensagem(){
	std::cout<<"Valor requisitado esta acima do limite"<<std::endl;
}