#include "MesaDeRestaurante.h"

#include <string>
#include <iostream>

#ifndef RESTAURANTECASEIRO_H_INCLUDED
#define RESTAURANTECASEIRO_H_INCLUDED
#endif // RESTAURANTECASEIRO_H_INCLUDED
#define NMESAS 20

class RestauranteCaseiro{
    public:
        MesaDeRestaurante mesas[NMESAS];

        void AdicionaAoPedido(unsigned int m, unsigned int n ,unsigned int q,std::string d,float p){
            mesas[m].AdicionaAoPedido(n,q,d,p);
        }
        double CalculaTotalRestaurante(){
            int c;
            double Rtotal=0;
            for(c=0;c<NMESAS;c++){
                Rtotal+=mesas[c].CalculaTotal();
            }
            return Rtotal;
        }
};
