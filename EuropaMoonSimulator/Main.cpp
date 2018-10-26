
#include "RidgeGenerator.h"

int main()
{
	RidgeGenerator gen;
	gen.generate_ridges(10);
	gen.write_ridges_to_file((char*)"ridges.xml");
	gen.read_ridges_from_file((char*)"ridges.xml", false);

	return 0;
}