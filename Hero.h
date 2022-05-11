#pragma once
#include<iostream>
#include <vector>
#include "Enemy.h"
using namespace std;

class Enemy;

class Hero
{
	private:
	double MaxHP;
	double HP;
	double Damage;
	double Armor;
	double Healing;


	public:
	Hero(int runs);
	Hero(double MaxHP, double HP, double Damage, double Armor, double Healing, int level, int XP); //Add Experience to constructor
	void attack(vector<Enemy>& enemies); //Attack function to deal damage to the enemies
	int nextLevel(int level);
	void heal();
	void revive();

	void add_Damage();
	void add_MaxHP();
	void add_Armor();
	void add_Healing();

	// get/set functions
	void set_HP(double hp);
	void set_Damage(double damage);
	void set_Armor(double armor);
	void set_Healing(double healing);

	double get_HP();
	double get_Damage();
	double get_Armor();
	double get_Healing();
	double get_MaxHP();
};
