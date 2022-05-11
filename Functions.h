#pragma once
#include <iostream>
#include <vector>
#include <unistd.h>
#include "Hero.h"
#include "Enemy.h"
#include "Prestige.h"

class Prestige;

void setHeroes(vector<Hero>& heroes, int runs); //Function to set up the initial stats of the Hero

void check(vector<Hero>& heroes, vector<Enemy>& enemies, vector<Hero>& deadHeroes, int& level, int& XP, int& reqXP, Prestige &prestige); //Function to see if the Hero or an enemy has died

void battle(vector<Hero>& heroes, vector<Enemy>& enemies, int& level, int& XP, int& reqXP, Prestige &prestige, int floor, vector<Hero>& deadHeroes); //Function to pit the Hero and the enemies against each other

void floor(int i, vector<Enemy>& enemies, int runs); //Function to activate the given floor the Hero is on

void reincarnation(int& i, vector<Hero>& heroes, vector<Hero>& deadHeroes); //Funxction used when the Hero dies

int nextLevel(int level);

void levelUp(int& level, int& XP, int& reqXP, Prestige &prestige);

void printBattle(vector<Hero> heroes, vector<Enemy> enemies, int level, int floor, int XP, Prestige prestige, int reqXP);