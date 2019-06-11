#ifndef ICONTA_H
#define ICONTA_H
#include <iostream>
#include <string>

class IConta
{
    public:
        IConta();
        virtual ~IConta();
    protected:
    	virtual void sacar(double valor)=0;
        virtual void depositar(double valor)=0;
};

#endif // ICONTA_H
