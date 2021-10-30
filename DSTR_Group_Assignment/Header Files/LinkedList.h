#pragma once
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
	* GET, PRINT, LENGTH FUNCTIONS
	*/
	T Get(int index) {
		if (index >= Length) {
			cout << "ERROR GET: Index exceeds list length";
			return T();
		}

		Current = Head;
		while (index > 0) {
			Current = Current->NextElement;
			index--;
		}
		return Current->Data;
	}
	int GetLength() {
		return Length;
	}
};