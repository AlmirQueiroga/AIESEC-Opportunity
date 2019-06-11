#include <iostream>
#include <string>
using namespace std;


class Empregado{
    private:
        string nome,sobrenome;
        float salario;
    public:
        Empregado(){
        	cout<<"Nome: ";
        	cin>>nome;
        	cout<<"Sobrenome: ";
        	cin>>sobrenome;
        	cout<<"Salario: ";
        	{
        	float teste;
        	cin>>teste;
        	while(teste<0){
        		cout<<"Valor invalido."<<endl;
        		cout<<"Salario: ";
        		cin>>teste;
        	}
        	salario=teste;
        	}	
        }
		Empregado(string n,string s,float sl){
			SetNome(n);
			SetSobrenome(s);
			SetSalario(sl);
		}
        string GetNome(){
           return nome;
        }
        string GetSobrenome(){
        	return sobrenome;
        }
        float GetSalario(){
        	return salario;
        }
        void SetNome(string n){
        	nome=n;
        }
        void SetSobrenome(string s){
        	sobrenome=s;
        }
        void SetSalario(float s){
        	if(s<0){
        		cout<<"Valor invalido"<<endl;
        	}
        	else{
        		salario=s;
        	}
        }

};

class EmpregadoTeste {
	public:
		void main(){
			Empregado joao;
			Empregado maria("maria","joazinho",1200.50);
			cout<<joao.GetSalario()*12<<endl;
			cout<<maria.GetSalario()*12<<endl;
			joao.SetSalario(joao.GetSalario()*1.1);
			maria.SetSalario(maria.GetSalario()*1.1);
			cout<<joao.GetSalario()*12<<endl;
			cout<<maria.GetSalario()*12<<endl;
		}
}teste;

int main(){
	teste.main();


}