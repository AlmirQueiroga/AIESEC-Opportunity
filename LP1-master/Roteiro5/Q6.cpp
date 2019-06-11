#include <iostream>
#include <string>
#define PAGAMENTOS 2
using namespace std;

class Pagamento{
private:	
	double valorPagamento;
	string nomeDoFuncionario;
public:
	double getvalorPagamento(){
    return valorPagamento;
	}
	string getnomeDoFuncionario(){
	return nomeDoFuncionario;	
	}
	void setvalorPagamento(double v){
		if (v < 0)
		{
			cout<<"Valor inválido!"<<endl;
		}else{
			valorPagamento = v;
		}
	}
	void setnomeDoFuncionario(string n){
        nomeDoFuncionario = n;
	}
	
	
};



 class ControleDePagamentos{
 private:
 	Pagamento pagamentos[PAGAMENTOS];
 public:
 	void setPagamentos(int i,double d,string s){
 		pagamentos[i].setvalorPagamento(d);
 		pagamentos[i].setnomeDoFuncionario(s);
 	}
 	double calculaTotalDePagamentos(){
     double total=0;
     int c;
     for(c=0;c<PAGAMENTOS;c++){
     	total+=pagamentos[c].getvalorPagamento();
     }
 	}

 	bool existePagamentoParaFuncionario(string nomeFuncionario){
 		bool b=0;
 		int c;
 		for(c=0;c<PAGAMENTOS;c++){
 			if(pagamentos[c].getnomeDoFuncionario()==nomeFuncionario){
 				b++;
 			}
 		}
 		return b;
 	}
 };

int main()
{
	double v;
	string n;
	cout << "insira o nome do meliante" << endl;
	cin >> n;
	cout << "Insira quanto o meliante ganha" << endl;
	cin >> v;
	ControleDePagamentos teste;
	teste.setPagamentos(0,780,"meliante");
	teste.setPagamentos(1,v,n);
	cout <<teste.existePagamentoParaFuncionario("meliante")<<endl;
	cout<<teste.calculaTotalDePagamentos()<<endl;
	return 0;
}