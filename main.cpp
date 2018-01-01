#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
void make_board(int &board_size, int &location_determiner, int &width, int &length,std::vector<char> &locations,int&player_pos,char&location_of_player_pos){
/*
std::cout << "How wide do you want the gameboard to be?" << std::endl;
std::cin >> width;
std::cout << "How long do you want the gameboard to be?"<<std::endl;
std::cin >> length;
length = length + 1;
*/
width = 5;
length = 5;
board_size = length * width;
locations.resize(board_size);
for(int x = 0; x<locations.size(); ++x){
  location_determiner = 0+(rand()%(10-0+1));
  if (location_determiner>= 0 && location_determiner <=8){
    locations.at(x) = 'O';
  }
  else{
    locations.at(x) = 'H';
  }
}
//player position

//player_pos = 0+(rand()%(locations.size()-1-0+1));
player_pos = 20;
location_of_player_pos = locations.at(player_pos);
locations.at(player_pos) = 'P';

//end of make_board function
}


//diplay the board
void display_board(std::vector<char> &locations,int width){
/*for(int x = 0; x < locations.size(); ++x){
  if (x % width==0 && x != 0){
    std::cout << locations.at(x) << std::endl;
  }
  else{
  std::cout << locations.at(x)<< "---";
  }
}*/
std::cout << std::endl<<std::endl;
std::cout << locations.at(0)<< "---"<< locations.at(1)<< "---"<< locations.at(2)<< "---"<< locations.at(3)<< "---"<<locations.at(4)<<std::endl;
std::cout << locations.at(5)<< "---"<< locations.at(6)<< "---"<< locations.at(7)<< "---"<< locations.at(8)<< "---"<<locations.at(9)<<std::endl;
std::cout << locations.at(10)<< "---"<< locations.at(11)<< "---"<< locations.at(12)<< "---"<< locations.at(13)<< "---"<<locations.at(14)<<std::endl;
std::cout << locations.at(15)<< "---"<< locations.at(16)<< "---"<< locations.at(17)<< "---"<< locations.at(18)<< "---"<<locations.at(19)<<std::endl;
std::cout << locations.at(20)<< "---"<< locations.at(21)<< "---"<< locations.at(22)<< "---"<< locations.at(23)<< "---"<<locations.at(24)<<std::endl;


}


int main(){
  //(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
srand(time(0));
int board_size;
int location_determiner;
int width;
int length;
std::vector<char> locations(board_size);
int player_pos;
char location_of_player_pos;
//width = 5;
//board_size = 25;
make_board(board_size,location_determiner,width,length,locations,player_pos,location_of_player_pos);
display_board(locations,width);

bool player_turn;

player_turn = true;
std::cout << std::endl;
std::cout << "Make your move"<<std::endl;
while(player_turn){

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
  if (player_pos - 5<0){

  }
  else{
    system("clear");
    locations.at(player_pos) = location_of_player_pos;
    player_pos -= 5;
    location_of_player_pos = locations.at(player_pos);
    locations.at(player_pos) = 'P';
    display_board(locations,width);
    player_turn = false;
  }
}

else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
  if (player_pos + 5>24){

  }
  else{
    system("clear");
    locations.at(player_pos) = location_of_player_pos;
    player_pos += 5;
    location_of_player_pos = locations.at(player_pos);
    locations.at(player_pos) = 'P';
    display_board(locations,width);
    player_turn = false;
  }
}

else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
  if (player_pos + 5>24){

  }
  else{
    system("clear");
    locations.at(player_pos) = location_of_player_pos;
    player_pos += 5;
    location_of_player_pos = locations.at(player_pos);
    locations.at(player_pos) = 'P';
    display_board(locations,width);
    player_turn = false;
  }
}


else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
  if (player_pos + 5>24){

  }
  else{
    system("clear");
    locations.at(player_pos) = location_of_player_pos;
    player_pos += 5;
    location_of_player_pos = locations.at(player_pos);
    locations.at(player_pos) = 'P';
    display_board(locations,width);
    player_turn = false;
  }
}

}

return 0;

}




//DEVELOPER NOTES
/*
Zombie game on a grid
using keyboard to move around and make choices
go to houses to collect supplies
have a dice roll kill zombies
goal is to survive as long as possible
*/
/*
location types
1.loot places (houses) (find loot at higher rates/zombies occur at lower rates POSSIBLY MAKE IT A HOMEBASE)
2.open path (find loot at lower rates/zombies occur at higher rates)


PUT IN MORE LOCATION TYPES LATER
*/
