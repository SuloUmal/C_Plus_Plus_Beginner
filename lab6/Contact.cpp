#include <iostream>
#include <cstring> 
#include "Contact.h"
#include "Contact.h"
#include <iomanip>
using namespace std;
namespace sict {
	Contact::Contact() {
		name[0] = '\0';
		phoneList = nullptr;
		size = 0;

	};

	Contact::Contact(const char*  contactName, const long long* phoneNumber, int counter) {

		int i; //counter for for-loop
		if (contactName != nullptr) {
			int length = strlen(contactName);
			for (i = 0; i <= length && i < MAX_CHAR; i++) {
				name[i] = contactName[i];
			}
		}
		else { name[0] = '\0'; }
		size = counter;
		if (phoneNumber != nullptr && size > 0) {
			phoneList = new long long[counter];
			for (i = 0; i < counter; i++) {
				if (phoneNumber[i] >= 10000000000 && phoneNumber[i] <= 999999999999) {
					phoneList[size] = phoneNumber[i];
					size++;
				}
			}

		}
		else {
			phoneList = nullptr;
		}
	};

	bool Contact::isEmpty() const {
		return ((name[0] == ' ' || name[0] == '\0') && phoneList == nullptr && size <= 0);
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			if (phoneList) {
				for (int i = 0; i < size; i++) {

					if (phoneList[i] > 99999999999 && phoneList[i] < 1000000000000) {
						cout << "(+" << phoneList[i] / 10000000000 << ") " << phoneList[i] / 10000000 % 1000 << " " << phoneList[i] / 10000 % 1000 << "-" << phoneList[i] % 10000 << endl;
					}
					if (phoneList[i] > 9999999999 && phoneList[i] < 100000000000) {
						cout << "(+" << phoneList[i] / 10000000000 << ") " << phoneList[i] / 10000000 % 1000 << " " << phoneList[i] / 10000 % 1000 << "-" << setfill('0') << setw(4) << phoneList[i] % 10000 << endl;
					}
				}
			}
		}
	}
	Contact::Contact(const Contact& objectCopy) {
		*this = objectCopy;
	}
	Contact& Contact::operator=(const Contact& rhs) {
		if (this != &rhs) {
			strcpy(name, rhs.name);
			size = rhs.size;
			if (rhs.phoneList == nullptr) {
				phoneList = nullptr;
			}
			else {
				phoneList = new long long[size];
				for (int i = 0; i < size; i++) {
					phoneList[i] = rhs.phoneList[i];
				}
			}
		}
		return *this;
	}
	Contact& Contact::operator+=(long long number) {
		if (number >= 10000000000 && number <= 999999999999 && !isEmpty()) {
			size++;
			long long* ptr = new long long[size];
			for (int i = 0; i < size - 1; i++) {
				ptr[i] = phoneList[i];
			}
			ptr[size - 1] = number;
			delete[] phoneList;
			phoneList = ptr;
		}
		return *this;
	}

	Contact::~Contact() {
		delete[] phoneList;
		phoneList = nullptr;
	}

}