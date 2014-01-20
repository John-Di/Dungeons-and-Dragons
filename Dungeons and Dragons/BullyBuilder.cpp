//This is part of the Builder Pattern
//This Builder is for building a Bully Fighter
//Bully Fighters are Fighters who ability priorities are (in descending order) 
//Strength, Constitution, Dexterity, Intelligence, Charisma, Wisdom

#include "BullyBuilder.h"

int BullyBuilder::getHealthPoints()
{
	return hp;
}

int BullyBuilder::getLevel()
{
	return level;
}

//Assign stats to the Fighter based on sub-type's priorities
void BullyBuilder::assignStats(int level, int values[])
{	
	this -> level = level;

	//Sorts the 6 generated stats in descending order
	sortStats(values[0], values[1], values[2], values[3], values[4], values[5]);						

	//Set stats based on sub-class priorities	
	int	intModifier = Modifier::ability(stats[3]),			//Intelligence Modifier used for the Fighter class' stat generation. (NOTE: stats[3] is intelligence by defintion of priority)
		multiplier = (level > 1) ? 1 : 4,					//By definition, a fighters stats have a multiplier when first generating them
		equationConstant = (2 + intModifier) * multiplier;	//By definition, this is the second part of the stat generation equation for fighters
															//The equation being Dice Roll + (2 + intelligence modifier) * multipler;
	str  = stats[0] + equationConstant;
	con	 = stats[1] + equationConstant;
	dex	 = stats[2] + equationConstant;
	intl = stats[3] + equationConstant;
	cha	 = stats[4] + equationConstant;
	wis  = stats[5] + equationConstant;

	//By the rules of d20, the Fighter's hp is determined by the constitution modifier + a d10 dice roll
	hp	 = Dice::roll(10) + Modifier::ability(con);
}

//getters
string BullyBuilder::getName()
{
	return name;
}

int BullyBuilder::getStrength()
{
	return str;
}

int BullyBuilder::getDexterity()
{
	return dex;
}

int BullyBuilder::getConstitution()
{
	return con;
}

int BullyBuilder::getIntelligence()
{
	return intl;
}

int BullyBuilder::getWisdom()
{
	return wis;
}

int BullyBuilder::getCharisma()
{
	return cha;
}

//Not sure if this section is needed yet. Depends on gameplay rules.
Helmet* BullyBuilder::buildHelmet(){return NULL;}
Armor*	BullyBuilder::buildArmor(){return NULL;} 
Weapon* BullyBuilder::buildWeapon(){return NULL;}
Shield* BullyBuilder::buildShield(){return NULL;}
Belt*	BullyBuilder::buildBelt(){return NULL;}
Ring*	BullyBuilder::buildRing(){return NULL;}
Boots*	BullyBuilder::buildBoots(){return NULL;} 