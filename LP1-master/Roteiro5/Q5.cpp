#include <iostream>
#include <string>
#define DESPESAS 2
using namespace std;

 class Despesa{
 private:
 	double valor;
 	string tipoDeGasto;
 public:
 	double getValor(){
 		return valor;
 	}
 	string getTipoDeGasto(){
 		return tipoDeGasto;
 	}
 	void setValor(double v){
 		if(v<0){
 			cout<<"Valor invalido"<<endl;
 		}
 		else{
 			valor=v;
 		}
 	}
 	void setTipoDeGasto(string s){
 		if(s.size()<0){
 			cout<<"Nome invalido"<<endl;
 		}
 		else{
 			tipoDeGasto=s;
 		}
 	}
 	/*Despesa(double v,string s){
 		setValor(v);
 		setTipoDeGasto(s);
 	}*/
 };
//----------------------------------------------------
class ControleDeGastos{
 private:
 	Despesa despesas[DESPESAS];
 public:
 	void setDespesas(int i,double v,string s){
 		despesas[i].setValor(v);
 		despesas[i].setTipoDeGasto(s);
 	}
 	double calculaTotalDeDespesas(){
 		double total=0;
 		int c;
 		for(c=0;c<DESPESAS;c++){
 			total+=despesas[c].getValor();
 		}
 		return total;
 	}
 	bool existeDespesaDoTipo(string s){
 		int aux=0,c;
 		for(c=0;c<DESPESAS;c++){
 			if(despesas[c].getTipoDeGasto()==s){
 				aux++;
 			}
 		}
 		return aux;
 	}
 };

 int main(void)
 {
 	ControleDeGastos controle;
 	controle.setDespesas(0,700,"Reforma");
 	controle.setDespesas(1,200,"Energia");
 	cout<<controle.calculaTotalDeDespesas()<<endl;
 	cout<<"Existe Feira :"<<controle.existeDespesaDoTipo("Feira")<<endl;
 	return 0;
 }