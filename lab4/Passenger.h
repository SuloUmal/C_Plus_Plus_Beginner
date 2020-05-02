    
// Workshop 4 - Constructors - Test Main
// Passenger.h
// Suleyman Umalatov
// 2019/06/11
// TODO: add file header comments here



// TODO: add header file guard here

#ifndef PASSENGER_H
#define PASSENGER_H

// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		char na[19];
		char dest[19];
		int dyear, dmonth, dday;
	public:
		Passenger(void);
    Passenger(const char *, const char *);
		Passenger(const char *, const char *, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name(void) const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif