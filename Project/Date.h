/*
Milestone 1
Suleyman Umalatov
Date.h
2019/07/15
*/

#ifndef _DATE_AID__
#define _DATE_AID__
namespace aid{
#define NO_ERROR 0
#define CIN_FAILED 1  
#define DAY_ERROR  2
#define MON_ERROR  3 
#define YEAR_ERROR 4
#define PAST_ERROR 5

const int min_year = 2018;
const int max_year = 2038;
const int min_date = 751098;
class Date{
  int m_year;
  int m_month;
  int m_day;
  int m_compare;
  int m_error;
 void errCode(int errorCode);
 int mdays(int year, int month) const;
 void set(int year,int month,int day);
 void setEmpty();
 public:
Date();
Date(int year, int month, int day);
bool operator==(const Date& rhs) const;
bool operator!=(const Date& rhs) const;
bool operator<(const Date& rhs) const;
bool operator>(const Date& rhs) const;
bool operator<=(const Date& rhs) const;
bool operator>=(const Date& rhs) const;
bool bad() const;
int errCode() const;
std::istream& read(std::istream& istr);
std::ostream& write(std::ostream& ostr) const;
};
std::ostream& operator << (std::ostream&, const Date&);
std::istream& operator >> (std::istream&, Date&);
}
#endif