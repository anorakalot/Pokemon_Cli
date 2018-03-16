#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>


class pokemon{
  private:
    int hp;
    int atk;
    int def;
    int sp_atk;
    int sp_def;

  public:
    //constructor
    pokemon();

    int get_hp();
    int get_atk();
    int get_def();
    int get_sp_atk();
    int get_sp_def();

    int damage_sp_atk(pokemon);
    int damage_atk(pokemon);
    void lose_hp(int);


};


#endif
