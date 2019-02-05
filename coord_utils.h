#pragma once

#include "atom.h"

// periodic boundaries
void PBC(double& delx, double& dely, double& delz, const double boxl);

// distance squared
double DistanceSq(const Atom& a1, const Atom& a2, const double& boxl);
