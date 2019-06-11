#include "TestaValidaNumero.h"

int main(int argc, char const *argv[])
{	
	int valor;
	std::cout<<"Digite um valor a ser validado"<<std::endl;
	std::cin>>valor;
	std::exception erro;
	TestaValidaNumero teste(valor);
	try{
		teste.ValidaNumero();
		std::cout<<"Valor valido"<<std::endl;
	}
	catch(ValorAbaixoException erro){
		erro.descrever();
	}
	catch(ValorAcimaException erro){
		erro.descrever();
	}
	catch(ValorMuitoAcimaException erro){
		erro.descrever();
	}
	return 0;
}