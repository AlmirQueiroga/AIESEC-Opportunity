#include <iostream>
#ifndef  TELEVISAO_H_
#define  TELEVISAO_H_
using namespace std;

class Televisao{
private:
    int volume = 10;
    int canal = 1;
public:
    void AvancarVolume(char);
    void AvancarCanal(char);
    void SetCanal(int);
    int GetVolume();
    int GetCanal();


};




#endif

