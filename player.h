// Contains the player class, to store information of the player.
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class player{
    private:
    int attack, defense, health, maxHealth;
    bool defending = false;
    int level = 1;
    public:
    player(int att, int def, int hp);
    ~player();
    // Similar to enemy class, player class has a damage and attacked function
    int attacked(int damage);
    int damage();
    void setDefending(bool d);

    // When the player levels up, the player can increase either their attack or defense
    // Health increases by a set amount each level (3), along with maxHealth
    void levelUp(char stat);

    // Prints out player stats
    void printPlayer();
};

#endif