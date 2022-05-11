#include "Hero.h"

Hero::Hero(int runs)
{
    HP = MaxHP = 100.0 * runs;
    Damage = 10.0 * runs;
    Armor = 5.0 * runs;
    Healing = 5.0 * runs;
}

Hero::Hero(double MaxHP, double HP, double Damage, double Armor, double Healing, int level, int XP)
{
    this -> HP = MaxHP = HP;
    this -> Damage = Damage;
    this -> Armor = Armor;
    this -> Healing = Healing;
}

void Hero::attack(vector<Enemy>& enemies) //Subtracts Hero's Damage from Enemy's HP levels until the HP is 0
{
    enemies[0].set_HP(enemies[0].get_HP() - Damage);
}

//Heal function for the hero to boost their HP during the battle
void Hero::heal()
{
    HP += Healing;
}

//add functions to boost the stats of the hero
void Hero::add_Damage()
{
    Damage += 5;
}

void Hero::add_MaxHP()
{
    MaxHP += 10;
    HP += 10;
}

void Hero::add_Armor()
{
    Armor += 5;
}

void Hero::add_Healing()
{
    Healing += 5;
}
//Revive function for when the Hero dies
void Hero::revive()
{
    HP = MaxHP;
}

// get/set functions
void Hero::set_HP(double hp)
{
    HP = hp;
}

void Hero::set_Damage(double damage)
{
    Damage = damage;
}

void Hero::set_Armor(double armor)
{
    Armor = armor;
}

void Hero::set_Healing(double healing)
{
    Healing = healing;
}

double Hero::get_HP()
{
    return HP;
}

double Hero::get_Damage()
{
    return Damage;
}

double Hero::get_Armor()
{
    return Armor;
}

double Hero::get_Healing()
{
    return Healing;
}

double Hero::get_MaxHP()
{
    return MaxHP;
}
