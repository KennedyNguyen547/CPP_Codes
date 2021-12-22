




#include <iostream>
#include "Somebody.h"
#include "BootleggedHashTable.h"
#include <string>


int main()
{
	/*
	BootleggedHashTable<int, int> BLHT;

	BLHT.insert(10, 20);

	BLHT.insert(100, 200);

	std::cout << BLHT;
	*/

	Somebody someone_a = Somebody("Ameri", "Azazel", "A high-ranked student council president of a demon school.");

	Somebody someone_b = Somebody("Bender", "Rodriguez", "Bending Unit 22, has a shiny metal ass.");

	Somebody someone_c = Somebody("K", "N", "Typical butthole, existentialist wannabe. Likes lesbian stories and comedy. Scared of hash tables and work.");

	Somebody someone_d = Somebody("William", "Murderface", "Can play guitar with his genitals. 'My fandom has doorknobs for a new world.'");

	Somebody someone_e = Somebody("Keenan", "Knaur", "Known CSULA professor. Caught a random person staring at his class lecture on hash tables one afternoon...");

	Somebody someone_f = Somebody("Satsuki", "Kiryuin", "A master swordswoman. Also has a very dominating aura...");

	Somebody someone_g = Somebody("Dr.", "Rockso", "A rock and roll clown that likes to do cocaine.");

	Somebody someone_h = Somebody("Sebastian", "Davis", "Master Agent of the Cart Narcs. Became known after appearing on Dr. Phil's daytime show.");

	Somebody someone_i = Somebody("Deckard", "Cain", "A known dead sage. 'Stay a while and listen.'");

	BootleggedHashTable <std::string, Somebody> BLHT;

	BLHT.insert(someone_a.last_name, someone_a);
	BLHT.insert(someone_b.last_name, someone_b);
	BLHT.insert(someone_c.last_name, someone_c);
	BLHT.insert(someone_d.last_name, someone_d);
	BLHT.insert(someone_e.last_name, someone_e);
	BLHT.insert(someone_f.last_name, someone_f);
	BLHT.insert(someone_g.last_name, someone_g);
	BLHT.insert(someone_h.last_name, someone_h);
	BLHT.insert(someone_i.last_name, someone_i);

	std::cout << BLHT;

	system("pause");
	return 0;
}













