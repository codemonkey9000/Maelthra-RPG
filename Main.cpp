#include <time.h>
#include <math.h>
#include <cstdlib>
#include "Map.h"
#include "Spell.h"

void initializeworldmap();
void runroomloop();
void pickstats();
void charcreation();
int askforstat(char stat[]);
void intro();
void PrintLines(int, int, char);
void deleteitem();

enemy rathidragon("Rathi Dragon", 12, 0, 6, 11, 5, false, 0, 10, 15, 30);
enemy senordemon("Demon", 14, 0, 6, 12, 8, true, 2, 0, 0, 40);
enemy draco("Draco", 14, 0, 7, 14, 8, false, 0, 10, 15, 50);
enemy zombie("Zombie", 4, 0, 4, 4, 2, false, 0, 0, 0, 5);
enemy spider("Spider", 3, 0, 7, 3, 3, false, 0, 0, 0, 7);
enemy goblin("Goblin", 4, 0, 6, 6, 4, false, 0, 0, 0, 10);
enemy skeleton("Skeleton", 4, 0, 5, 4, 3, false, 0, 0, 0, 8);

spell ltgbolt("Lightning Bolt", 1, 10, 5, 0, 2);
spell iceshard("Ice Shard", 2, 8, 4, 0, 1);
spell meteor("Meteor of DOOM", 3, 50, 10, 10, 20);
spell firestorm("Firestorm", 4, 35, 15, 15, 17);

location worldmap[3][6];
map maplocation;

player mainchar;

int main()
{
	srand(time(0));

	initializeworldmap();
	intro();

	charcreation();

	/*
	mainchar.additem(2, 1);
	mainchar.setgold(2000);
	mainchar.setcon(200);
	mainchar.setdex(200);
	mainchar.setint(200);
	mainchar.setstr(200);
	mainchar.setfemale(true);
	mainchar.setname("Embra");
	mainchar.setexp(40);
	*/

	runroomloop();

	cout << "Press Enter to Quit." << endl;

	return 0;
}

void charcreation()
{

	cout << "Please enter your desired name: ";

	char playerinputname[15];

	cin >> playerinputname;

	mainchar.setname(playerinputname);

	// Gender input

	char gender = 'N';

	while(!(gender == 'M' ||
		  gender == 'm' ||
		  gender == 'F' ||
		  gender == 'f'))
	{

		cout << "Please enter your gender(M/F): ";

		cin >> gender;

		switch(gender)
		{
			case 'm':
			case 'M':
				{
					mainchar.setfemale(false);

				}break;

			case 'f':
			case 'F':
				{
					mainchar.setfemale(true);

				}break;
		}

	}

	pickstats();

	// Ouput final choices

	cout << "Name: " << mainchar.getname() << endl;

	if(mainchar.getfemale())
	{
		cout << "Gender: Female" << endl;
	}
	else
	{
		cout << "Gender: Male" << endl;
	}

	displaystats();

	// Adds default starting dagger

	mainchar.additem(1, 1);
}

void displaystats()
{
	cout << "Current stats: " << endl;

	cout << "Str: " << mainchar.getstr() << endl;

	cout << "Con: " << mainchar.getcon() << endl;

	cout << "Int: " << mainchar.getint() << endl;

	cout << "Dex: " << mainchar.getdex() << endl;

	cout << endl << "Level: " << mainchar.level << " Exp: " << mainchar.getexp() << endl;
	cout << endl;
}



