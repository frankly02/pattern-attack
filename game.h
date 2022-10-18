// Contains the game class, to store state of the game.
#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "enemy.h"
using namespace std;

class game{
    private:
    enemy *currentEnemy;
    player *currentPlayer;
    int enemyNum;
    public:
    game();
    ~game();
    // Prints out the current state of the game
    void currentState();

    // When enemy is defeated, delete current and create a new one
    // Power scaling will be based on enemyNum
    void enemyDefeated(string newPattern);

    // Level up the player, given a stat to level
    void levelPlayer(char stat);

    // This function is what progresses the game. Takes a player action, and progresses the game from there\
    // In current version, it will check who's defending, then it will calculate attacks.
    // Then, after attacks are calculated, if anyone is dead, function will level up player, or end game
    // depending on who died. Returns 0 if no one died, -1 if player died, 1 if enemy died
    // Just a note: if both enemy and player dies, the game counts as a loss.
    int takeTurn(char playerAction);
};

#endif