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

#include<iostream>
#include "Kingdom.h"
using namespace std;
using namespace sict;

namespace sict {

	void display(const Kingdom& pKingdom) { // display one kingdom
		cout << pKingdom.m_name << ", " << "population " << pKingdom.m_population << endl;
	}

	void display(const Kingdom Karray[], int size) { //display every kingdom with total population of SICT
		int i;
		int total = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (i = 0; i < size; i++) {
			total += Karray[i].m_population;
		}

		for (i = size - 1; i >= 0; i--) {
			cout << i+1 << ". "; 
			display(Karray[i]);
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << total << endl;
		cout << "------------------------------" << endl;
	}

}
