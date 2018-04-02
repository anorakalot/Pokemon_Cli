#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <vector>
#include "pokemon.h"
using namespace std;



class trainer{
private:
  vector<pokemon> team;



public:
  void add_pokemon(pokemon);

};




#endif
