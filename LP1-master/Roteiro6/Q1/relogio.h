#include <iostream>
#ifndef RELOGIO_H_
#define RELOGIO_H_

using namespace std;

 class relogio{
     private:
 int hora, minutos, segundos;
     public:
       void SetHorario(int, int, int);
       int GetHora();
       int GetMinutos();
       int GetSegundos();
       void ProximoHorario(int, int, int);


 };


#endif
