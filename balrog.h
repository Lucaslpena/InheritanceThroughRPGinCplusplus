/* **************************************************************************
// * Program Name: balrog.h													*
// * Description: This is the header for class Balrog derived from Demon	*
// * which is derived from Creature											*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#ifndef BALROG_H
#define BALROG_H
#include "demon.h"
#include <iostream>
using namespace std;

class Balrog : public Demon
{
public:
	Balrog(); //default constructor 
	Balrog(int newType, int newStrength, int newHit); //constructor with parameters
	int getDamage(); //virtual get damage
	bool doubleAttack(); //boolean for double attack
	string getSpecies(); //virtual return species
};
#endif