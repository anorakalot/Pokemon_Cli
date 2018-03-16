#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>

enum type {grass, fire ,water};

class pokemon{
  private:
    int hp;
    int atk;
    int def;
    int sp_atk;
    int sp_def;
    type poke_type;

  public:
    //constructors
    pokemon();
    pokemon(int ,int ,int ,int,int ,type);


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
