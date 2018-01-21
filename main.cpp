#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

//tackle hits the most but does little damage
//dodge dodges the next attack but
//hyper beam can miss the most but does a lot of damage but your monster cant attack the next turn

/*
for reference to see board
"  ---------------------------------------\n"
"   0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  \n"
"  ---------------------------------------\n"
"   8  | 9  | 10 | 11 | 12 | 13 | 14 | 15 \n"
"  ---------------------------------------\n"
"   16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 \n"
"  ---------------------------------------\n"
"   24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 \n"
"  ---------------------------------------\n"

*/


void fill_board(std::vector<char> &myboard,int &player_pos);
void display_board(std::vector<char> &myboard);
void player_movement(std::vector<char> &myboard,int & player_pos,char &space_on);
int enemy_turn();
void battle_sequence(std::vector<std::string> & moves,std::string partner_mon, int &partner_hp,int &partner_hp_inc,char & space_on);

std::string intro_tutorial();
void end_credits();


int main(int argc, char* argv[]){
  srand(time(0));
  int player_pos;
  char space_on;

  std::string partner_mon;


  std::vector <char> myboard(32);
  partner_mon = intro_tutorial();

  int partner_hp=100;
  int partner_hp_inc=0;








  std::vector<std::string> moves(3);
  moves.at(0) = "tackle";
  moves.at(1) = "dodge";
  moves.at(2) = "hyper-beam";


  fill_board(myboard,player_pos);
  display_board(myboard);




while(std::find(myboard.begin(), myboard.end(), 'T') != myboard.end()){
  player_movement(myboard,player_pos,space_on);

  battle_sequence(moves,partner_mon,partner_hp,partner_hp_inc, space_on);




// end of main game loop
}



  //end of main
    return 0;
  }


void battle_sequence(std::vector<std::string> & moves,std::string partner_mon, int &partner_hp,int &partner_hp_inc,char & space_on){
  if (space_on == 'T'){
    std::string enemy_mon;
    enemy_mon = "(̿▀̿ ̿Ĺ̯̿̿▀̿ ̿)̄ ";
    std::cout<< "A wild monster appears!" << std::endl;
    std::cout << enemy_mon << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << partner_mon << std::endl;
    std::cout << "which move do you use" <<std::endl;
    int enemy_hp = 100;
    int input;
    int rng;
    int max = 10;
    int min = 0;
    int enemy_dec;
    int partner_dec;

    bool battle_turn = true;

    while(partner_hp >0 && enemy_hp > 0){
      //output moves you can do
    for(int x = 0; x < moves.size(); ++x){
      std::cout << x << " :" << moves.at(x) << std::endl;
      }
      // take input
      std::cin >> input;
      if (std::cin.fail()||input>=3||input<0){
        //nothing so it loops again
        system("clear");
      }
      else{
        if (input == 0){
          rng = min + rand()%(max-min+1);
          if (rng<=9){
            enemy_dec=20;
            partner_dec = enemy_turn();
          }
          else{
            enemy_dec = 0;
            partner_dec = enemy_turn();
            }
        }
        if (input==1){
          rng = min + rand()%(max-min+1);
          if (rng<=7){
            enemy_dec = 0;
            partner_dec = 0;
          }
          else{
            enemy_dec = 0;
            partner_dec = enemy_turn();
          }
        }
        if (input == 2){
          rng = min+rand()%(max-min+1);
          if (rng <=5){
            enemy_dec = 60;
            partner_dec = enemy_turn();
          }
          else{
            enemy_dec = 0;
            partner_dec = enemy_turn()+enemy_turn();
          }
        }
        system("clear");
        std::cout << partner_mon << " uses " << moves.at(input) <<"!"<<std::endl << std::endl;
        if (enemy_dec == 0&& input != 1){
          std::cout << "But Oh rats! it missed!"<<std::endl;
        }
        else if (input == 1){
          std::cout << "Your partner is focusing on dodging your foes next attack" << std::endl;
        }
        else{
          std::cout << "And it HITS!"<<std::endl;
        }
        std::cin.ignore();

        std::cout << enemy_mon << " attacks with mean stare!" <<std::endl;
        if (partner_dec ==0){
          std::cout << "But Yay! it misses"<<std::endl;
        }
        else{
          std::cout << "and it hits your partner..." << std::endl;
        }
        enemy_hp -= enemy_dec;
        partner_hp -= partner_dec;
        std::cout << "Partner Mon Hp: " << partner_hp << std::endl;
        std::cout << "Enemy Hp: " << enemy_hp << std::endl;

        //end of input and battle sequence
      }
      //end of while battle_turn loop
    }
    if (partner_hp<=0){
      std::cout << "Game Over" << std::endl;
      exit(0);
    }
    else{
      partner_hp_inc += 10;
      partner_hp = 100;
      partner_hp+=partner_hp_inc;
      std::cout << "Enemy_Defeated! Next Hp Level Reached"<<std::endl;
    }
    //end of if on T space statement
  }
}



