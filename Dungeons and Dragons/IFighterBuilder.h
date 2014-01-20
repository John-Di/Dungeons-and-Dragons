//Part of the Builder pattern
//This is the Fighter builder Interface
//This interface allows us to build multiple types of Fighters without having to know which type until runtime using polymorphism

#pragma once

#include "Fighter.h"
#include "d20.h"
#include <algorithm>

using namespace d20;

class IFighterBuilder
{
	protected:

		int stats[6];										//For sorting the 6 stats in the implementation
		int hp, level, str, dex, con, intl, wis, cha, exp;	//Fighter ability scores and stats
		string name;										//Fighter name
	
	public: 
		
		//utility
		void sortStats(int, int, int, int, int, int);
		

		virtual void assignStats(int, int[]) = 0;

		//getters
		virtual string getName() = 0;
		virtual int getHealthPoints() = 0;
		virtual int getLevel() = 0;		
		virtual int getStrength() = 0;
		virtual int getDexterity() = 0;
		virtual int getConstitution() = 0;
		virtual int getIntelligence() = 0;
		virtual int getWisdom() = 0;
		virtual int getCharisma() = 0;

		virtual Helmet* buildHelmet() = 0;
		virtual Armor*	buildArmor() = 0;
		virtual Weapon* buildWeapon() = 0;
		virtual Shield* buildShield() = 0;
		virtual Belt*	buildBelt() = 0;
		virtual Ring*	buildRing() = 0;
		virtual Boots*	buildBoots() = 0;

};