#include "Account.h"

namespace sict {
	Account::Account(double bal)
	{
		(bal) && bal >= 0 ? accBalance = bal : accBalance = 0;
	}
	bool Account::credit(double crd) {
		bool ret = true;
		(crd >= 0) ? accBalance += crd : ret = false;
		return ret;
	}

	bool Account::debit(double dbt) {
		bool ret = true;
		(dbt >= 0) ? accBalance -= dbt : ret = false;
		return ret;
	}

	double Account::balance() const {
		return accBalance;
	}
}

