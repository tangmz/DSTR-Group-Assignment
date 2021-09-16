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
	string GetMedicineID() { return MedicineID; }
	string GetName() { return Name; }
	string GetDatePurchased() { return DatePurchased; }
	double GetShelfLife() { return ShelfLife; }
	string GetSideEffects() { return SideEffects; }

	string showDetails() {
		string s = MedicineID + " : " + Name + "\nDate Purchased: " + DatePurchased +
			"\nShelf Life: " + to_string(ShelfLife) + "\nSide Effects: " + SideEffects;
		return s;
	}
};