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

int main() {
	srand(unsigned(time(NULL)));

	DoublyLinkedList<User>* users = new DoublyLinkedList<User>();
	AddUsers(users, 1000, 1, 100);
	users->PrintList();
	users->Sort(AttributeValues::User::Age)->SearchByRegex(".*a.*", AttributeValues::User::Email)->PrintList();
	SortUsers(users);
	return 0;
}