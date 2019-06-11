#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

#endif // PEDIDO_H_INCLUDED
#include <string>
#include <iostream>


class Pedido{
    private:
        unsigned int numero;
        unsigned int quantidade;
        std::string descricao;
        float preco;
    public:
        void Setnumero(unsigned int n){
            if(n>=0){
                numero=n;
            }
        };
        int Getnumero(){
            return numero;
        }
        void Setquantidade(unsigned int q){
            if(q>=0){
                quantidade=q;
            }
        }
        int Getquantidade(){
            return quantidade;
        }
        void Setdescricao(std::string d){
            descricao=d;
        }
        std::string Getdescricao(){
            return descricao;
        }
        void Setpreco(float p){
            preco=p;
        }
        float Getpreco(){
            return preco;
        }
        Pedido(unsigned int n,unsigned int q,std::string d,float p){
            Setnumero(n);
            Setquantidade(q);
            Setdescricao(d);
            Setpreco(p);
        };
        Pedido(){
            Setnumero(0);
            Setquantidade(0);
            Setdescricao(" ");
            Setpreco(0);
        };
        ~Pedido(){};

};
