#ifndef SUPERHERO_SICT__
#define SUPERHERO_SICT__
#include "Hero.h"
namespace sict {
	class SuperHero: public Hero
	{
		int bonusAttack;
		int defence;
	public:
		int attackStrength()const;
		int defend()const;
		SuperHero();
		SuperHero(const char heroName[41], int heroHealth, int attack, int bonusDmg, int bonusDefence);
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif