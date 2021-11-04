#pragma once
#include "../Header Files/Patient.h"
#include "../Header Files/Doctor.h"
#include "../Header Files/Nurse.h"
#include "../Header Files/User.h"
#include "../Header Files/Medicine.h"
#include "../Header Files/LinkedList.h"
//#include "../Header Files/ApplicationLists.h"
#include "../Header Files/Comparison.h"
using namespace std;

//DoublyLinkedList<User>* Users;
//DoublyLinkedList<Doctor>* Doctors;
//DoublyLinkedList<Medicine>* Medicines;
//DoublyLinkedList<Nurse>* Nurses;
//DoublyLinkedList<Patient>* Patients;
//
//static void LoadData(DoublyLinkedList<User>* users, DoublyLinkedList<Doctor>* doctors, DoublyLinkedList<Medicine>* medicines, 
//	DoublyLinkedList<Nurse>* nurses, DoublyLinkedList<Patient>* patients) {
//	Users = users;
//	Doctors = doctors;
//	Medicines = medicines;
//	Nurses = nurses;
//	Patients = patients;
//}

//class ApplicationLists {
//public:
//	static DoublyLinkedList<Patient>* Patients;
//	static DoublyLinkedList<Doctor>* Doctors;
//	static DoublyLinkedList<Nurse>* Nurses;
//	//static DoublyLinkedList<Appointment>* Appointments;
//	static DoublyLinkedList<Medicine>* Medicines;
//	static DoublyLinkedList<User>* Users;
//};

//DoublyLinkedList<Appointment>* ApplicationLists::Appointments = new DoublyLinkedList<Appointment>();
//DoublyLinkedList<User>* ApplicationLists::Users = new DoublyLinkedList<User>();
//DoublyLinkedList<Doctor>* ApplicationLists::Doctors = new DoublyLinkedList<Doctor>();
//DoublyLinkedList<Medicine>* ApplicationLists::Medicines = new DoublyLinkedList<Medicine>();
//DoublyLinkedList<Nurse>* ApplicationLists::Nurses = new DoublyLinkedList<Nurse>();
//DoublyLinkedList<Patient>* ApplicationLists::Patients = new DoublyLinkedList<Patient>();

//static void LoadData(DoublyLinkedList<User>* users, DoublyLinkedList<Doctor>* doctors, DoublyLinkedList<Medicine>* medicines,
//	DoublyLinkedList<Nurse>* nurses, DoublyLinkedList<Patient>* patients) {
//	ApplicationLists::Users = users;
//	ApplicationLists::Doctors = doctors;
//	ApplicationLists::Medicines = medicines;
//	ApplicationLists::Nurses = nurses;
//	ApplicationLists::Patients = patients;
//}

void PrintLine(char symbol, int length) {
	for (int i = 0; i < length; i++) {
		cout << symbol;
	}
	cout << endl;
}

//---Patient--------
bool Patient::Equals(Patient nextPatient) {
	bool match = true;
	match = FirstName == nextPatient.FirstName ? match : false;
	match = LastName == nextPatient.LastName ? match : false;
	match = Age == nextPatient.Age ? match : false;
	match = Gender == nextPatient.Gender ? match : false;
	match = Phone == nextPatient.Phone ? match : false;
	match = Email == nextPatient.Email ? match : false;
	match = Address == nextPatient.Address ? match : false;
	match = Disability == nextPatient.Disability ? match : false;
	match = Note == nextPatient.Note ? match : false;
	return match;
}
int Patient::CompareTo(Patient nextPatient, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
		case AttributeValues::All:
		case AttributeValues::User::ID:
			return CompareStrings(this->ID, nextPatient.ID);
		case AttributeValues::User::FirstName:
			value = CompareStrings(this->FirstName, nextPatient.FirstName);
			break;
		case AttributeValues::User::LastName:
			value = CompareStrings(this->LastName, nextPatient.LastName);
			break;
		case AttributeValues::User::Age:
			value = this->Age < nextPatient.Age ? 0 : 2;
			value = this->Age == nextPatient.Age ? 1 : value;
			break;
		case AttributeValues::User::Gender:
			value = CompareStrings(string(1, this->Gender), string(1, nextPatient.Gender));
			break;
		case AttributeValues::User::Phone:
			value = CompareStrings(this->Phone, nextPatient.Phone);
			break;
		case AttributeValues::User::Email:
			value = CompareStrings(this->Email, nextPatient.Email);
			break;
		case AttributeValues::User::Address:
			value = CompareStrings(this->Address, nextPatient.Address);
			break;
		case AttributeValues::Patient::Disability:
			value = CompareStrings(this->Disability, nextPatient.Disability);
			break;
		case AttributeValues::Patient::Note:
			value = CompareStrings(this->Note, nextPatient.Note);
			break;
		default:
			return 1;
	}
	return value == 1 ? CompareStrings(this->ID, nextPatient.ID) : value;
}
bool Patient::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
		case AttributeValues::All:
			if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
				regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
				regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
				regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp))) {
				return true;
			}
			break;
		case AttributeValues::User::ID:
			if (regex_match(ID, regex(regExp))) return true;
			break;
		case AttributeValues::User::FirstName:
			if (regex_match(FirstName, regex(regExp))) return true;
			break;
		case AttributeValues::User::LastName:
			if (regex_match(LastName, regex(regExp))) return true;
			break;
		case AttributeValues::User::Age:
			if (regex_match(to_string(Age), regex(regExp))) return true;
			break;
		case AttributeValues::User::Gender:
			if (regex_match(string(1, Gender), regex(regExp))) return true;
			break;
		case AttributeValues::User::Phone:
			if (regex_match(Phone, regex(regExp))) return true;
			break;
		case AttributeValues::User::Email:
			if (regex_match(Email, regex(regExp))) return true;
			break;
		case AttributeValues::User::Address:
			if (regex_match(Address, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::PatientID:
			if (regex_match(PatientID, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Disability:
			if (regex_match(Disability, regex(regExp))) return true;
			break;
		case AttributeValues::Patient::Note:
			if (regex_match(Note, regex(regExp))) return true;
			break;
		default:
			break;
	}
	return false;
}
void Patient::DisplayTableHeader(int startIndex, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(15) << left << "Patient ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" << endl;
}
void Patient::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(15) << PatientID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email << endl;
}
void Patient::DisplayDetails() {
	PrintLine('=', 100);

	cout << "User ID: " << ID << endl;
	cout << "Patient ID: " << PatientID << endl << endl;

	PrintLine('-', 100);

	cout << "Name: " << FirstName << " " << LastName << endl;
	cout << "IC: " << IC << endl;
	cout << "Age: " << Age << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Phone: " << Phone << endl;
	cout << "Email: " << Email << endl;
	cout << "Address: " << Address << endl;

	PrintLine('-', 100);

	cout << "Illness: ";
	if (Illness == "") cout << "NOT DIAGNOSED YET" << endl;
	else cout << Illness << endl;
	cout << "Visit Date and Time: ";
	if (VisitDate == "" || VisitTime == "") cout << "NO APPOINTMENT SCHEDULED" << endl;
	else cout << VisitDate << ", " << VisitTime << endl;
	cout << "Disability: ";
	if (Disability == "") cout << "UNDEFINED" << endl;
	else cout << Disability << endl;
	cout << "Assigned Doctor: ";
	if (AssignedDoctor == NULL) cout << "NO DOCTOR ASSIGNED" << endl;
	else cout << "Dr. " << AssignedDoctor->GetFirstName() << endl;
	cout << "Prescription: ";
	if (Prescription == NULL) cout << "NO PRESCRIPTION" << endl;
	else cout << Prescription->GetName() << endl;
	cout << "Notes: ";
	if (Note == "") cout << "NONE" << endl;
	else cout << Note << endl << endl;

	PrintLine('=', 100);
}

string Patient::GeneratePatientID(int n) {
	string id = "PAT-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
void Patient::UpdateAppointmentDate(DoublyLinkedList<Patient>* patientList, string newDate) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetDate(newDate);
}
void Patient::UpdateAppointmentTime(DoublyLinkedList<Patient>* patientList, string newTime) {
	//ApplicationLists::Appointments->SearchByRegex(appointmentID, AttributeValues::Appointment::AppointmentID)->Get(0)->SetTime(newTime);
}
int Patient::GetQueueNumber(DoublyLinkedList<Patient>* patientList) {
	//Get patient's visit date and find all patients visiting on the same day
	string targetDate = VisitDate;
	DoublyLinkedList<Patient>* dayPatients = new DoublyLinkedList<Patient>();
	for (int i = 0; i < patientList->GetLength(); i++) {
		if (patientList->Get(0).VisitDate == targetDate) dayPatients->AddToEnd(patientList->Get(i));
	}

	//Find the position of the patient in the day's patient list, sorted by time
	dayPatients = dayPatients->Sort(AttributeValues::Patient::VisitTime);
	for (int i = 0; i < dayPatients->GetLength(); i++) {
		if (dayPatients->Get(0).PatientID == PatientID) return i + 1;
	}
	return 0;
}
void Patient::ViewAllPatients(DoublyLinkedList<Patient>* patientList) {
	/*for (int i = 0; i < p->GetLength(); i++) {
		Patient p1 = p->Get(i);
		cout << p1.GetFirstName() << " : " << p1.GetLastName() << endl;
	}*/
	patientList->DisplayPages(10);
	system("pause");
}
DoublyLinkedList<Patient>* Patient::SearchPatient(DoublyLinkedList<Patient>* patientList, string regExp, int attributeValue) {
	return patientList->SearchByRegex(regExp, attributeValue);
}
void Patient::ModifyPatientRecord(DoublyLinkedList<Patient>* patientList) {
	//Here will return a Doubly linked list with only 1 (the selected) item inside, retains all operation of DoublyLL
	int selectedIndex = patientList->DisplayPages(10);
	if (selectedIndex == -1) return;
	Patient* selectedPatients = patientList->GetReference(selectedIndex);
	
	system("cls");
	string s;
	DoublyLinkedList<Medicine> selectedMed;
	int decision = -1;
	while (decision != 0) {
		PrintLine('-', 100);
		selectedPatients->DisplayDetails();
		//PrintLine('-', 100);
		cout << "1. Update Patient's First Name" << endl;
		cout << "2. Update Patient's Last Name" << endl;
		cout << "3. Update Patient's Age" << endl;
		cout << "4. Update Patient's Gender" << endl;
		cout << "5. Update Patient's Phone" << endl;
		cout << "6. Update Patient's Email" << endl;
		cout << "7. Update Patient's Address" << endl;
		cout << "8. Update Patient's Illness" << endl;
		cout << "9. Update Patient's Visit Date" << endl;
		cout << "10. Update Patient's Visit Time" << endl;
		cout << "11. Update Patient's Disability" << endl;
		cout << "12. Update Patient's Prescription" << endl;
		cout << "13. Update Patient's Note" << endl;
		cout << "0. Exit Modifying Patient" << endl;
		PrintLine('-', 70);
		cout << "Select Option: ";
		cin >> decision;
		cin.ignore();
		int age = -1;
		switch (decision)
		{
		case 1:
			cout << "Enter new first name: ";
			getline(cin, s);
			selectedPatients->SetFirstName(s);
			break;
		case 2:
			cout << "Enter new last name: ";
			getline(cin, s);
			selectedPatients->SetLastName(s);
			break;
		case 3:
			cout << "Enter new age: ";
			getline(cin, s);
		
			while (age < 0) {
				cout << "Enter new age: ";
				getline(cin, s);
			}
			selectedPatients->SetAge(age);
			break;
		case 4:
			cout << "Enter new gender: ";
			cin >> s;
			cin.ignore();
			selectedPatients->SetGender(s[0]);
			break;
		case 5:
			cout << "Enter new phone: ";
			getline(cin, s);
			selectedPatients->SetPhone(s);
			break;
		case 6:
			cout << "Enter new email: ";
			getline(cin, s);
			selectedPatients->SetEmail(s);
			break;
		case 7:
			cout << "Enter new Address: ";
			getline(cin, s);
			selectedPatients->SetAddress(s);
			break;
		case 8:
			cout << "Enter new illness: ";
			getline(cin, s);
			selectedPatients->SetIllness(s);
			break;
		case 9:
			cout << "Enter new visit date: ";
			getline(cin, s);
			selectedPatients->SetVisitDate(s);
			break;
		case 10:
			cout << "Enter new visit time: ";
			getline(cin, s);
			selectedPatients->SetVisitTime(s);
			break;
		case 11:
			cout << "Enter new disability: ";
			getline(cin, s);
			selectedPatients->SetDisability(s);
			break;
		case 12:
			/*selectedMed = mediList->DisplayPages(10);
			selectedPatients.Get(0).SetPrescription(&selectedMed.Get(0));*/
			break;
		case 13:
			cout << "Enter new patient note: ";
			getline(cin, s);
			selectedPatients->SetNote(s);
			break;
		default:
			break;
		}
		//cout << "Name " << selectedPatients->FirstName << endl;

	}
	
	//system("pause");
}
void Patient::SortRecords(DoublyLinkedList<Patient>* patientList, int attributeValue) {
	patientList = patientList->Sort(attributeValue);
}

//Interface
//void Patient::DisplayMainMenu() {
//	int decision = -1;
//	while (decision != 0) {
//		system("CLS");
//		PrintLine('=', 70);
//		cout << "Logged in as: Patient" << endl;
//		PrintLine('=', 70);
//		cout << "Available Option: " << endl;
//		cout << "1. Create Appointment" << endl;
//		cout << "2. Update Appointment" << endl;
//		cout << "3. Cancel Appointment" << endl;
//		cout << "4. Get Queue Number" << endl;
//		cout << "0. Logout" << endl;
//
//
//		PrintLine('-', 70);
//		cout << "Select Option: ";
//		cin >> decision;
//
//		switch (decision)
//		{
//		case 1:
//			//Create appointment
//			break;
//		case 2:
//			//Update appointment
//			//Let user choose to update date, time, doctor (no need payment as unreasonable to let patient set payment for themselves)
//			break;
//		case 3:
//			//Cancel appointment
//			break;
//		case 4:
//			//Get queue number
//			break;
//		case 0:
//			//exit and go back to login page
//
//		default:
//			break;
//		}
//	}
//}
//void Patient::DisplaySortPatients() {
//
//}
//void Patient::DisplaySearchPatients() {
//
//}

//---Doctor--------
//Interface
//void Doctor::DisplayMainMenu() {
//	int decision = -1;
//	while (decision != 0) {
//		system("CLS");
//		PrintLine('=', 70);
//		cout << "Logged in as: Doctor" << endl;
//		PrintLine('=', 70);
//		cout << "Available Option: " << endl;
//		cout << "1. View All Patients" << endl;
//		cout << "2. Search Patient by Name" << endl;
//		cout << "3. Search Patient by Illness" << endl;
//		cout << "4. Modify Patient's Record" << endl;
//		cout << "5. View Patient Based On Visiting Order" << endl;
//		cout << "6. Notify Nurse" << endl;
//		cout << "7. View Sorted List of Patient" << endl;
//		cout << "0. Logout" << endl;
//		PrintLine('-', 70);
//		cout << "Select Option: ";
//		cin >> decision;
//		cin.ignore();
//
//		switch (decision)
//		{
//		case 1:
//			//View all patient
//			Patient::ViewAllPatients(ApplicationLists::Patients);
//			break;
//		case 2:
//			//Search by name
//			break;
//		case 3:
//			//Search by illness
//			break;
//		case 4:
//			//Modify patient record
//			//Let user choose which patient first
//			break;
//		case 5:
//			//View by visiting order
//			break;
//		case 6:
//			//Notify nurse
//			break;
//		case 7:
//			//View sorted list
//			//Let user choose sort by what
//			break;
//		case 0:
//			//exit and go back to login page
//		default:
//			break;
//		}
//	}
//}


//---Nurse--------
//Interface
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


//---User--------
bool User::Equals(User nextUser) {
	bool match = true;
	match = FirstName == nextUser.FirstName ? match : false;
	match = LastName == nextUser.LastName ? match : false;
	match = Age == nextUser.Age ? match : false;
	match = Gender == nextUser.Gender ? match : false;
	match = Phone == nextUser.Phone ? match : false;
	match = Email == nextUser.Email ? match : false;
	match = Address == nextUser.Address ? match : false;
	match = IC == nextUser.IC ? match : false;
	return match;
}
int User::CompareTo(User nextUser, int attributeValue) {
	int index = 0, value = 0;
	switch (attributeValue) {
	case AttributeValues::All:
	case AttributeValues::User::ID:
		return CompareStrings(this->ID, nextUser.ID);
	case AttributeValues::User::FirstName:
		value = CompareStrings(this->FirstName, nextUser.FirstName);
		break;
	case AttributeValues::User::LastName:
		value = CompareStrings(this->LastName, nextUser.LastName);
		break;
	case AttributeValues::User::Age:
		value = this->Age < nextUser.Age ? 0 : 2;
		value = this->Age == nextUser.Age ? 1 : value;
		break;
	case AttributeValues::User::Gender:
		value = CompareStrings(string(1, this->Gender), string(1, nextUser.Gender));
		break;
	case AttributeValues::User::Phone:
		value = CompareStrings(this->Phone, nextUser.Phone);
		break;
	case AttributeValues::User::Email:
		value = CompareStrings(this->Email, nextUser.Email);
		break;
	case AttributeValues::User::Address:
		value = CompareStrings(this->Address, nextUser.Address);
		break;
	case AttributeValues::User::IC:
		value = CompareStrings(this->IC, nextUser.IC);
		break;
	default:
		return 1;
	}
	return value;
	//return value == 1 ? CompareStrings(this->ID, nextUser.ID) : value;
}
bool User::MatchesRegex(string regExp, int attributeValue) {
	switch (attributeValue) {
	case AttributeValues::All:
		if (regex_match(ID, regex(regExp)) || regex_match(FirstName, regex(regExp)) ||
			regex_match(LastName, regex(regExp)) || regex_match(to_string(Age), regex(regExp)) ||
			regex_match(string(1, Gender), regex(regExp)) || regex_match(Phone, regex(regExp)) ||
			regex_match(Email, regex(regExp)) || regex_match(Address, regex(regExp)) || regex_match(IC, regex(regExp))) {
			return true;
		}
		break;
	case AttributeValues::User::ID:
		if (regex_match(ID, regex(regExp))) return true;
		break;
	case AttributeValues::User::FirstName:
		if (regex_match(FirstName, regex(regExp))) return true;
		break;
	case AttributeValues::User::LastName:
		if (regex_match(LastName, regex(regExp))) return true;
		break;
	case AttributeValues::User::Age:
		if (regex_match(to_string(Age), regex(regExp))) return true;
		break;
	case AttributeValues::User::Gender:
		if (regex_match(string(1, Gender), regex(regExp))) return true;
		break;
	case AttributeValues::User::Phone:
		if (regex_match(Phone, regex(regExp))) return true;
		break;
	case AttributeValues::User::Email:
		if (regex_match(Email, regex(regExp))) return true;
		break;
	case AttributeValues::User::Address:
		if (regex_match(Address, regex(regExp))) return true;
		break;
	case AttributeValues::User::IC:
		if (regex_match(IC, regex(regExp))) return true;
		break;
	default:
		break;
	}
	return false;
}

string User::GenerateID(int n) {
	string id = "USR-";
	for (int i = 0; i < 6 - ceil(log10(n + 1)); i++) id += "0";
	id += to_string(n);
	return id;
}
//void User::Login() {
//	string loginResult = "";
//	do {
//		//Cannot switch string in c++, unless using enum
//		loginResult = User::DisplayLoginPage();
//		if (loginResult == "Doctor") {
//			Doctor::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Nurse") {
//			Nurse::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Patient") {
//			Patient::DisplayMainMenu();
//			break;
//		}
//		else if (loginResult == "Register") {
//			loginResult = ::User::DisplayRegisterPage();
//			break;
//		}
//		else if (loginResult == "Exit") {
//			User::DisplayExitPage();
//			break;
//		}
//	} while (loginResult != "Exit");
//}
//void User::Register() {
//	string registerResult = User::DisplayRegisterPage();
//	if (registerResult == "Doctor") {
//		Doctor::DisplayMainMenu();
//	}
//	else if (registerResult == "Nurse") {
//		Nurse::DisplayMainMenu();
//	}
//	else if (registerResult == "Patient") {
//		Patient::DisplayMainMenu();
//	}
//	else if (registerResult == "Login") {
//		User::Login();
//	}
//	else if (registerResult == "Exit") {
//		User::DisplayExitPage();
//	}
//}
//void User::Logout() {
//	User::Login();
//}
void User::ShowDetails() {
	cout << "User: " << ID << "; Name: " << FirstName << " " << LastName << endl;
}
void User::DisplayTableHeader(int startIndex, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << left << "No.";
	cout << setw(15) << left << "ID" <<
		setw(20) << "First Name" <<
		setw(20) << "Last Name" <<
		setw(5) << "Age" <<
		setw(5) << "M/F" <<
		setw(15) << "Phone" <<
		setw(20) << "Email" <<
		setw(30) << "Address" << endl;
}
void User::DisplayTableRow(int startIndex, int index, int tableLength) {
	if (startIndex >= 0) cout << setw(to_string(tableLength).length() + 2) << index + startIndex;
	cout << setw(15) << ID <<
		setw(20) << FirstName <<
		setw(20) << LastName <<
		setw(5) << Age <<
		setw(5) << Gender <<
		setw(15) << Phone <<
		setw(20) << Email <<
		setw(30) << Address << endl;
}

////Interface
//
//void User::DisplayStartupPage() {
//	PrintLine('=', 100);
//	cout << "||" << setw(96) << left << "PATIENT QUEUE MANAGEMENT SYSTEM" << "||" << endl;
//	PrintLine('=', 100);
//}
//string User::DisplayLoginPage() {
//	//returns the login role as a string upon successful login, else return "Invalid"
//	/*Usage
//	* while((role = DisplayLoginPage()) == "Invalid"); //Perma loop login function
//	* simultaneously discover the role the user logged in as
//	* Once login successfully, while loop will break
//	*/
//
//	string user, pass = "";
//	system("CLS");
//	cout << "Hello, Welcome to Klinik Sulaiman Patient Management System." << endl << endl;
//	cout << "Keyword: \"Reg\" to register, \"Exit\" to exit" << endl;
//	cout << "Please enter your username: ";
//
//	cin >> user;
//	cin.ignore();
//	if (user == "Reg") return "Register";
//	if (user == "Exit") return "Exit";
//	if (user == "Doktah") {									//Hard coded Doctor's username
//		while (pass != "42069" || "0") {					//Hard coded pass: 42069, and 0 to return to login page again
//			cout << "Please enter password (or type 0 to return): ";
//			cin >> pass;
//			if (pass == "0") { return "Invalid"; }			//Will recur this function again from first login page (in main function)
//			if (pass == "42069") { return "Doctor"; }		//Login successful, return login role
//			system("CLS");
//			cout << "Wrong password, please try again." << endl << flush;
//		}
//	}
//	else if (user == "Nurse") {	//Same code as "Doctor" above
//		while (pass != "Nurse" || "0") {
//			cout << "Please enter password (or type 0 to return): ";
//			cin >> pass;
//			if (pass == "0") { return "Invalid"; }
//			if (pass == "Nurse") { return "Nurse"; }
//			system("CLS");
//			cout << "Wrong password, please try again." << endl << flush;
//		}
//	}
//	else { //patient
//		/*
//		* while loop to check if username exist
//		* if exist loop until password is correct, or 0 to cancel
//		* if does not exist, finish first while loop, go below to show username not found
//		*/
//		cout << endl << "Username not found.." << endl << "Returning to Login page." << endl;
//		system("PAUSE");
//		return "Invalid";
//	}
//	return "Invalid";
//}
////Login for Patient is unfinished----------------------------------------------------------------------------------------
//string User::DisplayRegisterPage() {
//	return "";
//}
//void User::DisplayExitPage() {
//	cout << "EXITED THE PROGRAM" << endl;
//}
