#pragma once
class Interface {
public:
	class General {
	public:
		static void PrintLine(char symbol, int length);
	};
	class User {
	public:
		static void DisplayStartupPage();
		static void DisplayLoginPage();
		static void DisplayRegisterPage();
	};
	class Patient {
	public:
		static void DisplayPatientMainMenuPage();
	};
};