#pragma once
#include <sstream>
#include <iostream>
#include <vector>

#include <rapidxml_1.13/rapidxml.hpp>

#include "FileReadWriter.h"
#include "SurfaceFeature.h"
#include "Ridge.h"
#include "Crater.h"

class FeatureGenerator
{
private:
	int cur_index;
	std::vector<SurfaceFeature*> features;
public:
	void generate_ridges(int number);
	void generate_craters(int number);

	Ridge* parse_ridge(rapidxml::xml_node<>*);
	Crater* parse_crater(rapidxml::xml_node<>*);
	void write_features_to_file(char* file_name);
	void read_features_from_file(char* file_name, bool append = true);//if append_to_existing = false it will clear the existing ridges first
	FeatureGenerator();
	~FeatureGenerator();
};

