#pragma once
#include <iostream>
#include <string>
using namespace std;

class Medicine {
private:
	string MedicineID;
	string Name;
	string DatePurchased;
	double ShelfLife;
	string SideEffects;
public:
	Medicine(string medicineID, string name, string datePurchased, double shelfLife, string sideEffects) {
		MedicineID = medicineID;
		Name = name;
		DatePurchased = datePurchased;
		ShelfLife = shelfLife;
		SideEffects = sideEffects;
	}
	Medicine() {

	}

	string GetMedicineID() { return MedicineID; }
	string GetName() { return Name; }
	string GetDatePurchased() { return DatePurchased; }
	double GetShelfLife() { return ShelfLife; }
	string GetSideEffects() { return SideEffects; }

	void SetName(string name) { Name = name; }
	void SetDatePurchased(string datePurchased) { DatePurchased = datePurchased; }
	void SetShelfLife(double shelfLife) { ShelfLife = shelfLife; }
	void SetSideEffects(string sideEffects) { SideEffects = sideEffects; }

	bool Equals(Medicine nextMedicine);
	int CompareTo(Medicine nextMedicine, int attributeValue);
	bool MatchesRegex(string regExp, int attributeValue);
	void DisplayTableHeader(int startIndex, int tableLength);
	void DisplayTableRow(int startIndex, int index, int tableLength);
	void DisplayDetails();

	static string GenerateMedicineID(int n);
	string showDetails() {
		string s = MedicineID + " : " + Name + "\nDate Purchased: " + DatePurchased +
			"\nShelf Life: " + to_string(ShelfLife) + "\nSide Effects: " + SideEffects;
		return s;
	}
};