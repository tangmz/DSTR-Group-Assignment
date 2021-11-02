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
