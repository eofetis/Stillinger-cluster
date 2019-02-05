#include <cmath>
#include "coord_utils.h"

// periodic boundaries
void PBC(double& delx, double& dely, double& delz, const double boxl) {
	delx -= round(delx/boxl) * boxl;
	dely -= round(dely/boxl) * boxl;
	delz -= round(delz/boxl) * boxl;
}

// distance squared
double DistanceSq(const Atom& a1, const Atom& a2, const double& boxl) {
	double delx = std::abs(a1.x - a2.x);
	double dely = std::abs(a1.y - a2.y);
	double delz = std::abs(a1.z - a2.z);
	PBC(delx, dely, delz, boxl);
	return delx*delx + dely*dely + delz*delz;
}