void displayonenter() // if statemets for each coordinated room in the dungeon.....
{
	int totalgold = mainchar.getgold();


	cout<<"You are located at "<<maplocation.getx()<<","<<maplocation.gety()<<endl;
	if(maplocation.getx() == 1 && maplocation.gety() == 0)
	{
		cout << "You appear in the center of a small village." << endl;

		cout << "You see the entrence to a dungeon to the west." << endl;

		cout << "You see an old wizards hut to the east." << endl;

		cout << "You see a small weapon shop to the south." << endl;

		cout << endl;
	}
	if(maplocation.getx() == 1 && maplocation.gety() == 1)
	{
		cout << "You are standing in a weapon shop." << endl;

		cout << "Your only exit is to the north." << endl;

		bool repeatShopMenu = true;

		while(repeatShopMenu == true)
		{
			cout << endl;
			cout << "You have " << mainchar.getgold() << " gp" << endl;
			cout << "This is the Falcon's Talon Weapon Show:" << endl;
			cout << "-----------------" << endl;
			cout << "(1) Buy a Sword for 50gp" << endl;
			cout << "(2) Buy an Axe for 75gp" << endl;
			cout << "(3) Buy a Whip for 75gp" << endl;
			cout << "(4) Buy a Staff for 60gp" << endl;
			cout << "(5) Buy a Potion for 30gp" << endl;
			cout << "(6) Quit This Menu" << endl;

			char userShopInput;

			cin >> userShopInput;

			switch(userShopInput)
			{
				case '1':
				{
					if (mainchar.getgold() >= 50)
					{
						mainchar.setgold(mainchar.getgold() - 50);
						cout << "You have purchased the Sword, Your gold is now " << mainchar.getgold()  << endl << endl;
						mainchar.additem(2, 1);
					}
					else
					{
						cout << "You do not have enough money for this item." << endl;
					}

				}break;

				case '2':
				{
					if (mainchar.getgold() >= 75)
					{
						mainchar.setgold(mainchar.getgold() - 75);
						cout << "You have purchased the Axe, Your gold is now " << mainchar.getgold() << endl << endl;
						mainchar.additem(3, 1);
					}
					else
					{
						cout << "You do not have enough money for this item." << endl;
					}

				}break;

				case '3':
				{
					if (mainchar.getgold() >= 75)
					{
						mainchar.setgold(mainchar.getgold() - 75);
						cout << "You have purchased the whip, Your gold is now " << mainchar.getgold()  << endl << endl;
						mainchar.additem(4, 1);
					}
					else
					{
						cout << "You do not have enough money for this item." << endl;
					}

				}break;

				case '4':
				{
					if (mainchar.getgold() >= 60)
					{
						mainchar.setgold(mainchar.getgold() - 60);
						cout << "You have purchased the staff, Your gold is now " << mainchar.getgold()  << endl << endl;
						mainchar.additem(5, 1);
					}
					else
					{
						cout << "You do not have enough money for this item." << endl;
					}

				}break;

				case '5':
				{
					if (mainchar.getgold() >= 30)
					{
						mainchar.setgold(mainchar.getgold() - 30);
						cout << "You have purchased the potion, Your gold is now " << mainchar.getgold()  << endl << endl;
						mainchar.additem(8, 1);
					}
					else
					{
						cout << "You do not have enough money for this item." << endl;
					}

				}break;

				case '6':
				{
					cout << "Thank you for your business! Come again!" << endl;
					repeatShopMenu = false;

				}break;
				default:
				{
					cout << "Invalid Input.  Try Again." << endl;
				}
			}
		}
	}
	if(maplocation.getx() == 2 && maplocation.gety() == 0)
	{
		if(mainchar.wizfirsttime == true)
		{
			cout << "You are in the small hut of a wizard." << endl;

			cout << "\"Hello Stranger,\" Wizard says." << endl;

			cout << "\"Hello,\" you say." << endl;

			cout << "\"I have a favor to ask of you,\" the Wizard begins. \"There is a dungeon to the west of here that holds something I wish to have.\" he says." << endl;

			cout << "\"There is a great reward of riches and diamonds if you find the orb that the dragon keeps,\" the Wizard tells you." << endl;

			cout << "\"By the way, my name is Thiagg Faern,\" he adds." << endl;

			cout << "\"Hmmm, alright, if the treasures are as good as you say I will take up this challenge,\" you decide." << endl;

			cout << "\"Thank you, and good luck.\" The wizard bids you a final farewell." << endl;
			
			mainchar.wizfirsttime = false;
		}
		else if(mainchar.itemcheck(6) == true || mainchar.itemcheck(9) == true)
		{
			cout << "\"You have returned!\" Thiagg Faern cries with delight. \"Do you have the orb?\"" << endl;

			cout << "\"Yes, I killed the dragon and now I have the orb,\" you reply." << endl;

			cout << "You hand him the orb, but when he touches it, it shatters." << endl;

			cout << "\"This is not the real orb!\" he cries. \"Tell me, did you explore the entire dungeon?\"" << endl;

			cout << "You think for a while, then reply, \"No, I suppose I might not have." << endl;

			cout << "The wizard sighs. \"I know it is dangerous, but please return to the dungeon and bring back the REAL orb.\" Thiagg Faern eyes you suspiciously." << endl;

			cout << "You nod and bid the wizard farewell." << endl;
			mainchar.deleteitem(6);
			mainchar.additem(9, 1);
		}

		else if(mainchar.itemcheck(7) == true)
		{
			cout << "Ahhhhh yes this is it, This is the real Dragon Orb... I finally have it!" << endl;

			cout << "You hear the wizard mutter some words." << endl;

			cout << "You feel the dark energies of the orb surrounding you." << endl;

			cout << "Right before you, you see a Black Dragon spawn." << endl;

			cout << "\"Kill! Kill everything that exists (except for me)!\", the Wizard cackles demonically." << endl;

			cout << "As you back into a corner, the Dragon faces you and opens its jaw wide." << endl;

			cout << "Unprepared, you scream, as your head is ripped from its torso." << endl << endl;

			mainchar.alive = false;
		}
		else
		{
			cout << "You are in the hut of a wizard" << endl;

			cout << "Wizard: Go get me my orb!" << endl;

			cout << "The only exit is to the west." << endl;
		}
	}
	if(maplocation.getx() == 0 && maplocation.gety() == 0)
	{
		cout << "As you begin to walk down the stone stairs, the light fades and leaves you in darkness." << endl;

		cout << "You are underground in a stone dungeon." << endl;

		cout << "You appear to be in a room with a beautiful ceiling portraying a night sky, but consisting of only one constellation." << endl;

		cout << "You remember it to be the Draco constellation and wonder what it could mean." << endl;

		cout << "You have two obvious exits, one is to the south, deeper into the dungeon. The other is to the east, back into the village sqaure." << endl;
	}
	if(maplocation.getx() == 0 && maplocation.gety() == 1)
	{
		cout << "As you enter the room there is mist hanging in the air."<< endl;

		cout << "You have two obvious exits, one is to the south, deeper into the dungeon. The other is to the north, back to the entrence of the dungeon." << endl;
	}
	if(maplocation.getx() == 0 && maplocation.gety() == 2)
	{
		cout << "As you enter the room you see moss growing on the dungeon floor, it is damp." << endl;

		cout << "There are two obvious exits, one heading south and the other heading north." << endl;
	}
	if(maplocation.getx() == 0 && maplocation.gety() == 3)
	{
		cout << "As you enter the room you see tables lined against the dungeon wall, some with legs missing." << endl;

		cout << "There are three obvious exits, one heading south, one heading north, and the other heading east." << endl;
	}
	if(maplocation.getx() == 1 && maplocation.gety() == 3)
	{
		cout << "As you enter the room you see moss growing on the dungeon floor, it is damp." << endl;

		cout << "There are three obvious exits, one heading east, one heading north, and the other heading west into a dragons lair." << endl;
	}
	if(maplocation.getx() == 1 && maplocation.gety() == 2)
	{
		cout << "As you enter the room you see moss growing on the dungeon floor, it is damp." << endl;

		cout << "There are two obvious exits, one heading south and the other heading west." << endl;
	}
	if(maplocation.getx() == 2 && maplocation.gety() == 2)
	{
		cout << "As you enter the room you see moss growing on the dungeon floor, it is damp and very dark." << endl;

		cout << "There are two obvious exits, one heading east and the other heading north." << endl;
	}
	if(maplocation.getx() == 2 && maplocation.gety() == 1)
	{
		cout << "As you come into the next room you see a broken chandelier at the top of the ceiling and a blood red carpet below you." << endl;

		cout << "Also in the room ia a painting of a what looks to be the a King using the fabled Dragon Orb to command the dragons surrounding him." << endl;

		cout << "In the corner of the painting it says in small writing: Those who have the orb, have the power to control." << endl;

		cout << "The only obvious exit is back to the south." << endl;
	}
	if(maplocation.getx()  == 2 && maplocation.gety() == 3)
	{
		cout << "As you enter a gigantic cavern you feel the temperature rise." << endl;

		cout << "There is a huge ledge above you and the air smells of sweat." << endl;

		cout << "There is one obvious exit back to the north, and another less obvious to the south." << endl;
	}
	if(maplocation.getx() == 2 && maplocation.gety() == 4)
	{
		cout << "In this room lies a box." << endl;

		cout << "You go closer to investigate." << endl;

		if(mainchar.itemcheck(6) == false)
		{
			cout << "You have gained the Dragon Orb!" << endl;

			mainchar.additem(6, 1);
		}

		cout << "The only obvious exit is back to the north." << endl;
	}
	if(maplocation.getx() == 0 && maplocation.gety() == 4)
	{
		cout << "As you enter the room you see paintings all around you of dragons flying and mages battling." << endl;

		cout << "In the middle of the painting you see a single mage holding an orb." << endl;

		if (mainchar.itemcheck(9) == false)
		{
			cout << "The only exit is to the north." << endl;
		}
		else
		{
			cout << "There are two obvious exits, one is to the north, and the other is to the south." << endl;
		}
	}
	if(maplocation.getx() == 0 && maplocation.gety() == 5)
	{
		cout << "As you enter the room you see tables lined against the dungeon wall, some with legs missing." << endl;

		cout << "You see weapons made of bones scattered on the floor of the room." << endl;

		cout << "There are two obvious exits, one is to the north, and the other is to the east." << endl;
	}
	if(maplocation.getx() == 1 && maplocation.gety() == 5)
	{
		cout << "As you enter a gigantic cavern you feel the temperature rise." << endl;

		cout << "There is a huge ledge above you and this apears to be the main room of the dungeon." << endl;

		cout << "There is one obvious exit to the east, and two less obvious exits, one to the north and the other to the east." << endl;
	}
	if(maplocation.getx() == 1 && maplocation.gety() == 4)
	{
		cout << "There are piles of coins and treasure covering every part of the room." << endl;

		cout << "The only exit is back to the south." << endl;
	}
	if(maplocation.getx() == 2 && maplocation.gety() == 5)
	{
		cout << "There are piles of coins and treasure covering every part of the room." << endl;
		cout << "The only exit is to the west." << endl;

		if(mainchar.itemcheck(7) == false)
		{
			cout << "Out of the corner of your eye, you see a glimmer under a pile of gold coins." << endl;

			cout << "Moving closer to investigate you see that it is an orb. You pick it up." << endl;

			cout << "You have gained the Real Dragon Orb!!! <Unidentified>" << endl;

			mainchar.additem(7, 1);
		}
	}

}

