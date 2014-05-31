/* **************************************************************************
// * Program Name: balrog.cpp												*
// * Description: This is the definitions for class Balrog derived from Demon
// * which is derived from Creature											*
// *** SEE FUNCTION COMMENTS FOR SPECIFIC OPERATING PURPOSES ***			*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#include "balrog.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Balrog::Balrog(): Demon() //default constructor
{ }

Balrog::Balrog (int newType, int newStrength, int newHit) : Demon (newType, newStrength, newHit)
{ } //constructor with parameters

int Balrog::getDamage()
{ //damage used damage of Demon, which includes chance for demonic attack
	int damage = Demon::getDamage();
	int damage2 = 0; //Balrog ALWAYS attacks two times, however doesnt always hit twice
	cout << "Balrog's first attack is " << damage << " damage points!!" << endl;
	bool doubleA = doubleAttack();
	if ( doubleA == true )
	{
		damage2 = Demon::getDamage();
		cout << "Balrog attacks a second time for " << damage2 << " points!!" << endl;
		doubleA = false;
		damage = damage2 + damage;
		cout << "Balrog's total damage is " << damage << " points!!" << endl;
	}
	else
		cout << "Balrog misses his second attack" << endl;
	return damage ;
}

bool Balrog::doubleAttack()
{
	if ( ( rand() % 100 ) < 50 ) //*NOTE* Balrog had 50% chance of hitting with second attack*
		return true ;
	else
		return false ;
}

string Balrog::getSpecies() //return species for Balrog
{
	return "Balrog";
}