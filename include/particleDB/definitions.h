#ifndef PARTICLEDB_DEFINITIONS_H
#define PARTICLEDB_DEFINITIONS_H



namespace particleDB {

/**
 By default, all units are in S.I. system.
*/

static constexpr double c_light = 2.99792458e8; // m/s
static constexpr double c_squared = c_light * c_light; // m^2 / s^2
static constexpr double h_planck = 6.62606957e-34; // J.s
static constexpr double eplus = 1.602176487e-19; // A.s

static constexpr double eV = eplus; 
static constexpr double keV = 1e3 * eV;
static constexpr double MeV = 1e6 * eV;
static constexpr double GeV = 1e9 * eV;
static constexpr double TeV = 1e12 * eV;

} // namespace

#endif