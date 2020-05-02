#ifndef SICT_SAVINGACCOUNT__
#define SICT_SAVINGSACCOUNT__
#include "Account.h"
namespace sict {
	class SavingsAccount : public Account
	{
		double interestRate;
	public:
		SavingsAccount(double bal, double rate);
		void monthEnd();
		void display(std::ostream& os) const;
	};
}
#endif
