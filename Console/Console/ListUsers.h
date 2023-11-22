#pragma once
#include<vector>
#include<string>
#include"User.h"
class ListUsers {
private:
public:
	std::vector<User*> _List;
	int _size=0;
	ListUsers()=default;
	~ListUsers() = default;
	void sortListname();
	void sortListlogin();
	void show();
	int account_verification(std::string login,std::string password);
	int account_search(std::string login);
	void register_(std::string passw, std::string login, std::string name);
};