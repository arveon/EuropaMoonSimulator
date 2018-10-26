
#include "FeatureGenerator.h"

int main()
{
	FeatureGenerator gen;
	gen.generate_ridges(10);
	gen.generate_craters(5);
	gen.write_features_to_file((char*)"features.xml");
	gen.read_features_from_file((char*)"features.xml", false);

	return 0;
}