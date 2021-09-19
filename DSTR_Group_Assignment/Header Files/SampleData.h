#pragma once
#include "LinkedList.h"
using namespace std;

DoublyLinkedList<string>* LoadNames();
string GetRandomName(DoublyLinkedList<string>* nameList);
string GetRandomPhone();
char GetRandomGender();