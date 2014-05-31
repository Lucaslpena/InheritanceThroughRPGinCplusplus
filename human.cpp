/* **************************************************************************
// * Program Name: human.cpp												*
// * Description: This is the definitions for class human derived Creature  *
// *** SEE FUNCTION COMMENTS FOR SPECIFIC OPERATING PURPOSES ***			*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#include "human.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Human::Human() : Creature() //default constructor
{ }

Human::Human (int newType, int newStrength, int newHit) : Creature (newType, newStrength, newHit)
{ }//constructor with parameters

int Human::getDamage() //virtual function get damage
{
	int damage = Creature::getDamage(); //gets creature damage and sets to human damage
	cout << "Human's attack is at " << damage << " damage points!!" << endl;
	return damage ;
}
string Human::getSpecies() //return virtual species
{
	return "Human";
}

