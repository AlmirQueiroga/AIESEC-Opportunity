#ifndef COMISSIONADO_H
#define COMISSIONADO_H
#include "Funcionario.h"

class Comissionado :public Funcionario
{
    public:
        Comissionado();
        double calcularSalario();
        double getVendasSemanais();
        double getPercentualComissao();
        void setVendasSemanais(double v);
        void setPercentualComissao(double p);
    protected:
    private:
    	double vendasSemanais;
    	double percentualComissao;
};

#endif // COMISSIONADO_H
