#include "Header Files/Interface.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Interface::General::PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

void Interface::User::DisplayStartupPage() {
	Interface::General::PrintLine('=', 100);
	cout << "||" << setw(96) << left << "PATIENT QUEUE MANAGEMENT SYSTEM" << "||" << endl;
	Interface::General::PrintLine('=', 100);

}