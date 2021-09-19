#pragma once
#include "Appointment.h"
#include "AttributeValues.h"
#include "Doctor.h"
#include "Interface.h"
#include "Medicine.h"
#include "Nurse.h"
#include "Patient.h"
#include "User.h"
#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
	T Data;
	DoublyLinkedList* NextElement, * PreviousElement, * Head, * Current, * Tail;
	int Length = 0;
public:
	//Constructors and Delete Functions
	DoublyLinkedList(T data) {
		Data = data;
		NextElement = NULL;
		PreviousElement = NULL;
		Head = this;
		Current = NULL;
		Tail = this;
		Length = 1;
	}
	DoublyLinkedList() {
		NextElement = NULL;
		PreviousElement = NULL;
		Head = this;
		Current = NULL;
		Tail = this;
		Length = 0;
	}
	~DoublyLinkedList() {
		//cout << "Doubly Linked List with head element " << Head->Data << " deleted." << endl;
	}

	//Adding or Inserting Data
	void AddToEnd(T data) {
		if (Length == 0) {
			Data = data;
			Length++;
			return;
		}

		Current = Tail;
		Current->NextElement = new DoublyLinkedList<T>(data);
		Current->NextElement->PreviousElement = Current;
		Current->NextElement->Current = NULL;

		//Setup New Tail
		Tail = Current->NextElement;

		//Remove New Element's Head and Tail
		Current->NextElement->Head = NULL;
		Current->NextElement->Tail = NULL;

		Length++;
	}
	void AddToStart(T data) {
		//Insert new element at end of list
		AddToEnd(data);

		//Shift all data to the right
		Current = Tail;
		while (Current->PreviousElement != NULL) {
			Current->Data = Current->PreviousElement->Data;
			Current = Current->PreviousElement;
		}
		Current->Data = data;
	}
	void Insert(int index, T data) {
		if (index > Length) {
			cout << "ERROR INSERT: Index exceeds list length" << endl;
			return;
		}

		//Insert at start of list
		if (index == 0) {
			this->AddToStart(data);
			return;
		}
		//Insert at end of list
		if (index == Length) {
			this->AddToEnd(data);
			return;
		}
		//Insert between elements in list
		Current = Head;
		while (index > 1) {
			Current = Current->NextElement;
			index--;
		} //Goes to target index, right before the inserted index
		DoublyLinkedList<T>* tempList = Current->NextElement;
		Current->NextElement = new DoublyLinkedList<T>(data);
		Current->NextElement->NextElement = tempList;
		Current->NextElement->PreviousElement = Current;
		Current->NextElement->NextElement->PreviousElement = Current->NextElement;

		Current->NextElement->Head = NULL;
		Current->NextElement->Current = NULL;
		Current->NextElement->Tail = NULL;

		Length++;
	}

	//Popping or Deleting Data
	void PopEnd() {
		if (Length == 0) {
			cout << "ERROR POP_END: List is empty" << endl;
			return;
		}
		else if (Length == 1) {
			Length--;
			return;
		}

		Current = Tail;
		Current = Current->PreviousElement;
		Tail = Current;
		Current->NextElement = NULL;
	}
	void PopStart() {
		if (Length == 0) {
			cout << "ERROR POP_START: List is empty" << endl;
			return;
		}
		else if (Length == 1) {
			Length--;
			return;
		}

		Current = Head;
		while (Current->NextElement != NULL) {
			Current->Data = Current->NextElement->Data;
			Current = Current->NextElement;
		}
		Current = Current->PreviousElement;
		Tail = Current;
		Current->NextElement = NULL;
	}
	void DeleteAtIndex(int index) {
		if (index >= Length) {
			cout << "ERROR DELETE_AT_INDEX: Index exceeds list length" << endl;
			return;
		}

		if (index == 0) {
			PopStart();
			return;
		}
		if (index == Length - 1) {
			PopEnd();
			return;
		}

		Current = Head;
		while (index > 0) {
			Current = Current->NextElement;
			index--;
		}
		DoublyLinkedList<T>* tempList = Current->NextElement;
		Current = Current->PreviousElement;
		Current->NextElement = tempList;
		Current->NextElement->PreviousElement = Current;
	}
	void DeleteNthValue(T data, int n) {
		int index = 0;
		Current = Head;

		//Searches through all elements until either the target match is found, or end is reached
		while (index < Length && n > 0) {
			//If the data matches and n == 0, the data is the delete target
			if (Current->Data == data) {
				//cout << "MATCH at index " << index << endl;
				n--;
			}
			else {
				//cout << "NO MATCH with index " << index << endl;
			}
			if (n == 0) {
				//cout << "BREAK" << endl;
				break;
			}

			Current = Current->NextElement;
			index++;
		}
		if (n == 0) {
			//Match found
			DeleteAtIndex(index);
		}
		else {
			//End reached
			cout << "No items matching " << data << " found" << endl;
		}
	}
	void DeleteValues(T data) {
		int index = 0;
		Current = Head;

		while (index < Length) {
			if (Current->Data == data) {
				DeleteAtIndex(index);
				Current = Head;
				for (int i = 0; i < index; i++) Current = Current->NextElement;
				Length--;
				continue;
			}
			Current = Current->NextElement;
			index++;
		}
	}
	void Clear() {
		Current = Head;
		Current->NextElement = NULL;
		Tail = Current;
		Length = 0;
	}

	//Replacing Data
	void ReplaceAtIndex(int index, T newData) {
		if (index > Length) {
			cout << "ERROR REPLACE_AT_INDEX: Index exceeds list length" << endl;
			return;
		}

		Current = Head;
		while (index > 0) {
			Current = Current->NextElement;
			index--;
		}
		Current->Data = newData;
	}
	void ReplaceNthValue(T replacedData, T newData, int n) {
		int index = 0;
		Current = Head;

		//Searches through all elements until either the target match is found, or end is reached
		while (index < Length && n > 0) {
			//If the data matches and n == 0, the data is the delete target
			if (Current->Data == replacedData) {
				//cout << "MATCH at index " << index << endl;
				n--;
			}
			else {
				//cout << "NO MATCH with index " << index << endl;
			}
			if (n == 0) {
				//cout << "BREAK" << endl;
				break;
			}

			Current = Current->NextElement;
			index++;
		}
		if (n == 0) {
			//Match found
			DeleteAtIndex(index);
			Insert(index, newData);
		}
		else {
			//End reached
			cout << "No items matching " << replacedData << " found" << endl;
		}
	}
	void ReplaceAllValues(T replacedData, T newData) {
		int index = 0;
		Current = Head;
		while (index < Length) {
			if (Current->Data == replacedData) {
				Current->Data = newData;
			}
			Current = Current->NextElement;
			index++;
		}
	}
	void ReplaceAll(T newData) {
		int index = 0;
		Current = Head;
		while (index < Length) {
			Current->Data = newData;
			Current = Current->NextElement;
			index++;
		}
	}

	//Search Data
	DoublyLinkedList<T>* SearchByRegex(string regExp, int searchAttributeValue) {
		DoublyLinkedList<T>* filteredList = new DoublyLinkedList<T>();
		int index = 0;
		Current = Head;
		while (index < Length) {
			//Determines the class the list contents belong to
			//In each class, determine the attribute to search based on the passed int value
			//If the value is 0, consider ALL attributes
			if (searchAttributeValue == AttributeValues::All) {
				if (typeid(T) == typeid(User)) {
					if (regex_match(Current->Data.GetID(), regex(regExp)) ||
						regex_match(Current->Data.GetName(), regex(regExp)) ||
						regex_match(to_string(Current->Data.GetAge()), regex(regExp)) ||
						regex_match(string(1, Current->Data.GetGender()), regex(regExp)) ||
						regex_match(Current->Data.GetPhone(), regex(regExp)) ||
						regex_match(Current->Data.GetEmail(), regex(regExp)) ||
						regex_match(Current->Data.GetAddress(), regex(regExp)))
						filteredList->AddToEnd(Current->Data);
				}
			}
			//If the value is not 0, determine the specific attribute to search
			else if (typeid(T) == typeid(User) || typeid(T) == typeid(Doctor) ||
				typeid(T) == typeid(Nurse) || typeid(T) == typeid(Patient)) {
				switch (searchAttributeValue) {
					case AttributeValues::All:
						break;
					case AttributeValues::User::ID:
						if (regex_match(Current->Data.GetID(), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					case AttributeValues::User::Name:
						if (regex_match(Current->Data.GetName(), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					case AttributeValues::User::Age:
						if (regex_match(to_string(Current->Data.GetAge()), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					case AttributeValues::User::Gender:
						if (regex_match(string(1, Current->Data.GetGender()), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					case AttributeValues::User::Phone:
						if (regex_match(Current->Data.GetPhone(), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					case AttributeValues::User::Email:
						if (regex_match(Current->Data.GetEmail(), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					case AttributeValues::User::Address:
						if (regex_match(Current->Data.GetAddress(), regex(regExp))) filteredList->AddToEnd(Current->Data);
						break;
					default:
						break;
				}
				//Subclasses of User class
				if (typeid(T) == typeid(Doctor)) {

				}
				else if (typeid(T) == typeid(Nurse)) {

				}
				else if (typeid(T) == typeid(Patient)) {

				}
			}
			else if (typeid(T) == typeid(Medicine)) {

			}
			else if (typeid(T) == typeid(Appointment)) {

			}
			else {
				cout << "ERROR SEARCH_BY_REGEX: No class detected" << endl;
				break;
			}
			Current = Current->NextElement;
			index++;
		}
		return filteredList;
	}

	//Sorting Data
	DoublyLinkedList<T>* Sort(int sortAttributeValue) {
		//Check if length is 0
		if (Length == 0) {
			cout << "Checkpoint ERR" << endl;
			cout << "ERROR SORT: List of length 0 cannot be sorted" << endl;
			return this;
		}

		//Using Merge Sort
		DoublyLinkedList<T>* sortedList = new DoublyLinkedList<T>();
		Current = Head;
		int index = 0;
		if (Length == 1) {
			return this;
		}
		else if (Length > 1) {
			//Split the list into two even parts (If length is odd, first half gets 1 more element)
			DoublyLinkedList<T>* ListA = new DoublyLinkedList<T>();
			DoublyLinkedList<T>* ListB = new DoublyLinkedList<T>();
			while (index < Length) {
				if (index < Length / 2) ListA->AddToEnd(Current->Data);
				else ListB->AddToEnd(Current->Data);
				Current = Current->NextElement;
				index++;
			}

			//Sort the two lists
			ListA = ListA->Sort(sortAttributeValue);
			ListB = ListB->Sort(sortAttributeValue);

			//Combine the two lists by comparing each of their sorted elements
			int indexA = 0, indexB = 0;
			int lengthA = ListA->GetLength(), lengthB = ListB->GetLength();
			while (indexA < lengthA && indexB < lengthB) {
				int compareResult = ListA->Get(indexA).CompareTo(ListB->Get(indexB), sortAttributeValue);
				if (compareResult == 0) {
					//ListA[indexA] has higher priority
					sortedList->AddToEnd(ListA->Get(indexA));
					indexA++;
				}
				else if (compareResult == 1) {
					//ListA[indexA] has the same priority as ListB[indexB], meaning they are the same value
					sortedList->AddToEnd(ListA->Get(indexA));
					sortedList->AddToEnd(ListB->Get(indexB));
					indexA++;
					indexB++;
				}
				else {
					//ListB[indexB] has higher priority
					sortedList->AddToEnd(ListB->Get(indexB));
					indexB++;
				}
			}
			//One of the lists' elements have been inserted completely
			//Add remaining elements of the other list
			while (indexA < lengthA) {
				sortedList->AddToEnd(ListA->Get(indexA));
				indexA++;
			}
			while (indexB < lengthB) {
				sortedList->AddToEnd(ListB->Get(indexB));
				indexB++;
			}
			//Delete the two-part lists to save memory space
			delete ListA;
			delete ListB;
		}
		return sortedList;
	}

	//Accessing List Elements and Length
	T Get(int index) {
		int count = 0;
		Current = Head;
		while (Current->NextElement != NULL && count != index) {
			Current = Current->NextElement;
			count++;
		}
		return Current->Data;
	}
	void PrintList() {
		cout << setw(15) << "ID" <<
			setw(20) << "Name" <<
			setw(5) << "Age" <<
			setw(5) << "M/F" <<
			setw(15) << "Phone" <<
			setw(20) << "Email" <<
			setw(30) << "Address" << endl;
		Interface::General::PrintLine('-', 90);

		int index = 0;
		Current = Head;
		while (index < Length) {
			if (typeid(Current->Data) == typeid(User)) {
				cout << setw(15) << Current->Data.GetID() <<
					setw(20) << Current->Data.GetName() <<
					setw(5) << Current->Data.GetAge() <<
					setw(5) << Current->Data.GetGender() <<
					setw(15) << Current->Data.GetPhone() <<
					setw(20) << Current->Data.GetEmail() <<
					setw(30) << Current->Data.GetAddress() << endl;
			}
			else if (typeid(Current->Data) == typeid(Doctor)) {
				/*
				* INSERT CODE HERE
				*/
			}
			/*
			* INSERT CODE FOR OTHER CLASSES HERE
			*/

			Current = Current->NextElement;
			index++;
		}
	}
	void PrintDetails() {
		cout << setw(15) << "Data" << setw(15) << "Head" << setw(15) << "Current" << setw(15) << "Tail"
			<< setw(15) << "Prev." << setw(15) << "Next" << endl;
		Interface::General::PrintLine('-', 90);

		Current = Head;
		int count = 0;
		while (count < Length) {
			cout << setw(15) << Current->Data;

			if (Current->Head == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->Head->Data; }

			if (Current->Current == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->Current->Data; }

			if (Current->Tail == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->Tail->Data; }

			if (Current->PreviousElement == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->PreviousElement->Data; }

			if (Current->NextElement == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->NextElement->Data; }

			cout << endl;
			Current = Current->NextElement;
			count++;
		}
	}
	int GetLength() {
		return Length;
	}
};