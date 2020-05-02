// OOP244-BTP200 Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 2.1
// 2018/01/23
// Chris Szalwinski

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
int sum = 0, check = 0, i = 0, t, third = 0, second = 0, substract= 0, count = 0, SIN = 0, sin_check = 0;

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

if (sin >= min_sin && sin <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			sin_check = sin;
			check = sin % 10;
			//addition of each second num
			for (i = 0; i < 4; i++) {
				second += sin / 10 % 10 * 2;
				for (t = 0; t < 2; t++) {
					third = second % 10;
					third += second / 10 % 10;

				}
				sin /= 100;
			}

			sum = third + second; //summing odd nums and doubled even num

			//addition of odd num
			for (i = 0; i < 4; i++){
				second = sin / 100 % 10;
				second += sin / 10 % 10;
     			 }
			sum += second;
			substract = (sum / 10 % 10 + 1) * 10; //rounding


			if (sum == substract - check) {
				strncpy(family_name, familyName, max_name_length);
				strncpy(given_name, givenName, max_name_length);
				SIN = sin_check;
			}
		}
}
	


	// set adds a year and balanace to the return records for the
	// current object
	void CRA_Account::set(int year, double balance)
	{
		if (!isEmpty() && count < max_yrs) {
			tax[count] = year;
			owing[count] = balance;
			count++;
		}
	}

	// display inserts the current object's data into the output stream
	//
	void CRA_Account::display() const
	{
		if (!isEmpty()) {
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << SIN << endl;
			for (int i = 0; i < count; ++i) {
				cout << "Year (" << tax[i] << ") ";
				if (owing[i] > 2.00) {
					cout << "balance owing: " << owing[i] << endl;
				}
				else if (owing[i] < -2.00) {
					cout << "refund due: " << -owing[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	// isEmpty returns the empty status of the current object
	//
	bool CRA_Account::isEmpty() const {
		if (SIN == 0 && count < max_yrs + 1) {
			return true;
		}
		else {
			return false;
		};
	}
}