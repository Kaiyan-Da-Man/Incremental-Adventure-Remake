#include "Floor.h"


//These functions assign HP and Damage to the enemy units
/*
Every 2 floors, the stats of the enemy HP and Damage will be increased incrementally togive the Hero a greater challenge
Every 3 floors, another Enemy unit will be spawned with the same stats as the other units on that floor
*/
void Floor_1(vector<Enemy>& enemies, int runs)
{
    Enemy e("Enemy 1", 20 * runs, 5 * runs);
    enemies.push_back(e);
}
void Floor_2(vector<Enemy>& enemies, int runs)
{
	Enemy e("Enemy 1", 20 * runs, 5 * runs);
	enemies.push_back(e);
}
void Floor_3(vector<Enemy>& enemies, int runs)
{
	Enemy e("Enemy 1", 20 * runs, 10 * runs);
	enemies.push_back(e);
}
void Floor_4(vector<Enemy>& enemies, int runs)
{
	Enemy e("Enemy 1", 20 * runs, 10 * runs);
	enemies.push_back(e);

	Enemy e_2("Enemy 2", 20 * runs, 10 * runs);
	enemies.push_back(e_2);
}
void Floor_5(vector<Enemy>& enemies, int runs)
{
	Enemy e("Enemy 1", 30 * runs,15 * runs);
        enemies.push_back(e);

        Enemy e_2("Enemy 2", 30 * runs,15 * runs);
        enemies.push_back(e_2);
}
void Floor_6(vector<Enemy>& enemies, int runs)
{
        Enemy e("Enemy 1", 30 * runs,15 * runs);
        enemies.push_back(e);

        Enemy e_2("Enemy 2", 30 * runs,15 * runs);
        enemies.push_back(e_2);
}
void Floor_7(vector<Enemy>& enemies, int runs)
{
        Enemy e("Enemy 1", 40 * runs,20 * runs);
        enemies.push_back(e);

        Enemy e_2("Enemy 2", 40 * runs,20 * runs);
        enemies.push_back(e_2);

        Enemy e_3("Enemy 3", 40 * runs,20 * runs);
        enemies.push_back(e_3);
}
void Floor_8(vector<Enemy>& enemies, int runs)
{
        Enemy e("Enemy 1", 40 * runs,20 * runs);
        enemies.push_back(e);

        Enemy e_2("Enemy 2", 40 * runs,20 * runs);
        enemies.push_back(e_2);

        Enemy e_3("Enemy 3", 40 * runs,20 * runs);
        enemies.push_back(e_3);
}
void Floor_9(vector<Enemy>& enemies, int runs)
{
        Enemy e("Enemy 1", 50 * runs,25 * runs);
        enemies.push_back(e);

        Enemy e_2("Enemy 2", 50 * runs,25 * runs);
        enemies.push_back(e_2);

        Enemy e_3("Enemy 3", 50 * runs,25 * runs);
        enemies.push_back(e_3);
}
void Floor_10(vector<Enemy>& enemies, int runs)
{
        Enemy e("Enemy 1", 50 * runs,25 * runs);
        enemies.push_back(e);

        Enemy e_2("Enemy 2", 50 * runs,25 * runs);
        enemies.push_back(e_2);

        Enemy e_3("Enemy 3", 50 * runs,25 * runs);
        enemies.push_back(e_3);

	Enemy e_4("Enemy 4", 50 * runs,25 * runs);
	enemies.push_back(e_4);
}
