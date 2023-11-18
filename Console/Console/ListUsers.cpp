#include "ListUsers.h"
#include <vector>
#include <algorithm>
using namespace std;
bool Listcomparename(User*A,User*B) {
	return(A->returnname() < B->returnname());
}
bool Listcomparelogin(User* A, User* B) {
	return(A->returnlogin() < B->returnlogin());
}
void ListUsers::addUser(User* A)
{
	_List.push_back(*A);
}

void ListUsers::sortListname()
{
	sort(_List.begin(), _List.end(), Listcomparename);
}

void ListUsers::sortListlogin()
{
	sort(_List.begin(), _List.end(), Listcomparelogin);
}
