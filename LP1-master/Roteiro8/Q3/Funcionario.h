#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include <iostream>

class Funcionario
{
    public:
        Funcionario();
        virtual double calculaSalario()=0;
        std::string getNome();
        int getMatricula();
        void setNome(std::string n);
        void setMatricula(int m);
    protected:
    private:
    	std::string nome;
    	int matricula;
};

#endif // FUNCIONARIO_H
