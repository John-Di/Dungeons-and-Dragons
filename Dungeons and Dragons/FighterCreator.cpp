//Part of the Builder Pattern
//The Creator is the class that receives a builder type and builds an object based on that builder's typing
//This is the Fighter Creator and based on it's received Builder, it will build either a Bully Fighter, a Nimble Fighter or a Tank Fighter.

#include "FighterCreator.h"


void FighterCreator::setBuilder(IFighterBuilder* builder)
{
	this -> builder = builder;
}


Fighter* FighterCreator::getFighter(string name, int level)
{
	Fighter* fighter = new Fighter();
	
	//Generating 6 values to be sorted and assigned to the Fighter's ability scores
	int diceRolls[] = {Dice::roll4D6(), Dice::roll4D6(), Dice::roll4D6(), Dice::roll4D6(), Dice::roll4D6(), Dice::roll4D6()};

	//Assign ability score priorities
	builder -> assignStats(level, diceRolls);

	//Assign ability scores
	fighter -> setCharisma		(builder -> getCharisma());
	fighter -> setConstitution	(builder -> getConstitution());
	fighter -> setDexterity		(builder -> getDexterity());
	fighter -> setStrength		(builder -> getStrength());
	fighter -> setWisdom		(builder -> getWisdom());
	fighter -> setIntelligence	(builder -> getIntelligence());	
	fighter -> setHP			(builder -> getHealthPoints());	
	fighter -> setLevel			(builder -> getLevel());
	fighter -> setName			(name);


	return fighter;
}


