#include "FileReadWriter.h"



std::string FileReadWriter::get_file_string(char * filename)
{
	std::ifstream f(filename);
	std::string final_str, line;
	while (std::getline(f, line))
		final_str += line;

	f.close();

	return final_str;
}

std::vector<char> FileReadWriter::get_file_char_vector(char * filename)
{
	std::ifstream f(filename);
	std::string final_str, line;
	while (std::getline(f, line))
		final_str += line;

	f.close();

	std::vector<char> result(final_str.begin(), final_str.end());
	result.push_back('\0');
	return result;
}

void FileReadWriter::write_to_file(char * filename, std::string to_write)
{
	std::ofstream f(filename);
	f << to_write;
	f.close();
}

FileReadWriter::FileReadWriter()
{
}


FileReadWriter::~FileReadWriter()
{
}
