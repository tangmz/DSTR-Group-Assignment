#include "Header Files/Appointment.h"
#include "Header Files/Doctor.h"
#include "Header Files/LinkedList.h"
#include "Header Files/Medicine.h"
#include "Header Files/Nurse.h"
#include "Header Files/Patient.h"
#include "Header Files/Testing.h"
#include "C++ Files/User.cpp"
#include "C++ Files/Interface.cpp"
#include "C++ Files/SampleData.cpp"
using namespace std;


static DoublyLinkedList<Patient>* patients = new DoublyLinkedList <Patient>();

int main() {
	srand(unsigned(time(NULL)));
	Doctor d = Doctor();
	int id = 0;
	for (int i = 0; i < 5; i++) {
		string idS = "P-00" + id;
		Patient p = Patient(idS, "Jeanne", "D'Arc", 500, 'F', "012-3456789", "", "address");
		patients->AddToEnd(p);
	}

	d.viewAllPatients(patients);

	//patients
	//DoublyLinkedList<User>* users = new DoublyLinkedList<User>();
	//AddUsers(users, 1000, 1, 99);
	//DoublyLinkedList<User>* sortedUsers = users->Sort(AttributeValues::User::FirstName);
	//sortedUsers->DisplayPages(30);
	return 0;
}