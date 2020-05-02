    
// Workshop 4 - Constructors - Test Main
// Passenger.cpp
// Suleyman Umalatov
// 2019/06/11

#include <iostream> 
#include<cstring> 
#include "Passenger.h" 
#include "Passenger.h"
using namespace std;


namespace sict{
	
Passenger::Passenger() {
		na[0] = '\0';
		dest[0] = '\0';
		dday = 0;
		dmonth = 0;
		dyear = 0;
	}
  Passenger::Passenger(const char* pna, const char* pdest)
    {
        if( pna != NULL && pdest != NULL)
        {
          strncpy(na, pna, 18);
			strncpy(dest, pdest, 18);
            dyear = 2019;
            dmonth = 10;
            dday = 1;
        } else {
          *this = Passenger();
        }
    }

	Passenger::Passenger(const char* pna, const char* pdest, int year, int month, int day)
	{
		if (pna == NULL || pdest == NULL || day > 31 || day < 1 || month > 12 || month < 1 || year < 2019 || year > 2021) {
			*this = Passenger();
		}
		else {
			strncpy(na, pna, 18);
			strncpy(dest, pdest, 18);
			dyear = year;
			dmonth = month;
			dday = day;
		}
	}

	bool Passenger::isEmpty() const {
		if (na[0] == '\0' || dest[0] == '\0'  || dyear == 0 || dday == 0 || dmonth == 0) {
			return true;
		}
		else {
			return false;
		}
	}	

	void Passenger::display(void) const
  
	{ int code = 0;
		if (na[0] == '\0' || *dest == '\0' || dyear == 0 || dmonth == 0 || dday == 0)
		{
			cout << "No passenger!" << endl;
		}
		else{
      if (dday < 10 )  code = 1;  if (dmonth < 10 ) code = 2;
      if (dmonth < 10 && dday < 10)  code = 3;
      if (code == 1){
      cout << na << " - " << dest << " on " << dyear << "/" << dmonth << "/0" << dday << endl;}
      if (code == 2){
      cout << na << " - " << dest << " on " << dyear << "/0" << dmonth << "/" << dday << endl;}
       if (code == 3){
      cout << na << " - " << dest << " on " << dyear << "/0" << dmonth << "/0" << dday << endl;}
       if (code == 0){
      cout << na << " - " << dest << " on " << dyear << "/" << dmonth << "/" << dday << endl;}
      code = 0;
		}
	}
	const char * Passenger::name(void) const
	{
		return na;
	}

	bool Passenger::canTravelWith(const Passenger& pass) const
	{
		bool day = this->dday == pass.dday;
		bool month = this->dmonth == pass.dmonth;
		bool year = this->dyear == pass.dyear;

		bool same = day && month && year;

		return same;
	}

}
