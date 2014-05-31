/* **************************************************************************
// * Program Name: demon.h													*
// * Description: This is the header for class Demon derived from Creature	*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#ifndef DEMON_H
#define DEMON_H
#include "creature.h"
#include <iostream>
using namespace std;

class Demon : public Creature
{
public:
	Demon(); //default constructor
	Demon(int newType, int newStrength, int newHit); //constructor with parameters
	bool Plus50(); //boolean decides demon attack/strike
	int getDamage(); //virutal returns damage
	string getSpecies(); //returns species
};
#endif