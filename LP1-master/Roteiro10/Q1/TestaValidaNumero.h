#ifndef TESTAVALIDANUMERO_H
#define TESTAVALIDANUMERO_H
#include "Excecoes.h"

class TestaValidaNumero
{
    public:
        TestaValidaNumero(int n);
        virtual ~TestaValidaNumero();
        void ValidaNumero();
    protected:
    private:
    	int nume;
};

#endif // TESTAVALIDANUMERO_H
