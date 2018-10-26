#include "Ridge.h"



std::string Ridge::to_string()
{
	std::stringstream ss;
	ss << "<ridge><id>" << id << "</id><length>" << length << "</length><width>" << width << "</width><height>" << height <<"</height></ridge>";
	return ss.str();
}

Ridge::Ridge(int id, int length, int width, int height)
{
	this->id = id;
	this->length = length;
	this->width = width;
	this->height = height;
}


Ridge::~Ridge()
{
}
