//This is part of the Builder Pattern
//This Builder is for building a Tank Fighter
//Tank Fighters are Fighters who ability priorities are (in descending order) 
//Constitution, Dexterity, Strength, Intelligence, Charisma, Wisdom 

#include "TankBuilder.h"


int TankBuilder::getHealthPoints()
{
	return hp;
}

int TankBuilder::getLevel()
{
	return level;
}

//Assign stats to the Fighter based on sub-type's priorities
void TankBuilder::assignStats(int level, int values[])
{	
	this -> level = level;

	//Generates the 6 stats and sorts them in descending order
	sortStats(values[0], values[1], values[2], values[3], values[4], values[5]);	

	//Set stats based on sub-class priorities	
	int	intModifier = Modifier::ability(stats[3]),			//Intelligence Modifier used for the Fighter class' stat generation. (NOTE: stats[3] is intelligence by defintion of priority)
		multiplier = (level > 1) ? 1 : 4,					//By definition, a fighters stats have a multiplier when first generating them
		equationConstant = (2 + intModifier) * multiplier;	//By definition, this is the second part of the stat generation equation for fighters
															//The equation being Dice Roll + (2 + intelligence modifier) * multipler;
	con  = stats[0] + equationConstant;
	dex	 = stats[1] + equationConstant;
	str	 = stats[2] + equationConstant;
	intl = stats[3] + equationConstant;
	cha	 = stats[4] + equationConstant;
	wis  = stats[5] + equationConstant;

	//By the rules of d20, the Fighter's hp is determined by the constitution modifier + a d10 dice roll
	hp	 = Dice::roll(10) + Modifier::ability(con);
}

//getters

string TankBuilder::getName()
{
	return name;
}

int TankBuilder::getStrength()
{
	return str;
}

int TankBuilder::getDexterity()
{
	return dex;
}

int TankBuilder::getConstitution()
{
	return con;
}

int TankBuilder::getIntelligence()
{
	return intl;
}

int TankBuilder::getWisdom()
{
	return wis;
}

int TankBuilder::getCharisma()
{
	return cha;
}

//Not sure if this section is needed yet. Depends on gameplay rules.
Helmet* TankBuilder::buildHelmet(){return NULL;}
Armor*	TankBuilder::buildArmor(){return NULL;} 
Weapon* TankBuilder::buildWeapon(){return NULL;}
Shield* TankBuilder::buildShield(){return NULL;}
Belt*	TankBuilder::buildBelt(){return NULL;}
Ring*	TankBuilder::buildRing(){return NULL;}
Boots*	TankBuilder::buildBoots(){return NULL;} 