int enemy_turn(){
  int reng;
  int return_val;
  reng = 0 + rand()%(3-0+1);
  if (reng >= 0 && reng <= 2){
    return_val = 10;
  }
  else{
    return_val = 0;
  }
return return_val;
}



void player_movement(std::vector<char> &myboard,int & player_pos,char &space_on){
  char input;
  bool turn_not_over;
  turn_not_over = true;

  while(turn_not_over){

  std::cin >> input;
  if (input == 'w'){
    if (player_pos-8<0){
      //nothing

    }
    else{
    myboard.at(player_pos) = 'O';
    player_pos-=8;
    space_on = myboard.at(player_pos);
    myboard.at(player_pos) = 'P';
    turn_not_over = false;
    }
  }

  if (input == 's'){
    if (player_pos+8>31){
      //nothing
    }
    else{
    myboard.at(player_pos) = 'O';
    player_pos+=8;
    space_on = myboard.at(player_pos);
    //std::cout << space_on<<std::endl<<std::endl;
    myboard.at(player_pos) = 'P';
    turn_not_over = false;
      }
    }

    if (input == 'a'){
      if (player_pos-1<0){
        //nothing
      }
      else{
      myboard.at(player_pos) = 'O';
      player_pos-=1;
      space_on = myboard.at(player_pos);
      myboard.at(player_pos) = 'P';
      turn_not_over = false;
        }
      }

    if (input == 'd'){
      if (player_pos+1>31){
        //nothing
      }
      else{
        myboard.at(player_pos) = 'O';
        player_pos+=1;
        space_on = myboard.at(player_pos);
        myboard.at(player_pos) = 'P';
        turn_not_over = false;
          }
      }


//end of while turn loop
}
system("clear");
display_board(myboard);
//end of player_movement function
}


std::string intro_tutorial(){

  system("clear");
  std::cout << std::endl;


  std::vector<std::string> monsters(4);
  monsters.at(0) = "┬──┬ ノ( ゜-゜ノ)";
  monsters.at(1) = "ᕙ(⇀‸↼‶)ᕗ";
  monsters.at(2) = "( ͡° ͜ʖ ͡°)";
  monsters.at(3) = "(╯°□°）╯︵ ┻━┻";


  int input;
  std::string dummy_value;
  std::string partner_mon;
  bool checker = true;
  while(checker){
    system("clear");
    std::cout << std::endl;
    std::cout << "Which Monster do you want to be your partner" << std::endl;
    std::cout << "Enter their number to choose them " << std::endl;
    for(int x = 0; x < monsters.size(); ++x){
      std::cout << x << "  :" << monsters.at(x)<<std::endl<<std::endl;
    }
    std::cin >> input;
    //if input fails or input out of bounds
    if (std::cin.fail() || input<0 || input>3){
      //nothing so the loop loops again
    }
    else{
      partner_mon = monsters.at(input);
      checker = false;
    }
    //end of while loop
  }

  std::cout << "Great Choice" << std::endl;
  std::cout << partner_mon << " seems happy to be your partner" << std::endl << std::endl;
  std::cout << "P is the player Icon" << std::endl;
  std::cout << "Use WASD and enter to move" <<std::endl;
  std::cout << "O is open space and T is tall grass" << std::endl;
  std::cout << "Fight the monsters in the T spots and make them O spots to win" << std::endl;
  std::cout << "Type in any char and press enter to begin!"<<std::endl;
  std::cout << std::endl << std::endl;
  std::cin >> dummy_value;
  return partner_mon;
//end of intro function
}

  void fill_board(std::vector<char> &myboard,int &player_pos){
    int rand_bg;
    int rand_pp;

    //filling vector full of chars
    for(int x =0 ; x<myboard.size(); ++x){
      rand_bg = 1+rand()%((10-1)+1);
      if (rand_bg >=1 && rand_bg <=7){
      myboard.at(x) = 'O';
        }
      else if (rand_bg >7){
        myboard.at(x) = 'T';
      }
    }
    rand_pp = 0+rand()%(31-0+1);
    myboard.at(rand_pp) = 'P';
    player_pos = rand_pp;
  }
void display_board(std::vector<char> &myboard){
  for(int x = 0; x < myboard.size();++x){
    if (x % 8 == 0 && x != 0){
        std::cout << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
      }
      std::cout << myboard.at(x) << "  |  ";
    }
    std::cout << std::endl;
}

void end_credits(){
  std::cout <<std::endl<<std::endl;
  std::cout << "YOU BEAT THE GAME YOU ARE A MONSTER TRAINING CHAMPION"<<std::endl;
}
