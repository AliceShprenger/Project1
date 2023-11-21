#pragma once
#include<vector>
#include<string>
#include"User.h"
class ListUsers {
private:
public:
	std::vector<User*> _List;
	int _size;
	ListUsers()=default;
	~ListUsers() = default;
	void sortListname();
	void sortListlogin();
	int account_verification(std::string login,std::string password);
	void register_(std::string passw, std::string login, std::string name);
};