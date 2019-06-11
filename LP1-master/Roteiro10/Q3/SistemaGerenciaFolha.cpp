#include "SistemaGerenciaFolha.h"

SistemagerenciaFolha::SistemagerenciaFolha(){}

void SistemagerenciaFolha::setFuncionarios(Funcionario *f[]){
	int c;
	for(c=0;c<N_FUNCIONARIOS;c++){
		funcionarios[c]->setNome("Inserir Nome");
		funcionarios[c]->setMatricula(c+1);
	}
}

double SistemagerenciaFolha::CalcularValorTotalFolha(){
	int b;
	double d = 0;

	for(b = 0; b<N_FUNCIONARIOS; b++){
		d += funcionarios[b]->calculaSalario();
	}
	return d;
}




double SistemagerenciaFolha::ConsultaSalarioFuncionario(int c){
	if(c>N_FUNCIONARIOS){
		throw FuncionarioNaoExisteException();
	}
	else{
		return funcionarios[c-1]->calculaSalario();
	}

}