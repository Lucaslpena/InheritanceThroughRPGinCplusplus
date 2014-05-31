/* **************************************************************************
// * Program Name: demon.cpp												*
// * Description: This is the definitions for class demon derived from		*
// * Creature																*
// *** SEE FUNCTION COMMENTS FOR SPECIFIC OPERATING PURPOSES ***			*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#include "demon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Demon::Demon ( ) : Creature ( ) //default constructor
{ }

Demon::Demon ( int newType, int newStrength, int newHit ) : Creature (newType, newStrength, newHit)
{ } //constructor with parameters

int Demon::getDamage() //virtual function returns creature damage
{
	int damage = Creature::getDamage(); //get damage
	bool demonstrike = Plus50(); //setting plus 50 to bool demonstrike
	if (demonstrike == true) //if true
	{
		damage = damage + 50; //attack is not plus 50
		cout << "Demon Attack inflicted damage is now " << damage << " points!!" << endl;	
	}
	return damage;
}

bool Demon::Plus50() //boolean 5% change to do demonic strike
{
	if ( ( rand() % 100 ) < 5 )
		return true ;
	else
		return false ;
}

string Demon::getSpecies() //virtual function returns species
{
	return " ";
}