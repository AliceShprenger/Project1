#pragma once
#include"Messages.h"
#include <string>
class User:public Messages {
private:
	std::string _password;
	std::string _login;
	std::string _name;
public:
	User(std::string password, std::string login, std::string name);
	~User() = default;
	std::string returnname() const;
	std::string returnlogin()const;
	std::string returnpassword()const;
	int returnsizeNewMes()const;
	void changelogin(std::string login);
	void changename(std::string name);
	void changepassword(std::string password);
	void information()const;
	void sendMessage(User* A,std::string message);
	void showNewMessage();
};