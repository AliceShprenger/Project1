#pragma once
#include <string>
class User {
private:
	std::string _password;
	std::string _login;
	std::string _name="not indicated";
public:
	User(std::string login,std::string password){}
	User(std::string login, std::string password, std::string name) {}
	~User() = default;
	void information(){}
};