#ifndef MESADERESTAURANTE_H_INCLUDED
#define MESADERESTAURANTE_H_INCLUDED



#endif // MESADERESTAURANTE_H_INCLUDED
#include "Pedido.h"
#define NPEDIDOS 50
using namespace std;

class MesaDeRestaurante{
    private:
        Pedido pedidos[NPEDIDOS];
        int  N_pedido=0;
    public:
        void AdicionaAoPedido(unsigned int n,unsigned int q,std::string d,float p){
            int c;
            for(c=0;c<NPEDIDOS;c++){
                if(pedidos[c].Getnumero()==n){
                    pedidos[c].Setquantidade(pedidos[c].Getquantidade()+q);
                    break;
                }
                else{
                    pedidos[N_pedido].Setnumero(n);
                    pedidos[N_pedido].Setquantidade(q);
                    pedidos[N_pedido].Setdescricao(d);
                    pedidos[N_pedido].Setpreco(p);
                    N_pedido++;
                    break;
                }
            }
        };
        void ZeraPedidos(){
            int c;
            for(c=0;c<NPEDIDOS;c++){
                pedidos[c].Setquantidade(0);
            }

        };
        double CalculaTotal(){
            int c;
            double total=0;
            for(c=0;c<NPEDIDOS;c++){
                total+=(pedidos[c].Getquantidade())*(pedidos[c].Getpreco());
            }
            return total;
        };
        MesaDeRestaurante(){
            pedidos[NPEDIDOS];
            }
        ~MesaDeRestaurante(){};
};
