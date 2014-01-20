/*
All character classes are children of Character interface.
The Character interface has yet to be properly made abstract because of a lack of need for a virtual method.
*/

#pragma once


#include <iostream>
#include <sstream>
#include "ICharacter.h"


	//ctors
	ICharacter::ICharacter() {exp = 0;}

	ICharacter::ICharacter(string name) : name(name){exp = 0;}
	
	ICharacter::ICharacter(string name, int hp, int level, int str, int dex, int con, int intl, int wis, int cha) : 
						 name(name), hp(hp), level(level), str(str), dex(dex), con(con), intl(intl), wis(wis), cha(cha){exp = 0;}
	
	ICharacter::ICharacter(string name, int hp, int level, int str, int dex, int con, int intl, int wis, int cha,
		Helmet helmet, 
		Armor armor, 
		Weapon weapon, 
		Shield shield, 
		Ring ring1, 
		Ring ring2, 
		Belt belt, 
		Boots boots) : name(name), hp(hp), level(level), str(str), dex(dex), con(con), intl(intl), wis(wis), cha(cha),
					   helmet(helmet), armor(armor), weapon(weapon), shield(shield), ring1(ring1), ring2(ring2), belt(belt), boots(boots){exp = 0;}

	//getters
	int ICharacter::getHP()
		{
			return hp;
		}
	int ICharacter::getLevel()
		{
			return level;
		}
	int ICharacter::getStrength()
		{
			return str;
		}
	int ICharacter::getDexterity()
		{
			return dex;
		}
	int ICharacter::getConstitution()
		{
			return con;
		}
	int ICharacter::getIntelligence()
		{
			return intl;
		}
	int ICharacter::getWisdom()
		{
			return wis;
		}
	int ICharacter::getCharisma()
		{
			return cha;
		}
	int ICharacter::getExperience()
		{
			return exp;
		}
	string ICharacter::getName()
		{
			return this -> name;
		}

	Helmet ICharacter ::getHelmet()
		{
			return helmet;
		}
	Ring   ICharacter ::getRing1()
		{
			return ring1;
		}
	Ring   ICharacter ::getRing2()
		{
			return ring2;
		}
	Weapon ICharacter ::getWeapon()
		{
			return weapon;
		}
	Shield ICharacter ::getShield()
		{
			return shield;
		}
	Armor  ICharacter ::getArmor()
		{
			return armor;
		}
	Belt   ICharacter ::getBelt()
		{
			return belt;
		}
	Boots  ICharacter ::getBoots()
		{
			return boots;
		}
	
	//setters
	void ICharacter::setHP(int hp)
		{
			this -> hp = hp;
		}
	void ICharacter::setLevel(int level)
		{
			this -> level = level;
		}
	void ICharacter::setStrength(int str)
		{
			this -> str = str;
		}
	void ICharacter::setDexterity(int dex)
		{
			this -> dex = dex;
		}
	void ICharacter::setConstitution(int con)
		{
			this -> con = con;
		}
	void ICharacter::setIntelligence(int intl)
		{
			this -> intl = intl;
		}
	void ICharacter::setWisdom(int wis)
		{
			this -> wis = wis;
		}
	void ICharacter::setCharisma(int cha)
		{
			this -> cha = cha;
		}
	void ICharacter::gainExperience(int exp)					//After spending exp to level up (if level up is possible with amount of exp), 
		{														//the remaining amount of exp becomes the new value
			this -> exp = checkLevelUp(exp);			
		}
	void ICharacter::setName(string name)
		{
			this -> name = name;
		}

	void ICharacter::equipHelmet(Helmet helmet)
		{
			this -> helmet = helmet;

			updateStats(helmet.getStrength(), helmet.getDexterity(), helmet.getConstitution(), helmet.getIntelligence(), helmet.getWisdom(), helmet.getCharisma());
		}
	void ICharacter::equipRing1(Ring ring)
		{
			this -> ring1 = ring;

			updateStats(ring.getStrength(), ring.getDexterity(), ring.getConstitution(), ring.getIntelligence(), ring.getWisdom(), ring.getCharisma());
		}
	void ICharacter::equipRing2(Ring ring)
		{
			this -> ring2 = ring;

			updateStats(ring.getStrength(), ring.getDexterity(), ring.getConstitution(), ring.getIntelligence(), ring.getWisdom(), ring.getCharisma());
		}
	void ICharacter::equipWeapon(Weapon weapon)
		{
			this -> weapon = weapon;

			updateStats(weapon.getStrength(), weapon.getDexterity(), weapon.getConstitution(), weapon.getIntelligence(), weapon.getWisdom(), weapon.getCharisma());
		}
	void ICharacter::equipShield(Shield shield)
		{
			this -> shield = shield;

			updateStats(shield.getStrength(), shield.getDexterity(), shield.getConstitution(), shield.getIntelligence(), shield.getWisdom(), shield.getCharisma());
		}
	void ICharacter::equipArmor(Armor armor)
		{
			this -> armor = armor;

			updateStats(armor.getStrength(), armor.getDexterity(), armor.getConstitution(), armor.getIntelligence(), armor.getWisdom(), armor.getCharisma());
		}
	void ICharacter::equipBelt(Belt belt)
		{
			this -> belt = belt;

			updateStats(belt.getStrength(), belt.getDexterity(), belt.getConstitution(), belt.getIntelligence(), belt.getWisdom(), belt.getCharisma());
		}
	void ICharacter::equipBoots(Boots boots)
		{
			this -> boots = boots;

			updateStats(boots.getStrength(), boots.getDexterity(), boots.getConstitution(), boots.getIntelligence(), boots.getWisdom(), boots.getCharisma());
		}

	//Unsetters
	Helmet ICharacter::unequipHelmet()
		{
			Helmet returnHelmet = helmet;

			updateStats(-helmet.getStrength(), -helmet.getDexterity(), -helmet.getConstitution(), -helmet.getIntelligence(), -helmet.getWisdom(), -helmet.getCharisma());

			this -> helmet = Helmet(0, 0, 0, 0, 0, 0);

			return returnHelmet;
		}
	Ring   ICharacter::unequipRing1()
		{
			Ring returnRing = ring1;

			updateStats(-ring1.getStrength(), -ring1.getDexterity(), -ring1.getConstitution(), -ring1.getIntelligence(), -ring1.getWisdom(), -ring1.getCharisma());

			this -> ring1 = Ring(0, 0, 0, 0, 0, 0);

			return returnRing;
		}
	Ring   ICharacter::unequipRing2()
		{
			Ring returnRing = ring2;

			updateStats(-ring2.getStrength(), -ring2.getDexterity(), -ring2.getConstitution(), -ring2.getIntelligence(), -ring2.getWisdom(), -ring2.getCharisma());

			this -> ring2 = Ring(0, 0, 0, 0, 0, 0);

			return returnRing;
		}
	Weapon ICharacter::unequipWeapon()
		{
			Weapon returnWeapon = weapon;			

			updateStats(-weapon.getStrength(), -weapon.getDexterity(), -weapon.getConstitution(), -weapon.getIntelligence(), -weapon.getWisdom(), -weapon.getCharisma());

			this -> weapon = Weapon(0, 0, 0, 0, 0, 0);

			return returnWeapon;
		}
	Shield ICharacter::unequipShield()
		{
			Shield returnShield = shield;

			updateStats(-shield.getStrength(), -shield.getDexterity(), -shield.getConstitution(), -shield.getIntelligence(), -shield.getWisdom(), -shield.getCharisma());

			this -> shield = Shield(0, 0, 0, 0, 0, 0);

			return returnShield;
		}
	Armor  ICharacter::unequipArmor()
		{
			Armor returnArmor = armor;

			updateStats(-armor.getStrength(), -armor.getDexterity(), -armor.getConstitution(), -armor.getIntelligence(), -armor.getWisdom(), -armor.getCharisma());

			this -> armor = Armor(0, 0, 0, 0, 0, 0);

			return returnArmor;
		}
	Belt   ICharacter::unequipBelt()
		{
			Belt returnBelt = belt;

			updateStats(-belt.getStrength(), -belt.getDexterity(), -belt.getConstitution(), -belt.getIntelligence(), -belt.getWisdom(), -belt.getCharisma());

			this -> belt = Belt(0, 0, 0, 0, 0, 0);

			return returnBelt;
		}
	Boots  ICharacter::unequipBoots()
		{
			Boots returnBoots = boots;

			updateStats(-boots.getStrength(), -boots.getDexterity(), -boots.getConstitution(), -boots.getIntelligence(), -boots.getWisdom(), -boots.getCharisma());

			this -> boots = Boots(0, 0, 0, 0, 0, 0);

			return returnBoots;
		}
	
	//others
	string ICharacter::toString()
	{
		ostringstream out;

		out << "Level: " << this -> getLevel() << endl
			<< "Hit Points: " << this -> getHP() << endl
			<< "Strength: " << this -> getStrength() << endl
			<< "Dexterity: " << this -> getDexterity() << endl
			<< "Constitution: " << this -> getConstitution() << endl
			<< "Intelligence: " << this -> getIntelligence() << endl
			<< "Wisdom: " << this -> getWisdom() << endl
			<< "Charisma: " << this -> getCharisma() << endl
			<< "Attack Bonuses: +" << this -> getAttackBonus1() 
			<<                "/+" << this -> getAttackBonus2() 
			<<                "/+" << this -> getAttackBonus3() 
			<<                "/+" << this -> getAttackBonus4() << endl << endl;

		return out.str();
	}

	int ICharacter::checkLevelUp(int exp) 		//Checks to see if a character's exp passed the level up threshold
	{			
		int currentExp = this -> exp,
			level = this -> level, 
			nextLevelEXP;

		if(currentExp >= (nextLevelEXP = (level * (level + 1) * 500)))
		{				
			levelUp();

			return checkLevelUp(currentExp - nextLevelEXP);
		}

		return currentExp;
	}
	void ICharacter::levelUp()
	{
		this -> level++;
	}		