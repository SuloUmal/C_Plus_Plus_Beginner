#include <iostream>
#include <cstring>
#include "Error.h"
using namespace std;
namespace aid {

	void Error::set() {
		msg = nullptr;
	}


	Error::Error(const char* errorMessage) {

		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			set();
		}
		else {
			msg = new char[strlen(errorMessage + 1)];
			strcpy(msg, errorMessage);
		}
	}

	Error::~Error() {
		set();
	}

	void Error::clear() {
		if (msg != nullptr)
		msg[0] = '\0';
	}

	bool Error::isClear() const {
		return msg == nullptr || msg[0] == '\0';
	}

	void Error::message(const char* str) {
		delete[] msg;
		if (str == nullptr) {
			set();
		}
		else {
			msg = new char[strlen(str) + 1];
			strcpy(msg, str);
		}
	}

	const char* Error::message() const {
		return msg;
	}
	std::ostream& operator<<(std::ostream& os, const Error& obj) {
		if (!obj.isClear()) os << obj.message();
		return os;
	}
}