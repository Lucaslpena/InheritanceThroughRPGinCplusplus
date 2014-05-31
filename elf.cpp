/* **************************************************************************
// * Program Name: elf.cpp													*
// * Description: This is the definitions for class elf derived from Creature
// *** SEE FUNCTION COMMENTS FOR SPECIFIC OPERATING PURPOSES ***			*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#include "elf.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Elf::Elf(): Creature()//default constructor
{ }

Elf::Elf ( int newType, int newStrength, int newHit ) : Creature (newType, newStrength, newHit)
{ } //constructor with parameters

int Elf::getDamage() //virtual function returns damage
{
	int damage = Creature::getDamage(); //get creature damage
	cout << "Elf's attack is at " << damage << " damage points!!" << endl;
	bool magicA = magicAttack(); //if magic attack is true then 
	if ( magicA == true )
	{
		damage = damage * 2; //damage is twice the amount of initial damage
		cout << "Magic Attack inflicted damage is now doubled to " << damage << " points!!" << endl;	
	}
	return damage ;
}

bool Elf::magicAttack() //10 % change of  magic attack
{
	if ( ( rand() % 100 ) < 10 )
		return true ;
	else
		return false ;
}

string Elf::getSpecies() //return species in virtual function
{
	return "Elf";
}