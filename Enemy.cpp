#include "Enemy.h"

//constructor.  when making creature, determine stats
enemy::enemy(char *name_, int statstr_, int atkbonus_, int statdex_, int statcon_, 
			 int statint_, bool regen_, int regenamount_, int chancefirethrow_, int dmgfirethrow_, int exp_)
{
	int randnum = (statcon_ + rand() % 10 + 1);
	strcpy(name, name_);
	statstr = statstr_;
	atkbonus = atkbonus_;
	statdex = statdex_;
	statcon = statcon_;
	statint = statint_;
	chancetohitmagic = statint_ * 5;
	chancetohit = statdex_ * 8;
	atk = statstr_ + statstr_ - 5;
	health = randnum + 100;
	healthcap = randnum + 100;
	mana = statint * 4;
	regen = regen_;
	regenamount = regenamount_;
	chancefirethrow = chancefirethrow_;
	dmgfirethrow = dmgfirethrow_;
	exp = exp_;
}

void enemy::AI(player &mainchar)
{
	int num;
	num = rand()% 50 + 1;
	if(num <= chancefirethrow)
	{
		cout << "The monster attempts a fire attack!" << endl;
		num = rand()% 50 +1;
		if (num <= chancetohitmagic)
		{
			cout << "It gets you for "<< dmgfirethrow << " damage" << endl << endl;
			mainchar.sethealth(mainchar.gethealth() - (dmgfirethrow));
		}
			else
		{
			cout << "It misses!" << endl << endl;
		}
	}
	else
	{
		num = rand()% 50 + 1;
		if (num <= chancetohit)
		{
			cout << "The monster deals " << atk + atkbonus << " damage to you." << endl << endl;
			mainchar.sethealth(mainchar.gethealth() - (atk + atkbonus));
		}
		else
		{
			cout << "The monster misses you!" <<endl<<endl;
		}
	}
	
	if(regen == true)
	{
		if (health + 2 < healthcap)
		{
			health = health + 4;
		}
	}
}