/*
All character classes are children of Character interface.
The Character interface has yet to be properly made abstract because of a lack of need for a virtual method.
*/
#pragma once

#include "Items.h"
#include "IObservable.h"
#include <string>

using namespace std;
using namespace Equipables;


class ICharacter : public IObservable
{
	protected:
		Equipables::Helmet helmet;
		Equipables::Ring ring1, ring2;
		Equipables::Weapon weapon;
		Equipables::Shield shield; 
		Equipables::Armor armor;
		Equipables::Belt belt;
		Equipables::Boots boots;

		int hp, level, str, dex, con, intl, wis, cha, exp;		

		string name;

		void levelUp();
		int checkLevelUp(int);

	public:
		//ctors
		ICharacter();
		ICharacter(string);
		ICharacter(string, int, int, int, int, int, int, int, int);
		ICharacter(string, int, int, int, int, int, int, int, int,
			    Equipables::Helmet, 
				Equipables::Armor, 
				Equipables::Weapon, 
				Equipables::Shield, 
				Equipables::Ring, 
				Equipables::Ring, 
				Equipables::Belt, 
				Equipables::Boots);

		//getters
		int getHP();
		int getLevel();
		int getStrength();
		int getDexterity();
		int getConstitution();
		int getIntelligence();
		int getWisdom();
		int getCharisma();
		int getExperience();
		string getName();

		Equipables::Helmet getHelmet();
		Equipables::Ring getRing1();
		Equipables::Ring getRing2();
		Equipables::Weapon getWeapon();
		Equipables::Shield getShield();
		Equipables::Armor getArmor();
		Equipables::Belt getBelt();
		Equipables::Boots getBoots();

		virtual int getAttackBonus1() = 0;
		virtual int getAttackBonus2() = 0;
		virtual int getAttackBonus3() = 0;
		virtual int getAttackBonus4() = 0;

		//setters
		void setHP(int);
		void setLevel(int);
		void setStrength(int);
		void setDexterity(int);
		void setConstitution(int);
		void setIntelligence(int);
		void setWisdom(int);
		void setCharisma(int);
		void gainExperience(int);
		void setName(string);

		void equipHelmet(Equipables::Helmet);
		void equipRing1(Equipables::Ring);
		void equipRing2(Equipables::Ring);
		void equipWeapon(Equipables::Weapon);
		void equipShield(Equipables::Shield);
		void equipArmor(Equipables::Armor);
		void equipBelt(Equipables::Belt);
		void equipBoots(Equipables::Boots);

		//unsetters
		Equipables::Helmet unequipHelmet();
		Equipables::Ring unequipRing1();
		Equipables::Ring unequipRing2();
		Equipables::Weapon unequipWeapon();
		Equipables::Shield unequipShield();
		Equipables::Armor unequipArmor();
		Equipables::Belt unequipBelt();
		Equipables::Boots unequipBoots();
		
		virtual void updateStats(int, int, int, int, int, int) = 0;

		string toString();

};