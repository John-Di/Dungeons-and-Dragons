#pragma once

#include "ICharacter.h"
#include "d20.h"

using namespace d20;


class Fighter: public ICharacter
{
	public:		

		//ctor
	    Fighter();
		Fighter(string);
		Fighter(string, int, int, int, int, int, int, int, int);
		Fighter(string, int, int, int, int, int, int, int, int,
			    Equipables::Helmet, 
				Equipables::Armor, 
				Equipables::Weapon, 
				Equipables::Shield, 
				Equipables::Ring, 
				Equipables::Ring, 
				Equipables::Belt, 
				Equipables::Boots);
	
		

		//Getters
		int getAttackBonus1();
		int getAttackBonus2();
		int getAttackBonus3();
		int getAttackBonus4();

		//others
		void updateStats(int, int, int, int, int, int);
		void levelUp();
};