#include "enemy.h"
#include <random>
using namespace std;
enemy::enemy(int att, int def, int hp, bool random_gen){
    if (random_gen){
        attack = rand() % 7 + 5; // random number from 5 to 11
        defense = rand() % 7 + 5; // random number from 5 to 11
        health = rand() % 7 + 20; // random number from 20 to 26
        maxHealth = health;
    } else {
        attack = att;
        defense = def;
        health = hp;
        maxHealth = hp;
    }
}
enemy::~enemy(){
}

void enemy::setDefending(bool d){
    defending = d;
}

void enemy::setPattern(string p){
    if (p.length() > 0){
        pattern = p;
    }
}

char enemy::getAction(){
    char nextAction = pattern[0];
    pattern.push_back(nextAction);
    pattern.erase(0);
    return nextAction;
}

int enemy::attacked(int damage){
    if (defending) {
        return health;
    }
    if (defense >= damage) {
        damage = 0;
    } else {
        damage = damage - defense;
    }
    if (damage >= health) {
        health = 0;
    } else {
        health -= damage;
    }
    return health;
}

int enemy::damage(){
    return attack;
}

void enemy::printEnemy() {
    cout << "Enemy stats:" << endl;
    cout << "HP: " << health << "/" << maxHealth << endl;
}