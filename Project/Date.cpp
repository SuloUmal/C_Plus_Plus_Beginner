/*
Milestone 1
Suleyman Umalatov
Date.cpp
2019/07/15
*/
#include <iostream>
#include "Date.h"
using namespace std;
namespace aid {
	Date::Date() {
		setEmpty();
	}

	void Date::set(int year, int month, int day) {
		m_year = year;
		m_month = month;
		m_day = day;
		m_compare = m_year * 372 + m_month * 31 + m_day;
	}
	void Date::setEmpty() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_compare = 0;
		m_error = NO_ERROR;
	}

	Date::Date(int year, int month, int day) {
		setEmpty();
		if (year > max_year || year < min_year) errCode(YEAR_ERROR);
		if ((month > 12 || month < 1) && m_error == NO_ERROR) errCode(MON_ERROR);
		if (!mdays(year, month) && m_error == NO_ERROR) errCode(DAY_ERROR);
		if ((year * 372 + month * 31 + day) < min_date) errCode(PAST_ERROR);
		if (m_error == NO_ERROR) {
			set(year, month, day);
		}
	}

	void Date::errCode(int err) {
		m_error = err;
	}

	int Date::errCode() const {
		return m_error;
	}

	bool Date::bad() const {
		return m_error != NO_ERROR;
	}

	bool Date::operator==(const Date& rhs) const {
		return m_day == rhs.m_day && m_month == rhs.m_month && m_year == rhs.m_year;
	}
	bool Date::operator!=(const Date& rhs) const {
		return m_day != rhs.m_day || m_month != rhs.m_month || m_year != rhs.m_year;
	}

	bool Date::operator<(const Date& rhs) const {
		return this->m_compare < rhs.m_compare && m_error == NO_ERROR;
	}
	bool Date::operator>(const Date& rhs) const {
		return this->m_compare > rhs.m_compare && m_error == NO_ERROR;
	}
	bool Date::operator<=(const Date& rhs) const {
		return *this < rhs || *this == rhs;
	}

	bool Date::operator>=(const Date& rhs) const {
		return *this > rhs || *this == rhs;
	}

	std::istream& Date::read(std::istream& istr) {
		int year, month, day;
		char format;
		m_error = NO_ERROR;
		istr >> year >> format >> month >> format >> day;
		if (istr.fail()) {
			setEmpty();
			errCode(CIN_FAILED);
		}
		else {
			if ((year * 372 + month * 31 + day) < min_date) errCode(PAST_ERROR);
			if (year > max_year || year < min_year) errCode(YEAR_ERROR);
			if ((month > 12 || month < 1) && m_error == NO_ERROR) errCode(MON_ERROR);
			if (mdays(year, month) >= 1 && day > mdays(year, month)) errCode(DAY_ERROR);
			if (m_error == NO_ERROR) this->set(year, month, day);
		}
		istr.clear();
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		char symbol = '/';
		ostr << m_year << symbol;
		if (m_month < 10) {
			ostr << 0;
		}
		ostr << m_month << symbol;
		if (m_day < 10) {
			ostr << 0;
		}
		ostr << m_day;
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& object) {
		object.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& object) {
		object.read(istr);
		return istr;
	}


	int Date::mdays(int year, int mon) const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
}