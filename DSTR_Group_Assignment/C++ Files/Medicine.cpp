#pragma once
#include "../Header Files/Medicine.h"
#include "../Header Files/LinkedList.h"
#include "../Header Files/Comparison.h"
using namespace std;

bool Medicine::Equals(Medicine nextMedicine) {
	bool match = true;
	match = MedicineID == nextMedicine.MedicineID ? match : false;
	match = Name == nextMedicine.Name ? match : false;
	match = DatePurchased == nextMedicine.DatePurchased ? match : false;
	match = ShelfLife == nextMedicine.ShelfLife ? match : false;
	match = SideEffects == nextMedicine.SideEffects ? match : false;
	return match;
}
int Medicine::CompareTo(Medicine nextMedicine, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::Medicine::MedicineID:
			return CompareStrings(this->MedicineID, nextMedicine.MedicineID);
		case AttributeValues::Medicine::Name:
			value = CompareStrings(this->Name, nextMedicine.Name);
			break;
		case AttributeValues::Medicine::DatePurchased:
			value = CompareStrings(this->DatePurchased, nextMedicine.DatePurchased);
			break;
		case AttributeValues::Medicine::ShelfLife:
			value = this->ShelfLife < nextMedicine.ShelfLife ? 0 : 2;
			value = this->ShelfLife == nextMedicine.ShelfLife ? 1 : value;
			break;
		case AttributeValues::Medicine::SideEffects:
			value = CompareStrings(this->SideEffects, nextMedicine.SideEffects);
			break;
		default:
			return 1;
	}
	return value;
}
bool Medicine::MatchesRegex(string regExp, int attributeValue) {

}
void Medicine::DisplayTableHeader(int startIndex, int tableLength) {

}
void Medicine::DisplayTableRow(int startIndex, int index, int tableLength) {

}
void Medicine::DisplayDetails() {

}

string Medicine::GenerateMedicineID(int n) {

}