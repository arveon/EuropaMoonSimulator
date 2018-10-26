#pragma once
#include <string>

class SurfaceFeature
{
public:
	enum FeatureType {
		Ridge,
		Crater
	};
protected:
	unsigned int id;
	unsigned int x;
	unsigned int y;
	FeatureType type;
public:
	SurfaceFeature(unsigned int id, unsigned int x, unsigned int y, FeatureType type);
	~SurfaceFeature();

	FeatureType get_type() { return type; }

	virtual std::string to_string() = 0;
};

