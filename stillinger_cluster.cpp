#include "stillinger_cluster.h"

// checks if two atoms are the correct types
bool AtomMatch(const Atom& a1, const Atom& a2, const std::string atype1, const std::string atype2) {
	return (((a1.atype == atype1) and (a2.atype == atype2))
			or ((a1.atype == atype2) and (a2.atype == atype1)));
}

std::map<int, int> MapClusters(const std::vector<Atom>& atoms, const double rcut
		, const std::string atype1, const std::string atype2, const double boxl) {
	std::map<int, int> cluster_map;

	double rcutsq = rcut * rcut;
	std::vector<int> nextInCluster(atoms.size(), 0);
	for (int i = 0; i < atoms.size(); ++i) {
		nextInCluster[i] = i;
	}

	for (int kchain = 0; kchain < atoms.size(); ++kchain) {
		int ichain = kchain;
		if (nextInCluster[kchain] != kchain) continue;
		for (int jchain = kchain + 1; jchain < atoms.size(); ++jchain) {
			if (nextInCluster[jchain] != jchain) continue;

			if (AtomMatch(atoms[ichain], atoms[jchain], atype1, atype2) and
					(DistanceSq(atoms[ichain], atoms[jchain], boxl) <= rcutsq)) {
					nextInCluster[jchain] = nextInCluster[ichain];
					nextInCluster[ichain] = jchain;
					continue;
			}
		}

		while (true) {
			ichain = nextInCluster[ichain];
			if (ichain == kchain) break;
			for (int jchain = kchain + 1; jchain < atoms.size(); ++jchain) {
				if (nextInCluster[jchain] != jchain) continue;

				if (AtomMatch(atoms[ichain], atoms[jchain], atype1, atype2) and
						(DistanceSq(atoms[ichain], atoms[jchain], boxl) <= rcutsq)) {
						nextInCluster[jchain] = nextInCluster[ichain];
						nextInCluster[ichain] = jchain;
						continue;
				}
			}
		}
	}

	for (int ichain = 0; ichain < atoms.size(); ++ichain) {
		if (nextInCluster[ichain] == -1) continue;
		int kchain = ichain;
		int cl_size = 1;
		std::vector<int> cl_index;
		cl_index.push_back(ichain);

		while (true) {
			int jchain = kchain;
			kchain = nextInCluster[kchain];
			nextInCluster[jchain] = -1;
			if (kchain == ichain) break;
			++cl_size;
			cl_index.push_back(kchain);
		}

		for (int ind : cl_index) {
			cluster_map[ind] = cl_size;
		}
	}

	return cluster_map;
}
