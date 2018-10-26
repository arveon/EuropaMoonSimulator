#include "FeatureGenerator.h"

void FeatureGenerator::generate_ridges(int number)
{
	for (int i = 0; i < number; i++)
	{
		int length = (rand() % 10000)+10000;
		int height = (rand() % 50) + 100;
		int width = (rand() % 200) + 1800;
		unsigned int x = rand() % 300000000;
		unsigned int y = rand() % 300000000;

		Ridge* r = new Ridge(cur_index, length, width, height, x, y);
		features.push_back(r);

		cur_index++;
	}

}

void FeatureGenerator::generate_craters(int number)
{
	for (int i = 0; i < number; i++)
	{
		int radius_hor = (rand() % 15000) + 5000;
		int radius_vert = (rand() % 15000) + 5000;
		unsigned int x = rand() % 300000000;
		unsigned int y = rand() % 300000000;

		Crater* r = new Crater(cur_index, radius_hor, radius_vert, x, y);
		features.push_back(r);

		cur_index++;
	}

}

Ridge* FeatureGenerator::parse_ridge(rapidxml::xml_node<>* ridge)
{
	int id = std::stoi(ridge->first_node("id")->value());
	int height = std::stoi(ridge->first_node("height")->value());
	int width = std::stoi(ridge->first_node("width")->value());
	int length = std::stoi(ridge->first_node("length")->value());
	unsigned int x = std::stoi(ridge->first_node("coords")->first_node("x")->value());
	unsigned int y = std::stoi(ridge->first_node("coords")->first_node("y")->value());
	return new Ridge(id, length, width, height, x, y);
}

Crater * FeatureGenerator::parse_crater(rapidxml::xml_node<>* crater)
{
	int id = std::stoi(crater->first_node("id")->value());
	int radius_hor = std::stoi(crater->first_node("radius")->first_node("horizontal")->value());
	int radius_vert = std::stoi(crater->first_node("radius")->first_node("vertical")->value());
	unsigned int x = std::stoi(crater->first_node("coords")->first_node("x")->value());
	unsigned int y = std::stoi(crater->first_node("coords")->first_node("y")->value());
	return new Crater(id, radius_hor, radius_vert, x, y);
}

void FeatureGenerator::write_features_to_file(char * file_name)
{
	if (features.empty())
	{
		std::cerr << "Nothing to write. No ridges stored!" << std::endl;
		return;
	}

	std::stringstream sstream;
	sstream << "<features>" << std::endl;
	for (SurfaceFeature* r : features)
	{
		sstream << r->to_string() << std::endl;
	}
	sstream << "</features>" << std::endl;
	
	FileReadWriter::write_to_file(file_name, sstream.str());
}

void FeatureGenerator::read_features_from_file(char * file_name, bool append_to_existing)
{
	std::vector<char> contents = FileReadWriter::get_file_char_vector(file_name);

	if (!append_to_existing)
	{
		for (SurfaceFeature* f : features)
			delete f;
		features.clear();
	}

	rapidxml::xml_document<> doc;
	doc.parse<0>(&contents[0]);

	rapidxml::xml_node<>* feature = doc.first_node("features")->first_node();
	while (feature)
	{
		std::string name = feature->name();
		if (!name.compare("ridge"))
			features.push_back(parse_ridge(feature));
		else if (!name.compare("crater"))
			features.push_back(parse_crater(feature));

		feature = feature->next_sibling();
	}

}

FeatureGenerator::FeatureGenerator()
{
	cur_index = 0;
}


FeatureGenerator::~FeatureGenerator()
{
}
