#pragma once
#include<vector>
#include<string>
#include<map>
class Messages {
protected:
	std::vector< std::pair<std::string, std::string>> _NewMessages;
	int _sizeNewMes = 0;
public:
	Messages() = default;
	~Messages() = default;
};