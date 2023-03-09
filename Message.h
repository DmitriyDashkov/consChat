#pragma once
#include <iostream>
#include <string>

class Message
{
	std::string _from;
	std::string _to;
	std::string _message;

public:
	Message();
	Message(const std::string& from, const std::string& to, const std::string& message);
	~Message();

	
};