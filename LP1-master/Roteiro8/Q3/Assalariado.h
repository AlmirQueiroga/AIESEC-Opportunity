#ifndef ASSALARIADO_H
#define ASSALARIADO_H
#include "Funcionario.h"

class Assalariado:public Funcionario
{
    public:
        Assalariado();
        double calcularSalario();
        double getSalario().
        void setSalario(double s);
    protected:
    private:
    	double salario;
};

#endif // ASSALARIADO_H
