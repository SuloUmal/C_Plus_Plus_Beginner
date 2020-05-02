#ifndef SICT_ACCOUNT__
#define SICT_ACCOUNT__
#include "iAccount.h"
namespace sict {
	class Account :public iAccount
	{
		double accBalance;
	public:
		Account(double bal);
		bool credit(double crd);
		bool debit(double dbt);
	protected:
		double balance() const;
	};
}
#endif
