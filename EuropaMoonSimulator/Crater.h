#pragma once
#include <string>
#include <sstream>

#include "SurfaceFeature.h"
class Crater :
	public SurfaceFeature
{
protected:
	int radius_hor;
	int radius_vert;

public:
	Crater(int id, int radius_hor, int radius_vert, unsigned int x, unsigned int y);
	~Crater();

	std::string to_string() override;
};

