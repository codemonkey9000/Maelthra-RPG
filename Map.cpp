#include "Map.h"

map::map()
{
	boardx = 1;
	boardy = 0;
	
	fkx = 1;
	fky = 0;
}
void map::goN()
{
	--fky;
	if(fky < 6 && fky > -1)
	{
		boardy--;
	}
	else
	{
		cout<<"Error: Attempt to acess non-existant map array location."<<endl;
		++fky;
	}
}
void map::goS()
{
	++fky;
	if(fky < 6 && fky > -1)
	{
		boardy++;
	}
	else
	{
		cout<<"Error: Attempt to acess non-existant map array location "<<fkx<<","<<fky<<"."<<endl;
		fky--;
	}
}
void map::goE()
{
	++fkx;
	if(fkx < 3 && fkx > -1)
	{
		boardx++;
	}
	else
	{
		cout<<"Error: Attempt to acess non-existant map array location "<<fkx<<","<<fky<<"."<<endl;
		fky--;
	}
}
void map::goW()
{
	--fkx;
	if(fkx < 3 && fkx > -1)
	{
		boardx--;
	}
	else
	{
		cout<<"Error: Attempt to acess non-existant map array location "<<fkx<<","<<fky<<"."<<endl;
		fky++;
	}
}

// Location

location::location ()
{
	goN = false;
	goS = false;
	goE = false;
	goW = false;
	bigmon = false;
	
	randmonchance = 0;
	shop = false;
}
void location::runroom(player &mainchar, map &maplocation)
{
	displayonenter();
	combatcheck(mainchar);
	roommenu(mainchar, maplocation);
}
void location::roommenu(player &mainchar, map &maplocation)
{
	if (mainchar.alive == false)
	{
		return;
	}
	
	bool validinput = false;
	
	while(validinput == false)
	{
		if((mainchar.gethealth() + 5) < mainchar.gethealthcap())
		{
			mainchar.sethealth(mainchar.gethealth() + 5);
		}
		if((mainchar.getmana() + 5) < mainchar.getmanacap())
		{
			mainchar.setmana(mainchar.getmana() + 5);
		}
		cout<<"The Menu:"<<endl;
		if(goN == true)
		{
			cout<<"(N) Go North"<<endl;
		}
		if(goS == true)
		{
			cout<<"(S) Go South"<<endl;
		}
		if(goE == true)
		{
			cout<<"(E) Go East"<<endl;
		}
		if(goW == true)
		{
			cout<<"(W) Go West"<<endl;
		}
		
		cout<<"(1) Inventory"<<endl;
		cout<<"(2) Stats"<<endl;
		cout<<"(3) Equip Weapon"<<endl;
		char input;
		cin>>input;
		switch(input)
		{
		case 'n':
		case 'N':
			if(goN == true)
			{
				maplocation.goN();
				validinput = true;
			}
			else
			{
				cout<<"Invalid Input.  Try Again."<<endl;
			}
			break;
		case 's':
		case 'S':
			if(goS == true)
			{
				maplocation.goS();
				validinput = true;
			}
			else
			{
				cout<<"Invalid Input.  Try Again."<<endl;
			}
			break;
		case 'e':
		case 'E':
			if(goE == true)
			{
				maplocation.goE();
				validinput = true;
			}
			else
			{
				cout<<"Invalid Input.  Try Again."<<endl;
			}
			break;
		case 'w':
		case 'W':
			if(goW == true)
			{
				maplocation.goW();
				validinput = true;
			}
			else
			{
				cout<<"Invalid Input.  Try Again."<<endl;
			}
			break;
		case '1':
			mainchar.displayinv();
			break;
		case '2':
			displaystats();
			break;
		case '3':
			mainchar.displayinv();
			cout<<"Which item would you like to equip (inventory slot number)?"<<endl;
			cin>>input;
			input -= 48;
			mainchar.equipweapon(input - 1);
			validinput = true;
			break;
		default:
			cout<<"Invalid Input.  Try Again."<<endl<<endl;
		}
	}
	}
	void location::combatcheck(player &mainchar)
	{
		if(bigmonB == true)
		{
			combat(bigmon);
			bigmonB = false;
		}
		else
		{
			int num;
			num = rand() % 100 + 1;
			
			if(num <= randmonchance)
			{
				combat(randmon);
			}
		}
	}
	void location::initialize(bool goN_, bool goS_, bool goE_, bool goW_, bool bigmonB_, enemy *bigmon_, enemy *randmon_, int randmonchance_, bool shop_)
	{
		goN = goN_;
		goS = goS_;
		goE = goE_;
		goW = goW_;
		bigmonB = bigmonB_;
		bigmon = bigmon_;
		randmon = randmon_;
		randmonchance = randmonchance_;
		shop = shop_;
	}