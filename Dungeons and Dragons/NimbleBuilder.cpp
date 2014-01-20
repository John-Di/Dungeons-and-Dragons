//This is part of the Builder Pattern
//This Builder is for building a Nimble Fighter
//Nimble Fighters are Fighters who ability priorities are (in descending order) 
//Dexterity, Constitution, Strength, Intelligence, Charisma, Wisdom

#include "NimbleBuilder.h"


int NimbleBuilder::getHealthPoints()
{
	return hp;
}

int NimbleBuilder::getLevel()
{
	return level;
}

//Assign stats to the Fighter based on sub-type's priorities
void NimbleBuilder::assignStats(int level, int values[])
{	
	this -> level = level;

	//Generates the 6 stats and sorts them in descending order
	sortStats(values[0], values[1], values[2], values[3], values[4], values[5]);					

	//Set stats based on sub-class priorities	
	int	intModifier = Modifier::ability(stats[3]),			//Intelligence Modifier used for the Fighter class' stat generation. (NOTE: stats[3] is intelligence by defintion of priority)
		multiplier = (level > 1) ? 1 : 4,					//By definition, a fighters stats have a multiplier when first generating them
		equationConstant = (2 + intModifier) * multiplier;	//By definition, this is the second part of the stat generation equation for fighters
															//The equation being Dice Roll + (2 + intelligence modifier) * multipler;
	dex  = stats[0] + equationConstant;
	con	 = stats[1] + equationConstant;
	str	 = stats[2] + equationConstant;
	intl = stats[3] + equationConstant;
	cha	 = stats[4] + equationConstant;
	wis  = stats[5] + equationConstant;

	//By the rules of d20, the Fighter's hp is determined by the constitution modifier + a d10 dice roll
	hp	 = Dice::roll(10) + Modifier::ability(con);
}


//getters
string NimbleBuilder::getName()
{
	return name;
}

int NimbleBuilder::getStrength()
{
	return str;
}

int NimbleBuilder::getDexterity()
{
	return dex;
}

int NimbleBuilder::getConstitution()
{
	return con;
}

int NimbleBuilder::getIntelligence()
{
	return intl;
}

int NimbleBuilder::getWisdom()
{
	return wis;
}

int NimbleBuilder::getCharisma()
{
	return cha;
}

//Not sure if this section is needed yet. Depends on gameplay rules.
Helmet* NimbleBuilder::buildHelmet(){return NULL;}
Armor*	NimbleBuilder::buildArmor(){return NULL;} 
Weapon* NimbleBuilder::buildWeapon(){return NULL;}
Shield* NimbleBuilder::buildShield(){return NULL;}
Belt*	NimbleBuilder::buildBelt(){return NULL;}
Ring*	NimbleBuilder::buildRing(){return NULL;}
Boots*	NimbleBuilder::buildBoots(){return NULL;} 