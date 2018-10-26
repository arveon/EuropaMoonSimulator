#include "Ridge.h"



std::string Ridge::to_string()
{
	std::stringstream ss;
	ss << "<ridge><id>" << id << "</id><length>" << length << "</length><width>" << width << "</width><height>" << height <<"</height><coords><x>" << x << "</x><y>" << y << "</y></coords></ridge>";
	return ss.str();
}

Ridge::Ridge(unsigned int id, int length, int width, int height, unsigned int x, unsigned int y)
	: SurfaceFeature(id, x,y, FeatureType::Ridge)
{
	this->length = length;
	this->width = width;
	this->height = height;
}


Ridge::~Ridge()
{
}
