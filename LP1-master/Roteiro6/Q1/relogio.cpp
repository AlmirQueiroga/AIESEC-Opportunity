#include "relogio.h"
#include <iostream>
using namespace std;

void relogio::SetHorario(int H,int M,int S){
hora = H;
minutos = M;
segundos = S;
};

int relogio::GetHora(){
cout << "Horas:" << hora << endl;
return hora;
};

int relogio::GetMinutos(){
cout << "Minutos:" << minutos << endl;
return minutos;
};

int relogio::GetSegundos(){
cout << "Segundos:" << segundos << endl;
return segundos;
};


void relogio::ProximoHorario(int H, int M, int S){
if(S < 59){
    S++;
}
if (S == 59){
    S = 00;
    if(M < 59){
            M++;
    }
    if(M == 59){
            M = 00;
            if(H < 23){
                H++;
            }
            if(H == 23){
                H = 00;
            }
    }


}
cout << "O proximo horario eh" << H << ":" << M << ":" << S << endl;
};

int main()
{
  relogio ponteiro;
  int S, M, H;
     cout << "Insira as horas:" << endl;
cin >> H;
if(H > 23){
    cout << "Valor Invalido!" <<endl;
}
cout << "Insira os Minutos:" << endl;
cin >> M;
if (M > 59){
    cout << "Valor invalido!" << endl;
}
cout << "Insira os segundos:" <<endl;
cin >> S;
if (S > 59){
    cout << "Valor Invalido!" << endl;
}
ponteiro.SetHorario(H, M, S);
ponteiro.GetHora();
ponteiro.GetMinutos();
ponteiro.GetSegundos();
ponteiro.ProximoHorario(H, M, S);


    return 0;

}
