# pattern-attack

Pattern Attack V1

Pattern Attack is a basic turn-based combat minigame, heavily based off popular combat systems in RPG games such as Pokemon, Octopath Traveler, etc.
The player has attack and defense points, and they face one-on-one combat with a generated enemy, who also has attack and defense stats.

The enemy will act based on a set pattern, alternating between attack and defense. The goal of the player is to defeat as many enemies as possible
before dying (reach HP = 0).

After killing one enemy, the player will level up. The game will prompt the user for a stat (attack or defense) to increase as a reward, before
generating a new, stronger enemy and continuing.

At the current version (V1), it is very bare bones and as such will feel very basic and linear. The goal is to add more feature to create
a more dynamic gaming experience. For now though, enjoy it for what it is! :)

Implemented in C++.

Changelog:
  V1: Initial version
  
Future version ideas:
  Magic system: Player and enemies can cast spells, causing different effects (heal, damage over time, etc.)
  
  Status effects: Player and enemies can have certain status effects, positive and negative, adding another layer to consider
  
  Boss fights: At set intervals, create a stronger than normal enemy for the player to face
  
  Equipment: Player can equip equipment for stat buffs and possible additional effects
  
  GUI: Create a Graphical User Interface, making user input easier much more visually appealing, and easier
