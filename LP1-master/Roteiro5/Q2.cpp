#include <iostream>
#include <string>

using namespace std;

class Invoice{
    private:
        int numero,quantidade;
        string descricao;
        float preco;
    public:
        void invoice(){
            cout<<"numero:";
            cin>>numero;
            while(numero<0){
                if(numero<0){
                    cout<<"Valor invalido"<<endl;
                }
                cin>>numero;
            }
            cout<<"descricao:";
            cin>>descricao;

            cout<<"quantidade:";
            cin>>quantidade;
            while(quantidade<0){
                if(quantidade<0){
                    cout<<"Valor invalido"<<endl;
                }
                cin>>quantidade;
            }
            cout<<"preco:";
            cin>>preco;
            while(preco<0){
                if(preco<0){
                    cout<<"Valor invalido"<<endl;
                }
                cin>>preco;
            }
        }

        void setnumero(int v){
            if(v<0){cout<<"Valor invalido"<<endl;}
            else{numero=v;}
        }
        int getnumero(){return numero;}

        void setdescricao(string s){
            descricao=s;
        }
        string getdescricao(){return descricao;}

        void setquantidade(int q){
        if(q<0){cout<<"valor invalido"<<endl;}
        else{quantidade=q;}
        }
        int getquantidade(){return quantidade;}

        void setpreco(float p){
            if(p<0){cout<<"valor invalido"<<endl;}
            else{preco=p;}
        }
        float getpreco(){return preco;}

        float getInvoiceAmount(){
            if(preco<0){preco=0;}
            if(quantidade<0){quantidade=0;}
            return preco*quantidade;
        }
};

class InvoiceTest{
    public:
        void main(){
            Invoice chip,bolo,cafe;
            chip.invoice();
            cout<<chip.getnumero()<<endl;
            cout<<chip.getpreco()<<endl;
            bolo.invoice();
            bolo.setpreco(15);
            cout<<bolo.getpreco()<<endl;
            cout<<bolo.getdescricao()<<endl;
            cafe.invoice();
            cafe.setnumero(10);
            cout<<cafe.getnumero()<<endl;
            cout<<chip.getInvoiceAmount()<<endl;
            cout<<bolo.getInvoiceAmount()<<endl;
            cout<<cafe.getInvoiceAmount()<<endl;
        }
}teste;

int main(){
    teste.main();
}
