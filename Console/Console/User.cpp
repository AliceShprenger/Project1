#include"User.h"
#include<iostream>
#include<string>
#include<map>
using namespace std;
User::User(string password, string login, string name) :_login(login), _password(password),_name(name) {}
string User::returnname()
{
	return _name;
}
string User::returnlogin()
{
	return _login;
}
string User::returnpassword()
{
	return _password;
}
void User::information()
{
	cout <<"login: "<< _login << endl;
	cout <<"name: "<< _name << endl;
}
void User::changelogin(string login)
{
	_login = login;
}
void User::changename(string name)
{
	_name = name;
}
void User::changepassword(string password)
{
	_password = password;
}
void User::sendMessage(User* A,string message)
{
	A->_NewMessages.push_back({ this->_login,message });
}


