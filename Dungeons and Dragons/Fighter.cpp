#pragma once

#include "Fighter.h"

Fighter::Fighter() : ICharacter() {}

Fighter::Fighter(string name) : ICharacter(name)	{}

Fighter::Fighter(string name, int hp, int level, int str, int dex, int con, int intl, int wis, int cha) : ICharacter(name, hp, level, str, dex, con, intl, wis, cha){}

Fighter::Fighter(string name, int hp, int level, int str, int dex, int con, int intl, int wis, int cha,
	Helmet helmet, 
	Armor armor, 
	Weapon weapon, 
	Shield shield, 
	Ring ring1, 
	Ring ring2, 
	Belt belt, 
	Boots boots) : ICharacter(name, hp, level, str, dex, con, intl, wis, cha, helmet, armor, weapon, shield, ring1, ring2, belt, boots){}

void Fighter::levelUp()
{
	this -> level++;
	
	//When a Fighter levels up, his Health Points (HP) go up by a 1d10 roll + the constitution modifier
	this -> setHP(this -> getHP() 
		        + Dice::roll(10) 
				+ Modifier::ability(this -> getConstitution()));
}

void Fighter::updateStats(int str, int dex, int con, int intl, int wis, int cha)
{
	this -> str += str;
	this -> dex += dex;
	this -> con += con;
	this -> intl += intl;
	this -> wis += wis;
	this -> cha += cha;

	notify(*this);
}

int Fighter::getAttackBonus1()
{
	//The first attack bonus is the same as the Fighter's level with a cap at 20.
	return (level <= 20) ? level : 20;
}

int Fighter::getAttackBonus2()
{
	//the 2nd attack bonus is only 5 less than the 1st bonus if that bonus is greater than 5, otherwise it's 0
	return (getAttackBonus1() <= 5) ? 0 : getAttackBonus1() - 5;
}

int Fighter::getAttackBonus3()
{
	//the 3rd attack bonus is only 5 less than the 2nd bonus if that bonus is greater than 5, otherwise it's 0
	return (getAttackBonus2() <= 5) ? 0 : getAttackBonus2() - 5;
}

int Fighter::getAttackBonus4()
{
	//the 4th attack bonus is only 5 less than the 3rd bonus if that bonus is greater than 5, otherwise it's 0
	return (getAttackBonus3() <= 5) ? 0 : getAttackBonus3() - 5;
}
