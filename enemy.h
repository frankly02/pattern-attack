// Contains the enemy class, to store the information of the enemy. Parameters include attack, defense, and attack pattern.

#ifndef ENEMY_H
#define ENEMY_H

class enemy{
  private:
  int attack, defense;
  string pattern;
  public:
  enemy(int attack, int defense, bool rand);
  ~enemy();
};
#endif
