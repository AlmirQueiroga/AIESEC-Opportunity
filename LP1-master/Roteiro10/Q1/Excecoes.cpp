#include "Excecoes.h"

ValorAbaixoException::ValorAbaixoException(){

}
void ValorAbaixoException::descrever(){
	std::cout<<"Valor Baixo"<<std::endl;
}

//-------------
ValorAcimaException::ValorAcimaException(){

}
void ValorAcimaException::descrever(){
	std::cout<<"Valor Alto"<<std::endl;
}

//------------------
ValorMuitoAcimaException::ValorMuitoAcimaException(){

}
void ValorMuitoAcimaException::descrever(){
	std::cout<<"Valor muito alto"<<std::endl;
}

//------------------