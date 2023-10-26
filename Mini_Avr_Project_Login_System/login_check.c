/*
 * login_check.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Asus
 */
#include "login_check.h"

// Initialize your database with some values
Data_t DataBase[2];

void initializeDatabase() {
	// Assign values to the first structure in the array
	strcpy(DataBase[0].person_NAME, "Ahmed Ali");
	DataBase[0].person_ID = 1234;
	DataBase[0].person_PASSWORD = 5060;
	// Assign values to the second structure in the array
	strcpy(DataBase[1].person_NAME, "Sara Omar");
	DataBase[1].person_ID = 5678;
	DataBase[1].person_PASSWORD = 1020;
}

u8 PASSWORD_check(int *pPASSWORD) {
	int i, x, y;
	x = DataBase[0].person_PASSWORD;
	y = DataBase[1].person_PASSWORD;
	for (i = 3; i >= 0; i--) {
		if (pPASSWORD[i] == x % 10) {
			return 1; // first person
			x = x / 10;

		}

	}
	for (i = 3; i >= 0; i--) {
		if (pPASSWORD[i] == y % 10) {
			return 2; // second person
			y = y / 10;
		}
	}
	return 0;  // no match found
}

u8 ID_check(int *pID) {
	int i = 0, x, y;
	x = DataBase[0].person_ID;
	y = DataBase[1].person_ID;
	for (i = 3; i >= 0; i--) {
		if (pID[i] == x % 10) {
			return 1; // first person
			x = x / 10;

		}

	}
	for (i = 3; i >= 0; i--) {
		if (pID[i] == y % 10) {
			return 2; // second person
			y = y / 10;
		}
	}
	return 0;  // no match found
}

