#include "TestaValidaNumero.h"

TestaValidaNumero::TestaValidaNumero(int n)
{
    nume=n;
}

TestaValidaNumero::~TestaValidaNumero()
{
    //dtor
}
void TestaValidaNumero::ValidaNumero(){
    if(nume<=0){
        throw ValorAbaixoException();
    }
    if(nume>100 && nume<1000){
    	throw ValorAcimaException();
    }
    if(nume>=1000){
    	throw ValorMuitoAcimaException();
    }

}