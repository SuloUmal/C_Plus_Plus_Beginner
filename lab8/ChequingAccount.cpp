#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sict {
	ChequingAccount::ChequingAccount(double bal, double feeTransact, double feeMonth) : Account(bal) {
		feeTransact > 0 ? tFee = feeTransact : tFee = 0.0;

		feeMonth > 0 ? mFee = feeMonth : tFee = 0.0;
	}

	bool ChequingAccount::credit(double crd) {
		bool ret = true;
		(crd >= 0) ? Account::credit(crd) : ret = false;
		if (ret) Account::debit(tFee);
		return ret;
	}

	bool ChequingAccount::debit(double dbt) {
		bool ret = true;
		(dbt >= 0) ? Account::debit(dbt) : ret = false;
		if (ret) Account::debit(tFee);
		return ret;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(mFee);
	}
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << setprecision(2) << fixed<< tFee << endl;
		os << "Monthly Fee: " << mFee << endl;
	}
}