#include <iostream>
using namespace std;
void register_() {

}
int main()
{
	setlocale(LC_ALL, "");
	while (true) {
		cout << "log_in or sign_up: " << endl;
		string command;
		while (true)
		{
			cin >> command;
			if (command != "log_in" and command != "sign_up") {
				cout << "wrong command, retype: " <<endl;
			}
			else break;
		}

		if (command == "log_in") {

		}

		if (command == "sign_up") {

		}
	}
	return 0;
}