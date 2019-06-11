#include <iostream>
#include <time.h>
using namespace std;

class Data{
private:
    int dia,mes,ano;
public:
    void data(){
        cout<<"Digite o dia"<<endl;
        while(1){
        cin>>dia;
        if(dia<1 || dia>31){cout<<"Valor invalido"<<endl;continue;}
        break;
        }
        cout<<"Digite o mes"<<endl;
        while(1){
        cin>>mes;
        if(mes<1 || mes>12){cout<<"Valor invalido"<<endl;continue;}
        break;
        }
        cout<<"Digite o ano"<<endl;
        while(1){
        cin>>ano;
        if(ano<1){cout<<"Valor invalido"<<endl;continue;}
        break;
        }
    }
    void setdia(){
        cout<<"Digite o dia"<<endl;
        while(1){
        cin>>dia;
        if(dia<1 || dia>31){cout<<"Valor invalido"<<endl;continue;}
        break;
        }
    }

    int getdia(){return dia;}

    void setmes(){
    cout<<"Digite o mes"<<endl;
        while(1){
        cin>>mes;
        if(mes<1 || mes>12){cout<<"Valor invalido"<<endl;continue;}
        break;
        }
    }

    int getmes(){return mes;}

    void setano(){
    cout<<"Digite o ano"<<endl;
        while(1){
        cin>>ano;
        if(ano<1){cout<<"Valor invalido"<<endl;continue;}
        break;
        }
    }

    int getano(){return ano;}

    void avancarDia(){
        if(dia==31){
            dia=1;
            mes++;
        }
        else{dia++;}
    }
};

class DataTest{
public:
    void main(){
        Data aniversario;
        aniversario.data();
        aniversario.setmes();
        Data hoje;
        hoje.data();
        cout<<hoje.getdia()<<endl;
    }

}teste;

int main(){
    teste.main();
}
