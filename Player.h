#include <string.h>
#include <stdlib.h>
#include <iostream.h>

#pragma once

#define MAXINV 10

// Contains Weapon, Player, and Inventory classes

class weapon
{
private:
	int damagebonus;
	int weaponid;
	int percent;
	char name[25];
public:
	weapon(int damagebonus_, int weaponid_, int percent_, char *name_)
	{
		damagebonus = damagebonus_;
		weaponid = weaponid_;
		percent = percent_;
		strcpy(name, name_);
	}
	int getweaponid()
	{
		return weaponid;
	}
	int getdamagebonus()
	{
		return damagebonus;
	}
	void setdamagebonus(int newbonus)
	{
		damagebonus = newbonus;
	}
	int getpercent()
	{
		return percent;
	}
	void setpercent(int newpercent)
	{
		percent = newpercent;
	}
	char *getname()
	{
		return name;
	}
};

class inventory
{
public:

	int itemtype;
	int howmany;

	inventory()
	{
		itemtype = 0;
		howmany = 0;
	}

	char * nameofitem()
	{
		switch(itemtype)
		{
			case 0: return "Empty";
			case 1: return "Dagger";
			case 2: return "Sword";
			case 3: return "Axe";
			case 4: return "Whip";
			case 5: return "Staff";
			case 6: return "Dragon Orb!"; //real dragon orb
			case 7: return "Dragon Orb"; //fake dragon orb
			case 8: return "Potion";
			case 9: return "Shattered Orb";
			default: return "ERROR: Unindexed Item";
		}
	}

};

class player
{

private:

	// Define all stats

	char playername[15];
	int statstr;
	int statcon;
	int statint;
	int statdex;
	bool female;
	int healthcap;
	int health;
	int mana;
	int manacap;
	int chancetohit;
	int chancetohitmagic;
	int atk;
	int exp;
	int gold;


	// Define inventory

	inventory inv[MAXINV];

public:

	int points;
	int level;
	bool alive;
	bool wizfirsttime;
	weapon *equippedweapon;

	player();
	void deleteitem(int itemtype);
	void itemsubtract(int itemtype, int howmany);
	int howmany(int itemtype_);

	int getatk()
	{
		return atk;
	}
	char * getname()
	{
		return playername;
	}
	int getmanacap()
	{
		return manacap;
	}
	void setname(char* thename)
	{
		strcpy(playername, thename);
	}

	bool getfemale()
	{
		return female;
	}

	void setfemale(bool areyoufemale)
	{
		female = areyoufemale;
	}

	int getstr()
	{
		return statstr;
	}

	void setstr(int strchange)
	{
		statstr = strchange;
		atk =  strchange * 2 - 5;
	}

	int getcon()
	{
		return statcon;
	}

	void setcon(int conchange)
	{
		int num = (conchange + rand() % 10 + 1) * 3;
		statcon = conchange;
		health = num;
		healthcap = num;
	}

	int getint()
	{
		return statint;
	}

	void setint(int intchange)
	{
		statint = intchange;
		mana = intchange * 3;
		manacap = intchange * 3;
		if(intchange < 10)
		{
			chancetohitmagic = intchange * 15;
		}
		if(intchange > 10)
		{
			chancetohitmagic = 99;
		}
	}

	int getdex()
	{
		return statdex;
	}

	void setdex(int dexchange)
	{
		statdex = dexchange;
		chancetohit = dexchange * 8;
	}
	int gethealthcap()
	{
		return healthcap;
	}
	int getmana()
	{
		return mana;
	}
	void setmana(int newmana)
	{
		mana = newmana;
	}
	int getchancetohitmagic()
	{
		return chancetohitmagic;
	}
	int getchancetohit()
	{
		return chancetohit;
	}
	int gethealth()
	{
		return health;
	}
	void sethealth(int newhealth)
	{
		health = newhealth;
	}
	int getexp()
	{
		return exp;
	}
	void setexp(int newexp)
	{
		exp = newexp;
	}
	int getgold()
	{
		return gold;
	}
	void setgold(int newgold)
	{
		gold = newgold;
	}
	//equip weapon
	void equipweapon(int slot);
	// Add items to inventory
	void additem (int itype, int num);
	int getitemtype(int slot);
	// General display of inventory
	void displayinv();
	bool itemcheck(int theItemWeAreLookingFor);
};