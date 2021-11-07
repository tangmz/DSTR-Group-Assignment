#pragma once
#include "AttributeValues.h"
//#include "Interface.h"
#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
using namespace std;

template <typename T>
class DoublyLinkedList {
	class Node {
	public:
		T Data;
		Node* NextElement, * PreviousElement;

		Node(T data) {
			Data = data;
			NextElement = NULL;
			PreviousElement = NULL;
		}
	};

private:
	Node* Head, * Current, * Tail;
	int Length = 0;

	void PrintLine(char symbol, int length ) {
		for (int i = 0; i < length; i++) {
			cout << symbol;
		}
		cout << endl;
	}
public:
	/*
	* CONSTRUCTORS AND DELETION FUNCTIONS
	*/
	DoublyLinkedList(T data) {
		Head = new Node<T>(data);
		Tail = Head;
		Length = 1;
	}
	DoublyLinkedList() {
		Head = NULL;
		Tail = NULL;
		Length = 0;
	}
	~DoublyLinkedList() {
		//cout << "Doubly Linked List with head element " << Head->Data << " deleted." << endl;
	}

	/*
	* ADD AND INSERT FUNCTIONS
	*/
	/*DoublyLinkedList<Patient>* combineList(DoublyLinkedList<T>* second) {
		DoublyLinkedList<Patient>* combined = new DoublyLinkedList;
		for (int i = 0; i < this->GetLength(); i++) {
			combined->AddToEnd(this->Get(i));
		}
		for (int i = 0; i < second->GetLength(); i++) {
			combined->AddToEnd(second->Get(i));
		}
		return combined;
	}*/

	void AddToEnd(T data) {
		//If the list is empty, add its first node data
		if (Length == 0) {
			Head = new Node(data);
			Tail = Head;
			Length++;
			return;
		}

		//If the list has at least 1 element, go to the tail node and add the data as the next element
		Current = Tail;
		Current->NextElement = new Node(data);
		Current->NextElement->PreviousElement = Current;

		//Setup the new tail value
		Tail = Current->NextElement;

		Length++;
	}
	void AddToStart(T data) {
		if (Length == 0) {
			Head = new Node(data);
			Tail = Head;
			Length++;
			return;
		}
		Current = new Node(data);
		Current->NextElement = Head;
		Current->NextElement->PreviousElement = Current;
		Head = Current;
		Length++;

		/*
		//Insert new element at end of list
		AddToEnd(data);

		//Shift all data to the right, with the new data moved to the front
		Current = Tail;
		while (Current->PreviousElement != NULL) {
			Current->Data = Current->PreviousElement->Data;
			Current = Current->PreviousElement;
		}
		Current->Data = data;
		*/
	}
	void Insert(int index, T data) {
		//If requested index is longer than the list length, return an error
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
		//Go to the target index, right before the inserted index
		Current = Head;
		while (index > 1) {
			Current = Current->NextElement;
			index--;
		}

		//Add the new node
		Node* tempList = Current->NextElement;
		Current->NextElement = new Node(data);
		Current->NextElement->NextElement = tempList;
		Current->NextElement->PreviousElement = Current;
		Current->NextElement->NextElement->PreviousElement = Current->NextElement;

		Length++;
	}

	/*
	* POP AND DELETE FUNCTIONS
	*/
	void PopEnd() {
		//If list is empty, return an error
		if (Length == 0) {
			cout << "ERROR POP_END: List is empty" << endl;
			return;
		}
		//If list only has one node, update the list length to 0 and remove the node pointers
		else if (Length == 1) {
			Clear();
			return;
		}

		//Go to the second last node and remove its next element
		Current = Tail->PreviousElement;
		Current->NextElement = NULL;
		delete Tail;
		Tail = Current;
		Length--;
	}
	void PopStart() {
		//If list is empty, return an error
		if (Length == 0) {
			cout << "ERROR POP_START: List is empty" << endl;
			return;
		}
		//If list only has one node, update the list length to 0 and remove the node pointers
		else if (Length == 1) {
			Clear();
			return;
		}

		Current = Head->NextElement;
		Current->PreviousElement = NULL;
		Head = Current;

		/*
		//Shift all node data to the left, and remove the rightmost node
		Current = Head;
		while (Current->NextElement != NULL) {
			Current->Data = Current->NextElement->Data;
			Current = Current->NextElement;
		}
		Current = Current->PreviousElement;
		Tail = Current;
		Current->NextElement = NULL;
		*/
		Length--;
	}
	void DeleteAtIndex(int index) {
		//If index exceeds the list length, return an error
		if (index >= Length) {
			cout << "ERROR DELETE_AT_INDEX: Index exceeds list length" << endl;
			return;
		}

		//If index is at the list start or end, call the respective Pop functions
		if (index == 0) {
			PopStart();
			return;
		}
		if (index == Length - 1) {
			PopEnd();
			return;
		}

		//Start from head and go to the deletion index
		Current = Head;
		while (index > 0) {
			Current = Current->NextElement;
			index--;
		}

		//Remove the selected node
		Node* tempList = Current->NextElement;
		Current = Current->PreviousElement;
		Current->NextElement = tempList;
		Current->NextElement->PreviousElement = Current;
		Length--;
	}
	void DeleteNthValue(T data, int n) {
		int index = 0;
		Current = Head;

		//Searches through all elements until either the Nth target match is found, or the end is reached
		while (index < Length && n > 0) {
			//If the data matches and n == 0, the data is the delete target
			if (Current->Data == data) n--;
			if (n == 0) break;

			Current = Current->NextElement;
			index++;
		}

		//Determine if the target data is found or the list end is reached
		if (n == 0) DeleteAtIndex(index);
		else cout << "No items matching " << data << " found" << endl;
	}
	void DeleteValues(T data) {
		int index = 0;
		Current = Head;

		//Loop through the entire list and delete all nodes that have the same data values as the inputted data
		while (index < Length) {
			if (Current->Data == data) {
				DeleteAtIndex(index);

				//Reset the Current node as it may have been changed in the DeleteAtIndex function
				Current = Head;
				for (int i = 0; i < index; i++) Current = Current->NextElement;

				continue;
			}
			Current = Current->NextElement;
			index++;
		}
	}
	void Clear() {
		while (Head != NULL) {
			Current = Head;
			Head = Head->NextElement;
			delete Current;
		}
		Head = NULL;
		Tail = NULL;
		Length = 0;
	}

