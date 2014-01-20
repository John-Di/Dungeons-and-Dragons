/*
All types of equipable items (ie Helmet, Armor, Weapons, Rings, Boots, Belts, Shield) are children of an Equipable interface.
The Equipable interface has yet to be properly made abstract because of a lack of need for a virtual method.
*/

#pragma once

using namespace std;

namespace Equipables
{
	class IEquipable
	{
		public: 
			IEquipable(int, int, int, int, int, int);

			int getStrength();
			int getDexterity();
			int getConstitution();
			int getIntelligence();
			int getWisdom();
			int getCharisma();

		private:
			int str, dex, con, intl, wis, cha;
	};

	class Helmet : public IEquipable
	{
		public: 
			Helmet();
			Helmet(int, int, int, int, int, int);
	};

	class Armor : public IEquipable
	{
		public: 
			Armor();
			Armor(int, int, int, int, int, int);
	};

	class Weapon : public IEquipable
	{
		public: 
			Weapon();
			Weapon(int, int, int, int, int, int);
	};

	class Shield : public IEquipable
	{
		public: 
			Shield();
			Shield(int, int, int, int, int, int);
	};
	
	class Ring : public IEquipable
	{
		public: 
			Ring();
			Ring(int, int, int, int, int, int);
	};
	
	class Belt : public IEquipable
	{
		public: 
			Belt();
			Belt(int, int, int, int, int, int);
	};
	
	class Boots : public IEquipable
	{
		public: 
			Boots();
			Boots(int, int, int, int, int, int);
	};
}
