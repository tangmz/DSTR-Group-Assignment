#pragma once
#include "Interface.h"
#include "Linked List.h"
#include "User.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
	T Data;
	DoublyLinkedList* NextElement, * PreviousElement, * Head, * Current, * Tail;
public:
	//Constructors and Delete Functions
	DoublyLinkedList(T data) {
		Data = data;
		NextElement = NULL;
		PreviousElement = NULL;
		Head = this;
		Current = NULL;
		Tail = this;
	}
	DoublyLinkedList() : DoublyLinkedList(NULL) {

	}
	~DoublyLinkedList() {
		//cout << "Doubly Linked List with head element " << Head->Data << " deleted." << endl;
	}

	//Adding or Inserting Data
	void AddToEnd(T data) {
		Current = Tail;
		Current->NextElement = new DoublyLinkedList<T>(data);
		Current->NextElement->PreviousElement = Current;
		Current->NextElement->Current = NULL;

		//Setup New Tail
		Tail = Current->NextElement;

		//Remove New Element's Head and Tail
		Current->NextElement->Head = NULL;
		Current->NextElement->Tail = NULL;
	}
	void AddToStart(T data) {
		//Insert new element at end of list
		AddToEnd(data);
		
		//Shift all data to the right / below
		T tempData = Get(GetLength() - 1);
		Current = Tail;
		while (Current->PreviousElement != NULL) {
			Current->Data = Current->PreviousElement->Data;
			Current = Current->PreviousElement;
		}
		Current->Data = tempData;
	}
	void Insert(int index, T data) {
		if (index > this->GetLength()) {
			cout << "INVALID INSERT: Index exceeds list length" << endl;
			return;
		}

		//Insert at start of list
		if (index == 0) {
			this->AddToStart(data);
			return;
		}
		//Insert at end of list
		if (index == this->GetLength()) {
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
	}

	//Popping or Deleting Data
	void PopEnd() {
		if (GetLength() <= 1) {
			cout << "INVALID POP_END: List already at length 1" << endl;
			return;
		}

		Current = Tail;
		Current = Current->PreviousElement;
		Tail = Current;
		Current->NextElement = NULL;
	}
	void PopStart() {
		if (GetLength() <= 1) {
			cout << "INVALID POP_START: List already at length 1" << endl;
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
		if (index >= GetLength()) {
			cout << "INVALID DELETE_AT_INDEX: Index exceeds list length" << endl;
			return;
		}

		if (index == 0) {
			PopStart();
			return;
		}
		if (index == GetLength() - 1) {
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
		int len = GetLength();
		Current = Head;

		//Searches through all elements until either the target match is found, or end is reached
		while (index < len && n > 0) {
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
		int len = GetLength();
		Current = Head;

		while (index < len) {
			if (Current->Data == data) {
				DeleteAtIndex(index);
				Current = Head;
				for (int i = 0; i < index; i++) Current = Current->NextElement;
				len--;
				continue;
			}
			Current = Current->NextElement;
			index++;
		}
	}

	//Replacing Data
	void ReplaceAtIndex(int index, T newData) {
		if (index > GetLength()) {
			cout << "ERROR REPLACE_AT_INDEX: Index exceeds list length" << endl;
			return;
		}

		int currentIndex = 0;
		int len = GetLength();
		Current = Head;
		while (currentIndex < index) {
			Current = Current->NextElement;
		}
		Current->Data = newData;
	}
	void ReplaceNthValue(T replacedData, T newData, int n) {

	}
	void ReplaceAllValues(T replacedData, T newData) {

	}
	void ReplaceAll(T newData) {

	}

	//Sorting Data

	//Accessing List Element
	T Get(int index) {
		int count = 0;
		Current = Head;
		while (Current->NextElement != NULL && count != index) {
			Current = Current->NextElement;
			count++;
		}
		return Current->Data;
	}
	void PrintDetails() {
		cout << setw(10) << "Data" << setw(10) << "Head" << setw(10) << "Current" << setw(10) << "Tail"
			<< setw(10) << "Prev." << setw(10) << "Next" << endl;
		Interface::General::PrintLine('-', 60);

		int len = GetLength();
		Current = Head;
		int count = 0;
		while (count < len) {
			cout << setw(10) << Current->Data;

			if (Current->Head == NULL) { cout << setw(10) << ""; }
			else { cout << setw(10) << Current->Head->Data; }

			if (Current->Current == NULL) { cout << setw(10) << ""; }
			else { cout << setw(10) << Current->Current->Data; }

			if (Current->Tail == NULL) { cout << setw(10) << ""; }
			else { cout << setw(10) << Current->Tail->Data; }

			if (Current->PreviousElement == NULL) { cout << setw(10) << ""; }
			else { cout << setw(10) << Current->PreviousElement->Data; }

			if (Current->NextElement == NULL) { cout << setw(10) << ""; }
			else { cout << setw(10) << Current->NextElement->Data; }

			cout << endl;
			Current = Current->NextElement;
			count++;
		}
	}

	//Get List Length
	int GetLength() {
		int count = 1;
		Current = Head;
		while (Current->NextElement != NULL) {
			Current = Current->NextElement;
			count++;
		}
		return count;
	}
};