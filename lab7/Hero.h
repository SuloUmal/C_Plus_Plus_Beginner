#ifndef SICT_HELPER__
#define SICT_HELPER__
#include <iostream>
using namespace std;
namespace sict {
#define MAX_ROUNDS 100
	class Hero {
		char heroName[41];
		int heroHealth;
		int attack;
	public:
		Hero();
		Hero(const char heroName[41], int heroHealth, int attack);
		void set();
		void operator-=(int attack);
		bool isAlive()const;
		int attackStrength()const;
		ostream& display(ostream& os = cout) const;
	};
	ostream& operator<<(ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif