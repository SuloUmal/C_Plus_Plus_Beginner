#include "iAccount.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"
namespace sict {
	double rate = 0.05;
	double tFee = 0.50;
	double mFee = 2.00;
	iAccount* CreateAccount(const char* account_name, double bal) {
		iAccount *newAcc = nullptr;
		if (account_name[0] == 'S') {
			newAcc = new SavingsAccount(bal, rate);
		}
		if (account_name[0] == 'C') {
			newAcc = new ChequingAccount(bal, tFee, mFee);
		}
		return newAcc;
	}
}