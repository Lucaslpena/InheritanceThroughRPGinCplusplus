/* **************************************************************************
// * Program Name: elf.h													*
// * Description: This is the header for class Elf derived from Creature	*
// * Date: 11/14/12															*
// * Owner:  Lucas Lorenzo Pena												*
// *************************************************************************/
#ifndef ELF_H
#define ELF_H
#include "creature.h"
#include <iostream>
using namespace std;

class Elf : public Creature
{
public:
	Elf(); //default constructor
	Elf(int newType, int newStrength, int newHit); //constructor with parameters
	int getDamage(); //virtual damage function
	bool magicAttack(); //boolean decides whether or not attack is doubled 
	string getSpecies();//function that returns species
};
#endif