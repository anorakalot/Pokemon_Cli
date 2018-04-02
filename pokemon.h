#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>
#include <vector>
//#include "move.h"
using namespace std;


enum type {grass, fire ,water};
enum move_attack{special_atk,physical_atk};

struct move{
  int power;
  string name;
  type move_type;
  move_attack attack_type;
};

class pokemon{
  //public:


  private:
    string name;
    string sprite;
    int hp;
    int atk;
    int def;
    int sp_atk;
    int sp_def;
    type poke_type;
    int level;
    int exp_pts;
    vector<move> moves;
    int speed;

  public:

    //constructors
    pokemon();
    pokemon(string,string,int ,int ,int ,int,int ,type,int,int,vector<move>,int);


    int get_hp();
    int get_atk();
    int get_def();
    int get_sp_atk();
    int get_sp_def();
    int get_level();
    int get_speed();
    string get_sprite();
    type get_type();
    vector<move> get_moves();

    int damage_sp_atk(move,pokemon);
    int damage_atk(move,pokemon);
    void lose_hp(int);
    int get_modifier(move,pokemon);
    void add_move(int,string,type,move_attack);
    void show_moves();

    //void battle(pokemon);
};


#endif
