/* **************************************************************************
// * Program Name: cyberdemon.cpp											*
// * Description: This is the definitions for class cyberdemon derived from *
// * Demon which is derived from Creature									*
// *** SEE FUNCTION COMMENTS FOR SPECIFIC OPERATING PURPOSES ***			*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#include "cyberdemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Cyberdemon::Cyberdemon() : Demon() //default constructor
{ }

Cyberdemon::Cyberdemon(int newType, int newStrength, int newHit) : Demon (newType, newStrength, newHit)
{ } //constructor with parameters

int Cyberdemon::getDamage() //virtual function that returns damage with demonic attack
{
	int damage = Demon::getDamage();
	cout << "Cyberdemon's attack is at " << damage << " damage points!!" << endl;
	return damage ;
}
string Cyberdemon::getSpecies() //virtual function retruns cyberdemon
{
	return "Cyberdemon";
}