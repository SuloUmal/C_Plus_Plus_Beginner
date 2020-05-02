/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 2.0
// Date 28 May 2019
// Author Suleyman Umalatov
// Description
// Learning Dynamic Memory
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name: Suleyman Umalatov    Date: 28 May 2019    Reason Learning Dynamic Memory
//
///////////////////////////////////////////////////////////
***********************************************************/
#ifndef _SICT_KINGDOM_H_
#define _SICT_KINGDOM_H_


namespace sict {

	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom& point); // display one kingdom

	void display(const Kingdom Karray[], int size); //display every kingdom with total population of SICT
}
#endif

