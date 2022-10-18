// Contains the enemy class, to store the information of the enemy. 
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
using namespace std;

class enemy{
  private:
  int attack, defense, health, maxHealth;
  string pattern = "a";
  bool defending = false;
  public:
  enemy(int att, int def, int hp, bool random_gen);
  ~enemy();
  void setDefending(bool d);
  void setPattern(string p); // sets the enemy's action sequence as a string of 'a' and 'd's
  char getAction(); // returns the enemy's next action, then moves it to the back
  
  // when the enemy is attacked by the player with attack = damage, this function will
  // calculate the damage taken (0 if enemy is defending), modify its health, then return the remaining hp
  int attacked(int damage);

  // this will return the enemy's attack value, to be used when the enemy attacks
  int damage();

  // Prints enemy's stats (only hp)
  void printEnemy();
};
#endif

