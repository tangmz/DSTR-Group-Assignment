//#pragma once
//#include "../Header Files/Medicine.h"
//#include "../Header Files/LinkedList.h"
//#include "../Header Files/Comparison.h"
//using namespace std;
//
//void PrintLine(char symbol, int length) {
//	for (int i = 0; i < length; i++) {
//		cout << symbol;
//	}
//	cout << endl;
//}
//
//bool Medicine::Equals(Medicine nextMedicine) {
//	bool match = true;
//	match = MedicineID == nextMedicine.MedicineID ? match : false;
//	match = Name == nextMedicine.Name ? match : false;
//	match = DatePurchased == nextMedicine.DatePurchased ? match : false;
//	match = ShelfLife == nextMedicine.ShelfLife ? match : false;
//	match = SideEffects == nextMedicine.SideEffects ? match : false;
//	return match;
//}
//int Medicine::CompareTo(Medicine nextMedicine, int attributeValue) {
//	int index = 0, value = 0;
//	switch (attributeValue) {
//		case AttributeValues::All:
//		case AttributeValues::Medicine::MedicineID:
//			return CompareStrings(this->MedicineID, nextMedicine.MedicineID);
//		case AttributeValues::Medicine::Name:
//			value = CompareStrings(this->Name, nextMedicine.Name);
//			break;
//		case AttributeValues::Medicine::DatePurchased:
//			value = CompareStrings(this->DatePurchased, nextMedicine.DatePurchased);
//			break;
//		case AttributeValues::Medicine::ShelfLife:
//			value = this->ShelfLife < nextMedicine.ShelfLife ? 0 : 2;
//			value = this->ShelfLife == nextMedicine.ShelfLife ? 1 : value;
//			break;
//		case AttributeValues::Medicine::SideEffects:
//			value = CompareStrings(this->SideEffects, nextMedicine.SideEffects);
//			break;
//		default:
//			return 1;
//	}
//	return value;
//}
//bool Medicine::MatchesRegex(string regExp, int attributeValue) {
//	switch (attributeValue) {
//		case AttributeValues::All:
//			if (regex_match(MedicineID, regex(regExp)) || regex_match(Name, regex(regExp)) ||
//				regex_match(DatePurchased, regex(regExp)) || regex_match(to_string(ShelfLife), regex(regExp)) ||
//				regex_match(SideEffects, regex(regExp))) {
//				return true;
//			}
//			break;
//		case AttributeValues::Medicine::MedicineID:
//			if (regex_match(MedicineID, regex(regExp))) return true;
//			break;
//		case AttributeValues::Medicine::Name:
//			if (regex_match(Name, regex(regExp))) return true;
//			break;
//		case AttributeValues::Medicine::DatePurchased:
//			if (regex_match(DatePurchased, regex(regExp))) return true;
//			break;
//		case AttributeValues::Medicine::ShelfLife:
//			if (regex_match(to_string(ShelfLife), regex(regExp))) return true;
//			break;
//		case AttributeValues::Medicine::SideEffects:
//			if (regex_match(SideEffects, regex(regExp))) return true;
//			break;
//		default:
//			break;
//	}
//	return false;
//}
//void Medicine::DisplayTableHeader(int startIndex, int tableLength) {
//	PrintLine('=', 110);
//	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << left << "No.";
//	cout << setw(15) << left << "Medicine ID" <<
//		setw(30) << "Name" <<
//		setw(20) << "Date Purchased" <<
//		setw(15) << "Shelf Life" <<
//		setw(30) << "Side Effects" << endl;
//	PrintLine('-', 110);
//}
//void Medicine::DisplayTableRow(int startIndex, int index, int tableLength) {
//	if (startIndex >= 0) cout << setw(to_string(startIndex + tableLength).length() + 2) << index + startIndex;
//	cout << setw(15) << MedicineID <<
//		setw(30) << Name <<
//		setw(20) << DatePurchased <<
//		setw(15) << ShelfLife <<
//		setw(30) << SideEffects << endl;
//}
//void Medicine::DisplayDetails() {
//	PrintLine('=', 100);
//
//	cout << "Medicine ID: " << MedicineID << endl << endl;
//
//	PrintLine('-', 100);
//
//	cout << "Name: " << Name << endl;
//	cout << "Date Purchased: " << DatePurchased << endl;
//	cout << "Shelf Life (Months): " << ShelfLife << endl;
//	cout << "Side Effects: " << SideEffects << endl;
//
//	PrintLine('=', 100);
//}
//
//string Medicine::GenerateMedicineID(int n) {
//	string id = "MED-";
//	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
//	id += to_string(n);
//	return id;
//}