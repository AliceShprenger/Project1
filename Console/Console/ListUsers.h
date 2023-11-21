#pragma once
#include<vector>
#include<string>
#include"User.h"
class ListUsers {
private:
	std::vector<User> _List;
	int _size;
public:
	ListUsers()=default;
	~ListUsers() = default;
	void sortListname();
	void sortListlogin();
	bool account_verification(std::string login,std::string password);
	void register_(std::string passw, std::string login, std::string name);
};