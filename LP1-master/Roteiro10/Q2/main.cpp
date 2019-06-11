#include "ContaEspecial.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int main(int argc, char const *argv[])
{
	std::system("CLS");
	std::system("clear");
	ContaEspecial especial("Joaozinho",1500,2,8750);
	Conta normal("Janailson",1500,2,8750);
	especial.depositar(1250);
	normal.depositar(1250);
	float valor;
	//limite para a conta Especial=4500 ,limite para conta normal=3000
	while(normal.getSaldo()){
	std::cout<<"Saldo especial: "<<especial.getSaldo()<<std::endl;
	std::cout<<"Saldo normal: "<<normal.getSaldo()<<std::endl;
	std::cout<<"Digite o valor a ser sacado da conta especial: "<<std::endl;
	std::cin>>valor;
	especial.sacar(valor);
	std::cout<<"Digite o valor a ser sacado da conta normal: "<<std::endl;
	std::cin>>valor;
	normal.sacar(valor);
	fflush(stdin);
	std::cout<<"\n ----\t----\t----\t----\t----\t----\t----\t----\t----"<<std::endl;
	}
	return 0;
}