#ifndef CONTA_H
#define CONTA_H
#include "IConta.h"

class Conta : public IConta
{
    public:
        Conta(std::string nc,float sl,unsigned int id,double sa);
        virtual ~Conta();
        std::string getNomeCliente();
        float getSalarioMensal();
        unsigned int getNumeroConta();
        double getSaldo();
        float getLimite();
        void setNomeCliente(std::string nc);
        void setSalarioMensal(float sl);
        void setNumeroConta(unsigned int id);
        void setSaldo(double sa);
        void setLimite(float li);
        void definirLimite();
        int sacar(double valor);
        void depositar(double valor);
    private:
    	std::string nomeCliente;
    	float salarioMensal;
    	unsigned int numeroConta;
    	double saldo;
    	float limite;

};

#endif // CONTA_H
