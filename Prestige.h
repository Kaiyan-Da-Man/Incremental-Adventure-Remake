#pragma once
#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;
//Prestige File if we have enough time to implement it
class Hero;

class Prestige
{
	private:
	double stat_point;

	public:
	Prestige();
	Prestige(double stat_point);
	void add_stat_point();

	void set_stat_point(double stat_point);
	void stat_menu(vector<Hero>& heroes);
	double get_stat_point();
};
