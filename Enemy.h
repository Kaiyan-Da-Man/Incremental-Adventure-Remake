#pragma once
#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;

class Hero; //Class to store the enemies that the hero will be facing

class Enemy
{
	private:
	string Name;
	double HP;
	double Damage;
	int XP;

	public:
	Enemy();
	Enemy(string name, double HP, double Damage);
	void attack(vector<Hero>& heroes); //Attack function to deal damage to the hero

	// get/set
	void set_HP(double hp);
	void set_Damage(double damage);
	double get_HP();
	double get_Damage();
	int get_XP();
	string get_Name();
};
