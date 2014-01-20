//This is part of the Builder Pattern
//This Builder is for building a Bully Fighter
//Bully Fighters are Fighters who ability priorities are (in descending order) 
//Strength, Constitution, Dexterity, Intelligence, Charisma, Wisdom

#pragma once

#include "IFighterBuilder.h"

class BullyBuilder : public IFighterBuilder
{
	public:

		//getters
	   	string getName();
	
		int getHealthPoints();
		int getLevel();
		int getStrength();
		int getDexterity();
		int getConstitution();
		int getIntelligence();
		int getWisdom();
		int getCharisma();

		Helmet* buildHelmet();
		Armor*	buildArmor(); 
		Weapon* buildWeapon();
		Shield* buildShield();
		Belt*	buildBelt();
		Ring*	buildRing();
		Boots*	buildBoots(); 

		//Utility
		void assignStats(int, int[]);
};

