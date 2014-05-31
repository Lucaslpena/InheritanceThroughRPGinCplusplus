/* **************************************************************************
// * Program Name: creature.cpp												*
// * Description: This is the definitions for class Creature				*
// *** SEE FUNCTION COMMENTS FOR SPECIFIC OPERATING PURPOSES ***			*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#include "creature.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

Creature::Creature() : type (1), strength (10), hitpoints (10) //default constructor creates a human with strength 10 and hitpoints 10
{ }

Creature::Creature(int newType, int newStrength, int newHit) : type (newType), strength (newStrength), hitpoints (newHit)
{ } //constructor with parameters 

int Creature::getDamage() //virtual return damage
{
    int damage;
    // all creatures inflict damage which is a random number up to their strength
    damage = (rand() % strength) + 1;
    //cout << getSpecies() << " attacks for " << damage << " points!" << endl;
    return damage;
}

string Creature::getSpecies() //VIRTUAL get species
{
    return " ";
}

void Creature::takeDamage(int dmg) //creature gets hit
{
	hitpoints = hitpoints - dmg; //set new hitpoints to hitpoints - dmage
	if (hitpoints <= 0) //if below or is zero they are dead
		isDead = true;
	else
		isDead = false;
}

int Creature::getStrength() //return strength
{
	return strength;
}

int Creature::getHitpoints() //return hitpoints
{
	return hitpoints;
}