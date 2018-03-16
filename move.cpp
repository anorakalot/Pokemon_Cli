#include "move.h"


move::move(){
  this->name = "tackle";
  this->power = 1;
  move_type = fire;
}

move::move(string name,int pwr , type type_given){
  this-> power = pwr;
  move_type = type_given;
  this-> name = name;
}


int move::get_power(){
  return this->power;
}



type move::get_move_type(){
  return this->move_type;

}

string name::get_name(){
  return this->name;
}
