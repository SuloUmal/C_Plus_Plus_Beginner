#ifndef SICT_IACCOUNT__
#define SICT_IACCOUNT__
#include <iostream>
namespace sict {
	class iAccount {
	public:
		virtual bool credit(double crd) = 0;
		virtual bool debit(double dbt) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& os) const = 0;
		virtual ~iAccount() {};

	};
	iAccount* CreateAccount(const char* account_name, double bal);
}
#endif