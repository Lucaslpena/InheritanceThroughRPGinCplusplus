/* **************************************************************************
// * Program Name: cyberdemon.h												*
// * Description: This is the header for class cyberdemon derived from Demon
// * which is derived from Creature											*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
#include <iostream>
using namespace std;

class Cyberdemon : public Demon
{
public:
	Cyberdemon(); //default constructor
	Cyberdemon (int newType, int newStrength, int newHit); //constructor with parameters
	int getDamage(); //damage function 
	string getSpecies();//species function
};
#endif