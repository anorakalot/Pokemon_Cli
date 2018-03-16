#include "move.h"


move::move(){
  this->power = 1;
  move_type = fire;
}

move::move(int pwr , type type_given){
  this-> power = pwr;
  move_type = type_given;
}


int move::get_power(){
  return this->power;
}
