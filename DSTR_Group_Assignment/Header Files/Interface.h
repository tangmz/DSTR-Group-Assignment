#pragma once
#include <string>

class Interface {
public:
	class General {
	public:
		static void PrintLine(char symbol, int length);
	};
	class User {
	public:
		static void DisplayStartupPage();
		static std::string DisplayLoginPage();
		static std::string DisplayRegisterPage();
		static void DisplayExitPage();
	};
	class Doctor {
	public:
		static void DisplayMainMenu();
	};
	class Nurse {
	public:
		static void DisplayMainMenu();
	};
	class Patient {
	public:
		static void DisplayMainMenu();
		static void DisplaySortPatients();
		static void DisplaySearchPatients();
	};
};