	/*
	* REPLACE FUNCTIONS
	*/
	void ReplaceAtIndex(int index, T newData) {
		//If list length is 0, return an error
		if (index > Length) {
			cout << "ERROR REPLACE_AT_INDEX: Index exceeds list length" << endl;
			return;
		}

		//Go to the selected index and replace the data value
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

		//Searches through all elements until either the Nth target match is found, or end is reached
		while (index < Length && n > 0) {
			//If the data matches and n == 0, the data is the delete target
			if (Current->Data == replacedData) n--;
			if (n == 0) break;

			Current = Current->NextElement;
			index++;
		}
		//Match found - Delete the matching data and insert the new replacement data at the same index
		if (n == 0) {
			DeleteAtIndex(index);
			Insert(index, newData);
		}
		//End reached
		else {
			cout << "No items matching " << replacedData << " found" << endl;
			system("pause");
		}
	}
	void ReplaceAllValues(T replacedData, T newData) {
		int index = 0;
		Current = Head;

		//Loop through the list and replace all matching node data with the new data
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

		//Loop through the list and replace ALL node data with the new data
		while (index < Length) {
			Current->Data = newData;
			Current = Current->NextElement;
			index++;
		}
	}

	/*
	* SEARCH FUNCTIONS
	*/
	DoublyLinkedList<T>* SearchByRegex(string regExp, int searchAttributeValue) {
		//Create a new DoublyLinkedList to store the filtered list
		DoublyLinkedList<T>* filteredList = new DoublyLinkedList<T>();
		int index = 0;
		Current = Head;

		try {
			while (index < Length) {
				if (Current->Data.MatchesRegex(regExp, searchAttributeValue)) {
					filteredList->AddToEnd(Current->Data);
				}
				Current = Current->NextElement;
				index++;
			}
		}
		catch (int errorNum) {
			cout << "ERROR SEARCH_BY_REGEX: Error Number = " << errorNum << endl;
		}
		return filteredList;
	}

