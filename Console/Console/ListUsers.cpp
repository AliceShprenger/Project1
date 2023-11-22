#include "ListUsers.h"
#include "User.h"
#include <vector>
#include <algorithm>
#include<string>
#include<iostream>
using namespace std;
bool Listcomparename(User* A,User* B) {
	return(A->returnname() < B->returnname());
}
bool Listcomparelogin(User* A, User* B) {
	return(A->returnlogin() < B->returnlogin());
}
void ListUsers::sortListname()
{
	sort(_List.begin(), _List.end(), Listcomparename);
}

void ListUsers::sortListlogin()
{
	sort(_List.begin(), _List.end(), Listcomparelogin);
}

void ListUsers::show()
{
	for (int i = 0; i < _size; i++) {
		cout << _List[i]->returnname() << "   " << _List[i]->returnlogin() << endl;
	}
}

int ListUsers::account_verification(string login, string password)
{
	for (int i = 0; i < _size; i++)
	{
		if (login == _List[i]->returnlogin() and password == _List[i]->returnpassword()) return i;
	}
	return -1;
}

int ListUsers::account_search(std::string login)
{
	for (int i = 0; i < _size; i++)
	{
		if (login == _List[i]->returnlogin()) return i;
	}
	return -1;
}

void ListUsers::register_(string passw, string login, string name)
{
	User* B=new User(passw, login, name);
	_List.push_back(B);
	_size++;
}

