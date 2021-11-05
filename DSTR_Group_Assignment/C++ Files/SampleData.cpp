#include "../Header Files/LinkedList.h"
#include "../Header Files/SampleData.h"
#include <cstdlib>
#include <direct.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

DoublyLinkedList<string>* LoadNames() {
	DoublyLinkedList<string>* names = new DoublyLinkedList<string>();
	string line;
	ifstream inputFile = ifstream("Names.txt");

	while (getline(inputFile, line)) {
		names->AddToEnd(line);
	}
	return names;
}
string GetRandomName(DoublyLinkedList<string>* nameList) {
	return nameList->Get(rand() % nameList->GetLength());
}
string GetRandomPhone() {
	string sampleNumbers = "0123456789";
	string phone = "";

	for (int i = 0; i < 10; i++) {
		phone += sampleNumbers[rand() % sampleNumbers.length()];
	}
	return phone;
}
char GetRandomGender() {
	string sampleChar = "MF";
	return sampleChar[rand() % sampleChar.length()];
}
string GetRandomDayOfMonth(int max) {
	string day = to_string(rand() % max + 1);
	if (day.length() == 1) day = "0" + day;
	return day;
}
string GetRandomVisitDate() {
	int month = rand() % 12 + 1;
	string day;
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = GetRandomDayOfMonth(31);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = GetRandomDayOfMonth(30);
		break;
	default:
		day = GetRandomDayOfMonth(28);
		break;
	}
	string monthS = to_string(month);
	if (monthS.length() == 1) monthS = "0" + monthS;
	return monthS + " " + day;

}

string GetRandomTime() {
	string hr = to_string(rand() % 24);
	if (hr.length() == 1) hr = "0" + hr;
	string min = to_string(rand() % 60);
	if (min.length() == 1) min = "0" + min;

	return hr + " " + min;
}

string GetRandomIllness() {
	string illness[] = { "Flu", "Hair Loss", "Injury", "Covid", "AIDS", "Psychosis", "Intoxication" };
	return illness[rand() % illness->size()];
}

