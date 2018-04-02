#include "trainer.h"
#include <iostream>
#include <vector>
using namespace std;


void trainer::add_pokemon(pokemon new_addition){
  team.push_back(new_addition);
}