	/*
	* SORT FUNCTIONS
	*/
	DoublyLinkedList<T>* Sort(int sortAttributeValue) {
		//If list length is 0, return an error
		if (Length == 0) {
			cout << "Checkpoint ERR" << endl;
			cout << "ERROR SORT: List of length 0 cannot be sorted" << endl;
			return this;
		}

		//Use Merge Sort
		DoublyLinkedList<T>* sortedList = new DoublyLinkedList<T>();
		Current = Head;
		int index = 0;
		//If the list length is 1, it is already sorted, so return it
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

			//Sort the two lists through recursive sorting
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
					//sortedList->AddToEnd(ListB->Get(indexB));
					indexA++;
					//indexB++;
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

	//Similar done by MZ
	//DoublyLinkedList<T>* Combine(DoublyLinkedList<T>* list2) {
	//	DoublyLinkedList<T>* combinedList = new DoublyLinkedList<T>();
	//	for (int i = 0; i < Length; i++) {
	//		combinedList->AddToEnd(this->Get(i));
	//	}
	//	for (int i = 0; i < list2->GetLength(); i++) {
	//		combinedList->AddToEnd(list2->Get(i));
	//	}
	//	return combinedList;
	//}

	/*
	* GET, PRINT, LENGTH FUNCTIONS
	*/
	T Get(int index) {
		if (index >= Length) {
			cout << "ERROR GET: Index " << index << " exceeds list length of " << Length << endl;
			return T();
		}

		Current = Head;
		while (index > 0) {
			Current = Current->NextElement;
			index--;
		}
		return Current->Data;
	}
	T* GetReference(int index) {
		if (index >= Length) {
			cout << "ERROR GET: Index " << index << " exceeds list length of " << Length << endl;
			return NULL;
		}

		Current = Head;
		while (index > 0) {
			Current = Current->NextElement;
			index--;
		}
		return &(Current->Data);
	}
	void PrintList(int startIndex = -1) {
		cout << "List Length: " << Length << endl;
		Current->Data.DisplayTableHeader(startIndex, Length);

		int index = 0;
		Current = Head;
		while (index < Length) {
			Current->Data.DisplayTableRow(startIndex, index, Length);
			Current = Current->NextElement;
			index++;
		}
		cout << endl;
	}
	void PrintDetails() {
		cout << setw(15) << "Data" << setw(15) << "Head" << setw(15) << "Current" << setw(15) << "Tail"
			<< setw(15) << "Prev." << setw(15) << "Next" << setw(10) << "Length" << endl;
		PrintLine('-', 100);

		Current = Head;
		int count = 0;
		while (count < Length) {
			cout << setw(15) << Current->Data;

			if (Head == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Head->Data; }

			if (Current == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->Data; }

			if (Tail == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Tail->Data; }

			if (Current->PreviousElement == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->PreviousElement->Data; }

			if (Current->NextElement == NULL) { cout << setw(15) << "-"; }
			else { cout << setw(15) << Current->NextElement->Data; }

			cout << setw(10) << Length;
			cout << endl;
			Current = Current->NextElement;
			count++;
		}
	}
	int DisplayPages(int pageLength) {
		int i = 0, length = this->GetLength();
		while (true) {
			system("cls");
			cout << "Displaying list elements [" << i + 1 << "/" << length << "] to ["
				<< i + pageLength - (i + pageLength > length ? i + pageLength - length : 0) << "/" << length << "]" << endl;
			this->GetPage(i, pageLength)->PrintList(i + 1);

			string answer;
			bool exit = false;
			cout << "Enter a navigation option [\">\" = Next Page; \"<\" = Previous Page; \"X\" = Exit]\n> ";
			getline(cin, answer);
			try { //Integer answer for selected a specific element
				int selectedIndex = stoi(answer);
				//Example: i = 0, pageLength = 10 >> Range = 1 ~ 10
				if (selectedIndex < i + 1 || selectedIndex > i + pageLength - (i + pageLength > length ? i + pageLength - length : 0)) {
					throw - 1;
				}
				/*DoublyLinkedList<T> selectedList = DoublyLinkedList<T>();
				selectedList.AddToEnd(this->Get(selectedIndex - 1));*/
				return selectedIndex -1;
			}
			catch (...) { //Error = char input for navigation
				char ans = answer[0];
				switch (toupper(ans)) {
					case '>':
						if (i + pageLength > length - 1) i = 0;
						else i += pageLength;
						continue;
					case '<':
						if (i - pageLength < 0) {
							if (length % pageLength == 0) i = length - pageLength;
							else i = length - (length % pageLength);
						}
						else i -= pageLength;
						continue;
					case 'X':
						exit = true;
						break;
					default:
						cout << "ERROR DISPLAY_PAGES: Invalid input. Exiting..." << endl;
						system("pause");
						exit = true;
						break;
				}
				if (exit) break;
			}
		}
		system("cls");
		return -1;
	}
	DoublyLinkedList<T> DisplayDetails() {
		int i = 0, length = this->GetLength();
		while (true) {
			system("cls");
			cout << "Displaying list element [" << i + 1 << "/" << length << "]" << endl;
			this->Get(i).DisplayDetails();

			char answer;
			bool exit = false;
			cout << "Enter a navigation option [\">\" = Next Page; \"<\" = Previous Page; \"X\" = Exit]\n> ";
			cin >> answer;
			cin.ignore();
			switch (toupper(answer)) {
				case '>':
					if (i + 1 >= Length) i = 0;
					else i++;
					continue;
				case '<':
					if (i - 1 < 0) i = Length - 1;
					else i--;
					continue;
				case 'X':
					exit = true;
					break;
				default:
					cout << "ERROR DISPLAY_DETAILS: Invalid input. Exiting..." << endl;
					system("pause");
					exit = true;
					break;
			}
			if (exit) break;
		}
		system("cls");
		return DoublyLinkedList<T>();
	}
	DoublyLinkedList<T>* GetPage(int index, int length) {
		DoublyLinkedList<T>* displayedList = new DoublyLinkedList<T>();
		for (int i = index; i < index + length && i < GetLength(); i++) {
			displayedList->AddToEnd(this->Get(i));
		}
		return displayedList;
	}
	int GetLength() {
		return Length;
	}
};