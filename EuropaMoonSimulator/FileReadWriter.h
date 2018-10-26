#pragma once
#include <string>
#include <fstream>
#include <vector>

class FileReadWriter
{
public:
	static std::string get_file_string(char* filename);
	static std::vector<char> get_file_char_vector(char* filename);
	static void write_to_file(char* filename, std::string to_write);

	FileReadWriter();
	~FileReadWriter();
};

