#include "SistemaGerenciaFolha.h"
#include "Assalariado.h"
#include "FuncionarioNaoExisteException.h"

int main(int argc, char const *argv[])
{
	SistemagerenciaFolha sistema;
	std::exception erro;
	try{
		sistema.ConsultaSalarioFuncionario(5);
		std::cout<<"Consulta Concluida"<<std::endl;
	}
	catch(FuncionarioNaoExisteException erro){
		std::cout<<erro.what()<<std::endl;
	}

	return 0;
}