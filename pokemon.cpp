#include "pokemon.h"
#include <iostream>

pokemon::pokemon(){
  hp = 1;
  atk = 1;
  sp_atk = 1;
  def = 1;
  sp_def = 1;
}


int pokemon::get_hp(){
  return this->hp;
}

int pokemon::get_atk(){
  return this->atk;
}

int pokemon::get_sp_atk(){
  return this->sp_atk;
}



int pokemon::get_def(){
  return this->def;
}


int pokemon::get_sp_def(){
  return this->sp_def;
}

void pokemon::lose_hp(int dmg){
  this->hp -=dmg;
}


int pokemon::damage_atk(pokemon enemy){
  int power = 1;
  int level = 1;
  int modifier = 1;
  int damage = (((2*level/5) + 2) * power * (this -> get_atk() / enemy.get_def()))/ 50 + 2 * modifier;
  return damage;
}


int pokemon::damage_sp_atk(pokemon enemy){
  int power = 1;
  int level = 1;
  int modifier = 1;
  int damage = (((2*level/5) + 2) * power * (this -> get_sp_atk() / enemy.get_sp_def()))/ 50 + 2 * modifier;
  return damage;
}