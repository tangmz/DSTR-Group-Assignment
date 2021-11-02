#include "Header Files/Appointment.h"
#include "Header Files/Doctor.h"
#include "Header Files/LinkedList.h"
#include "Header Files/Medicine.h"
#include "Header Files/Nurse.h"
#include "Header Files/Patient.h"
#include "Header Files/User.h"
using namespace std;

class ApplicationLists {
public:
	static DoublyLinkedList<Patient>* Patients = new DoublyLinkedList<Patient>();
	static DoublyLinkedList<Doctor>* Doctors = new DoublyLinkedList<Doctor>();
	static DoublyLinkedList<Nurse>* Nurses = new DoublyLinkedList<Nurse>();
	static DoublyLinkedList<Appointment>* Appointments = new DoublyLinkedList<Appointment>();
	static DoublyLinkedList<Medicine>* Medicines = new DoublyLinkedList<Medicine>();
};