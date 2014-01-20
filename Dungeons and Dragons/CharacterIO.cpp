/*#include "CharacterIO.h"

template<typename T>
void CharacterIO<T>::saveCharacter(T& character)
{
	T* ch = &character;

	ofstream ofs("test.dat", ios::binary);
	
	ofs.write((char *) &ch, sizeof(ch));
	ofs.close();
}

template<typename T>
vector<T> CharacterIO<T>::loadCharacter()
{
	ifstream ifs("test.dat", ios::in|ios::binary|ios::ate);
	ifstream::pos_type size;

	if (ifs.is_open())
	{
		size = ifs.tellg();
		ifs.seekg (0, ios::beg);
		ifs.close();
	}
	else cout << "Unable to open file";
	

	vector<T> characters;
	
	while(!ifs.eof())
	{
		T* ch;

		ifs.read((char *) &ch, sizeof(ch));

		characters.push_back(*ch);
	}
	return characters;
}


*/