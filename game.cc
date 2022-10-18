#include "game.h"
using namespace std;
game::game(){
    currentEnemy = new enemy(5, 5, 15, false);
    currentPlayer = new player(10, 1, 25);
    enemyNum = 0;
}
game::~game(){
    delete(currentEnemy);
    delete(currentPlayer);
}

void game::currentState(){
    currentEnemy->printEnemy();
    currentPlayer->printPlayer();
}

void game::enemyDefeated(string newPattern) {
    delete(currentEnemy);
    enemyNum += 1;
    int newAttack = 5 + enemyNum * 2;
    int newDefense = 5 + enemyNum % 2;
    int newHealth = 15 + enemyNum * 10; 
    currentEnemy = new enemy(enemy(newAttack, newDefense, newHealth, false));
    currentEnemy->setPattern(newPattern);
}

void game::levelPlayer(char stat) {
    currentPlayer->levelUp(stat);
}

int game::takeTurn(char playerAction) {
    char enemyAction = currentEnemy->getAction();
    if (playerAction == 'd') {
        currentPlayer->setDefending(true);
    }
    if (enemyAction == 'd') {
        currentEnemy->setDefending(true);
    }
    int enemyHP, playerHP;
    if (enemyAction == 'a') {
        int incomingDamage = currentEnemy->damage();
        playerHP = currentPlayer->attacked(incomingDamage);
    }
    if (playerAction == 'a') {
        int outgoingDamage = currentPlayer->damage();
        enemyHP = currentEnemy->attacked(outgoingDamage);
    }
    if (playerHP == 0) {
        return -1;
    } else if (enemyHP == 0) {
        return 1;
    }
    return 0;
}