/* **************************************************************************
// * Program Name: human.h													*
// * Description: This is the header for class human derived from Creature	*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#ifndef HUMAN_H
#define HUMAN_H
#include "creature.h"
#include <iostream>
using namespace std;

class Human : public Creature
{
public:
	Human(); //default constructor
	Human(int newType, int newStrength, int newHit); //constructor with parameters
	int getDamage(); //virtual damage function
	string getSpecies();//virtual function retruns species
};
#endif