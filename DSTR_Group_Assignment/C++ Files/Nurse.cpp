//#include "../Header Files/Nurse.h"
//#include "../Header Files/LinkedList.h"
//using namespace std;
//
//
//
//void Nurse::sortRecord() {
//
//}
//
//
////Interface
//void PrintLine(char symbol, int length) {
//	for (int i = 0; i < length; i++) {
//		cout << symbol;
//	}
//	cout << endl;
//}
//
//void Nurse::DisplayMainMenu() {
//	int decision = -1;
//	while (decision != 0) {
//		system("CLS");
//		PrintLine('=', 70);
//		cout << "Logged in as: Nurse" << endl;
//		PrintLine('=', 70);
//		cout << "Available Option: " << endl;
//		cout << "1. Add New Patient to List" << endl;
//		cout << "2. View All Patients" << endl;
//		cout << "3. Search Patient" << endl;
//		cout << "4. View Sorted List of Patient" << endl;
//		cout << "5. Change Patient's Priority" << endl;
//		cout << "6. Notify Next Patient" << endl;
//		cout << "7. Collect Payment" << endl;
//		cout << "0. Logout" << endl;
//
//		PrintLine('-', 70);
//		cout << "Select Option: ";
//		cin >> decision;
//
//		switch (decision)
//		{
//		case 1:
//			//Add patient
//			break;
//		case 2:
//			//View all patient
//			break;
//		case 3:
//			//Search patient
//			break;
//		case 4:
//			//View sorted list (need to create another list for sorted data?)
//			//Let user choose sort by what
//			break;
//		case 5:
//			//Change priority
//			break;
//		case 6:
//			//Notify patient
//			break;
//		case 7:
//			//Collect payment
//			break;
//		case 0:
//			//exit and go back to login page
//
//		default:
//			break;
//		}
//	}
//}