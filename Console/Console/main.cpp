#include <iostream>
#include <vector>
#include <string>
#include <set>
#include"ListUsers.h"
#include"User.h"
using namespace std;
ListUsers LIST;
map < std::pair<std::string, std::string>, std::vector < std::pair<std::string, std::string> >> AllMessages;
set<string>Alllogins;
bool password_check(string passw) {
	cout << "Repeat the password again: ";
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
				cout << "wrong command, retype: ";
			}
			else break;
		}

		if (command == "log_in") {
			string passw, login, name;
			cout << "(don't use spaces)" << endl;;
			cout << "Create a login: ";
			cin >> login;
			if (Alllogins.find(login) != Alllogins.end())
			{
				cout<<"login is already in use"<< endl;
			}
			else {
				cout << "Create a name: ";
				cin >> name;
				cout << "Create a password: ";
				cin >> passw;
				if (password_check(passw))
				{
					Alllogins.insert(login);
					LIST.register_(passw, login, name);
					cout << "Account created" << endl;
				}
				else cout << "Account not created" << endl;
			}
		}

		if (command == "sign_up") {
			string passw, login;
			cout << "Enter login: ";
			cin >> login;
			if (Alllogins.find(login) == Alllogins.end())
			{
				cout << "account not found" << endl;

			}
			else {
				cout << "Enter password: ";
				cin >> passw;
				int j = LIST.account_verification(login, passw);
				if (j == -1)
				{
					cout << "wrong password" << endl;
				}
				else {
					return j;
				}
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
			if (Alllogins.find(newlogin) != Alllogins.end())
			{
				cout << "login is already in use" << endl;
			}
			else {
				Alllogins.erase(current_user->returnlogin());
				Alllogins.insert(newlogin);
				current_user->changelogin(newlogin);
				cout << "login changed" << endl;
			}
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

void send_message(User* current_user) {
	string login;
	cout << "Enter the login of the person you want to send a message: " ;
	cin >> login;
	int i = LIST.account_search(login);
	if (i == -1) cout << "account not found "<< endl;
	else {
		cout << "Enter your message:" << endl;
		string message;
		cin.get();
		getline(cin,message);
		current_user->sendMessage(LIST._List[i],message);
		AllMessages[{max(current_user->returnlogin(), LIST._List[i]->returnlogin()), min(current_user->returnlogin(), LIST._List[i]->returnlogin())}].push_back({ current_user->returnlogin(),message });
	}
}

void send_message_all(User* current_user) {
	cout << "Enter your message:" << endl;
	string message;
	cin.get();
	getline(cin, message);
	for (int i = 0; i < LIST._size; i++)
	{
		current_user->sendMessage(LIST._List[i], message);
		AllMessages[{max(current_user->returnlogin(), LIST._List[i]->returnlogin()), min(current_user->returnlogin(), LIST._List[i]->returnlogin())}].push_back({ current_user->returnlogin(),message });
	}
}

void show_all_correspondence(User* current_user) {
	string login;
	cout <<"Enter user login: ";
	cin>> login;
	int i = LIST.account_search(login);
	if (i == -1) cout << "user is not found" << endl;
	else {
		int SIZE= AllMessages[{max(current_user->returnlogin(), LIST._List[i]->returnlogin()), min(current_user->returnlogin(), LIST._List[i]->returnlogin())}].size();
		for (int j = 0; j < SIZE; j++)
		{
			cout << AllMessages[{max(current_user->returnlogin(), LIST._List[i]->returnlogin()), min(current_user->returnlogin(), LIST._List[i]->returnlogin())}][j].first << ":  " << AllMessages[{max(current_user->returnlogin(), LIST._List[i]->returnlogin()), min(current_user->returnlogin(), LIST._List[i]->returnlogin())}][j].second << endl;
		}
	}
}

void show_new_messages(User* current_user) {
	while (true) {
		cout << "You have " << current_user->returnsizeNewMes() << " new messages" << endl;
		char command;
		cout << "Enter the command: 1 - show new message, 2 - come back" << endl;
		cin >> command;
		switch (command) {
		case '1':
			current_user->showNewMessage();
			break;
		case '2':
			return;
			break;
		default:
			cout << "invalid command" << endl;
			break;
		}
	}
}


void check_messages(User* current_user) {
	while (true) {
		char command;
		cout << "Enter the command: 1 - show new messages, 2 - show all correspondence with the user, 3 - come back" << endl;
		cin >> command;
		switch (command) {
		case '1':
			show_new_messages(current_user);
			break;
		case '2':
			show_all_correspondence(current_user);
			break;
		case '3':
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
			cout << "Enter the command: 1 - send message, 2 - send message all, 3 - check messages, 4 - settings, 5 - list of users, 6 - log out of your account, 7 - exit" << endl;
			cin >> command;
			switch (command) {
			case '1':
				send_message(current_user);
				break;
			case '2':
				send_message_all(current_user);
				break;
			case '3':
				check_messages(current_user);
				break;
			case '4':
				settings(current_user);
				break;
			case '5':
				list_of_users();
				break;
			case '6':
				exit = 1;
				break;
			case '7':
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