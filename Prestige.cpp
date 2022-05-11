#include"Prestige.h"
#include "Hero.h"
#include"Functions.h"


//Prestige prestige;

Prestige::Prestige()
{
	stat_point = 0.0;
}
Prestige::Prestige(double stat_point)
{
	this -> stat_point = stat_point;
}
void Prestige::set_stat_point(double stat_point)
{
	stat_point = stat_point;
}
double Prestige::get_stat_point()
{
	return stat_point;
}

void Prestige::stat_menu(vector<Hero>& heroes) //Menu where the user will be able to spend their stat points
{
	//Initial Status outpup / Status before prestige
	cout << "Current Status: " << endl;
	cout << setw(23) << setfill('-') << "-" << "\n";
	cout << "| " << setw(20) << setfill(' ') << left << "Hero" << "|" << endl;
	cout << "| " << setw(10) << setfill(' ') << left << "HP: " << setw(10) << setfill(' ') << left << heroes[0].get_HP() << "|" << endl;
	cout << "| " << setw(10) << setfill(' ') << left << "Damage: " << setw(10) << setfill(' ') << left << heroes[0].get_Damage() << "|" << endl;
	cout << "| " << setw(10) << setfill(' ') << left << "Armor: " << setw(10) << setfill(' ') << left << heroes[0].get_Armor() << "|" << endl;
	cout << "| " << setw(10) << setfill(' ') << left << "Healing: " << setw(10) << setfill(' ') << left << heroes[0].get_Healing() << "|" << endl;
	cout << setw(23) << setfill('-') << "-" << "\n";
	cout << endl;
	int Choice;
	if(stat_point >= 1.0)//Will allow the user to add to their stats if they have enough stat points
	{
		do
		{
			if(stat_point == 0)	// checks if user used up all stat points
				break;

			cout << "***Prestige Menu***" << endl; //Will let the user pick which boost to use a stat point on
			cout << "Total stat points: " << stat_point << endl;
			cout << "Choose the stat you would like to boost for your Hero: " << endl;
			cout << " 1: Adds 10 to your Hero's max Health" << endl;
			cout << " 2: Adds 5 to your Hero's total Damage" << endl;
			cout << " 3: Adds 5 to your Hero's Armor" << endl;
			cout << " 4: Adds 5 to your Hero's Healing" << endl;
			cout << " 0: Exit menu" << endl;
			cout << "Enter a number: ";
			cin >> Choice;
			cout << endl;

			switch (Choice)
			{
			case 1:
				heroes[0].add_MaxHP();
				stat_point--;
				break;

			case 2:
				heroes[0].add_Damage();
				stat_point--;
				break;

			case 3:
				heroes[0].add_Armor();
				stat_point--;
				break;

			case 4:
				heroes[0].add_Healing();
				stat_point--;
				break;

			case 0:
				break;

			default:
				cout << "Please enter a valid choice" << endl;
				break;
			}
		} while (Choice != 0);
	}
}
void Prestige::add_stat_point() //Adds a stat point if the Hero levels up
{
	stat_point++;
}

