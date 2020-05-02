#ifndef CRA_ACCOUNT_H
#define CRA_ACCOUNT_H


namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;
	class CRA_Account {
		int tax[max_yrs];
		float owing[max_yrs];
		char family_name[max_name_length];
		char given_name[max_name_length];
		int SIN;

	public:
		void set(int year, double balance);
		void set(const char* familyName, const char* givenName, int sin);
		void display() const;
		bool isEmpty() const;
	};
}
#endif

