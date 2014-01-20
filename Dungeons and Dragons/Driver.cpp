//ALL D20 RULES AND WHATNOT were taken from http://www.dandwiki.com/wiki/Main_Page and http://www.wikihow.com/Create-a-Dungeons-and-Dragons-Character
//http://boredoms4squares.com/2010/04/intro-to-dungeons-and-dragons-3-5-part-three/
//
//and http://www.d20srd.org/srd/classes/fighter.htm or more generally
//http://www.d20srd.org/

#pragma once

#include <iostream>
#include <stdio.h>
#include "Console.h"
#include "FighterCreator.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include "CharacterIO.h"

//Wait for user to read everything and have them press any key to continue
void wait()
{
	cout << "Press [enter] to continue..." << endl << endl;
	
	cin.ignore();
}

int main()
{
	//The console observer
	Console cs = Console();

	cout << "Welcome to the Dungeons and Dragons Fighter Class Creator!" << endl << endl
		 << "Let me introduce you to Level 1 Bully Fighter - Gavin Free" << endl << endl;

	string name = "Gavin Free";
	
	int level = 1;

	//Our builder pattern
	FighterCreator creator;
	BullyBuilder bullyBuilder;
	NimbleBuilder nimbleBuilder;
	TankBuilder tankBuilder;

	//Setting our Fighter creator to build Bully type Fighters
	creator.setBuilder(&bullyBuilder);

	//Creating a Bully Fighter with the builder pattern
	Fighter* gavin = creator.getFighter(name, level);

	//Attach the console observer to gavin
	gavin -> attach(&cs);					
	

	cout << "Let's get " << gavin -> getName() << " started!" << endl << endl;
	cout << "Gavin is all set up! Let's see his stats!" << endl << endl;
	cout << gavin -> toString();
	
	wait();
	
	/*
	cout << "Let's give Gavin some Armor:" << endl;
	
	
	//Showing how Armor classes have stats as well which work with the Character classes
	Armor gavins = Armor(10,2,3,4,5,6);

	cout << "Armor Strength: "		<< gavins.getStrength() << endl
		 << "Armor Dexterity: "		<< gavins.getDexterity() << endl
		 << "Armor Constitution: "	<< gavins.getConstitution() << endl
		 << "Armor Intelligence: "	<< gavins.getIntelligence() << endl
		 << "Armor Wisdom: "		<< gavins.getWisdom() << endl
		 << "Armor Charisma: "		<< gavins.getCharisma() << endl << endl;
	
	wait();
	
	//Showing stat changes when adding armor. Also, notice that toString() isn't called directly here. 
	//The observer pattern kicks in when stats are changed.
	cout << "Gavin has some new Armor! Let's see his stats!" << endl << endl;
	gavin -> equipArmor(gavins);
	cout << endl;

	wait();

	//Demonstrating stat changes after removing armor
	cout << "This armor is too heavy for Gavin! Let's take it off!" << endl << endl;	
	gavin -> unequipArmor();

	wait();

	cout << "Let's build Gavin some friends!" << endl << endl;

	//Setting our Fighter creator to build Nimble type Fighters
	creator.setBuilder(&nimbleBuilder);
	*/
	//Creating a Nimble Fighter with the builder pattern
	Fighter* geoff = creator.getFighter("Geoff Ramsey", level);
	/*
	cout << "Introducing Nimble Fighter " << geoff -> getName() << "!" << endl;
	cout << geoff -> toString() << endl;
	
	//Setting our Fighter creator to build Tank type Fighters
	creator.setBuilder(&tankBuilder);

	cout << "and" << endl;
	*/
	//Creating a Tank Fighter with the builder pattern
	Fighter* jack = creator.getFighter("Jack Pattillo", level);
	/*
	//Attach the console observer to the new Fighters
	jack -> attach(&cs);					

	cout << "Tank Fighter " << jack -> getName() << "!" << endl;
	cout << jack -> toString() << endl;

	wait();

	//Let's show the Fighter's health points and attack bonuses increasing as he levels up (according to d20 rules)
	cout << "Let's see Gavin's hp and attack bonuses as he levels up from 1 to 30" << endl << endl;	

	wait();

	for(int level = 1; level <= 30; level++)
	{
		cout << "Level: " << level << " "
			 << "HP: " << gavin -> getHP() << " "
			 << "Attack Bonuses: +" << gavin -> getAttackBonus1() 
			 <<                "/+" << gavin -> getAttackBonus2() 
			 <<                "/+" << gavin -> getAttackBonus3() 
			 <<                "/+" << gavin -> getAttackBonus4() << endl;

		delay(1000);

		
		gavin -> levelUp();
	}

	cout << endl;*/

	CharacterIO<Fighter> io;

	io.saveCharacter(*geoff);
	io.saveCharacter(*jack);
	io.saveCharacter(*gavin);
	
	vector<Fighter> characters = io.loadCharacter();//Problem!!!!
	
	for(int i = 0; i < characters.size(); i++)
    {
		cout << characters[i].getName() << endl;
        cout << characters[i].toString() << endl;
    }

	//io.test();
	system("PAUSE");
	return 0;
}