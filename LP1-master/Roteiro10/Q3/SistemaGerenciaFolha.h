#ifndef SISTEMAGERENCIAFOLHA_H
#define SISTEMAGERENCIAFOLHA_H
#include "Funcionario.h"
#include "FuncionarioNaoExisteException.h"
#define N_FUNCIONARIOS 4

class SistemagerenciaFolha{
private:
    Funcionario *funcionarios[N_FUNCIONARIOS];
public:
	SistemagerenciaFolha();
	void setFuncionarios(Funcionario *x[]);
	double CalcularValorTotalFolha();
	double ConsultaSalarioFuncionario(int i);
};


#endif