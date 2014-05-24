#include "Player.h"

weapon dagger (2, 1, 0, "dagger");
weapon sword (5, 2, 0, "sword");
weapon axe (6, 3, -10, "axe");
weapon whip (3, 4, +50, "whip");
weapon staff (4, 5, +10, "staff");

player::player()
{
	// Set all stats to 0
	
	statstr = 0;
	statcon = 0;
	statint = 0;
	statdex = 0;
	female = 0;
	healthcap = 0;
	health = 0;
	mana = 0;
	manacap = 0;
	chancetohit = 0;
	chancetohitmagic = 0;
	atk = 0;
	equippedweapon = &dagger;
	exp = 0;
	gold = 0;
	points = 40;
	level = 1;
	alive = true;
	wizfirsttime = true;
	
}
void player::deleteitem(int itemtype)
{
	int inc = 0;
	
	while(MAXINV != inc)
	{
		if(itemtype == inv[inc].itemtype)
		{
			inv[inc].itemtype = 0;
			
			inv[inc].howmany = 0;
		}
		inc ++;
	}
}
void player::itemsubtract(int itemtype, int howmany)
{
	
	for (int i = 0; i < MAXINV; i++)
	{
		if ( itemtype == inv[i].itemtype )
		{
			inv[i].howmany -= howmany;
		}
	}
	if(inv[i].howmany <= 0)
	{
		inv[i].itemtype = 0;
		inv[i].howmany = 0;
	}
}
int player::howmany(int itemtype_)
{
	for (int i = 0; i < MAXINV; i++ )
	{
		
		if (itemtype_ == inv[i].itemtype )
		{
			return inv[i].howmany;
			
		}
	}
	return 0;
}
//equip weapon
void player::equipweapon(int slot)
{
	if((inv[slot].itemtype >=1) && (inv[slot].itemtype <=5))
	{
		switch (inv[slot].itemtype)
		{
		case 1:
			equippedweapon = &dagger;
			break;
		case 2:
			equippedweapon = &sword;
			break;
		case 3:
			equippedweapon = &axe;
			break;
		case 4:
			equippedweapon = &whip;
			break;
		case 5:
			equippedweapon = &staff;
			break;
		}
	}
	else
	{
		cout << "Invalid Input.  Try Again." << endl;
	}
}
// Add items to inventory
void player::additem (int itype, int num)
{
	for (int i = 0; i < MAXINV; i++)
	{
		if(inv[i].itemtype == itype)
		{
			
			inv[i].howmany += num;
			
			i= 1337;
		}
	}
	if(i == MAXINV)
	{
		for(int j = 0; j < MAXINV; j++)
		{
			if(inv[j].itemtype == 0)
			{
				
				inv[j].itemtype=itype;
				
				inv[j].howmany=num;
				
				i = 1337;
				j = 1337;
			}
		}
	}
	if ( i <= MAXINV )
	{
		cout << "Warning: Item List is full. ***********CAN'T ADD ITEM***********" << endl;
	}
}
int player::getitemtype(int slot)
{
	return inv[slot].itemtype;
}
// General display of inventory
void player::displayinv()
{
	cout << endl << "Current Inventory: " << endl;
	
	for(int k = 0; k < MAXINV; ++k)
	{
		cout << "Slot " << k+1 << ": ";
		
		if(inv[k].itemtype == 0)
		{
			cout << "Empty" << endl;
		}
		else
		{
			cout << inv[k].nameofitem() << " X " << inv[k].howmany;
			
			if(equippedweapon->getweaponid() == inv[k].itemtype)
			{
				cout << " (Equipped)" << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}
	
	cout << endl;
	
	cout << "You have " << getgold() << " gold." << endl << endl;
}

bool player::itemcheck(int theItemWeAreLookingFor)
{
	
	for ( int i = 0; i < MAXINV; i++ )
	{
		if ( theItemWeAreLookingFor == inv[i].itemtype )
		{
			return true;
		}
	}
	
	return false;
	
}