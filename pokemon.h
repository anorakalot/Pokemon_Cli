#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>
#include "move.h"
using namespace std;

enum type {grass, fire ,water};

class pokemon{
  private:
    string name;
    int hp;
    int atk;
    int def;
    int sp_atk;
    int sp_def;
    type poke_type;
    int level;
    int exp_pts;


  public:
    //constructors
    pokemon();
    pokemon(string,int ,int ,int ,int,int ,type,int,int);


    int get_hp();
    int get_atk();
    int get_def();
    int get_sp_atk();
    int get_sp_def();
    type get_type();

    int damage_sp_atk(pokemon);
    int damage_atk(pokemon);
    void lose_hp(int);

};


#endif
