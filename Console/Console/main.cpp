#include <iostream>
#include"ListUsers.h"
#include"User.h"
using namespace std;
ListUsers LIST;

bool password_check(string passw) {
	for (int i = 0; i <= 1; i++)
	{
		cout << "repeat the password again: ";
		string passw1;
		cin >> passw1;
		if (passw1 == passw) return 1;
		cout << "passwords did not match" << endl;
	}
	return 0;
}

void ENTER()
{
	while (true) {
		cout << "log_in or sign_up: " << endl;
		string command;
		while (true)
		{
			cin >> command;
			if (command != "log_in" and command != "sign_up") {
				cout << "wrong command, retype: " << endl;
			}
			else break;
		}

		if (command == "log_in") {
			string passw, login, name;
			cout << "Create a login: ";
			cin >> login;
			cout << "Create a name: ";
			cin >> name;
			cout << "Create a password: ";
			cin >> passw;
			if (password_check(passw))
			{
				LIST.register_(passw, login, name);
				cout << "Account created" << endl;
			}
			else cout << "Account not created" << endl;
		}

		if (command == "sign_up") {
			string passw, login;
			cout << "Enter login: " << endl;
			cin >> login;
			cout << "Enter password: " << endl;
			cin >> passw;
			if (LIST.account_verification(login, passw))
			{
				break;
			}
			else cout << "Account not found" << endl;
		}

	}
}



int main()
{
	while (true)
	{
		bool exit = 0;
		ENTER();//�������� ����� �� ���������
		while (true)
		{
			int command;
			cout << "Enter the command: 1 - send message, 2 - check new messages, 3 - settings, 4 - list of users, 5 - log out of your account, 6 - exit" << endl;
			cin >> command;
			switch (command) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				exit = 1;
				break;
			case 5:
				return 0;
				break;

			default:
				cout << "invalid command" << endl;
				break;
			}
			if (exit) break;
		}
	}
	return 0;
}