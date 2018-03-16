#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include "pokemon.h"
using namespace std;
//enum type {grass, fire ,water};

class move{

  private:
    string name;
    int power;
    type move_type;


  public:
    move();
    move(string,int,type);

    string get_name();
    int get_power();
    type get_move_type();
};


#endif
