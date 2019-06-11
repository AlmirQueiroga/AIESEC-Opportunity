#include <iostream>
#include "televisao.h"

using namespace std;

void Televisao::AvancarVolume(char a){
    int b = volume;

    if(a ==  'V' && b < 100){
        b++;
    }
    if(a == 'v' && b > 0){
        b--;
    }
    if(a == 'v' && b == 0){
            b = 0;
    }
    volume = b;
}

void Televisao::AvancarCanal(char d){
    int c = canal;
   if (d == 'C' ) {
    c++;
   }
   if(d == 'c' && d > 0){
    c--;
   }
   canal = c;

}

void Televisao::SetCanal(int e){
    canal = e;
}

int Televisao::GetCanal(){
    return canal;
}

int Televisao::GetVolume(){
    return volume;
}


int main()
{
    Televisao tv;
    int i=1, x, z;
    char y;

  		cout << "Digite 1 para obter o volume" << endl;
        cout << "Digite 2 para obter o canal" << endl;
        cout << "Digite 3 para mudar o volume" << endl;
        cout << "Digite 4 para mudar o canal" << endl;
        cout << "Digite 0 para encerrar" << endl;


    while(i){
        cin >> x;

        if (x == 0){
            break;
        }
        if (x == 1){
            cout << "Volume: " << tv.GetVolume() << endl;
        }
         if (x == 2){
            cout << "Canal: " << tv.GetCanal() << endl;
        }
         if (x == 3){
            cout << "Digite 'V' para aumentar o volume ou 'v' para diminuir o volume" << endl;
            cin >> y;

            if(y == 'V'){
                tv.AvancarVolume(y);
                cout << "Volume: " << tv.GetVolume() << endl;
            }
            if(y == 'v'){
                tv.AvancarVolume(y);
                cout << "Volume: " << tv.GetVolume() << endl;
            }
        }
         if (x == 4){
             cout << "Digite 'C' para avancar o canal ou 'c' para diminuir o canal ou 'm' para modifica-lo" << endl;
             cin >> y;

            if(y == 'C'){
                tv.AvancarCanal(y);
                cout << "Canal: " << tv.GetCanal() << endl;
            }
            if(y == 'c'){
                tv.AvancarCanal(y);
                cout << "Canal: " << tv.GetCanal() << endl;
            }
            if (y == 'm'){
                cin >> z;
                tv.SetCanal(z);
                cout << "Canal: " << tv.GetCanal() << endl;
            }



         }

}

    return 0;
}
