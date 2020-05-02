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

#include <iostream>
#include "Kingdom.h"
#include "Kingdom.h" // intentional

using namespace std;
using namespace sict;
void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array

	Kingdom* pKingdom = NULL; //declaring pointer for dynamic memory

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pKingdom = new Kingdom[count]; // allocating dynamic memory with pKingdom pointer

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]); // calling function for adding the data into Kingdom structure
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element
	{
		Kingdom* secondPointer = NULL;
		secondPointer = new Kingdom[count + 1]; // declaring pointer for allocating count + 1 memory

		for (int i = 0; i < count; i++) { // copying the data from the first pointer to the second
			secondPointer[i] = pKingdom[i]; 
		}
		
		delete[] pKingdom; // deallocating dynamic memory from original array
		pKingdom = NULL;

		pKingdom = secondPointer; // copying the address from the new pointer to the original
		// add the new Kingdom
		cout << "==========\n"
			 << "Input data\n"
			 << "==========\n"
			 << "Kingdom #" << count + 1 << ": " << endl;

		read(pKingdom[count]); // calling function for adding the data into Kingdom structure
		count++;
		cout << "==========\n" << endl;
	}

	// testing that the overload of "display(...)" works
	display(pKingdom, count);

	delete[] pKingdom; // deallocating dynamic memory from original array
	pKingdom = NULL;

	return 0;
}

// read accepts data for a Kingdom from standard input
void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
