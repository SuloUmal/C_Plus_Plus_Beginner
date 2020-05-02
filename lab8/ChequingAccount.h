#ifndef SICT_CHEQUINGACCOUNT__
#define SICT_CHEQUINGACCOUNT__
#include "Account.h"
#include <iostream>
namespace sict {
	class ChequingAccount : public Account
	{
		double tFee;
		double mFee;
	public:
		ChequingAccount(double bal, double feeTransact, double feeMonth);
		bool credit(double crd);
		bool debit(double dbt);
		void monthEnd();
		void display(std::ostream& os) const;
	};
}
#endif
