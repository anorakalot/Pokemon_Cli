#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>
#include <vector>
//#include "move.h"
using namespace std;


enum type {grass, fire ,water};

struct move{
  int power;
  string name;
  type move_type;
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

  public:

    //constructors
    pokemon();
    pokemon(string,string,int ,int ,int ,int,int ,type);


    int get_hp();
    int get_atk();
    int get_def();
    int get_sp_atk();
    int get_sp_def();
    int get_level();
    type get_type();

    int damage_sp_atk(move,pokemon);
    int damage_atk(move,pokemon);
    void lose_hp(int);
    int get_modifier(move,pokemon);
    void add_move(int,string,type);

};


#endif
