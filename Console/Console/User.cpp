#include"User.h"
#include<iostream>
#include<string>
User::User(std::string login, std::string password) :_login(login), _password(password) {}
User::User(std::string login, std::string password, std::string name) :_login(login), _password(password),_name(name) {}
std::string User::returnname()
{
	return _name;
}
std::string User::returnlogin()
{
	return _login;
}
void User::information()
{
	std::cout <<"login: "<< _login << std::endl;
	std::cout << "name: "<< _name << std::endl;
}