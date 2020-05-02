#include <iostream>
#include "SuperHero.h"
using namespace std;
namespace sict {
	SuperHero::SuperHero():	Hero::Hero(){
		bonusAttack = 0;
		defence = 0;
	}

	SuperHero::SuperHero(const char heroName[41], int heroHealth, int attack, int bonusDmg, int bonusDefence):Hero::Hero(heroName, heroHealth, attack)
	{
		
		bonusAttack = bonusDmg;
		defence = bonusDefence;
	}

	int SuperHero::attackStrength()const {
		return bonusAttack + Hero::attackStrength();
	}
	int SuperHero::defend()const {
		return defence;
	}
	ostream& operator<<(ostream& os, const SuperHero& SuperHero) {
		return SuperHero.display(os);
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero lhs = first, rhs = second;
		const SuperHero* winner = &second;
		int flag = 0;
		int round = 0;
		for (round = round; round < MAX_ROUNDS && flag == 0; round++) {
			lhs -= rhs.attackStrength() - lhs.defend();
			rhs -= lhs.attackStrength() - rhs.defend();
			if (!rhs.isAlive() || !lhs.isAlive()) flag = 1;
		}
		cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
		if (round == MAX_ROUNDS || !rhs.isAlive()) {
			cout << first << " in " << round << " rounds." << endl;
			winner = &first;
		}
		else {
			cout << second << " in " << round << " rounds." << endl;
		}
		return *winner;
	}
}
