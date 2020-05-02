#include <cstring>
#include "Hero.h"
using namespace std;
namespace sict {
	Hero::Hero() {
		set();
	}
	
	void Hero::set() {
		heroName[0] = '\0';
		heroHealth = 0;
		attack = 0;
	}
	Hero::Hero(const char name[41], int health, int dmg) {
		if (name[0] != '\0' && health >= 0 && dmg >= 0) {
			strcpy(heroName, name);
			heroHealth = health;
			attack = dmg;
		}
		else {
			set();
		}
	}	void Hero::operator-=(int attack) {
		if (attack > 0) {
			heroHealth -= attack;
		}
		else if (heroHealth < 0) {
			heroHealth = 0;
		}
	}
	bool Hero::isAlive()const {
		return heroHealth > 0;
	}

	int Hero::attackStrength()const {
		return attack;
	}
  
ostream& Hero::display(ostream& os) const{
if (heroName[0] == '\0') {
			os << "No hero" << endl;
		}
		else {
			os << heroName;
		} return os;
}

	ostream& operator<<(ostream& os, const Hero& hero) {
		return hero.display(os);
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero lhs = first, rhs = second;
		const Hero* winner = &second;
		int flag = 0;
		int round = 0;
		for (round = round; round <= MAX_ROUNDS && flag == 0; round++) {
			lhs -= rhs.attackStrength();
			rhs -= lhs.attackStrength();
			if (!rhs.isAlive() || !lhs.isAlive()) flag = 1;
		}
		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
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