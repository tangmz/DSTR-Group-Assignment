#pragma once
#include <string>

class Interface {
public:
	class General {
	public:
		static void PrintLine(char symbol, int length);
	};
	class UserInterface {
	public:
		static void DisplayStartupPage();
		static std::string DisplayLoginPage();
		static std::string DisplayRegisterPage();
		static void DisplayExitPage();
	};
	class DoctorInterface {
	public:
		static void DisplayMainMenu();
	};
	class NurseInterface {
	public:
		static void DisplayMainMenu();
	};
	class PatientInterface {
	public:
		static void DisplayMainMenu();
		static void DisplaySortPatients();
		static void DisplaySearchPatients();
	};
};