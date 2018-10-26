#pragma once
#include "Ridge.h"

#include <sstream>
#include <iostream>
#include <vector>

#include <rapidxml_1.13/rapidxml.hpp>

#include "FileReadWriter.h"

class RidgeGenerator
{
private:
	int cur_index;
	std::vector<Ridge> ridges;

public:
	void generate_ridges(int number);
	void write_ridges_to_file(char* file_name);
	void read_ridges_from_file(char* file_name, bool append = true);//if append_to_existing = false it will clear the existing ridges first
	RidgeGenerator();
	~RidgeGenerator();
};

