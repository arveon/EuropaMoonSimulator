#pragma once
#include <string>
#include <sstream>

class Ridge
{
private:
	int id;
	int length;
	int width;
	int height;
	int x;
	int y;
public:
	std::string to_string();

	Ridge(int id, int length, int width, int height);
	~Ridge();
};

