#include "Enemy.h"
#include "Hero.h"
#include "Functions.h"
#include "Floor.h"
#include "Prestige.h"
using namespace std;

int main()
{
	//Hero vectors
	vector<Hero> heroes;
	vector<Hero> deadHeroes;
	//Enemy vector
	vector<Enemy> enemies;
	Prestige prestige(2.0); //Gives the user an initial 2 stat points
	int level = 1;
	int XP = 0;
	int reqXP = nextLevel(level);
	int runs = 1;
	setHeroes(heroes, runs);	//Will set initial Hero stats

	while(1)
	{
		prestige.stat_menu(heroes);
		for(int i = 1; i <= 10; i++)
		{
			//cout << "Floor " << i << endl;
			floor(i, enemies, runs); //Will set battle on the given floor
			battle(heroes, enemies, level, XP, reqXP, prestige, i, deadHeroes); //Execute the battle
			if(heroes.size() == 0) //if the Hero dies
			{
				reincarnation(i, heroes, deadHeroes); //Will reset the hero while keeping the current stats
				cout << endl << "REINCARNATE" << endl;
				enemies.clear(); //Resets the enemy stats to restart the floor climb
				prestige.stat_menu(heroes);
				continue;
			}
		cout << endl;
		}

	cout << "You win" << endl; //If all floors are cleared
	runs++;

	}

return 0;
}
