#include "Functions.h"
#include "Floor.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

void setHeroes(vector<Hero>& heroes, int runs) //This function sets a Hero into the vector, allowing the battle function to utilize it
{
    Hero h(runs);
    heroes.push_back(h);
}

void check(vector<Hero>& heroes, vector<Enemy>& enemies, vector<Hero>& deadHeroes, int& level, int& XP, int& reqXP, Prestige &prestige) //This will check if the hero or an enemy has died, then erase their stats to the initial state
{

	// checks if hero died
	for(int i = 0; i < heroes.size(); i++)
	{
		if(heroes[i].get_HP() <= 0)
		{
            		cout << "Hero has died." << endl;
			deadHeroes.push_back(heroes[0]);
	  		heroes.erase(heroes.begin());
        	}
	}
	// checks for any enemy deaths
	for(int i = 0; i < enemies.size(); i++)
	{
		if(enemies[i].get_HP() <= 0)
		{
			cout << enemies[i].get_Name() << " has died." << endl;
			cout << "Hero has recieved " << enemies[i].get_XP() << " XP" << endl; //Gives the hero XP after the enemy's death
			XP += enemies[i].get_XP();
			if(XP >= reqXP)
				levelUp(level, XP, reqXP, prestige);
			enemies.erase(enemies.begin() + i);
		}
	}
}

void battle(vector<Hero>& heroes, vector<Enemy>& enemies, int& level, int& XP, int& reqXP, Prestige &prestige, int floor, vector<Hero>& deadHeroes) //Function to execute the atack funtions for the Hero and the Enemies
{
	// gets the size of the bigger vector
    	int size = heroes.size();
    	if(size < enemies.size())
        	size = enemies.size();

	srand(time(NULL));

    // will keep going until all heroes or all enemies are defeated
    while(1)
    {
        // heroes' turn
        for(int i = 0; i < heroes.size(); i++)
	{
		int healChance = rand() % 3;	// random chance to heal
            	sleep(1);

            	check(heroes, enemies, deadHeroes, level, XP, reqXP, prestige);
			if(enemies.size() == 0)
        		return;

            		if((heroes[i].get_HP() <= heroes[i].get_MaxHP() * .75) && (heroes[i].get_Healing() > 0) && (healChance == 0))
				{
					heroes[i].heal();
					printBattle(heroes, enemies, level, floor, XP, prestige, reqXP);
					cout << "Hero has healed " << heroes[i].get_Healing() << " HP!" << endl;
				}
				else if (enemies[0].get_HP() < heroes[i].get_Damage())
				{
					heroes[i].attack(enemies);
					enemies[0].set_HP(0);
					printBattle(heroes, enemies, level, floor, XP, prestige, reqXP);
            				cout << "Hero " << "dealt " << heroes[i].get_Damage() << " damage to " << enemies[0].get_Name() << "!" << endl;
				}
				else
				{
					heroes[i].attack(enemies);
					printBattle(heroes, enemies, level, floor, XP, prestige, reqXP);
            				cout << "Hero " << "dealt " << heroes[i].get_Damage() << " damage to " << enemies[0].get_Name() << "!" << endl;
				}
        }
        check(heroes, enemies, deadHeroes, level, XP, reqXP, prestige);
        if(enemies.size() == 0)
            return;

        // enemies' turn
	for(int i = 0; i < enemies.size(); i++)
	{
        	sleep(1);
            	check(heroes, enemies, deadHeroes, level, XP, reqXP, prestige);
		if(heroes.size() == 0)
            	return;

		if(enemies[i].get_Damage() < heroes[0].get_Armor())
		{
			printBattle(heroes, enemies, level, floor, XP, prestige, reqXP);
			cout << enemies[i].get_Name() << " dealt 0 damage to the hero!" << endl;
		}
		else
		{
			enemies[i].attack(heroes);
			printBattle(heroes, enemies, level, floor, XP, prestige, reqXP);
			cout << enemies[i].get_Name() << " dealt " << enemies[i].get_Damage() - heroes[0].get_Armor() << " damage to the hero!" << endl;
		}
        }
        check(heroes, enemies, deadHeroes, level, XP, reqXP, prestige);
        if(heroes.size() == 0)
            return;

    }
}
void floor(int i, vector<Enemy>& enemies, int runs) //Will call the floor number to set the stat count and number of enemies
{
	switch(i)
	{
		case 1:
			Floor_1(enemies, runs);
			break;

		case 2:
			Floor_2(enemies, runs);
			break;

		case 3:
			Floor_3(enemies, runs);
			break;

		case 4:
			Floor_4(enemies, runs);
			break;

		case 5:
			Floor_5(enemies, runs);
			break;

		case 6:
			Floor_6(enemies, runs);
			break;

		case 7:
			Floor_7(enemies, runs);
			break;

		case 8:
			Floor_8(enemies, runs);
			break;

		case 9:
			Floor_9(enemies, runs);
			break;

		case 10:
			Floor_10(enemies, runs);
			break;

	}
}

