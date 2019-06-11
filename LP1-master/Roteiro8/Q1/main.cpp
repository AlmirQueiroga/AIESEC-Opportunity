#include "ContaEspecial.h"

int main(int argc, char const *argv[])
{
	ContaEspecial especial("Joaozinho",1500,2,8750);
	Conta normal("Janailson",1500,2,8750);
	especial.depositar(1250);
	normal.depositar(1250);
	std::cout<<"Saldo especial: "<<especial.getSaldo()<<std::endl;
	std::cout<<"Saldo normal: "<<normal.getSaldo()<<std::endl;
	float valor;
	//limite para a conta Especial=4500 ,limite para conta normal=3000
	std::cout<<"Digite o valor a ser sacado da conta especial: "<<std::endl;
	std::cin>>valor;
	if(especial.sacar(valor)){
		std::cout<<"Transação concluida"<<std::endl;
	}
	else{
		std::cout<<"Valor acima do limite"<<std::endl;
	}
	std::cout<<"Digite o valor a ser sacado da conta normal: "<<std::endl;
	std::cin>>valor;
	if(normal.sacar(valor)){
		std::cout<<"Transação concluida"<<std::endl;
	}
	else{
		std::cout<<"Valor acima do limite"<<std::endl;
	}
	std::cout<<"Saldo especial: "<<especial.getSaldo()<<std::endl;
	std::cout<<"Saldo normal: "<<normal.getSaldo()<<std::endl;
	
	return 0;
}