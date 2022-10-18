#include "player.h"
using namespace std;
player::player(int att, int def, int hp){
    attack = att;
    defense = def;
    health = hp;
    maxHealth = hp;
}
player::~player(){
}

void player::setDefending(bool d) {
    defending = d;
}

int player::attacked(int damage) {
    if (defending) {
        if (health < maxHealth) {
            health += 1;
        }
        return health;
    }
    if (defense >= damage) {
        damage = 0;
    } else {
        damage = damage - defense;
    }
    if (health <= damage) {
        health = 0;
        return health;
    } else {
        health = health - damage;
        return health;
    }
}

int player::damage(){
    return attack;
}

void player::levelUp(char stat) {
    if (stat == 'a') {
        attack += 1;
    } else {
        defense += 1;
    }
    health += 3;
    maxHealth += 3;
    level += 1;
}

void player::printPlayer() {
    cout << "Player stats:" << endl;
    cout << "HP: " << health << "/" << maxHealth << endl;
    cout << "Atk: " << attack << endl;
    cout << "Def: " << defense << endl;
}
