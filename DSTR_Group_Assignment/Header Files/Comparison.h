#pragma once
#include <iostream>
using namespace std;
const string STRING_COMPARISON_LIST = " ()_-,.AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789";

static int CompareStrings(string strA, string strB) {
	int index = 0;
	while (index < int(strA.length()) && index < int(strB.length())) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < int(STRING_COMPARISON_LIST.length()); i++) {
			if (STRING_COMPARISON_LIST[i] == strA[index]) a = i + 1;
			if (STRING_COMPARISON_LIST[i] == strB[index]) b = i + 1;
			if (a > 0 && b > 0) break;
		}
		if (a < b) return 0;
		if (b < a) return 2;
		index++;
	}
	if (strA.length() > strB.length()) return 2;
	else if (strA.length() < strB.length()) return 0;
	else return 1;
}