void initializeworldmap()
{
	worldmap[0][0].initialize(false, true, true, false, false,  0, &spider, 48, false);
	worldmap[0][1].initialize(true, true, false, false, false,  0, &skeleton, 25, false);
	worldmap[0][2].initialize(true, true, false, false, false,  0, &skeleton, 35, false);
	worldmap[0][3].initialize(true, true, true, false, false,  0, &zombie, 78, false);
	worldmap[0][4].initialize(true, true, false, false, false,  0, &zombie, 45, false);
	worldmap[0][5].initialize(true, false, true, false, true,  &senordemon, 0, 0, false); // senor demon
	worldmap[1][0].initialize(false, true, true, true, false,  0, 0, 0, false);
	worldmap[1][1].initialize(true, false, false, false, false,  0, 0, 0, true);
	worldmap[1][2].initialize(false, true, true, false, false,  0, &skeleton, 45, false);
	worldmap[1][3].initialize(true, false, true, true, false,  0, &goblin, 39, false);
	worldmap[1][4].initialize(false, true, false, false, false,  0, &skeleton, 78, false);
	worldmap[1][5].initialize(true, false, true, true, true,  &draco, 0, 0, false); // draco
	worldmap[2][0].initialize(false, false, false, true, false,  0, 0, 0, false);
	worldmap[2][1].initialize(false, true, false, false, false,  0, &spider, 47, false);
	worldmap[2][2].initialize(true, false, false, true, false,  0, &goblin, 67, false);
	worldmap[2][3].initialize(false, true, false, true, true, &rathidragon, 0, 0, false); // Rathi Dragon
	worldmap[2][4].initialize(true, false, false, false, false, 0, 0, 0, false);
	worldmap[2][5].initialize(false, false, false, true, false, 0, 0, 0, false); // Dragon orb real
}

