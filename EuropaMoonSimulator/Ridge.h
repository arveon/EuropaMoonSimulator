#pragma once
#include <string>
#include <sstream>

#include "SurfaceFeature.h"

class Ridge : public SurfaceFeature
{
private:
	int length;
	int width;
	int height;
public:
	std::string to_string() override;

	Ridge(unsigned int id, int length, int width, int height, unsigned int x, unsigned int y);
	~Ridge();
};