void reincarnation(int& i, vector<Hero>& heroes, vector<Hero>& deadHeroes) //If the Hero dies, they will be reincarnated and reset the floor number
{
	i = 0;
	for(int j = 0; j < deadHeroes.size(); j++) //This will give the hero back their current stats after being revived
	{
		deadHeroes[j].revive();
		heroes.push_back(deadHeroes[0]);
		deadHeroes.erase(deadHeroes.begin());
	}
	int deathCounter = 0; //Counter to keep track of all the times the Hero dies
	deathCounter++;
}

int nextLevel(int level) //Function to set the parameter of how much XP is needed to accend to the next nevel
{
	return ceil((0.04 * pow(level, 3)) + (0.8 * pow(level, 2)) + (2 * level));
}

void levelUp(int& level, int& XP, int& reqXP, Prestige &prestige) //Function to level up the Hero if enought Xp is gained
{
	XP -= reqXP;
	level++;
	prestige.add_stat_point();
	cout << "Leveled up to LEVEL " << level << endl;
	reqXP = nextLevel(level);
}

void printBattle(vector<Hero> heroes, vector<Enemy> enemies, int level, int floor, int XP, Prestige prestige, int reqXP) //Function to output the game and show the user what is going on
{
	// Level: xxxxx     Stat Points: xxxxx     XP: xxxxx/reqXP     Floor: xxxxx
	cout << setw(143) << setfill('_') << "_" << endl;
	cout << "Level: " << setfill(' ') << setw(5) << level << "  |  ";
	cout << "Stat Points: " << setfill(' ') << setw(5) << prestige.get_stat_point() << "  |  ";
	cout << "XP: " << setfill(' ') << setw(5) << XP << "/" << reqXP << "  |  ";
	cout << "Floor: " << setfill(' ') << setw(5) << floor;
	cout << endl;

	//Hero loop
	for(int i = 0; i < heroes.size(); i++)
		cout << setw(23) << setfill('-') << "-" << "\t";
	cout << endl;
	for(int i = 0; i < heroes.size(); i++)
		cout << "| " << setw(20) << setfill(' ') << left << "Hero" << "|" << "\t";
	cout << endl;
	for(int i = 0; i < heroes.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "HP: " << setw(10) << setfill(' ') << left << heroes[0].get_HP() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < heroes.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "Damage: " << setw(10) << setfill(' ') << left << heroes[0].get_Damage() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < heroes.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "Armor: " << setw(10) << setfill(' ') << left << heroes[0].get_Armor() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < heroes.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "Healing: " << setw(10) << setfill(' ') << left << heroes[0].get_Healing() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < heroes.size(); i++)
		cout << setw(23) << setfill('-') << "-" << "\t";
	cout << endl;

	//Enemy loop
	for(int i = 0; i < enemies.size(); i++)
		cout << setw(23) << setfill('-') << "-" << "\t";
	cout << endl;
	for(int i = 0; i < enemies.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "Name: " << setw(10) << setfill(' ') << left << enemies[i].get_Name() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < enemies.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "HP: " << setw(10) << setfill(' ') << left << enemies[i].get_HP() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < enemies.size(); i++)
		cout << "| " << setw(10) << setfill(' ') << left << "Damage: " << setw(10) << setfill(' ') << left << enemies[i].get_Damage() << "|" << "\t";
	cout << endl;
	for(int i = 0; i < enemies.size(); i++)
		cout << setw(23) << setfill('-') << "-" << "\t";
	cout << endl;



	cout << endl;
}