void runroomloop()
{
	bool playinggame = true;

	while(mainchar.alive == true)
	{
		worldmap[maplocation.getx()][maplocation.gety()].runroom(mainchar, maplocation);
	}

	cout<<"mainchar.alive = false"<<endl;

}

void pickstats()
{

	system("cls");

	displaystats();

	// Strength

	mainchar.setstr(askforstat("strength"));

	system("cls");

	displaystats();

	// Constitution

	mainchar.setcon(askforstat("constitution"));

	system("cls");

	displaystats();

	// Intelligence

	mainchar.setint(askforstat("intelligence"));

	system("cls");

	displaystats();

	// Dexterity

	mainchar.setdex(askforstat("dexterity"));

	system("cls");

	displaystats();

	// Confirmation

	cout << "You have " << mainchar.points << " points left." << endl << endl;
}

int askforstat(char stat[])
{
	// Points left over

	int playerinput;

	cout << "You have " << mainchar.points << " points left." << endl << endl;

	cout << "Please enter a number of " << stat << " points: ";

	cin >> playerinput;

	if(playerinput <= mainchar.points && playerinput > 0)
	{
		mainchar.points -= playerinput;
	}
	else
	{
		system("cls");

		displaystats();

		return askforstat(stat);
	}

	return playerinput;
}

