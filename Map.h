#include "Enemy.h"

#pragma once

// Contains Map and Location classes

class map
{
private:
	int boardx;
	int boardy;

	int fkx;
	int fky;
public:
	map();
	void goN();
	void goS();
	void goE();
	void goW();

	int getx()
	{
		return boardx;
	}
	int gety()
	{
		return boardy;
	}
};

class location
{
private:
	//can the player go north, south, east and/or west?
	bool goN;
	bool goS;
	bool goE;
	bool goW;
	bool bigmonB; //unique monster in room?
	int randmonchance;
	bool shop;

public:
	enemy *bigmon;
	enemy *randmon;

	location ();
	void runroom(player &mainchar, map &maplocation);
	void roommenu(player &mainchar, map &maplocation);
	void combatcheck(player &mainchar);
	void initialize(bool goN_, bool goS_, bool goE_, bool goW_, bool bigmonB_, enemy *bigmon_, enemy *randmon_, int randmonchance_, bool shop_);
};

void displayonenter();
void displaystats();

void combat(enemy *hostile);