#include "Header Files/Doctor.h"
#include "Header Files/LinkedList.h"



void Doctor::viewAllPatients(DoublyLinkedList<Patient> *p) {
	for (int i = 0; i < p->GetLength(); i++) {
		Patient p1 = p->Get(i);
		cout << p1.GetFirstName() << " : " << p1.GetLastName() << endl;
	}
}
void Doctor::searchPatientsbyName(Patient target) {

}
void Doctor::searchPatientsbyIllness(string illness) {

}
void Doctor::modifyPatientRecord(Patient newPatient) {

}
void Doctor::sortPatientsbyVisit() {

}
