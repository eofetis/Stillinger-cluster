#pragma once

#include <vector>
#include <map>
#include <string>
#include "atom.h"
#include "coord_utils.h"


// maps each atom in the box to the cluster size it belongs to (based on atom1--atom2 rcut)
std::map<int, int> MapClusters(const std::vector<Atom>& atoms, const double rcut
		, const std::string atype1, const std::string atype2, const double boxl);

// checks if two atoms are the correct types
bool AtomMatch(const Atom& a1, const Atom& a2, const std::string atype1, const std::string atype2);
