// main function

#include "enemy.h"
#include "player.h"
#include "game.h"
using namespace std;

// Array of some basic patterns. 
string basicPatterns[10] = {
    "aadada",
    "adadd",
    "ad",
    "ddaad",
    "adaaa",
    "dadaaa",
    "daa",
    "dad",
    "adaddaaaa",
    "aaaaaad"
};

int main() {
    // Main function, while user input is valid, starts a game and keeps asking for input
    // Based on how a turn results (return value of game::takeTurn), loop for 
    // next turn, level up player and create new enemy if enemy is defeated,
    // or terminate game if player is defeated.

    cout << "Welcome to Pattern Attack." << endl;
    cout << "Creating game..." << endl;

    game *currentGame = new game();
    cout << "Game created. Input any character to begin." << endl;

    // game loop
    char userInput;
    cin >> userInput;
    while (true) {
        int result;
        currentGame->currentState();
        cout << "Input 'a' to attack, 'd' to defend." << endl;
        cin >> userInput;
        if (userInput == 'a' || userInput == 'd') {
            result = currentGame->takeTurn(userInput);
            if (result == 1) {
                cout << "Enemy defeated!" << endl;
                char stat = 'n';
                while (stat != 'a' && stat != 'd') {
                    cout << "Input 'a' to increase attack, 'd' to increase defense, 'q' to quit." << endl;
                    cin >> stat;
                }
                currentGame->levelPlayer(stat);
                int rng = rand() % 10;
                currentGame->enemyDefeated(basicPatterns[rng]);
            } else if (result == -1) {
                cout << "You died!" << endl;
                break;
            }
        } else if (userInput == 'q') {
            break;
        }
    }
    cout << "ggs" << endl;
}