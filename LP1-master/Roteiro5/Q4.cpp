#include <iostream>
#include <cstring>

using namespace std;

 class Pessoa{
 private:
 	string nome,telefone;
 	int idade;
 public:
 	Pessoa(string n);
 	Pessoa(string n,int i,string t);
 	string getNome(){
 		return nome;
 	}
 	int getIdade(){
 		return idade;
 	}
 	string getTelefone(){
 		return telefone;
 	}
 	void setNome(string n){
 		if("n"!=" "){
 			nome=n;
 		}
 		else{
 			cout<<"Valor invalido1"<<endl;
 		}
 	}
 	void setIdade(int i){
 		if(i>=0){
 			idade=i;
 		}
 		else{
 			cout<<"Valor Invalido2"<<endl;
 		}
 	}
 	void setTelefone(string t){
 		size_t tamanho;
 		tamanho=t.size();
 		if(tamanho<10){
 			cout<<"Valor invalido3"<<endl;
 		}
 		else{
 			telefone=t;
 		}
 	}
 };
 Pessoa::Pessoa(string n){
 		setNome(n);
 		setIdade(0);
 		setTelefone("00000000000");//11 zeros
 	};
 Pessoa::Pessoa(string n,int i,string t){
 		setNome(n);
 		setIdade(i);
 		setTelefone(t);
 	};

class CadastroDePessoas{
public:
	void main(){
		Pessoa Joao("Joao");
		Pessoa Maria("Maria",26,"83983763231");
		Joao.setIdade(12);
		Joao.setTelefone("83942423132");
		cout<<Joao.getTelefone()<<endl;
		cout<<Joao.getIdade()<<endl;
		cout<<Joao.getNome()<<endl;
		cout<<Maria.getNome()<<endl;
		cout<<Maria.getIdade()<<endl;
		cout<<Maria.getTelefone()<<endl;
	}
}teste;

int main(){
	teste.main();
}