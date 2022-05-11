#include "Enemy.h"

Enemy::Enemy()
{
    Name = "";
    HP = 0.0;
    Damage = 0.0;
    XP = 0;
}

Enemy::Enemy(string Name, double HP, double Damage)
{
    this->Name = Name;
    this -> HP = HP;
    this -> Damage = Damage;
    XP = Damage / 5;
}

void Enemy::attack(vector<Hero>& heroes)//Function that deals damage to the Hero during each enemy turn
{
    heroes[0].set_HP(heroes[0].get_HP() - (Damage - heroes[0].get_Armor()));
}

// get/set
void Enemy::set_HP(double hp)
{
    HP = hp;
}

void Enemy::set_Damage(double damage)
{
    Damage = damage;
}

double Enemy::get_HP()
{
    return HP;
}

double Enemy::get_Damage()
{
    return Damage;
}

int Enemy::get_XP()
{
    return XP;
}

string Enemy::get_Name()
{
    return Name;
}
