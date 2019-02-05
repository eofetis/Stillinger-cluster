#pragma once

#include <string>

struct Atom {
	double x; // coordinates in Angstrom
	double y;
	double z;
	double q; // charge in units of e
	std::string atype // atom type name;
};
