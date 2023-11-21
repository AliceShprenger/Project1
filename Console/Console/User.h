#pragma once
#include <string>
class User {
private:
	std::string _password;
	std::string _login;
	std::string _name;
public:
	User(std::string login, std::string password, std::string name);
	~User() = default;
	std::string returnname();
	std::string returnlogin();
	std::string returnpassword();
	void information();

};