#pragma once
#include<vector>
#include"User.h"
class ListUsers {
private:
	std::vector<User> _List;
public:
	ListUsers()=default;
	~ListUsers() = default;
	void addUser(User* A);
	void sortListname();
	void sortListlogin();
};