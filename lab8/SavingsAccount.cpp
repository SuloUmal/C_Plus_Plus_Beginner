#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount(double bal, double rate) : Account(bal) {
		rate > 0 ? interestRate = rate : interestRate = 0;
	}
	void SavingsAccount::monthEnd() {
		credit(balance() * interestRate);
	}
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl;
		os << "Balance: $" << setprecision(2) << fixed << balance() << endl;
		os << "Interest Rate (%): " << interestRate * 100 << endl;
	}
}