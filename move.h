#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include "pokemon.h"

//enum type {grass, fire ,water};

class move{

  private:
    int power;
    type move_type;

  public:
    move();
    move(int,type);

    int get_power();





};


#endif
