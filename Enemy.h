#include <stdlib.h>
#include <iostream.h>
#include "Player.h"

#pragma once

class enemy
{
private:
	char name[25];
	int statstr;
	int atkbonus;
	int statdex;
	int statcon;
	int statint;
	int chancetohitmagic;
	int healthcap; //DO NOT INPUT FOR CONSTRUCTOR!!
	int mana;   //DO NOT INPUT FOR CONSTRUCTOR!!
	int atk;    //DO NOT INPUT FOR CONSTRUCTOR!!
	bool regen; //does he regenerate true/false
	int regenamount; //if so how much?
	int chancefirethrow; // chance that AI will attempt a fire throw attack
	int dmgfirethrow; // damage on sucessful fire throw attack
	int chancetohit;
	int health;
	int exp;

public:
	//constructor.  when making creature, determine stats
	enemy(char *name_, int statstr_, int atkbonus_, int statdex_, int statcon_, 
	int statint_, bool regen_, int regenamount_, int chancefirethrow_, int dmgfirethrow_, int exp_);

	void AI(player &mainchar);

	void setregenerate(bool regen_, int regenamount_)
	{
		regen = regen_;
		regenamount = regenamount_;
	}

	void setstr(int newstr)
	{
		statstr = newstr;
		atk = newstr + newstr - 5;
	}
	void setdex(int newdex)
	{
		statdex = newdex;
		chancetohit = newdex * 9;
	}
	void setint(int newint)
	{
		statint = newint;
		mana = newint * 4;
		chancetohitmagic = newint * 6;
	}
	void setcon(int newcon)
	{
		int num = ((newcon) + rand() % 10 + 1) + 25;
		statcon = newcon;
		health = num;
		healthcap = num;
	}
	void setatkbonus(int newbonus)
	{
		atkbonus = newbonus;
	}
	void sethealth(int healthchange)
	{
		health = healthchange;
	}
	int getstr()
	{
		return statstr;
	}
	int getdex()
	{
		return statdex;
	}
	int getint()
	{
		return statint;
	}
	int getcon()
	{
		return statcon;
	}
	int getatkbonus()
	{
		return atkbonus;
	}
	char *getname()
	{
		return name;
	}
	int gethealth()
	{
		return health;
	}
	int getexp()
	{
		return exp;
	}
	int getgold()
	{
		return (statstr + statcon + statdex + statint);
	}
	int gethealthcap()
	{
		return healthcap;
	}
};
