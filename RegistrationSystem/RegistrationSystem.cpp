// SampleQuiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int choice = 0;
	string newUsername;
	string newPassword;
	string username;
	string password;
	string checkUsername;
	string checkPassword;
	ofstream outputFile;
	ifstream inputFile;

	do {
		cout << "Please choose your respective menu options..." << endl
			<< "1. Register" << endl
			<< "2. Login" << endl
			<< "-------------------------------------------------" << endl
			<< "Enter any other number to quit..." << endl << endl;

		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Create your username ";
			cin >> newUsername;
			cout << endl;

			while ((newUsername.length() < 5) || (newUsername.length() > 12)) {
				cout << "Please enter a username between 5 to 12 characters ";
				cin >> newUsername;
				cout << endl;
			}

			cout << "Create your password ";
			cin >> newPassword;
			cout << endl;

			while ((newPassword.length() < 4) || (newPassword.length() > 10)) {
				cout << "Please enter a password between 4 to 10 characters ";
				cin >> newPassword;
				cout << endl;
			}
			outputFile.open ("CustomerInfo.txt");

			outputFile << newUsername << endl;
			outputFile << newPassword << endl;

			cout << "Successfully registered..." << endl;
			
			break;

		case 2:
			cout << "Enter your username ";
			cin >> username;
			cout << endl;

			cout << "Enter your password ";
			cin >> password;
			cout << endl;

			inputFile.open("CustomerInfo.txt");
			
			inputFile >> checkUsername >> checkPassword;

			if ((checkUsername == username) && (checkPassword == password))
				cout << "Successfully logged in..." << endl;

			else
				cout << "Login failed..." << endl;

			break;
		}
		cout << endl;
	} while ((choice == 1) || (choice == 2));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
