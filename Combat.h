#include "Player.h"
#include "Enemy.h"
#include "Map.h"

#pragma once

// Contains Spell class

class spell
{
private:
	char name[25];
	int spellid;
	int dmgmod;
	int dmgbase;
	int AEdamage;
	int castingcost;

public:
	spell(char *name_, int spellid, int dmgmod_, int dmgbase_, int AEdamage_, int castingcost_)
	{
		strcpy(name, name_);
		dmgbase = dmgbase_;
		dmgmod = dmgmod_;
		AEdamage = AEdamage_;
		castingcost = castingcost_;
	}
	char *getname()
	{
		return name;
	}
	int getspellid()
	{
		return spellid;
	}
	int getdamage()
	{
		return (rand() % dmgbase) + dmgmod;
	}
	int getAEdamage()
	{
		return AEdamage;
	}
	int getcastingcost()
	{
		return castingcost;
	}
};
