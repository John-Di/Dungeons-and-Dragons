#pragma once

#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include "Fighter.h"

using namespace std;

template<typename T>

class CharacterIO
{
public:
	void saveCharacter(Fighter character)
	{		
		Fighter* ch = &character;

		ofstream ofs("test.txt", ios::binary|ios::app|ios::out);
		ofstream names("testnames.txt", ios::app|ios::out);
	
		ofs.write((char *) &character, sizeof(character));
		names.write((char * ) &(character.getName()), sizeof(character.getName()));
		ofs.close();
		names.close();
	}
	
	vector<Fighter> loadCharacter()
	{
		ifstream ifs("test.txt", ios::in|ios::binary|ios::ate);				//Open the binary file containing the characters pointing to the 
		ifstream::pos_type size;											//Size of the file

		if (ifs.is_open())													//If file is opened, i.e. file exists:
		{
			size = ifs.tellg();												//Set the file size to the current file pointer position
			ifs.seekg (0, ios::beg);										//Set the file pointer to the begining of the file
		}
		else cout << "Unable to open file";

		vector<Fighter> characters;
	
		while(!ifs.eof())													//While we still have stuff in the file to read
		{
			Fighter* ch;

			ifs.read((char *) &ch, sizeof(ch));								//Read the current Character

		cout << ch->getName() << endl;
		cout << ch->toString();
			
			characters.push_back(*ch);										//Push it into the Vector
		}

		cout << "Vector Size: " << characters.size() << endl;

		ifs.close();
		return characters;

	}	
};

