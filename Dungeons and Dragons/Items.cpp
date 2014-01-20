#pragma once
#include "Items.h"
using namespace Equipables;

//IEquipable
IEquipable::IEquipable(int str, int dex, int con, int intl, int wis, int cha) : str(str), dex(dex), con(con), intl(intl), wis(wis), cha(cha){}

int IEquipable::getStrength()
		{
			return str;
		}

int IEquipable::getDexterity()
		{
			return dex;
		}

int IEquipable::getConstitution()
		{
			return con;
		}

int IEquipable::getIntelligence()
		{
			return intl;
		}

int IEquipable::getWisdom()
		{
			return wis;
		}

int IEquipable::getCharisma()
		{
			return cha;
		}


//IEquipable concrete classes

Helmet::Helmet() : IEquipable(0,0,0,0,0,0){};
Helmet::Helmet(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};

Armor::Armor() : IEquipable(0,0,0,0,0,0){};
Armor::Armor(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};
 
Weapon::Weapon() : IEquipable(0,0,0,0,0,0){};
Weapon::Weapon(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};

Shield::Shield() : IEquipable(0,0,0,0,0,0){};
Shield::Shield(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};

Ring::Ring() : IEquipable(0,0,0,0,0,0){};
Ring::Ring(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};

Belt::Belt() : IEquipable(0,0,0,0,0,0){};
Belt::Belt(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};
 
Boots::Boots() : IEquipable(0,0,0,0,0,0){};
Boots::Boots(int str, int dex, int con, int intl, int wis, int cha) : IEquipable(str, dex, con, intl, wis, cha){};
