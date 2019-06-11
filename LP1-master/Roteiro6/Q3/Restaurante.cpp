#include "RestauranteCaseiro.h"
#include <stdlib.h>

int main(){
    RestauranteCaseiro Bar;
    int opcao=0;

    unsigned int m,n,q;
    std::string d;
    float p;

    while(1){
        cout<<"\t\t||Menu-Restaurante||"<<endl;
        cout<<"1.\tAdicionar pedido"<<endl;
        cout<<"2.\tCalcular Total(Restaurante)"<<endl;
        cout<<"3.\tZera Pedidos"<<endl;
        cout<<"4.\tCalcular Total(Mesa)"<<endl;
        cin>>opcao;
        switch (opcao){
            case 1:
                cout<<"Digite a mesa"<<endl;
                cin>>m;
                cout<<"Digite o numero do pedido"<<endl;
                cin>>n;
                cout<<"Digite a quantidade"<<endl;
                cin>>q;
                cout<<"Descreva o produto"<<endl;
                cin>>d;
                cout<<"Digite o preco do produto"<<endl;
                cin>>p;
                Bar.AdicionaAoPedido(m,n,q,d,p);
                system("@cls||clear");
                continue;
            case 2:
                cout<<"Ate o momento ,foi computado um total de: "<<Bar.CalculaTotalRestaurante()<<endl;
                continue;
            case 3:
                cout<<"Digite a mesa a ter seus pedidos zerados: "<<endl;
                cin>>m;
                Bar.mesas[m].ZeraPedidos();
                system("@cls||clear");
                continue;
            case 4:
                cout<<"Digite a mesa a ter seu custo total calculado: "<<endl;
                cin>>m;
                cout<<"Total: "<<Bar.mesas[m].CalculaTotal()<<endl;
                continue;
            default:
                cout<<"Opcao invalida"<<endl;
                continue;
        }
    }
    return 1;
}
