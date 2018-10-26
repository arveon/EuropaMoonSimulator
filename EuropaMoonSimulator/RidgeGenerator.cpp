#include "RidgeGenerator.h"

void RidgeGenerator::generate_ridges(int number)
{
	for (int i = 0; i < number; i++)
	{
		int length = (rand() % 10000)+10000;
		int height = (rand() % 50) + 100;
		int width = (rand() % 200) + 1800;

		Ridge r(cur_index, length, width, height);
		ridges.push_back(r);

		cur_index++;
	}

}

void RidgeGenerator::write_ridges_to_file(char * file_name)
{
	if (ridges.empty())
	{
		std::cerr << "Nothing to write. No ridges stored!" << std::endl;
		return;
	}

	std::stringstream sstream;
	sstream << "<ridges>" << std::endl;
	for (Ridge r : ridges)
	{
		sstream << r.to_string() << std::endl;
	}
	sstream << "</ridges>" << std::endl;
	
	FileReadWriter::write_to_file(file_name, sstream.str());
}

void RidgeGenerator::read_ridges_from_file(char * file_name, bool append_to_existing)
{
	std::vector<char> contents = FileReadWriter::get_file_char_vector(file_name);

	if (!append_to_existing)
		ridges.clear();

	rapidxml::xml_document<> doc;
	doc.parse<0>(&contents[0]);

	rapidxml::xml_node<>* ridge = doc.first_node("ridges")->first_node("ridge");
	while (ridge)
	{
		int id = std::stoi(ridge->first_node("id")->value());
		int height = std::stoi(ridge->first_node("height")->value());
		int width = std::stoi(ridge->first_node("width")->value());
		int length = std::stoi(ridge->first_node("length")->value());

		ridges.push_back(Ridge(id, length, width, height));
		ridge = ridge->next_sibling();
	}

}

RidgeGenerator::RidgeGenerator()
{
	cur_index = 0;
}


RidgeGenerator::~RidgeGenerator()
{
}
