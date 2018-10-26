#include "Crater.h"


Crater::Crater(int id, int radius_hor, int radius_vert, unsigned int x, unsigned int y)
	:SurfaceFeature(id, x, y, FeatureType::Crater)
{
	this->radius_hor = radius_hor;
	this->radius_vert = radius_vert;
}

Crater::~Crater()
{
}

std::string Crater::to_string()
{
	std::stringstream ss;
	ss << "<crater><id>" << id << "</id><radius><horizontal>" << radius_hor << "</horizontal><vertical>" << radius_vert << "</vertical></radius><coords><x>" << x << "</x><y>" << y << "</y></coords></crater>";
	return ss.str();
}
