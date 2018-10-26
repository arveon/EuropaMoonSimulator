#include "SurfaceFeature.h"

SurfaceFeature::SurfaceFeature(unsigned int id, unsigned int x, unsigned int y, FeatureType type)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->type = type;
}

SurfaceFeature::~SurfaceFeature()
{
}