void intro()
{
	cout << endl << endl;

	PrintLines (80, 2, '*');

	cout << endl;

	PrintLines (26, 1, ' ');

	cout << "Welcome to the land of" << endl << endl;

	PrintLines (80, 1, '#');

	cout << endl;
	cout << "      fL    iG,    ;L;    :Lfffff. G:   tffLfff jj    ii iLjjjfj.    :L;" << endl;
	cout << "      KGL  .KEt   :K;K:   ,W       #;      Wt   tE    Lf fE    LL    K;K:" << endl;
	cout << "      K,E: GiDt   Ei iE   ,#fffft  #;      Wt   tWffffEf fWfffGL:   Lj iE." << endl;
	cout << "      K,,EtG Dt  fDjjjGG  ,W       #;      Wt   tE    Lf fE   ;K.  fEjjjGE" << endl;
	cout << "      D: fE. Li :E.    D; :Efffff, KLfff;  Ei   iG    jj jG    jf: E:    Gt" << endl;
	cout << endl;

	PrintLines (80, 1, '#');

	cout << endl;

	cout << "Made by: Katherine McAuliffe" << endl;

	cout << endl;
	
	PrintLines (80, 2, '*');

	cout << endl;

	cout << "This game is operating under the stupid user agreement.  If it asks for one \nletter, do not feed it a number, or a word. \n\nThank You. \n" << endl;
}

void PrintLines (int nChars, int nLines, char whatChar)
{
	for (int c = 0; c < nLines; c++)
	{
		for (int d = 0; d < nChars; d++)
		{
			cout << whatChar;
		}
	}
}

