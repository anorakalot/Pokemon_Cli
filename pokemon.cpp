#include "pokemon.h"
#include <iostream>
#include <vector>
using namespace std;
pokemon::pokemon(){
  name = "";
  sprite = "";
  hp = 1;
  atk = 1;
  sp_atk = 1;
  def = 1;
  sp_def = 1;
  poke_type = fire;
  level = 1;
  exp_pts = 0;
  moves = moves;
  speed = 1;
}

pokemon::pokemon(string name,string sprite,int hp,int atk,int sp_atk,int def,int sp_def, type type_given,int level,
   int exp_pts,vector<move> moves, int speed){
  this-> name = name;
  this->sprite = sprite;
  this-> hp = hp;
  this-> atk = atk;
  this-> sp_atk = sp_atk;
  this-> def = def;
  this-> sp_def = sp_def;
  this-> poke_type = type_given;
  this -> level = 1;
  this -> exp_pts = 0;
  this ->moves = moves;
  this -> speed = speed;
}

int pokemon::get_hp(){
  return this->hp;
}

int pokemon::get_speed(){
  return this -> speed;
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

string pokemon::get_sprite(){
  return this-> sprite;
}

int pokemon::get_sp_def(){
  return this->sp_def;
}

int pokemon::get_level(){
  return this -> level;
}
void pokemon::lose_hp(int dmg){
  this->hp -=dmg;
}


type pokemon::get_type(){
  return this -> poke_type;
}

int pokemon::damage_atk(move attack_move,pokemon enemy){
  int power = attack_move.power;
  int level = get_level();
  int modifier = get_modifier(attack_move, enemy);
  int damage = (((2*level/5) + 2) * power * (this -> get_atk() / enemy.get_def()))/ 50 + 2 * modifier;
  return damage;
}


int pokemon::get_modifier(move attack_move, pokemon enemy){
  int modifier = 1;
  int stab  = 1;
  int type_eff = 1;
  if (attack_move.move_type == enemy.poke_type){
      stab = 1.5;
  }
  if (attack_move.move_type == grass && enemy.poke_type == fire){
    type_eff = 0.5;
  }
  if (attack_move.move_type == grass && enemy.poke_type == water){
    type_eff = 2;
  }
  if (attack_move.move_type == fire && enemy.poke_type == water){
    type_eff = 0.5;
  }
  if (attack_move.move_type == fire && enemy.poke_type == grass){
    type_eff = 2;
  }
  if (attack_move.move_type == water && enemy.poke_type == grass){
    type_eff = 0.5;
  }
  if (attack_move.move_type == water && enemy.poke_type == fire){
    type_eff = 2;
  }


  modifier = stab * type_eff;
  return modifier;


}

int pokemon::damage_sp_atk(move sp_atk_move,pokemon enemy){
  int power = sp_atk_move.power;
  int level = get_level();
  int modifier = get_modifier(sp_atk_move, enemy);
  int damage = (((2*level/5) + 2) * power * (this -> get_sp_atk() / enemy.get_sp_def()))/ 50 + 2 * modifier;
  return damage;
}


void pokemon::show_moves(){
  for(int x =0; x < moves.size(); ++x){
    cout << x << ": " << moves.at(x).name << endl;
  }
}

vector<move> pokemon::get_moves(){
  return moves;
}

void pokemon::add_move(int power, string name , type move_type, move_attack attack_type){
  move new_move;
  new_move.power = power;
  new_move.name = name;
  new_move.move_type = move_type;
  new_move.attack_type = attack_type;
  moves.push_back(new_move);
}
