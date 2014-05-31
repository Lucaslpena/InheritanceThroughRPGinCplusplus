/* **************************************************************************
// * Program Name: creature.h												*
// * Description: This is the header for class Creature						*
// * which is derived from Creature											*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>
using namespace std;

class Creature
{
    private:
        int type;               // 0 human, 1 cyberdemon, 2 balrog, 3 elf
        int strength;           // how much damage it can inflict
        int hitpoints;          // how much damage it can sustain
    public:
        Creature(); //default constructor
        Creature(int newType, int newStrength, int newHit); //constructor with parameters
        virtual int getDamage();		//returns type of damage virtually
		virtual string getSpecies();    // returns type of species virtually
		void takeDamage(int dmg);	//take hit function
		int getStrength(); //return strength
		int getHitpoints(); //return hitpoints
		bool isDead; //bool decides if dead or alive
};
#endif
