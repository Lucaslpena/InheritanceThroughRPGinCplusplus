/* **************************************************************************
// * Program Name: creatureApp.h											*
// * Description: This is the driver program for the Class creature and the	*
// * files that are derived from it! below is a switch statement that runs	*
// * the minimum program requirements with a switch statement 1 and extra	*
// * credit material in challenging a randomly generated set of enemies		*
// * the user inputs his own data for the 4 creatures directly!				*
// * SEE THE INDIVIDUAL LINES OF CODE FOR COMMENTS							*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/

#include "balrog.h"
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	srand ( time(NULL) ); //needed to run random numbers
	int menuoption = 0; //menuoption
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; //menu below
	cout << "~WELCOME TO MEDIEVAL BATTLE ARENA~\n"; 
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Please Enter the Following Menu Options: \n";
	cout << "Enter 1 to Load game from a file\n"; //BASIC REQUIREMENT MATERIAL
	cout << "Enter 2 to play vs the computer\n"; //EXTRA CREDIT MATERIAL
	cin >> menuoption;
	Creature * GOODcreatures[8];
	Creature * BADcreatures[8];
	switch (menuoption)
	{
		while ((menuoption !=1) || (menuoption !=2)) //error checking
		{
			cout << "INVALID OPTION ENTERED" << endl;
			cin >> menuoption;
		}

		case 1: //BASIC requirements below
		{
			string infilename; //open file
			ifstream inFile;
			cout << "Please Enter a Valid File Name: ";
			cin >> infilename; //read in filename
			inFile.open(infilename.c_str()); //open file
			while(!inFile.is_open()) //if not open invalid file re-open
			{ 
				cout << "Invalid File Name, Please Enter a Valid File Name: ";
				cin >> infilename;
				inFile.open(infilename.c_str());
			}
			if (inFile.is_open()) //if open show valide
			{	
				cout << "Valid File Entered! Data Loaded to file";
				cout << infilename << endl;
				int i = 0;
				for( int i = 0; i < 4; i++) 
				{//read in data for 4 good guys and set to respective objects
					int t, str, hp;
					inFile >> t >> str >> hp;
					if (t == 0) ////correct constructors are being called
						GOODcreatures[i] = new Human(t,str,hp);
					if (t == 1)
						GOODcreatures[i] = new Cyberdemon(t,str,hp);
					if (t ==2)
						GOODcreatures[i] = new Balrog(t,str,hp);
					if (t== 3)
						GOODcreatures[i] = new Elf(t,str,hp);
				}
				for( int i = 0; i < 4; i++)
				{//read in data for 4 bad guys and set to respective objects
					int t, str, hp;
					inFile >> t >> str >> hp;
					if (t == 0) ////correct constructors are being called
						BADcreatures[i] = new Human(t,str,hp);
					if (t == 1)
						BADcreatures[i] = new Cyberdemon(t,str,hp);
					if (t ==2)
						BADcreatures[i] = new Balrog(t,str,hp);
					if (t== 3)
						BADcreatures[i] = new Elf(t,str,hp);
				}
			}
			inFile.close(); //close file
		}
			break;
		case 2: 
		{	//user enters in strength and hipoints himself and opposes a 
			//randomly generated opponent similiar to their one
			cout << "Enter in STRENGTH followed by HITPOINTS for your HUMAN\n";
			int hSTR, hHP;
			cout << "Enter STRENGTH: ";
			cin >> hSTR;
			cout << "Enter HITPOINTS: ";
			cin >> hHP;
			GOODcreatures[0] = new Human(0,hSTR,hHP);
			BADcreatures[0] = new Human(0,(( rand() % hSTR )+1), (( rand() % hHP )+1));
			cout << endl;
			cout << "Enter in STRENGTH followed by HITPOINTS for your ELF\n";
			int eSTR, eHP;
			cout << "Enter STRENGTH: ";
			cin >> eSTR;
			cout << "Enter HITPOINTS: ";
			cin >> eHP;
			GOODcreatures[1] = new Elf(0,eSTR,eHP);
			BADcreatures[1] = new Elf(0,(( rand() % eSTR )+1), (( rand() % eHP )+1));
			cout << endl;
			cout << "Enter in STRENGTH followed by HITPOINTS for your BALROG\n";
			int bSTR, bHP;
			cout << "Enter STRENGTH: ";
			cin >> bSTR;
			cout << "Enter HITPOINTS: ";
			cin >> bHP;
			GOODcreatures[2] = new Balrog(0,bSTR,bHP);
			BADcreatures[2] = new Balrog(0,(( rand() % bSTR )+1), (( rand() % bHP )+1));
			cout << endl;
			cout << "Enter in STRENGTH followed by HITPOINTS for your CYBERDEMON\n";
			int cSTR, cHP;
			cout << "Enter STRENGTH: ";
			cin >> cSTR; 
			cout << "Enter HITPOINTS: ";
			cin >> cHP;
			GOODcreatures[3] = new Cyberdemon(0,cSTR,cHP);
			BADcreatures[3] = new Cyberdemon(0,(( rand() % cSTR )+1), (( rand() % cHP )+1));
		}
			break;
	}
	for(int k = 0; k < 4; k++)
	{	//creating 4 more entries in the array equal to that of the first 4
		//used in fighting NEXT NON-DEAD individual ONLY!!!!!!!
		BADcreatures[k+4] = BADcreatures[k];
		GOODcreatures[k+4] = GOODcreatures[k];
	}
	
	for(int k = 0; k <=7; k++) //initializing dead to false default!
	{
		BADcreatures[k]->takeDamage(0);
		GOODcreatures[k]->takeDamage(0);
	}
	//MENU TO SHOW CHARACTERS BASE STATS BELOW!!
	cout << endl;
	cout << "Below is the GOOD creatures and their base stats!\n";
	cout << "___TYPE__________STRENGTH________HITPOINTS__\n";
	for(int i = 0; i < 4; i++)
	{
		cout << setw(10) << left << GOODcreatures[i]->getSpecies();
		cout << setw(13) << right << GOODcreatures[i]->getStrength();
		cout << setw(15) << GOODcreatures[i]->getHitpoints();
		cout << endl;
	}
	cout << endl;
	cout << "Below is the BAD creatures and their base stats!\n";
	cout << "___TYPE__________STRENGTH________HITPOINTS__\n";
	for(int i = 0; i < 4; i++)
	{
		cout << setw(10) << left << BADcreatures[i]->getSpecies();
		cout << setw(13) << right << BADcreatures[i]->getStrength();
		cout << setw(15) << BADcreatures[i]->getHitpoints();
		cout << endl;
	}

	//BATTLES BELOW
	cout << endl;
	cout << "PRESS ANY KEY THEN ENTER TO LET BATTLE BEGIN!!!\n";
	char begin;
	cin >> begin;
	for(int roundnum = 1; roundnum <= 20; roundnum++) //LET THE BATTLE BEGIN!
	{
		if (roundnum == 20) //if rounds are 20 then show tie
		{				
			cout << "!TIE! NO WINNING TEAM!" << endl;
			cout << "THANK YOU FOR PLAYING!!";	
			system("pause");
			return 0;
		}	
		cout << " BATTLE ROUND NUMBER " << roundnum << "!!\n";
		cout << "BAD creatures attack first!!" << endl; //BAD ATTACKING!
		for(int i = 0; i < 4; i++)
		{
				
			int change = 0;
			
			if (BADcreatures[i]->isDead == true) //if attacking creature is dead
			{
				cout << "BAD " << BADcreatures[i]->getSpecies() << "is dead so BAD " << BADcreatures[i+1]->getSpecies() << " attacks\n";
				if ( i == 3)
					i = 0;
				else
					i++;
				if (BADcreatures[i]->isDead == true) //if that attacking creature is dead
				{	
					cout << "BAD " << BADcreatures[i]->getSpecies() << "is dead so BAD " << BADcreatures[i+1]->getSpecies() << " attacks\n";
					if ( i == 3)
						i = 0;
					else
						i++;
					if (BADcreatures[i]->isDead == true) //if that attacking creature is dead
					{
						cout << "BAD " << BADcreatures[i]->getSpecies() << "is dead so BAD " << BADcreatures[i+1]->getSpecies() << " attacks\n";
						if ( i == 3)
							i = 0;
						else
							i++;
						if (BADcreatures[i]->isDead == true) //if that attacking creature is dead
						{
							cout << "BAD " << BADcreatures[i]->getSpecies() << "is dead so BAD " << BADcreatures[i+1]->getSpecies() << " attacks\n";
							cout << "GOOD CREATURES HAVE WON! THANK YOU FOR PLAYING!!";
							return 0;
						}	
					}
				}
			}
			if (GOODcreatures[i]->isDead == true) //if aiming at a dead creature
			{
				cout << "GOOD "<< GOODcreatures[i]->getSpecies() << " is DEAD and can't be attacked!!\n"; //print dead message
				change++; //change in target
				//if dead attack someone else
				cout << "BAD " << BADcreatures[i]->getSpecies() << " now takes aim at GOOD " << GOODcreatures[change+i]->getSpecies() << endl;
				if (GOODcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
				{
					cout << "GOOD "<< GOODcreatures[i+change]->getSpecies() << " is DEAD and can't be attacked!!\n";
					if (change == 3)
						change = 0;
					else
						change++;
					if (GOODcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
					{
						cout << "GOOD "<< GOODcreatures[i+change]->getSpecies() << " is DEAD and can't be attacked!!\n";
						if (change == 3)
							change = 0;
						else
							change++;
						if (GOODcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
						{
							cout << "GOOD "<< GOODcreatures[i+change]->getSpecies() << " is DEAD and can't be attacked!!\n";
							if (change == 3)
								change = 0;
							else
								change++;
							if (GOODcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
							{
								cout << "BAD CREATURES HAVE WON! THANK YOU FOR PLAYING!!";
								return 0;										
							}
						}	
					}
				}
			}
			int j = i + change;

			cout << "BAD ";
			int recieveddmg= BADcreatures[i]->getDamage();//display damage and set to integer
			GOODcreatures[j]->takeDamage(recieveddmg); //pass opponent integer into their take damage function
			if(GOODcreatures[j]->isDead == true) //if dead show is now dead
				cout << "GOOD " << GOODcreatures[j]->getSpecies() << " is now DEAD!!\n" << endl;
			else //otherwise are alive and show remaining hitpoints
				cout << "GOOD " << GOODcreatures[j]->getSpecies() << " now has "
				<< GOODcreatures[j]->getHitpoints() << " HITPOINTS LEFT!\n" << endl;
		}
		
		cout << "PRESS ANY KEY THEN ENTER TO LET THE NEXT BATTLE BEGIN!!!\n";
		char z;
		cin >> z;

		roundnum++; 
		if (roundnum == 20) //if is 20 then end
		{				
			cout << "!TIE! NO WINNING TEAM!" << endl;
			cout << "THANK YOU FOR PLAYING!!";	
			system("pause");
			return 0;
		}
		cout << " BATTLE ROUND NUMBER " << roundnum << "!!\n";
		cout << "GOOD creatures attack first!!" << endl; //GOOD ATTACKING
		for(int i = 0; i < 4; i++)
		{

			int change = 0;
			
			if (GOODcreatures[i]->isDead == true) //if attacking creature is dead
			{
				cout << "GOOD " << GOODcreatures[i]->getSpecies() << "is dead so GOOD " << GOODcreatures[i+1]->getSpecies() << " attacks\n";
				if ( i == 3)
					i = 0;
				else
					i++;
				if (GOODcreatures[i]->isDead == true) //if that attacking creature is dead
				{	
					cout << "GOOD " << GOODcreatures[i]->getSpecies() << "is dead so GOOD " << GOODcreatures[i+1]->getSpecies() << " attacks\n";
					if ( i == 3)
						i = 0;
					else
						i++;
					if (GOODcreatures[i]->isDead == true) //if that attacking creature is dead
					{
						cout << "GOOD " << GOODcreatures[i]->getSpecies() << "is dead so GOOD " << GOODcreatures[i+1]->getSpecies() << " attacks\n";
						if ( i == 3)
							i = 0;
						else
							i++;
						if (GOODcreatures[i]->isDead == true) //if that attacking creature is dead
						{
							cout << "GOOD " << GOODcreatures[i]->getSpecies() << "is dead so GOOD " << GOODcreatures[i+1]->getSpecies() << " attacks\n";
							cout << "BAD CREATURES HAVE WON! THANK YOU FOR PLAYING!!";
							return 0;
						}	
					}
				}
			}

			if (BADcreatures[i]->isDead == true) //if aiming at a dead creature
			{
				cout << "BAD "<< BADcreatures[i]->getSpecies() << " is DEAD and can't be attacked!!\n"; //print dead message
				change++; //change in target
				//if dead attack someone else
				cout << "GOOD " << GOODcreatures[i]->getSpecies() << " now takes aim at BAD " << BADcreatures[change+i]->getSpecies() << endl;
				if (BADcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
				{
					cout << "BAD "<< BADcreatures[i+change]->getSpecies() << " is DEAD and can't be attacked!!\n";
					if (change == 3)
						change = 0;
					else
						change++;
						if (BADcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
					{
						cout << "BAD "<< BADcreatures[i+change]->getSpecies() << " is DEAD and can't be attacked!!\n";
						if (change == 3)
							change = 0;
						else
							change++;
						if (BADcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
						{
							cout << "BAD "<< BADcreatures[i+change]->getSpecies() << " is DEAD and can't be attacked!!\n";
							if (change == 3)
								change = 0;
							else
								change++;
							if (BADcreatures[change+i]->isDead == true)// if changed target is also dead print error and change++
							{
								cout << "GOOD CREATURES HAVE WON! THANK YOU FOR PLAYING!!";
								return 0;										
							}
						}
					}
				}
			}
			int j = i + change;

			cout << "GOOD ";
			int recieveddmg= GOODcreatures[i]->getDamage();//display damage and set to integer
			BADcreatures[j]->takeDamage(recieveddmg);//pass opponent integer into their take damage function
			if(BADcreatures[j]->isDead == true)//if dead show is now dead
				cout << "BAD " << BADcreatures[j]->getSpecies() << " is now DEAD!!\n" << endl;
			else//otherwise are alive and show remaining hitpoints
				cout << "BAD " << BADcreatures[j]->getSpecies() << " now has "
				<< BADcreatures[j]->getHitpoints() << " HITPOINTS LEFT!\n" << endl;
		}
		cout << "PRESS ANY KEY THEN ENTER TO LET THE NEXT BATTLE BEGIN!!!\n";
		char q;
		cin >> q;
	}
	return 0;
}
