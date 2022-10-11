#pragma once
#include <iostream>
#include <string.h>

class mouseStatus {
private:
	int mouse;
	std::string mosStatus;

public:
	void setMouseStatus(std::string setStatus);
	std::string getMouseStatus();
};