void combat(enemy *hostile)
{
	bool whilefighting = true;

	cout << endl << "You have been engaged by a " << hostile->getname() << endl;

	while (whilefighting == true)
	{
		bool menu1 = true;
		char userInput;

		while(menu1 == true)
		{
			bool menu2 = true;

			cout << "It's your turn!" << endl;
			cout << "You are fighting in location " << maplocation.getx() << "," << maplocation.gety() << endl;
			cout << "You engage the " << hostile->getname() << endl;
			cout << "Your health is: " << mainchar.gethealth() << "/" << mainchar.gethealthcap() << endl;
			cout << "Your mana is:   " << mainchar.getmana() << "/" << mainchar.getmanacap() << endl;
			cout << "You have " << mainchar.howmany(8) << " potions left." << endl << endl;
			cout << "This is the Combat Menu:" << endl;
			cout << "-----------------" << endl;
			cout << "(S) Use Spell on " << hostile->getname() << endl;
			cout << "(A) Attack " << hostile->getname() << " with your " << mainchar.equippedweapon->getname() << endl;
			cout << "(Q) Quaff a Potion" << endl;
			cout << "| ";

			while (menu2 == true)
			{
				bool menu3 = true;

				cin >> userInput;
				cout << endl;

				switch(userInput)
				{
				case 's':
				case 'S':
					{
						if(mainchar.getmana() > 3)
						{
							cout << "Which spell do you want to use?" << endl;
							cout << "(L) " << ltgbolt.getname() << endl;
							cout << "(I) " << iceshard.getname() << endl;
							cout << "(M) " << meteor.getname() << endl;
							cout << "(F) " << firestorm.getname() << endl;


							while(menu3 == true)
							{
								mainchar.setmana(mainchar.getmana() - 3);
								cin>>userInput;

								switch(userInput)
								{
									int numtocast;

								case 'l':
								case 'L':
									{
										numtocast = rand() % 100 + 1;
										if(numtocast < mainchar.getchancetohitmagic())
										{
											int damage = ltgbolt.getdamage();

											cout<<"You deal "<< damage <<" damage."<<endl;
											hostile->sethealth(hostile->gethealth() - damage);
										}
										else
										{
											cout << "YOU FAIL!!!" << endl;
										}
										menu3 = false;
										menu2 = false;
										menu1 = false;
										break;
									}
								case 'i':
								case 'I':
									{
										numtocast = rand() % 100 + 1;
										if(numtocast < mainchar.getchancetohitmagic())
										{
											int damage = iceshard.getdamage();

											cout<<"You deal "<< damage <<" damage."<<endl;
											hostile->sethealth(hostile->gethealth() - damage);
										}
										else
										{
											cout << "YOU FAIL!!!" << endl;
										}
										menu3 = false;
										menu2 = false;
										menu1 = false;

										break;
									}
								case 'm':
								case 'M':
									numtocast = rand() % 100 + 1;
									if(numtocast < mainchar.getchancetohitmagic())
									{
										int damage = meteor.getdamage();
										int AEdamage = meteor.getAEdamage();

										cout<<"You deal "<<damage<<" damage."<<endl;
										cout<<"And take "<<AEdamage<<" in collateral damage."<<endl;

										hostile->sethealth(hostile->gethealth() - damage);
										mainchar.sethealth(mainchar.gethealth() - AEdamage);
									}
									else
									{
										cout << "YOU FAIL!!!" << endl;
									}
									menu3 = false;
									menu2 = false;
									menu1 = false;

									break;
								case 'f':
								case 'F':
									numtocast = rand() % 100 + 1;
									if(numtocast < mainchar.getchancetohitmagic())
									{
										int damage = firestorm.getdamage();
										int AEdamage = firestorm.getAEdamage();

										cout<<"You deal "<<damage<<" damage."<<endl;
										cout<<"And take "<<AEdamage<<" in collateral damage."<<endl;

										hostile->sethealth(hostile->gethealth() - damage);
										mainchar.sethealth(mainchar.gethealth() - AEdamage);
									}
									else
									{
										cout << "YOU FAIL!!!" << endl;
									}
									menu3 = false;
									menu2 = false;
									menu1 = false;

									break;
								default:
									cout << "Invalid Input.  Try Again." << endl;
									break;
								}
								if (hostile->gethealth() <= 0)
								{
									cout<<"The "<< hostile->getname() <<" has died."<<endl;
									cout<<"You gain "<<hostile->getexp()<<" exp."<<endl;
									mainchar.setexp(mainchar.getexp() + hostile->getexp());
									cout<<"You now have "<<mainchar.getexp()<<" exp total."<<endl;

									if (mainchar.getexp() >= mainchar.level * 50)
									{
										mainchar.level = mainchar.level +1;
										mainchar.setstr (mainchar.getstr() +3);
										mainchar.setcon (mainchar.getcon() +3);
										mainchar.setint (mainchar.getint() +3);
										mainchar.setdex (mainchar.getdex() +3);
										cout << "You have gained a level! You are now level " << mainchar.level << "!" << endl;
										cout << "Your stats have all increased by 3!" << endl;
									}

									cout<<"It drops "<<hostile->getgold()<<" gold."<<endl;
									mainchar.setgold(mainchar.getgold() + hostile->getgold());

									hostile->sethealth(hostile->gethealthcap());
									whilefighting = false;
								}
								else
								{
									hostile->AI(mainchar);
								}
								if(mainchar.gethealth() <= 0)
								{
									cout<<"You have died."<<endl;
									mainchar.alive = false;
									whilefighting = false;
								}
							}
							break;
						}

						else
						{
							cout<<"You lack the mana to perform a spell."<<endl;
						}
					}
				case 'a':
				case 'A':
					{
						int num = rand() % 100 + 1;

						if(num < (mainchar.getchancetohit() + mainchar.equippedweapon->getpercent()))
						{
							int dmg = rand() % mainchar.getatk() + (mainchar.equippedweapon->getdamagebonus() + 1);
							cout << "You attack the " << hostile->getname() << endl;
							cout << "You deal " << dmg << " damage" << endl;
							hostile->sethealth((hostile->gethealth()) - dmg);

							if(hostile->gethealth() <= 0)
							{
								cout<<"The "<< hostile->getname() <<" has died."<<endl;
								cout<<"You gain "<<hostile->getexp()<<" exp."<<endl;
								mainchar.setexp(mainchar.getexp() + hostile->getexp());
								cout<<"You now have "<<mainchar.getexp()<<" exp total."<<endl;

								if (mainchar.getexp() >= mainchar.level * 50)
									{
										mainchar.level = mainchar.level +1;
										mainchar.setstr (mainchar.getstr() +3);
										mainchar.setcon (mainchar.getcon() +3);
										mainchar.setint (mainchar.getint() +3);
										mainchar.setdex (mainchar.getdex() +3);
										cout << "You have gained a level! You are now level " << mainchar.level << "!" << endl;
										cout << "Your stats have all increased by 3!" << endl;
									}
								
								cout<<"It drops "<<hostile->getgold()<<" gold."<<endl;
								mainchar.setgold(mainchar.getgold() + hostile->getgold());

								hostile->sethealth(hostile->gethealthcap());
								whilefighting = false;
							}
							else
							{
								hostile->AI(mainchar);
							}
							if(mainchar.gethealth() <= 0)
							{
								cout<<"You have died."<<endl;
								mainchar.alive = false;
								whilefighting = false;
							}
						}
						else
						{
							cout << "You miss!" << endl;
						}
						menu2 = false;
						menu1 = false;
					}break;
				case 'q':
				case 'Q':
					{
						int num = 4 + rand() % 8;
						
						if(mainchar.gethealth() + num + mainchar.getcon() > mainchar.gethealthcap() && mainchar.howmany(8) > 0)
						{
							cout<<"You quaff a potion and are at full health." << endl << endl;

							mainchar.sethealth(mainchar.gethealthcap());

							mainchar.itemsubtract(8, 1);

							menu1 = false;
							menu2 = false;
						}
						else if (mainchar.howmany(8) > 0)
						{
							mainchar.sethealth(mainchar.gethealth() + num + mainchar.getcon());

							cout<<"You quaff a potion for and extra " << num + mainchar.getcon() << " health" << endl;

							mainchar.itemsubtract(8, 1);

							menu1 = false;
							menu2 = false;
						}
					}break;
				default:
					{
					cout << "Invalid Input.  Try Again." << endl;
					cout <<"|";
					break;
					}
				}
			}
		}
	}
}