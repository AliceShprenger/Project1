#include <iostream>
#include"ListUsers.h"
#include"User.h"
using namespace std;
ListUsers LIST;

bool password_check(string passw) {
	cout << "repeat the password again: ";
	string passw1;
	cin >> passw1;
	if (passw1 == passw) return 1;
	cout << "passwords did not match" << endl;
	return 0;
}

int ENTER()
{
	while (true) {
		cout << "log_in or sign_up or exit" << endl;
		string command;
		while (true)
		{
			cin >> command;
			if (command != "log_in" and command != "sign_up" and command != "exit") {
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
			cout << "Enter login: ";
			cin >> login;
			cout << "Enter password: ";
			cin >> passw;
			int j = LIST.account_verification(login, passw);
			if (j==-1)
			{
				cout << "Account not found" << endl;
			}
			else {
				return j;
			}
		}

		if (command == "exit") return -1;

	}
}

void list_of_users() {
	while (true)
	{
		char command;
		cout << "Enter the command: 1 - sort list of users by name, 2 - sort list of users by login, 3 - show list, 4 - come back" << endl;
		cin >> command;
		switch (command) {
		case '1':
			LIST.sortListname();
			break;
		case '2':
			LIST.sortListlogin();
			break;
		case '3':
			LIST.show();
			break;
		case '4':
			return;
			break;
		default:
			cout << "invalid command" << endl;
			break;

		}
	}
}

void settings(User* current_user) {
	while (true) {
		char command;
		string newlogin, newname, newpassword;
		cout << "Enter the command:1 - account information, 2 - change login, 3 - change name, 4 - change password, 5 - come back" << endl;
		cin >> command;
		switch (command) {
		case '1':
			current_user->information();
			break;
		case '2':
			cout << "Enter a new login: " ;
			cin >> newlogin;
			current_user->changelogin(newlogin);
			cout << "login changed" << endl;
			break;
		case '3':
			cout << "Enter a new name: ";
			cin >> newname;
			current_user->changename(newname);
			cout << "name changed" << endl;
			break;
		case '4':
			cout << "Enter a new password: ";
			cin >> newpassword;
			if (password_check(newpassword)) {
				current_user->changepassword(newpassword);
				cout << "password changed" << endl;
			}
			else
			{
				cout << "password has not been changed" << endl;
			}
			break;
		case '5':
			return;
			break;
		default:
			cout << "invalid command" << endl;
			break;

		}
	}
}


int main()
{
	while (true)
	{
		bool exit = 0;
		int ent = ENTER();
		if (ent==-1) return 0;
		User* current_user=LIST._List[ent];
		while (true)
		{
			char command;
			cout << "Enter the command: 1 - send message, 2 - check new messages, 3 - settings, 4 - list of users, 5 - log out of your account, 6 - exit" << endl;
			cin >> command;
			switch (command) {
			case '1':
				break;
			case '2':
				break;
			case '3':
				settings(current_user);
				break;
			case '4':
				list_of_users();
				break;
			case '5':
				exit = 1;
				break;
			case '6':
				return 0;
				break;

			default:
				cout << "invalid command" << endl;
				break;
			}
			if (exit) break;
		}
	}
	return 0;//добавить конст после функций, сделать,чтобы логины не повтор€лись, сделатьЅчтобы при входе различались ошибки
	//ввода парол€ и существовани€ аккаунта
}