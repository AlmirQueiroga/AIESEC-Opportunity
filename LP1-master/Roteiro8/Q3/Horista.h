#ifndef HORISTA_H
#define HORISTA_H
#include "Funcionario.h"

class Horista :public Funcionario
{
    public:
        Horista();
        double calculaSalario();
        double getSalarioPorHora();
        double getHorasTrabalhadas();
        void setSalarioPorHora(double s);
        void setHorasTrabalhadas(double h);
    protected:
    private:
    	double salarioPorHora;
    	double horasTrabalhadas;
};

#endif // HORISTA_H
